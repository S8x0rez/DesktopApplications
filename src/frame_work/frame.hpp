#ifndef _FRAME_H_
#define _FRAME_H_

#include <vector>
#include "component.hpp"

using namespace std;

class Frame : Component{

    cv::Mat window;
    vector<Component> obj;

public:
    DialogBase(string);
    ~DialogBase();

    int getInputAreaWidth();

    void imgShow();
};

#endif
