#ifndef SOCCER_PLAYGROUND_HPP
#define SOCCER_PLAYGROUND_HPP

#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>

class soccer_playground {
    private:
        cv::Mat football_playground;
    public:
        void create();
        cv::Mat display();
};

#endif 