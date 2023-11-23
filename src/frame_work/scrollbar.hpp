#ifndef _SCROLLBAR_H_
#define _SCROLLBAR_H_

#include "component.hpp"

bool while_scroll = false;

class ScrollBar : Component{
    int scrollrect_posi;
    int scrollrect_height;
    
    cv::Mat scrollbar;
    cv::Vec3b getValueAtCursor(int , int);
    void setScrollPosi(int);
    void setScrollbar();
    bool getWhileScroll();
    void setWhileScroll(bool);

public:
    ScrollBar();
    ~Scrollbar();

};

#endif
