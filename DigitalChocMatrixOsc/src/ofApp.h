#pragma once

#include "ofMain.h"
#include "ofxPostGlitch.h"
#include "ofxOsc.h"
#include "RandomShader.h"
#include "OscReceiver.h"

class ofApp : public ofBaseApp {

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
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	static const int MAX = 4;
	RandomShader randomShader[MAX * MAX];
	ofFbo myFbo;
	ofxPostGlitch myGlitch;
	int div;
	bool showLog;
	OscReceiver *osc;
	int fxFreq;
};
