#pragma once
#include "ofMain.h"

class RandomShader {
public:
	RandomShader();
	void update();
	void draw();
	void randomize();
	~RandomShader();

	vector<ofShader> shaders;
	ofFbo fbo;

	int num;
	int div;
};

