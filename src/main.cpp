#include "main_frame.hpp"

int main(){
	MainFrame* frame = new MainFrame("frame");

	while(true){
		frame->imgShow();
		
        char key = cv::waitKey(50) & 0xFF;
        if (key == 'q') {
            break;
        }
	}

	return 0;
}
