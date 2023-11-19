#ifndef _DIALOG_BASE_H_
#define _DIALOG_BASE_H_

#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace std;

void onMouse(int event, int x, int y, int flags, void* param);

class DialogBase{
    int window_height;
    int window_width;
    int scrollbar_width;
    int scrollbar_posi;
    int scrollrect_height;
    int input_area_width;
    string title;

    bool while_scroll;

    cv::Mat window;
    cv::Mat input_area;
    cv::Mat scrollbar;

public:
    DialogBase(string);
    ~DialogBase();

    int getInputAreaWidth();
    cv::Vec3b getValueAtCursor(int , int);
    void setScrollPosi(int);
    void setScrollbar();
    bool getWhileScroll();
    void setWhileScroll(bool);

    void imgConcat();
    void imgShow();
};

#endif
