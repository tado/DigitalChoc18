#include "OscReceiver.h"
#include "ofApp.h"

OscReceiver::OscReceiver() {
	receiver.setup(9000);
	sender.setup("192.168.0.2", 9001);
}

void OscReceiver::update() {
	ofApp *app = ((ofApp*)ofGetAppPtr());
	// check for waiting messages
	while (receiver.hasWaitingMessages()) {
		ofxOscMessage m;
		receiver.getNextMessage(m);
		if (m.getAddress() == "/renick/shader") {
			ofxOscMessage m;
			for (int i = 0; i < app->div * app->div; i++) {
				app->randomShader[i].randomize();
				m.setAddress("/tado/shader");
				m.addIntArg(app->randomShader[i].num);
			}
			sender.sendMessage(m, false);
			/*
			app->num = ofRandom(1, app->shaders.size());
			ofxOscMessage m;
			m.setAddress("/tado/shader");
			m.addIntArg(app->num);
			sender.sendMessage(m, false);
			*/
		}
		if (m.getAddress() == "/renick/effect") {
			int numEffects = 0;
			int fxnum[] = { 0, 2, 3, 4, 6, 7, 8, 9 };
			for (int i = 0; i < 8; i++) {
				int rand = int(ofRandom(4));
				bool fx;
				if (rand == 0) {
					fx = true;
					numEffects++;
				}
				else {
					fx = false;
				}
				app->myGlitch.setFx(ofxPostGlitchType(fxnum[i]), fx);
			}
			ofxOscMessage m;
			m.setAddress("/tado/effect");
			m.addIntArg(numEffects);
			sender.sendMessage(m, false);
		}
		if (m.getAddress() == "/renick/matrix") {
			app->div = int(ofRandom(1, app->MAX + 1));
			ofxOscMessage m;
			m.setAddress("/tado/matrix");
			m.addIntArg(app->div);
			sender.sendMessage(m, false);
		}
	}
}
