#ifndef PLAYGROUND_H
#define SHAPEDRAWER_H

#include <opencv2/opencv.hpp>

class PlayGround {
public:
    PlayGround(int base_index);
    void drawMainRect();
    void drawMiddleCircle();
    void drawLeftGoal();
    void drawRighGoal();
    void drawSmallGoalRect();
    void drawBigGoalRect();
    void showImage();

private:
    cv::Mat image;
    int base_index;
};

#endif
