#include "play_ground.h"

int main() {
    PlayGround drawer(60); // Initialize with width and height

    // Draw shapes
    drawer.drawGoals();
    drawer.drawMainRect();
    drawer.drawMiddleCircle();
    drawer.drawBigGoalRect();
    drawer.drawSmallGoalRect();
    drawer.drawPoints();

    drawer.showImage();

    return 0;
}
