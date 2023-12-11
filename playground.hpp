#ifndef PLAYGROUND_HPP
#define PLAYGROUND_HPP

#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>

class playground {
    private:
        cv::Mat football_playground;
    public:
        // playground();
        void Create();
        cv::Mat Access();
};

#endif 