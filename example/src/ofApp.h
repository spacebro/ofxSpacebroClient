#pragma once

#include "ofMain.h"

#include "ofxSpacebroClient.h"

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
    void onNewMediaEvent(ofxSocketIOData& data);
    void onOtherEvent(ofxSocketIOData& data);

    ofxSpacebroClient spacebroClient;
    ofEvent<ofxSocketIOData&> newMediaEvent;
    ofEvent<ofxSocketIOData&> otherEvent;
};
