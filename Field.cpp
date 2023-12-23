# ifndef MRL_SOCCER_PLAYGROUND
    # include "Field.hpp"
    /**
     * @brief Initialize Soccer Playground Object
     */
    SoccerPlayground::SoccerPlayground() {
        rectangles.resize(0);
        circles.resize(0);
        lines.resize(0);
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
            ),
            NOT_NECCESSARY
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
            ),
            NOT_NECCESSARY
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
            ),
            OPPONENT_GOAL_AREA
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
            ),
            TEAM_GOAL_AREA
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
            ),
            NOT_NECCESSARY
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
            ),
            NOT_NECCESSARY
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
            ),
            NOT_NECCESSARY
        });
        isInitialized += 1;
    }
    void SoccerPlayground::initCircles() {
        //-- Background Center Circle
        circles.push_back({
            cv::Point(
                (BORDER_STRIP_WIDTH + FIELD_LENGTH / 2) * SCALE,
                (BORDER_STRIP_WIDTH + FIELD_WIDTH / 2) * SCALE
            ),
            int(CENTER_CIRCLE_DIAMETER * SCALE / 2),
            BACKGROUND_CIRCLE
        });
        //-- Center Circle
        circles.push_back({
            cv::Point(
                (BORDER_STRIP_WIDTH + FIELD_LENGTH / 2) * SCALE,
                (BORDER_STRIP_WIDTH + FIELD_WIDTH / 2) * SCALE
            ),
            int(CENTER_CIRCLE_DIAMETER * SCALE / 2),
            NOT_NECCESSARY
        });
        //-- Center Point
        circles.push_back({
            cv::Point(
                (BORDER_STRIP_WIDTH + FIELD_LENGTH / 2) * SCALE,
                (BORDER_STRIP_WIDTH + FIELD_WIDTH / 2) * SCALE
            ),
            CIRCLE_RADIUS,
            NOT_NECCESSARY
        });
        //-- Penalty Mark Left
        circles.push_back({
            cv::Point(
                (BORDER_STRIP_WIDTH + PENALTY_MARK_DISTANCE) * SCALE,
                (BORDER_STRIP_WIDTH + FIELD_WIDTH / 2) * SCALE
            ),
            CIRCLE_RADIUS,
            NOT_NECCESSARY
        });
        //-- Penalty Mark Right
        circles.push_back({
            cv::Point(
                (BORDER_STRIP_WIDTH + FIELD_LENGTH - PENALTY_MARK_DISTANCE) * SCALE,
                (BORDER_STRIP_WIDTH + FIELD_WIDTH / 2) * SCALE
            ),
            CIRCLE_RADIUS,
            NOT_NECCESSARY
        });
        isInitialized += 1;
    }
    void SoccerPlayground::initLines() {
        //-- Half Line
        lines.push_back({
            cv::Point(
                (BORDER_STRIP_WIDTH + FIELD_LENGTH / 2) * SCALE,
                BORDER_STRIP_WIDTH * SCALE
            ),
            cv::Point(
                (BORDER_STRIP_WIDTH + FIELD_LENGTH / 2) * SCALE,
                (BORDER_STRIP_WIDTH + FIELD_WIDTH) * SCALE
            )
        });
    }
    /**
     * @brief Method to Draw Playground (Alireza Mortezaei)
     */
    void SoccerPlayground::drawPlayground() {
        initRectangles();
        initCircles();
        initLines();
        //-- Draw Rectangles
        for (int i = 0; i < rectangles.size(); i++) {
            cv::Scalar color = LINE_COLOR;
            if (rectangles[i].name_id == OPPONENT_GOAL_AREA) {
                color = OPPONENT_GOAL_AREA_COLOR;
            } else if (rectangles[i].name_id == TEAM_GOAL_AREA) {
                color = TEAM_GOAL_AREA_COLOR;
            } else {
                color = LINE_COLOR;
            }
            cv::rectangle(
                preview,
                rectangles[i].topLeft,
                rectangles[i].downRight,
                color,
                LINE_THICKNESS,
                LINE_TYPE,
                LINE_SHIFT
            );
        }
        //-- Draw Lines
        for (int i = 0; i < lines.size(); i++) {
            cv::line(
                preview,
                lines[i].start,
                lines[i].end,
                LINE_COLOR,
                LINE_THICKNESS,
                LINE_TYPE,
                LINE_SHIFT
            );
        }
        //-- Draw Circles
        for (int i = 0; i < circles.size(); i++) {
            int thickness = LINE_THICKNESS;
            if (circles[i].radius == CIRCLE_RADIUS) {
                thickness = cv::FILLED;
            }
            cv::Scalar color = LINE_COLOR;
            if (circles[i].name_id == BACKGROUND_CIRCLE) {
                thickness = cv::FILLED;
                color = BACKGROUND_COLOR;
            }
            cv::circle(
                preview,
                cv::Point(
                    circles[i].center.x,
                    circles[i].center.y
                ),
                circles[i].radius,
                color,
                thickness,
                LINE_TYPE,
                LINE_SHIFT
            );
        }
    }
# endif // MRL_SOCCER_PLAYGROUND
