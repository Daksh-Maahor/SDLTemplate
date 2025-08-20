#include "Game.h"
#include <iostream>

Game::Game() 
    : m_window(nullptr)
    , m_renderer(nullptr)
    , m_running(false)
    , m_width(800)
    , m_height(600)
    , m_exampleTexture(nullptr)
{
}

Game::~Game() {
    cleanup();
}

bool Game::init(const std::string& title, int width, int height) {
    m_width = width;
    m_height = height;
    
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }
    
    // Initialize SDL_image
    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        std::cerr << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        return false;
    }
    
    // Create window
    m_window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        m_width,
        m_height,
        SDL_WINDOW_SHOWN
    );
    
    if (!m_window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }
    
    // Create renderer
    m_renderer = SDL_CreateRenderer(
        m_window,
        -1,
        SDL_RENDERER_ACCELERATED
    );
    
    if (!m_renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }
    
    // Set renderer color
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    
    // Load textures
    if (!loadTextures()) {
        std::cerr << "Failed to load textures!" << std::endl;
        return false;
    }
    
    m_running = true;
    std::cout << "Game initialized successfully!" << std::endl;
    return true;
}

void Game::run() {
    while (m_running) {
        handleEvents();
        update();
        render();
        
        // Cap frame rate to ~60 FPS
        SDL_Delay(16);
    }
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                m_running = false;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    m_running = false;
                }
                break;
        }
    }
}

void Game::update() {
    // Update game logic here
    // This is where you would update positions, check collisions, etc.
}

void Game::render() {
    // Clear screen
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);
    
    // Render game objects here
    // Example: render a simple rectangle
    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_Rect rect = {m_width/2 - 25, m_height/2 - 25, 50, 50};
    SDL_RenderFillRect(m_renderer, &rect);
    
    // Present render
    SDL_RenderPresent(m_renderer);
}

bool Game::loadTextures() {
    // Load textures here
    // Example: m_exampleTexture = IMG_LoadTexture(m_renderer, "res/assets/example.png");
    // Note: The res/ directory is copied to the build directory during CMake configuration
    // So you can reference textures as "res/assets/filename.png" at runtime
    
    // For now, we'll just return true since we're not loading any textures yet
    return true;
}

void Game::cleanup() {
    if (m_exampleTexture) {
        SDL_DestroyTexture(m_exampleTexture);
        m_exampleTexture = nullptr;
    }
    
    if (m_renderer) {
        SDL_DestroyRenderer(m_renderer);
        m_renderer = nullptr;
    }
    
    if (m_window) {
        SDL_DestroyWindow(m_window);
        m_window = nullptr;
    }
    
    IMG_Quit();
    SDL_Quit();
    
    std::cout << "Game cleaned up!" << std::endl;
}

