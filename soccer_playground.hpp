#ifndef SOCCER_PLAYGROUND_HPP
#define SOCCER_PLAYGROUND_HPP
class soccer_playground {
    private:
        cv::Mat football_playground;
    public:
        void create();
        cv::Mat display();
};

#endif 