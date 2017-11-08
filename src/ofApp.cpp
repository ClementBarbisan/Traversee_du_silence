#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	kinect.open();
	kinect.initDepthSource();
	kinect.initColorSource();
	kinect.initInfraredSource();
	kinect.initBodySource();
	kinect.initBodyIndexSource();
	buffer.load("buffer");
	distortion.load("distortion");
	displacement.load("displacement");
	displacementImg.loadImage("Displacement.png");
	displacementImg2.loadImage("Displacement2.png");
	framebuffer.allocate(1400, 766, GL_RGBA);
	framebuffer2.allocate(1400, 766, GL_RGBA);
	if (PLAYVIDEO)
		videoPlayer.load("Istwen.mov");
	font.load("trench.ttf", 24);
	ofBackground(1);
	if (FULLSCREEN)
	{
		ofSetFullscreen(true);
		ofHideCursor();
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	if (!start)
		return;
	kinect.update();
	if (timeOutRandomSeconds > 0.0f)
		timeOutRandomSeconds -= ofGetLastFrameTime();
	if (timeOutSeconds > 0.0f)
		timeOutSeconds -= ofGetLastFrameTime();
	else if (!videoPlayed)
	{
		videoPlayed = true;
		videoPlayer.setLoopState(OF_LOOP_NONE);
		videoPlayer.play();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (!start)
	{
		font.drawString("TRAVERSEE DU SILENCE", 520, 525);
		return;
	}
	if (timeOutRandomSeconds <= 0.0f)
		return;
	float timeVideo = videoPlayer.getPosition();
	framebuffer.begin();
	distortion.begin();
	distortion.setUniform1f("timeOutRandom", 0);
	if (timeOutSeconds > 0.0f || timeVideo >= 0.98 || PLAYVIDEO == false)
	{
		videoPlayer.setPaused(true);
		kinect.getBodyIndexSource()->draw(0, 0, 1400, 766);
	}
	else
	{
		videoPlayer.update();
		videoPlayer.draw(0, 0, 1400, 766);
	}
	distortion.end();
	framebuffer.end();
	framebuffer.begin();
	displacement.begin();
	if (index % 2 == 0)
		displacement.setUniformTexture("displacement", displacementImg.getTextureReference(), 1);
	else	
		displacement.setUniformTexture("displacement", displacementImg2.getTextureReference(), 1);
	displacement.setUniform1f("timeOut", timeOutSeconds / TIMEOUT);
	displacement.setUniform1f("timeOutRandom", timeOutRandomSeconds / TIMEOUTRANDOM);
	displacement.setUniform1f("time", ofGetElapsedTimef());
	if (timeOutSeconds > 0.0f || timeVideo >= 0.98 || PLAYVIDEO == false)
	{
		kinect.getBodyIndexSource()->draw(0, 0, 1400, 766);
	}
	else
	{
		videoPlayer.draw(0, 0, 1400, 766);
		if (timeVideo <= 0.25)
		{
			videoPlayer.draw(100 * sin(timeVideo * 4 * PI), -500 * sin(timeVideo * 4 * PI), 1400, 766);
			videoPlayer.draw(300 * sin(timeVideo * 4 * PI), -50 * sin(timeVideo * 4 * PI), 1400, 766);
			videoPlayer.draw(-50 * sin(timeVideo * 4 * PI), 350 * sin(timeVideo * 4 * PI), 1400, 766);
			videoPlayer.draw(-250 * sin(timeVideo * 4 * PI), 50 * sin(timeVideo * 4 * PI), 1400, 766);
			videoPlayer.draw(450 * sin(timeVideo * 4 * PI), 200 * sin(timeVideo * 4 * PI), 1400, 766);
			/*videoPlayer.draw(1400 + 100 * sin(timeVideo * 4 * PI), -500 * sin(timeVideo * 4 * PI), -1400, 788);
			videoPlayer.draw(1400 + 300 * sin(timeVideo * 4 * PI), -50 * sin(timeVideo * 4 * PI), -1400, 788);
			videoPlayer.draw(1400 + -50 * sin(timeVideo * 4 * PI), 350 * sin(timeVideo * 4 * PI), -1400, 788);
			videoPlayer.draw(1400 + -250 * sin(timeVideo * 4 * PI), 50 * sin(timeVideo * 4 * PI), -1400, 788);
			videoPlayer.draw(1400 + 450 * sin(timeVideo * 4 * PI), 200 * sin(timeVideo * 4 * PI), -1400, 788);*/
		}
	}
	displacement.end();
	framebuffer.end();
	/*framebuffer2.begin();
	buffer.begin();
	buffer.setUniform1f("timeOutRandom", timeOutRandomSeconds / TIMEOUTRANDOM);
	buffer.setUniform1f("timeOut", timeOutSeconds / TIMEOUT);
	framebuffer.draw(0, 0, 1400, 788);
	buffer.end();
	framebuffer2.end();*/
	distortion.begin();
	distortion.setUniform1f("timeOutRandom", timeOutRandomSeconds / TIMEOUTRANDOM);
	distortion.setUniform1f("time", ofGetElapsedTimef());
	framebuffer.draw(0,0, 1400, 766);
	distortion.end();
	if (increment >= 20)
	{
		index++;
		increment = 0;
	}
	increment++;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	switch (key)
	{
		case ' ':
			start = true;
		break;
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
