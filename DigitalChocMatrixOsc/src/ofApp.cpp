#include "ofApp.h"

void ofApp::setup(){
	ofBackground(0);
	ofSetFrameRate(60);
	ofHideCursor();
	osc = new OscReceiver();
	myFbo.allocate(1920, 1080);
	myGlitch.setup(&myFbo);
	div = 1;
	ofToggleFullscreen();
	showLog = false;

	randomShader[0].num = 0;
	fxFreq = 6;
}

void ofApp::update(){
	osc->update();

	for (int i = 0; i < div * div; i++) {
		randomShader[i].div = div;
		randomShader[i].update();
	}
	/*
	int fxNum[] = { 0, 2, 3, 4, 6, 7, 8, 9 };
	if (ofGetFrameNum() % int(ofRandom(2, 6)) == 0) {
		for (int i = 0; i < 8; i++) {
			int rand = int(ofRandom(12));
			bool fx;
			if (rand == 0) {
				fx = true;
			}
			else {
				fx = false;
			}
			myGlitch.setFx(ofxPostGlitchType(fxNum[i]), fx);
		}
		div = int(ofRandom(1, MAX + 1));
		for (int i = 0; i < div * div; i++) {
			randomShader[i].div = div;
		}
	}
	*/
}

void ofApp::draw(){
	for (int i = 0; i < div * div; i++) {
		randomShader[i].draw();
	}
	myFbo.begin();
	for (int j = 0; j < div; j++) {
		for (int i = 0; i < div; i++) {
			randomShader[j * div + i].fbo.draw(1920 / div * i, 1080 / div * j, 1920 / div, 1080 / div);
		}
	}
	myFbo.end();
	myGlitch.generateFx();
	myFbo.draw(0, 0, ofGetWidth(), ofGetHeight());

	if (showLog) {
		ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate()), 20, 20);
	}
}

void ofApp::keyPressed(int key){
	if (key == 'f'){
		ofToggleFullscreen();
	}
	if (key == ' ') {
		for (int i = 0; i < div * div; i++) {
			randomShader[i].randomize();
		}
	}
	if (key == 'z') {
		int fxMAX[] = { 0, 2, 3, 4, 6, 7, 8, 9 };
		for (int i = 0; i < 8; i++) {
			int rand = int(ofRandom(fxFreq));
			bool fx;
			if (rand == 0) {
				fx = true;
			}
			else {
				fx = false;
			}
			myGlitch.setFx(ofxPostGlitchType(fxMAX[i]), fx);
		}
	}
	if (key == 'x') {
		int fxMAX[] = { 0, 2, 3, 4, 6, 7, 8, 9 };
		for (int i = 0; i < 8; i++) {
			myGlitch.setFx(ofxPostGlitchType(fxMAX[i]), false);
		}
	}
	if (key == 'c') {
		div = int(ofRandom(1, MAX + 1));
	}
	if (key == 'v') {
		div = 1;
	}
	if (key == 'a') {
		for (int i = 0; i < div * div; i++) {
			randomShader[i].num = 0;
		}
		div = 1;
	}
	if (key == 'l') {
		showLog ? showLog = false : showLog = true;
	}
	if (key == '2') {
		if (key < 18) {
			fxFreq++;
		}
	}
	if (key == '1'){
		if (key > 2) {
			fxFreq--;
		}
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
