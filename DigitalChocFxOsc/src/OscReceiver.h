#pragma once
#include "ofMain.h"
#include "ofxOsc.h"

class OscReceiver
{
public:
	OscReceiver();
	void update();
	void draw();

	ofxOscReceiver receiver;
	ofxOscSender sender;
};

