#ifndef CORE_H
#define CORE_H

//Using SDL, SDL OpenGL, GLEW, standard IO, and strings
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <string>

class Core
{
    public:
        Core();
        virtual ~Core();

        //Screen dimension constants
        const int SCREEN_WIDTH = 640;
        const int SCREEN_HEIGHT = 480;

        //The window we'll be rendering to
        SDL_Window* gWindow = NULL;

        //OpenGL context
        SDL_GLContext gContext;

        //Render flag
        bool gRenderQuad = true;

        //Graphics program
        GLuint gProgramID = 0;
        GLint gVertexPos2DLocation = -1;
        GLuint gVBO = 0;
        GLuint gIBO = 0;

        //Starts up SDL, creates window, and initializes OpenGL
        bool init();

        //Initializes rendering program and clear color
        bool initGL();

        // Handles main loop.
        int loop();

        //Input handler
        void handleKeys( unsigned char key, int x, int y );

        //Per frame update
        void update();

        //Renders quad to the screen
        void render();

        //Frees media and shuts down SDL
        void close();

        //Shader loading utility programs
        void printProgramLog( GLuint program );
        void printShaderLog( GLuint shader );

    protected:
    private:
};

#endif // CORE_H
