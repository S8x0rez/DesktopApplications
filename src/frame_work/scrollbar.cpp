#include "scrollbar.hpp"

ScrollBar::ScrollBar(){
	scrollrect_posi = 37;
	scrollrect_height = 20;
}


void Frame::onMouse(int event, int x, int y, int flags, void* param){
    Frame* img = static_cast<Frame*>(param);
	img->onMouse(event, x, y, flags);
}

void Scrollbar::onMouse(int event, int x, int y, int flags) {

	switch (event) {
    	case cv::EVENT_LBUTTONDOWN:
			if(x > getInputAreaWidth()){
				if(getValueAtCursor(y, x) == cv::Vec3b(100, 100, 100)) {
					setWhileScroll(true);
				}
			}
			break;

		case cv::EVENT_LBUTTONUP:
			if (getWhileScroll()) {
				setWhileScroll(false);
				setScrollbar();
			}
			break;

		case cv::EVENT_MOUSEMOVE:
			if (getWhileScroll()) {
				setScrollPosi(y);
				setScrollbar();
			}
			break;
    }
}

cv::Vec3b ScrollBar::getValueAtCursor(int y, int x){
	return window.at<cv::Vec3b>(y, x);
}

void ScrollBar::setScrollPosi(int y){
	if(y < 37){
		scrollbar_posi = 37;
	}
	else if(y > window_height - 40){
		scrollbar_posi = window_height - 40;
	}
	else scrollbar_posi = y;
}

bool ScrollBar::getWhileScroll(){
	return while_scroll;
}

void ScrollBar::setWhileScroll(bool b){
	while_scroll = b;
}

void ScrollBar::setScrollbar(){
	scrollbar = cv::Mat(window_height, scrollbar_width, CV_8UC3, cv::Scalar(50, 50, 50));
    cv::drawMarker(scrollbar, cv::Point(7, 10), cv::Scalar(130, 130, 130), cv::MARKER_TRIANGLE_UP, 6, 1, cv::LINE_AA);
    cv::drawMarker(scrollbar, cv::Point(7, window_height - 10), cv::Scalar(130, 130, 130), cv::MARKER_TRIANGLE_DOWN, 6, 1, cv::LINE_AA);

	cv::rectangle(scrollbar, cv::Point(2, scrollbar_posi-scrollrect_height), cv::Point(scrollbar_width - 2, scrollbar_posi+scrollrect_height), cv::Scalar(100, 100, 100), cv::FILLED);
}
