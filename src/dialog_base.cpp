#include "dialog_base.hpp"

DialogBase::DialogBase(string s){
	window_height = 500;
	window_width = 800;
	scrollbar_width = 15;
	scrollbar_posi = 37;
	scrollrect_height = 20;
	input_area_width = window_width - scrollbar_width;
	title = s;

	while_scroll = false;

	input_area = cv::Mat::zeros(window_height, input_area_width, CV_8UC3);
	cv::namedWindow(title, cv::WINDOW_NORMAL);
	cv::resizeWindow(title, window_width, window_height);
	cv::setMouseCallback(title, &DialogBase::onMouse, this);
}

DialogBase::~DialogBase(){}

void DialogBase::onMouse(int event, int x, int y, int flags, void* param){
    DialogBase* img = static_cast<DialogBase*>(param);
	img->onMouse(event, x, y, flags);
}

void DialogBase::onMouse(int event, int x, int y, int flags) {

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

int DialogBase::getInputAreaWidth() {
	return input_area_width;
}

cv::Vec3b DialogBase::getValueAtCursor(int y, int x){
	return window.at<cv::Vec3b>(y, x);
}

void DialogBase::setScrollPosi(int y){
	if(y < 37){
		scrollbar_posi = 37;
	}
	else if(y > window_height - 40){
		scrollbar_posi = window_height - 40;
	}
	else scrollbar_posi = y;
}

bool DialogBase::getWhileScroll(){
	return while_scroll;
}

void DialogBase::setWhileScroll(bool b){
	while_scroll = b;
}

void DialogBase::setScrollbar(){
	scrollbar = cv::Mat(window_height, scrollbar_width, CV_8UC3, cv::Scalar(50, 50, 50));
    cv::drawMarker(scrollbar, cv::Point(7, 10), cv::Scalar(130, 130, 130), cv::MARKER_TRIANGLE_UP, 6, 1, cv::LINE_AA);
    cv::drawMarker(scrollbar, cv::Point(7, window_height - 10), cv::Scalar(130, 130, 130), cv::MARKER_TRIANGLE_DOWN, 6, 1, cv::LINE_AA);

	cv::rectangle(scrollbar, cv::Point(2, scrollbar_posi-scrollrect_height), cv::Point(scrollbar_width - 2, scrollbar_posi+scrollrect_height), cv::Scalar(100, 100, 100), cv::FILLED);
}

void DialogBase::imgConcat(){
	cv::hconcat(input_area, scrollbar, window);
}

void DialogBase::imgShow(){
	setScrollbar();
	imgConcat();
	cv::imshow(title, window);
}
