#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

#include "object.hpp"

class Component{
    int x;
    int y;
    int height;
    int width;
    
    string title;

    void isInside(int, int, int, int);
    void onMouse(int, int, int, int);

public:
    static void onMouse(int, int, int, int, void*);

    void setPosition(int, int);

};

#endif
