//
//  ofxTwistedRibbon.cpp
//  example
//
//  Created by Atsushi Tadokoro on 8/14/14.
//
//

#include "ofxTwistedRibbon.h"

ofxTwistedRibbon::ofxTwistedRibbon(int _length, ofColor _color, float _thickness){
    length = _length;
    color = _color;
    thickness = _thickness;
}

void ofxTwistedRibbon::update(ofVec3f position){
    points.push_back(position);
    if (points.size() > length) {
        points.pop_front();
    }
}

void ofxTwistedRibbon::draw(){
    ofEnableDepthTest();
    
    ofSetColor(color);
    
    ofVboMesh mesh;
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    for(unsigned int i = 1; i < points.size(); i++){
        ofVec3f thisPoint = points[i-1];
        ofVec3f nextPoint = points[i];
        ofVec3f direction = (nextPoint - thisPoint);
        float distance = direction.length();
        ofVec3f unitDirection = direction.normalized();
        
        ofVec3f toTheLeft = unitDirection.getRotated(90, ofVec3f(0, 1, 1));
        ofVec3f toTheRight = unitDirection.getRotated(0, ofVec3f(0, 1, 1));
        
        ofVec3f leftPoint = thisPoint+toTheLeft * thickness;
        ofVec3f rightPoint = thisPoint+toTheRight * thickness;
        
        mesh.addVertex(ofVec3f(leftPoint.x, leftPoint.y, leftPoint.z));
        mesh.addVertex(ofVec3f(rightPoint.x, rightPoint.y, rightPoint.z));
    }
    
    mesh.draw();
}