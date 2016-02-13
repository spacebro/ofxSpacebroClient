#include "ofxSpacebroClient.h"


//--------------------------------------------------------------
void ofxSpacebroClient::setup(string clientName) {
  // look for a service
  ofLogNotice("Waiting for spacebro...");
  browser.lookup("_spacebro._tcp");
  ofAddListener(browser.serviceNewE, this, &ofxSpacebroClient::onServiceNew);
  ofAddListener(browser.serviceRemoveE, this, &ofxSpacebroClient::onServiceRemove);
  this->clientName = clientName;
}


//--------------------------------------------------------------
void ofxSpacebroClient::onServiceNew(ofxAvahiService &s){
  ofLogNotice("Found spacebro:" + s.name + " | " + s.host_name + " | " + s.domain + " | " + s.ip + " | " + ofToString(s.port));

  string address = "http://" + s.host_name + ":" + ofToString(s.port);
  socketIO.setup(address);

  ofAddListener(socketIO.notifyEvent, this, &ofxSpacebroClient::gotEvent);
  ofAddListener(socketIO.connectionEvent, this, &ofxSpacebroClient::onConnection);
}

//--------------------------------------------------------------
void ofxSpacebroClient::onServiceRemove(ofxAvahiService &s){
  ofLogNotice("Spacebro went down:" + s.name + " | " + s.host_name + " | " + s.domain + " | " + s.ip + " | " + ofToString(s.port));
}


//--------------------------------------------------------------
void ofxSpacebroClient::onConnection () {
  ofLogNotice("socketio connected");
  registerToMaster();
  bindEvents();
}

//--------------------------------------------------------------
void ofxSpacebroClient::registerToMaster () {
  string key = "register";
  string message = "{\"eventsList\":"+getEventsList()+", \"clientName\":\"" + clientName+"\"}";
  socketIO.emit(key, message);
}

//--------------------------------------------------------------
string ofxSpacebroClient::getEventsList() {
  //"[\"shoot\", \"bump\", \"new-media\"]"
  string eventsList = "[";
  for (unsigned int i = 0; i < eventNames.size(); i++){
    eventsList += "\"" + eventNames[i] + "\"";
    if (i != eventNames.size() - 1){
      eventsList += ",";
    } else {
      eventsList += "]";
    }
  }
  return eventsList;
}

//--------------------------------------------------------------
void ofxSpacebroClient::registerEvent(ofEvent<ofxSocketIOData&>& event, string eventName) {
  eventNames.push_back(eventName);
  events.push_back(&event);
}

//--------------------------------------------------------------
void ofxSpacebroClient::bindEvents () {
  for (int i = 0; i < events.size(); i++){
    bindEvent(*events[i], eventNames[i]);
  }
}

//--------------------------------------------------------------
void ofxSpacebroClient::bindEvent (ofEvent<ofxSocketIOData&>& event, string eventName) {
  socketIO.bindEvent(event, eventName);
}

//--------------------------------------------------------------
void ofxSpacebroClient::gotEvent(string& name) {
  ofLogNotice("Got event", name);
}
