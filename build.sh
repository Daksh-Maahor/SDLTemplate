#!/bin/bash

# SDL Template Build Script

echo "Building SDL Template..."

# Create build directory if it doesn't exist
mkdir -p build

# Navigate to build directory
cd build

# Configure with CMake
echo "Configuring with CMake..."
cmake ..

# Check if configuration was successful
if [ $? -eq 0 ]; then
    echo "Configuration successful! Building..."
    
    # Build the project
    make
    
    # Check if build was successful
    if [ $? -eq 0 ]; then
        echo "Build successful!"
        echo "Executable location: build/SDLTemplate"
        echo "Resources copied to: build/res/"
        echo ""
        echo "You can now run the program with: ./SoundWSDLTemplateave3DGame"
    else
        echo "Build failed!"
        exit 1
    fi
else
    echo "Configuration failed!"
    exit 1
fi

