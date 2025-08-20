#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <memory>

class Game {
public:
    Game();
    ~Game();
    
    // Initialize SDL and create window/renderer
    bool init(const std::string& title, int width, int height);
    
    // Main game loop
    void run();
    
    // Clean up resources
    void cleanup();
    
    // Check if game is running
    bool isRunning() const { return m_running; }

private:
    // Handle events
    void handleEvents();
    
    // Update game state
    void update();
    
    // Render everything
    void render();
    
    // Load textures
    bool loadTextures();
    
    // Member variables
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    bool m_running;
    
    // Window dimensions
    int m_width;
    int m_height;
    
    // Example texture (you can add more)
    SDL_Texture* m_exampleTexture;
};

