#include "RandomShader.h"
#include "ofApp.h"

RandomShader::RandomShader(){
	ofApp *app = ((ofApp*)ofGetAppPtr());
	ofDirectory dir("100fragments");
	for (int i = 0; i < dir.getFiles().size(); i++) {
		ostringstream digit;
		digit << setfill('0') << right << setw(2) << i;
		ofShader sh;
		sh.load("", "100fragments/" + digit.str() + ".frag");
		shaders.push_back(sh);
	}
	num = int(ofRandom(1, shaders.size()));
	div = app->MAX;
	//fbo.allocate(1920/div, 1080/div);
}

void RandomShader::update() {
	//fbo.clear();
	fbo.allocate(1920/div, 1080/div);
	if (ofGetFrameNum() % int(ofRandom(2, 6)) == 0) {
		num = int(ofRandom(1, shaders.size()));
	}
	fbo.begin();
	shaders[num].begin();
	shaders[num].setUniform1f("time", ofGetElapsedTimef());
	shaders[num].setUniform2f("resolution", 1920/div, 1080/div);
	ofDrawRectangle(0, 0, 1920/div, 1080/div);
	shaders[num].end();
	fbo.end();
}

void RandomShader::draw(int left, int top, int width, int height) {

}

RandomShader::~RandomShader(){
}

