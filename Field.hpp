# ifndef MRL_SOCCER_PLAYGROUND_CONFIGS
    # include "Configs.hpp"
    # ifndef MRL_SOCCER_PLAYGROUND
        /**
         * @file Field.hpp
         * @author Mobina Abforoosh (mobinaabf@gmail.com)
         * @author Amir Yusefian (amiryn996@gmail.com)
         * @author Erfan Zarabadi (mohammadspace39@gmail.com)
         * @author Parsa Karbasi (ijackgonjishke@gmail.com)
         * @author Alireza Mortezaei (alirezamortezaei50@gmail.com)
         * @author Ramtin Kosari (ramtinkosari@gmail.com)
         * @brief MRL HSL Soccer Filed Preview with OpenCV
         * @version 1.0
         * @date 2023-12-22
         */
        # define MRL_SOCCER_PLAYGROUND
    # endif // MRL_SOCCER_PLAYGROUND
    struct SoccerRectangle {
        cv::Point topLeft;
        cv::Point downRight;
    };
    /**
     * @brief MRL HSL Soccer Playground Class
     * @details This class is used to create a soccer playground with OpenCV
     */
    class SoccerPlayground {
        private:
            /**
             * @brief Playground Image
             */
            cv::Mat preview;
            /**
             * @brief Playground Rectangles
             */
            std::vector<SoccerRectangle> rectangles;
        public:
            /**
             * @brief Initialize Soccer Playground Object
             */
            SoccerPlayground();
            /**
             * @brief Method to Get Playground Image
             * @return cv::Mat
             */
            cv::Mat getPlayground();
            /**
             * @brief Method to Draw Playground (Alireza Mortezaei)
             */
            void drawPlayground();
    };
# endif // MRL_SOCCER_PLAYGROUND_CONFIGS