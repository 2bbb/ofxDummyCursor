//
//  ofxDummyCursor.h
//
//  Created by ISHII 2bit on 2015/09/10.
//
//

#ifndef ofxDummyCursor_h
#define ofxDummyCursor_h

#include "ofMain.h"
#include "Poco/Base64Decoder.h"

enum ofxDummyCursorType {
    OFX_DUMMY_CURSOR_TYPE_ICON,
    OFX_DUMMY_CURSOR_TYPE_CIRCLE,
};

class ofxDummyCursor {
    ofImage image;
    ofxDummyCursor()
    : color(ofColor::white)
    , radius(8)
    , type(OFX_DUMMY_CURSOR_TYPE_ICON)
    , bShow(false)
    {
        stringstream ss("iVBORw0KGgoAAAANSUhEUgAAAAsAAAARCAYAAAAL4VbbAAAABGdBTUEAALGPC/xhBQAAACBjSFJNAAB6JgAAgIQAAPoAAACA6AAAdTAAAOpgAAA6mAAAF3CculE8AAAB1WlUWHRYTUw6Y29tLmFkb2JlLnhtcAAAAAAAPHg6eG1wbWV0YSB4bWxuczp4PSJhZG9iZTpuczptZXRhLyIgeDp4bXB0az0iWE1QIENvcmUgNS40LjAiPgogICA8cmRmOlJERiB4bWxuczpyZGY9Imh0dHA6Ly93d3cudzMub3JnLzE5OTkvMDIvMjItcmRmLXN5bnRheC1ucyMiPgogICAgICA8cmRmOkRlc2NyaXB0aW9uIHJkZjphYm91dD0iIgogICAgICAgICAgICB4bWxuczp0aWZmPSJodHRwOi8vbnMuYWRvYmUuY29tL3RpZmYvMS4wLyI+CiAgICAgICAgIDx0aWZmOkNvbXByZXNzaW9uPjE8L3RpZmY6Q29tcHJlc3Npb24+CiAgICAgICAgIDx0aWZmOk9yaWVudGF0aW9uPjE8L3RpZmY6T3JpZW50YXRpb24+CiAgICAgICAgIDx0aWZmOlBob3RvbWV0cmljSW50ZXJwcmV0YXRpb24+MjwvdGlmZjpQaG90b21ldHJpY0ludGVycHJldGF0aW9uPgogICAgICA8L3JkZjpEZXNjcmlwdGlvbj4KICAgPC9yZGY6UkRGPgo8L3g6eG1wbWV0YT4KAtiABQAAAJZJREFUKBWNkm8OwBAMxW2ZM+HEROJOruAE5skqNX+iX6z6e69NTeQS4jBucKeCChtjzgRwlVJmrTU+9yMBAHwk4DAESilczTv84W2HGbzssIKngh08jMRhrI87osajPgYHsA3kzrlxI1DydVlr1zunNvQvIadxQgi9O4oE0um9b7OnlIY6cfXk7tzs6agvuUoQFGNsyAvKht/qExRTdgAAAABJRU5ErkJggg==");
        Poco::Base64Decoder decoder(ss);
        
        ofBuffer buffer;
        decoder >> buffer;
        
        image.loadImage(buffer);
    }
    
    void draw(ofEventArgs &args) {
        ofPushMatrix();
        ofPushStyle();
        
        ofSetupScreen();
        float x = ofGetMouseX(), y = ofGetMouseY();
        ofSetColor(color);
        ofSetCircleResolution(40);
        switch(type) {
            case OFX_DUMMY_CURSOR_TYPE_ICON:
                image.draw(x - 1, y - 2);
                break;
            case OFX_DUMMY_CURSOR_TYPE_CIRCLE:
                ofCircle(x, y, radius);
                break;
            default:
                break;
        }
        
        ofPopStyle();
        ofPopMatrix();
    }

    ofxDummyCursorType type;
    int radius;
    ofColor color;
    bool bShow;
    
    static ofxDummyCursor *getSharedInstance() {
        static ofxDummyCursor *sharedInstance = new ofxDummyCursor;
        return sharedInstance;
    }
    
public:
    
    static bool isShow() {
        return getSharedInstance()->bShow;
    }
    
    static void show(bool withHideOriginalCursor = true) {
        getSharedInstance()->bShow = true;
        if(withHideOriginalCursor) {
            ofHideCursor();
        }
        ofAddListener(ofEvents().draw, getSharedInstance(), &ofxDummyCursor::draw, OF_EVENT_ORDER_AFTER_APP);
    }
    
    static void hide(bool withShowOriginalCursor = false) {
        getSharedInstance()->bShow = false;
        if(withShowOriginalCursor) {
            ofShowCursor();
        }
        ofRemoveListener(ofEvents().draw, getSharedInstance(), &ofxDummyCursor::draw, OF_EVENT_ORDER_AFTER_APP);
    }
    
    static void toggle() {
        if(isShow()) {
            hide();
        } else {
            show();
        }
    }
    
    static void setCursorType(ofxDummyCursorType type) {
        getSharedInstance()->type = type;
    }
    
    static void setCursorColor(const ofColor &c) {
        getSharedInstance()->color = c;
    }
    
    static void setCircleRadius(int radius) {
        getSharedInstance()->radius = radius;
    }
};

#endif
