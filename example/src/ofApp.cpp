#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  spacebroClient.registerEvent(newMediaEvent, "new-media");
  ofAddListener(newMediaEvent, this, &ofApp::onNewMediaEvent);
  spacebroClient.registerEvent(otherEvent, "other");
  ofAddListener(otherEvent, this, &ofApp::onOtherEvent);

  spacebroClient.setup("ofxSpacebroClient");
}

//--------------------------------------------------------------
void ofApp::onNewMediaEvent (ofxSocketIOData& data) {
  ofLogNotice("Got new-media", data.getStringValue("data"));
}

//--------------------------------------------------------------
void ofApp::onOtherEvent (ofxSocketIOData& data) {
  ofLogNotice("Got other", data.getStringValue("data"));
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
