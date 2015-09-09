#include "ofMain.h"

#include "ofxDummyCursor.h"

class ofApp : public ofBaseApp{
public:
    void setup() {
        ofxDummyCursor::show();
    }
    void update() {}
    void draw() {
        ofBackground(0, 0, 0);
        ofSetColor(255, 255, 255);
        ofDrawBitmapString("e: show dummy cursor with hide original cursor.", 20, 20);
        ofDrawBitmapString("d: hide dummy cursor with hide original cursor.", 20, 40);
        ofDrawBitmapString("E: show dummy cursor with show original cursor.", 20, 60);
        ofDrawBitmapString("D: hide dummy cursor with show original cursor.", 20, 80);
        ofDrawBitmapString("i: set dummy cursor to icon.", 20, 100);
        ofDrawBitmapString("c: set dummy cursor to circle.", 20, 120);
    }
    
    void keyPressed(int key) {
        switch (key) {
            case 'e':
                ofxDummyCursor::show();
                break;
            case 'd':
                ofxDummyCursor::hide();
                break;
            case 'E':
                ofxDummyCursor::show(false);
                break;
            case 'D':
                ofxDummyCursor::hide(true);
                break;
            case 'i':
                ofxDummyCursor::setCursorType(OFX_DUMMY_CURSOR_TYPE_ICON);
                break;
            case 'c':
                ofxDummyCursor::setCursorType(OFX_DUMMY_CURSOR_TYPE_CIRCLE);
                break;
            default:
                break;
        }
    }
};

int main() {
    ofSetupOpenGL(1024, 768, OF_WINDOW);
    ofRunApp(new ofApp);
}
