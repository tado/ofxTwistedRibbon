#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ribbon = new ofxTwistedRibbon();
}

//--------------------------------------------------------------
void ofApp::update(){
    ofVec3f position;
    float speed = 3.0;
    float radius = sin(ofGetElapsedTimef() * speed * 0.2) * 90 + 200;
    position.z = sin(ofGetElapsedTimef() * speed) * radius;
    position.x  = cos(ofGetElapsedTimef() * speed) * radius;
    position.y  = sin(ofGetElapsedTimef() * speed * 1.3) * radius;
    ofColor color;
    int hue = int(ofGetElapsedTimef() * 10) % 255;
    color.setHsb(hue, 120, 220);
    ribbon->update(position, color);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor(127), ofColor(0), OF_GRADIENT_CIRCULAR);
    
    cam.begin();
    ofRotate(ofGetElapsedTimef() * 10, 1, 1, 0);
    ribbon->draw();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'f') {
        ofToggleFullscreen();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
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
