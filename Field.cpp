# ifndef MRL_SOCCER_PLAYGROUND
    # include "Field.hpp"
    /**
     * @brief Initialize Soccer Playground Object
     */
    SoccerPlayground::SoccerPlayground() {
        preview = cv::Mat(
            (FIELD_WIDTH + BORDER_STRIP_WIDTH) * SCALE,
            (FIELD_LENGTH + BORDER_STRIP_WIDTH) * SCALE,
            CV_8UC3,
            BACKGROUND_COLOR
        );
        //-- Find Center Pixel of Screen
        Display* disp = XOpenDisplay(NULL);
        Screen* scrn = DefaultScreenOfDisplay(disp);
        cv::imshow(WINDOW_NAME, preview);
        cv::moveWindow(
            WINDOW_NAME,
            scrn->width / 2 - preview.cols / 2,
            scrn->height / 2 - preview.rows / 2
        );
        XCloseDisplay(disp);
    }
    /**
     * @brief Method to Get Playground Image
     * @return cv::Mat
     */
    cv::Mat SoccerPlayground::getPlayground() {
        return preview;
    }
    /**
     * @brief Method to Draw Playground
     */
    void SoccerPlayground::drawPlayground() {

    }
# endif // MRL_SOCCER_PLAYGROUND





// struct MainRectangle {
//         cv::Point topLeft;
//         cv::Point bottomRight;
//         cv::Scalar color;
//         int thickness;

//         // Constructor to initialize the members
//         MainRectangle() : 
//             topLeft(borderStripWidth * contractPixel, borderStripWidth * contractPixel),
//             bottomRight((borderStripWidth + feildLength) * contractPixel, (borderStripWidth + feildWidth) * contractPixel),
//             color(255, 255, 255),  // White color
//             thickness(1) {}
//     };