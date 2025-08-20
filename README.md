# SDL Template Project

A C++ project template using SDL2, SDL2_image, and CMake for building.

## Features

- SDL2 for window management and rendering
- SDL2_image for image loading (PNG, JPG support)
- CMake build system
- Basic game loop structure
- Event handling (keyboard, window events)
- Resource management and cleanup

## Prerequisites

### Ubuntu/Debian
```bash
sudo apt update
sudo apt install build-essential cmake libsdl2-dev libsdl2-image-dev
```

### Arch Linux
```bash
sudo pacman -S base-devel cmake sdl2 sdl2_image
```

### Fedora
```bash
sudo dnf install gcc-c++ cmake SDL2-devel SDL2_image-devel
```

### macOS (using Homebrew)
```bash
brew install cmake sdl2 sdl2_image
```

### Windows
- Install Visual Studio with C++ support
- Install CMake
- Download SDL2 and SDL2_image development libraries
- Or use vcpkg: `vcpkg install sdl2 sdl2-image`

## Building the Project

### Using CMake (Recommended)

1. Create a build directory:
```bash
mkdir build
cd build
```

2. Configure the project:
```bash
cmake ..
```

3. Build the project:
```bash
make
```

4. Run the executable:
```bash
./SDLTemplate
```

### Alternative: Build from source directory
```bash
cmake -B build
cmake --build build
```

## Project Structure

```
SDLTemplate/
├── CMakeLists.txt      # CMake build configuration
├── include/            # Header files
│   └── Game.h         # Game class header
├── src/                # Source files
│   ├── main.cpp       # Main entry point
│   └── Game.cpp       # Game class implementation
├── res/                # Resources (images, sounds, etc.)
│   └── assets/        # Game assets
├── build/              # Build output (created by CMake)
├── build.sh            # Build script
├── .gitignore          # Git ignore file
└── README.md           # This file
```

## Controls

- **ESC**: Exit the game
- **Close Window**: Exit the game

## Customization

### Adding New Textures
1. Place your image files in the `res/assets/` directory
2. Modify `Game::loadTextures()` in `src/Game.cpp` to load your textures
3. Use `IMG_LoadTexture()` to load images

### Adding Game Objects
1. Create new classes for your game objects
2. Add them to the Game class
3. Update the `update()` and `render()` methods

### Modifying the Game Loop
The main game loop is in `Game::run()`. You can modify the frame rate, add timing, or implement more sophisticated loop control.

## Troubleshooting

### SDL2 not found
Make sure you have installed the development libraries:
- `libsdl2-dev` (Ubuntu/Debian)
- `sdl2` (Arch Linux)
- `SDL2-devel` (Fedora)

### SDL2_image not found
Install the SDL2_image development libraries:
- `libsdl2-image-dev` (Ubuntu/Debian)
- `sdl2_image` (Arch Linux)
- `SDL2_image-devel` (Fedora)

### Build errors
- Ensure you have a C++17 compatible compiler
- Check that all dependencies are properly installed
- Verify CMake version is 3.16 or higher

## License

This template is provided as-is for educational and development purposes.

## Contributing

Feel free to modify and extend this template for your own projects!

