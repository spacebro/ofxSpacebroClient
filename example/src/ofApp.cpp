#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// start a test service
	service.start("Test Service!", "_http._tcp", 8080);
  // look for a service
  browser.lookup("_spacebro._tcp");
  ofAddListener(browser.serviceNewE, this, &ofApp::onServiceNew);
  ofAddListener(browser.serviceRemoveE, this, &ofApp::onServiceRemove);
}

//--------------------------------------------------------------
void ofApp::onServiceNew(ofxAvahiService &s){
  ofLogNotice("Found spacebro:" + s.name + " | " + s.host_name + " | " + s.domain + " | " + s.ip + " | " + ofToString(s.port));

  string address = "http://" + s.host_name + ":" + ofToString(s.port);
  ofLogNotice("Connect to " + address);
  socketIO.setup(address);

  ofAddListener(socketIO.notifyEvent, this, &ofApp::gotEvent);
  ofAddListener(socketIO.connectionEvent, this, &ofApp::onConnection);
}

//--------------------------------------------------------------
void ofApp::onServiceRemove(ofxAvahiService &s){
  ofLogNotice("Spacebro went down:" + s.name + " | " + s.host_name + " | " + s.domain + " | " + s.ip + " | " + ofToString(s.port));
}


//--------------------------------------------------------------
void ofApp::onConnection () {
  bindEvents();
}

//--------------------------------------------------------------
void ofApp::bindEvents () {
  std::string eventName = "new-media";
  socketIO.bindEvent(serverEvent, eventName);
  ofAddListener(serverEvent, this, &ofApp::onServerEvent);
}



//--------------------------------------------------------------
void ofApp::gotEvent(string& name) {
  ofLogNotice("Got event", name);
}

//--------------------------------------------------------------
void ofApp::onServerEvent (ofxSocketIOData& data) {
  ofLogNotice("Got data", data.getStringValue("data"));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
