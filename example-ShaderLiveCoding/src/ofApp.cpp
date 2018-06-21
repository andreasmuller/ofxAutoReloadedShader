#include "ofApp.h"

void ofApp::setup() {
	ofSetLogLevel(OF_LOG_VERBOSE);
	
#ifdef TARGET_OPENGLES
	autoShader.load("Shaders/LiveShader");
	cout << "Loading mobile shader" << endl;
#else
	autoShader.load("Shaders/LiveShaderDesktop");
	cout << "Loading desktop shader" << endl;	
#endif
	
	fbo.allocate(ofGetWidth(), ofGetHeight());
	fbo.begin();
		ofClear(0, 0, 0, 0);
	fbo.end();

	image.load("Textures/landangui.jpg");

	font.load(ofToDataPath("Fonts/DIN.otf"), 8);
}

void ofApp::update() {}

void ofApp::draw() {
	// draw to the FBO
	ofEnableAlphaBlending();	
	fbo.begin();
	ofClear(0, 0, 0, 0);
		autoShader.begin();
		autoShader.setUniform1f("u_time", ofGetElapsedTimef() );
			image.draw(0,0, ofGetWidth(), ofGetHeight() );
		autoShader.end();
	fbo.end();
	ofDisableAlphaBlending();

	// draw the FBO to screen
	fbo.draw(0, 0);

	// draw the FPS
	sprintf(tempStr, "%4.1f", ofGetFrameRate() );
	ofVec2f pos( ofGetWidth()-30, ofGetHeight()-5 );
	ofSetColor(0);
	font.drawString( tempStr, pos.x + 1, pos.y + 1 );
	ofSetColor( 255 );
	font.drawString( tempStr, pos.x, pos.y );
}

void ofApp::keyPressed(int key) {}
void ofApp::keyReleased(int key) {}
void ofApp::mouseMoved(int x, int y ) {}
void ofApp::mouseDragged(int x, int y, int button) {}
void ofApp::mousePressed(int x, int y, int button) {}
void ofApp::mouseReleased(int x, int y, int button) {}
void ofApp::mouseEntered(int x, int y) {}
void ofApp::mouseExited(int x, int y) {}
void ofApp::windowResized(int w, int h) {}
void ofApp::gotMessage(ofMessage msg) {}
void ofApp::dragEvent(ofDragInfo dragInfo) {}
