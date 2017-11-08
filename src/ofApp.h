#pragma once

#include "ofMain.h"
#include "ofxKinectForWindows2.h"

#define TIMEOUT 35
#define TIMEOUTRANDOM 165
#define FULLSCREEN true
#define PLAYVIDEO false
#define PI 3.14159265

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		ofxKFW2::Device kinect;
		ofShader displacement;
		ofShader distortion;
		ofShader buffer;
		ofImage displacementImg;
		ofImage displacementImg2;
		float timeOut = 1.0f;
		float timeOutSeconds = TIMEOUT;
		float timeOutRandom = 1.0f;
		float timeOutRandomSeconds = TIMEOUTRANDOM;
		ofFbo framebuffer;
		ofFbo framebuffer2;
		ofVideoPlayer videoPlayer;
		bool start = false;
		ofTrueTypeFont font;
		float radius = 20;
		bool videoPlayed = false;
		int increment = 0;
		int index = 0;
};
