# ifndef MRL_SOCCER_PLAYGROUND
    # include "Field.hpp"
    /**
     * @brief Initialize Soccer Playground Object
     */
    SoccerPlayground::SoccerPlayground() {
        rectangles.resize(0);
        preview = cv::Mat(
            (FIELD_WIDTH + BORDER_STRIP_WIDTH * 2) * SCALE,
            (FIELD_LENGTH + BORDER_STRIP_WIDTH * 2) * SCALE,
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
     * @brief Initialize Playground Rectangles
     */
    void SoccerPlayground::initRectangles() {
        //-- Goal Area Left
        rectangles.push_back({
            cv::Point(
                BORDER_STRIP_WIDTH * SCALE,
                (BORDER_STRIP_WIDTH + (FIELD_WIDTH - GOAL_AREA_WIDTH) / 2) * SCALE
            ),
            cv::Point(
                (BORDER_STRIP_WIDTH + GOAL_AREA_LENGTH) * SCALE,
                (BORDER_STRIP_WIDTH + (FIELD_WIDTH + GOAL_AREA_WIDTH) / 2) * SCALE
            )
        });
        //-- Goal Area Right
        rectangles.push_back({
            cv::Point(
                (BORDER_STRIP_WIDTH + (FIELD_LENGTH - GOAL_AREA_LENGTH)) * SCALE,
                (BORDER_STRIP_WIDTH + (FIELD_WIDTH - GOAL_AREA_WIDTH) / 2) * SCALE
            ),
            cv::Point(
                (BORDER_STRIP_WIDTH + FIELD_LENGTH) * SCALE,
                (BORDER_STRIP_WIDTH + (FIELD_WIDTH + GOAL_AREA_WIDTH) / 2) * SCALE
            )
        });
        //-- Goal Left
        rectangles.push_back({
            cv::Point(
                BORDER_STRIP_WIDTH * SCALE,
                (BORDER_STRIP_WIDTH + (FIELD_WIDTH - GOAL_WIDTH) / 2) * SCALE
            ),
            cv::Point(
                (BORDER_STRIP_WIDTH - GOAL_DEPTH) * SCALE,
                (BORDER_STRIP_WIDTH + (FIELD_WIDTH + GOAL_WIDTH) / 2) * SCALE
            )
        });
        //-- Goal Right
        rectangles.push_back({
            cv::Point(
                (BORDER_STRIP_WIDTH + FIELD_LENGTH + GOAL_DEPTH) * SCALE,
                (BORDER_STRIP_WIDTH + (FIELD_WIDTH - GOAL_WIDTH) / 2) * SCALE
            ),
            cv::Point(
                (BORDER_STRIP_WIDTH + FIELD_LENGTH) * SCALE,
                (BORDER_STRIP_WIDTH + (FIELD_WIDTH + GOAL_WIDTH) / 2) * SCALE
            )
        });
        //-- Penalty Area Left
        rectangles.push_back({
            cv::Point(
                BORDER_STRIP_WIDTH * SCALE,
                (BORDER_STRIP_WIDTH + (FIELD_WIDTH - PENALTY_AREA_WIDTH) / 2) * SCALE
            ),
            cv::Point(
                (BORDER_STRIP_WIDTH + PENALTY_AREA_LENGTH) * SCALE,
                (BORDER_STRIP_WIDTH + (FIELD_WIDTH - PENALTY_AREA_WIDTH) / 2 + PENALTY_AREA_WIDTH) * SCALE
            )
        });
        //-- Penalty Area Right
        rectangles.push_back({
            cv::Point(
                (BORDER_STRIP_WIDTH + (FIELD_LENGTH - PENALTY_AREA_LENGTH)) * SCALE,
                (BORDER_STRIP_WIDTH + (FIELD_WIDTH - PENALTY_AREA_WIDTH) / 2) * SCALE
            ),
            cv::Point(
                (BORDER_STRIP_WIDTH + FIELD_LENGTH) * SCALE,
                (BORDER_STRIP_WIDTH + (FIELD_WIDTH - PENALTY_AREA_WIDTH) / 2 + PENALTY_AREA_WIDTH) * SCALE
            )
        });
        //-- Main Rectangle
        rectangles.push_back({
            cv::Point(
                BORDER_STRIP_WIDTH * SCALE,
                BORDER_STRIP_WIDTH * SCALE
            ),
            cv::Point(
                (BORDER_STRIP_WIDTH + FIELD_LENGTH) * SCALE,
                (BORDER_STRIP_WIDTH + FIELD_WIDTH) * SCALE
            )
        });
        isInitialized = true;
    }
    /**
     * @brief Method to Draw Playground (Alireza Mortezaei)
     */
    void SoccerPlayground::drawPlayground() {
        if (isInitialized == false) {
            initRectangles();
        }
        for (int i = 0; i < rectangles.size(); i++) {
            cv::rectangle(
                preview,
                rectangles[i].topLeft,
                rectangles[i].downRight,
                LINE_COLOR,
                LINE_THICKNESS,
                LINE_TYPE,
                LINE_SHIFT
            );
        }
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