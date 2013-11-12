//
//  variant2.h
//  apc-ex-05-1
//
//  Created by Raphael Matile on 12/11/13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#ifndef __apc_ex_05_1__variant2__
#define __apc_ex_05_1__variant2__

#include <iostream>

class Rectangle2 {
protected:
	int width;
	int height;
    
public:
    virtual void setWidth(int pWidth) {
        width = pWidth;
    }
    virtual void setHeight(int pHeight) {
        height = pHeight;
    }
    int getHeight() {
        return height;
    }
    int getWidth() {
        return width;
    }
    
};

class Square2 : public Rectangle2 {
public:
    void setWidth(int pWidth) {
        width = pWidth;
        height = pWidth;
    }
    
    void setHeight(int pHeight) {
        width = pHeight;
        height = pHeight;
    }
    
	
};


#endif /* defined(__apc_ex_05_1__variant2__) */
