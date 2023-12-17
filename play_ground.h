#ifndef PLAYGROUND_H
#define SHAPEDRAWER_H

#include <opencv2/opencv.hpp>

class PlayGround {
public:
    PlayGround(int width, int height);
    void drawMainRect();
    void drawMiddleCircle();
    void drawLeftGoal();
    void drawRighGoal();
    void drawLeftSmallRect();
    void drawLeftBigRect();
    void drawRightSmallRect();
    void drawRightBigRect();
    void showImage();

private:
    cv::Mat image;
};

#endif
