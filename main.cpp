#include "soccer_playground.hpp"

int main()
{
    soccer_playground playground;
    playground.create();

    cv::imshow("football_playground", playground.display() );
    cv::waitKey(0);
}
