#include "play_ground.h"

int main() {
    PlayGround drawer(60); // Initialize with width and height

    // Draw shapes
    drawer.drawMainRect();
    // drawer.drawCircle(cv::Point(300, 150), 100, cv::Scalar(255, 255, 255));
    // drawer.drawLine(cv::Point(350, 300), cv::Point(450, 400), cv::Scalar(255, 255, 255));

    drawer.showImage();

    return 0;
}
