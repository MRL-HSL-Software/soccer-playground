# include "Configs.hpp"

int main() {
    // std::cout << __MRL__ << std::endl;
    cv::Mat abc(300, 300, CV_8UC3, cv::Scalar(255, 0, 0));
    cv::imshow("abc", abc);
    cv::waitKey(0);
}