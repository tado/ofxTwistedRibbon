//
//  ofxTwistedRibbon.h
//  example
//
//  Created by Atsushi Tadokoro on 8/14/14.
//
//

#pragma once
#include "ofMain.h"

class ofxTwistedRibbon {
    
public:
    ofxTwistedRibbon(int length = 1000, ofColor color = 0xcccccc, float thickness = 10.0);
    void update(ofVec3f position);
    void update(ofVec3f position, ofColor color);
    void draw();
    
    int length;
    ofColor color;
    float thickness;
    deque <ofVec3f> points;
    deque <ofColor> colors;
};
