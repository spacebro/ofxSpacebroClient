#pragma once

#include "ofMain.h"

#include "ofxAvahiClient.h"
#include "ofxSocketIO.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    void onServiceNew(ofxAvahiService &s);
    void onServiceRemove(ofxAvahiService &s);
    void onConnection();
    void bindEvents();
    void gotEvent(std::string& name);
    void onServerEvent(ofxSocketIOData& data);
    void registerToMaster(string actionList, string clientName);

		ofxAvahiClientService service;
		ofxAvahiClientBrowser browser;

    ofxSocketIO socketIO;
    ofEvent<ofxSocketIOData&> serverEvent;
};
