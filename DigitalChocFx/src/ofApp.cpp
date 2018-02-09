#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofSetFrameRate(120);
    ofDirectory dir("100fragments");
	for (int i = 0; i < dir.getFiles().size(); i++){
		ostringstream digit;
		digit << setfill('0') << right << setw(2) << i;
		ofShader sh;
		sh.load("", "100fragments/" + digit.str() + ".frag");
		shaders.push_back(sh);
	}
    ofToggleFullscreen();
	ofHideCursor();
	showLog = false;
	myFbo.allocate(1920, 1080);
	myGlitch.setup(&myFbo);
	num = int(ofRandom(shaders.size()));
}

//--------------------------------------------------------------
void ofApp::update(){
	/*
	int fxnum[] = { 0, 2, 3, 4, 6, 7, 8, 9 };
	if (ofGetFrameNum() % int(ofRandom(2, 20)) == 0) {
		num = int(ofRandom(shaders.size()));
	}
    if (ofGetFrameNum() % int(ofRandom(2, 20)) == 0) {
		for (int i = 0; i < 8; i++) {
			int rand = int(ofRandom(4));
			bool fx;
			if (rand == 0) {
				fx = true;
			} else {
				fx = false;
			}
			myGlitch.setFx(ofxPostGlitchType(fxnum[i]), fx);
		}
	}
	*/
}

//--------------------------------------------------------------
void ofApp::draw(){
	myFbo.begin();
	ofClear(0, 0, 0, 255);
	shaders[num].begin();
	shaders[num].setUniform1f("time", ofGetElapsedTimef());
	shaders[num].setUniform2f("resolution", 1920, 1080);
	ofDrawRectangle(0, 0, 1920, 1080);
	shaders[num].end();
	myFbo.end();
	myGlitch.generateFx();
	myFbo.draw(0, 0, ofGetWidth(), ofGetHeight());
	if (showLog) {
		ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate()), 20, 20);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'f'){
		ofToggleFullscreen();
	}
	if (key == 's') {
		if (showLog){
			showLog = false;
		} else {
			showLog = true;
		}
	}
	if (key == ' '){
		num = int(ofRandom(shaders.size()));
	}
	if (key == 'z'){
		int fxnum[] = { 0, 2, 3, 4, 6, 7, 8, 9 };
		for (int i = 0; i < 8; i++) {
			int rand = int(ofRandom(4));
			bool fx;
			if (rand == 0) {
				fx = true;
			}
			else {
				fx = false;
			}
			myGlitch.setFx(ofxPostGlitchType(fxnum[i]), fx);
		}
	}
	if (key == 'x')	{
		int fxnum[] = { 0, 2, 3, 4, 6, 7, 8, 9 };
		for (int i = 0; i < 8; i++) {
			myGlitch.setFx(ofxPostGlitchType(fxnum[i]), false);
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
