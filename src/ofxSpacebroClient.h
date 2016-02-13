#pragma once

#include "ofMain.h"

#include "ofxAvahiClient.h"
#include "ofxSocketIO.h"

class ofxSpacebroClient : public ofBaseApp{
	public:
		void setup(string clientName);
    void onServiceNew(ofxAvahiService &s);
    void onServiceRemove(ofxAvahiService &s);
    void onConnection();
    void bindEvents();
    void gotEvent(std::string& name);
    ofEvent<ofxSocketIOData&>& registerEvent(string eventName);
    void bindEvent(ofEvent<ofxSocketIOData&> &event, string eventName);
    string getEventsList();

  protected:
    void registerToMaster();

		ofxAvahiClientService service;
		ofxAvahiClientBrowser browser;

    ofxSocketIO socketIO;
    vector< ofEvent<ofxSocketIOData&> > events;

    vector<string> eventNames;
    string clientName;
};
