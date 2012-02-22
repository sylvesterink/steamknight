#include "GWindow.h"

namespace ie_game
{
    /**
     * @brief Initialize default window object properties
     */
    GWindow::GWindow():
        _width(0),
        _height(0),
        _bitsPerPixel(0),
        _isFullscreen(false),
        _isInitialized(false),
        _title("")
    {

    }

    /**
     * @brief Object destructor
     */
    GWindow::~GWindow()
    {
    }

    /**
     * @brief Initialize the window and set default settings
     * @param width Pixel width of the window
     * @param height Pixel height of the window
     * @param bitsPerPixel Bit depth per pixel
     * @param isFullscreen Whether to render as a window or fullscreen
     * @param title The title of the window
     * @return True if initialization was successful, false if it failed
     */
    bool GWindow::initialize(int width, int height, int bitsPerPixel,
            bool isFullscreen, const string& title)
    {
        // Store window values
        _height = height;
        _width = width;
        _title = title;
        _isFullscreen = isFullscreen;
        _bitsPerPixel = bitsPerPixel;

        // Check for valid input
        if (_width <= 0) {
            _width = 1;
        }
        if (_height <= 0) {
            _height = 1;
        }
        if (_bitsPerPixel <= 0) {
            _bitsPerPixel = 8;
        }

        // Initialize SDL and OpenGL
        if (initializeSDL() == false) {
            return false;
        }

        if (initializeOpenGL() == false) {
            return false;
        }

        // SDL doesn't trigger off a ResizeEvent at startup, but this needs to
        // be done for OpenGL
        SDL_Event resizeEvent;
        resizeEvent.type = SDL_VIDEORESIZE;
        resizeEvent.resize.w = width;
        resizeEvent.resize.h = height;

        SDL_PushEvent(&resizeEvent);

        return true;
    }

    /**
     * @brief Initialize OpenGL attributes
     * @return Whether initialization was successful or not
     */
    //TODO: Check for opengl errors before returning
    bool GWindow::initializeOpenGL()
    {
        // Set up OpenGL attributes
        // All values are "at least"!
        // TODO: Set attributes with relation to how window is set up,
        //      for example, bits per pixel etc.
        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 5);

        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_SWAP_CONTROL, 1); //vsync

        // Unused settings at the moment
        //SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,    8);
        //SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE,    8);
        //SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE,    8);
        //SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE,    8);

        // Anti-aliasing settings
        //SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,  1);   //Enable AA
        //SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,  2);   //How much AA

        return true;
    }

    /**
     * @brief Initialize SDL attributes
     * @return Whether initialization was successful or not
     */
    bool GWindow::initializeSDL()
    {
        // Set the title.
        SDL_WM_SetCaption(_title.c_str(), _title.c_str());

        // Flags tell SDL about the type of window we are creating.
        int flags = SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL;

        if (_isFullscreen) {
            flags |= SDL_FULLSCREEN;
        }

        // TODO: Might be necessary to store surface that setvideo returns
        if (SDL_SetVideoMode( _width, _height, _bitsPerPixel, flags ) == NULL) {
            return false;
        }

        return true;
    }

    /**
     * @brief Set the new size of the window
     * @param width New window width
     * @param height New window height
     * @return Whether the resize was successful
     */
    //TODO: Make window process resize and re-initialize
    //      Also, this may not change resolution either
    bool GWindow::setSize(int width, int height)
    {
        if (!_isInitialized) {
            return false;
        }

        _height = height;
        _width = width;

        return true;
    }

    /**
     * @brief Get the width of the window
     * @return Window width
     */
    int GWindow::getWidth()
    {
        return _width;
    }

    /**
     * @brief Get the height of the window
     * @return Window height
     */
    int GWindow::getHeight()
    {
        return _height;
    }
}
