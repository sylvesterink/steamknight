#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <string>

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
//#include <GL/gl.h>
//#include <GL/glu.h>

using std::string;

namespace ie_game
{
    /**
     * @brief Window object that handles the setup and rendering of sdl and
     *          opengl.
     */
    class GameWindow
    {
        public:
            GameWindow();
            ~GameWindow();

            bool initialize(int width, int height, int bitsPerPixel, bool isFullscreen,
                    const string& title);
            bool setSize(int width, int height);
            int getHeight();
            int getWidth();

        protected:
            bool initializeOpenGL();
            bool initializeSDL();

        private:
            int _width;
            int _height;
            int _bitsPerPixel;
            bool _isFullscreen;
            bool _isInitialized;
            string _title;
    };
};

#endif /* end of include guard: GAMEWINDOW_H */
