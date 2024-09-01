#pragma once

class Viewport {
public:
    Viewport(int width, int height) : width(width), height(height) {}

    // Resizes the viewport to new dimensions
    void Resize(int newWidth, int newHeight) {
        if (newWidth > 0 && newHeight > 0) {  // Ensure positive dimensions
            width = newWidth;
            height = newHeight;
        }
    }

    // Getters for width and height
    int GetWidth() const { return width; }
    int GetHeight() const { return height; }

private:
    int width;
    int height;
};
