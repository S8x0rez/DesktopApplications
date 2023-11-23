#include "frame.hpp"

Frame::Frame(string s){
	height = 500;
	width = 800;
	title = s;

	while_scroll = false;

	input_area = cv::Mat::zeros(window_height, input_area_width, CV_8UC3);
	cv::namedWindow(title, cv::WINDOW_NORMAL);
	cv::resizeWindow(title, window_width, window_height);
	cv::setMouseCallback(title, &Frame::onMouse, this);
}

Frame::~Frame(){}


int Frame::getInputAreaWidth() {
	return input_area_width;
}


void Frame::imgShow(){
	cv::imshow(title, window);
}
