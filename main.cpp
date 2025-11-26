#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>

#include "ComplexPlane.h"

using namespace sf;
using namespace std;

int main() {

    std::cout << "Program started" << std::endl;

    int desktopWidth  = VideoMode::getDesktopMode().width;
    int desktopHeight = VideoMode::getDesktopMode().height;

    RenderWindow window(VideoMode(desktopWidth, desktopHeight),"Mandelbrot");

    window.setFramerateLimit(60);

    ComplexPlane plane(desktopWidth, desktopHeight);

    Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cout << "Error loading font\n";
    }

    Text uiText;
    uiText.setFont(font);
    uiText.setCharacterSize(18);
    uiText.setFillColor(Color::White);

    // ============================
    // Main Loop
    // ============================
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            if (event.type == Event::MouseButtonPressed)
            {
                Vector2i pixel(event.mouseButton.x, event.mouseButton.y);

                if (event.mouseButton.button == Mouse::Left) {
                    plane.setCenter(pixel);
                    plane.zoomIn();
                }

                if (event.mouseButton.button == Mouse::Right) {
                    plane.setCenter(pixel);
                    plane.zoomOut();
                }
            }
            if (event.type == Event::MouseMoved)
            {
                plane.setMouseLocation(
                    Vector2i(event.mouseMove.x, event.mouseMove.y)
                );
            }
        }

        // Escape key closes app
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        // ============================
        // Update Scene
        // ============================
        plane.updateRender();
        plane.loadText(uiText);

        // ============================
        // Draw Scene
        // ============================
        window.clear(Color::Black);

        window.draw(plane);
        window.draw(uiText);

        window.display();
    }

    return 0;
}
