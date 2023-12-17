#include "play_ground.h"

int main() {
    PlayGround drawer(60); // Initialize with width and height

    // Draw shapes
    drawer.drawMainRect();
    drawer.drawMiddleCircle();
    drawer.drawBigGoalRect();
    drawer.drawSmallGoalRect();
    drawer.drawGoals();

    drawer.showImage();

    return 0;
}
