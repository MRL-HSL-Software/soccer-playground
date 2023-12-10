#include "playground.hpp"

int main()
{
    soccer_playground playground;
    playground.create();

    cv::imshow("Soccer Playground ", playground.display());
    cv::waitKey(0);
}
