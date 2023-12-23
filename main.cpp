# include "Field.hpp"

int main() {
    SoccerPlayground playground;
    playground.drawPlayground();
    cv::imshow(WINDOW_NAME, playground.getPlayground());
    cv::waitKey(0);
    cv::destroyAllWindows();
}