#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	int len = 72;
	bool fried = false;
	for (int x = len; x < ofGetWidth(); x += len * 2) {

		for (int y = len; y < ofGetHeight(); y += len * 2) {

			this->draw_egg(ofPoint(x, y), len - 10, fried);
			fried = !fried;
		}
	}
	
}

//--------------------------------------------------------------
void ofApp::draw_egg(ofPoint location, float len, bool fried) {

	float a = 1;
	float b = 0.72;
	float c = 0.08;

	ofPushMatrix();
	ofTranslate(location);
	ofRotate(90);

	ofSetColor(239);
	ofBeginShape();
	for (int deg = 0; deg < 360; deg += 1) {

		float x = a * cos(deg * DEG_TO_RAD);
		float y = (b + c * cos(deg * DEG_TO_RAD)) * sin(deg * DEG_TO_RAD);

		float noise_value = fried ? ofMap(ofNoise(location.x * 0.005 + x, location.y * 0.05 + y, ofGetFrameNum() * 0.005), 0, 1, 0.7, 1.2) : 1;

		ofPoint p = ofPoint(x, y) * len * noise_value;

		ofVertex(p);
	}
	ofEndShape();

	if (fried) {

		ofSetColor(220, 220, 39);
		ofDrawCircle(ofPoint(), len * 0.4);
	}
	
	ofPopMatrix();
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}