#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>

#include "ComplexPlane.h"

using namespace sf;
using namespace std;

int main() {

    int width, height;
    width = VideoMode::getDesktopMode().width / 2;
    height = VideoMode::getDesktopMode().height / 2;

    VideoMode vm(width, height);
    ComplexPlane cp(width, height);
    
    //FONT CREATION
    Font font;
	Text text;
	
    font.loadFromFile("Roboto-VariableFont_wdth,wght.ttf");
	text.setFont(font);
	text.setString("Select 3 points as the vertices of the triangle and a 4th as the starting point for the ChaosGame");
	text.setCharacterSize(35);
	text.setFillColor(Color(0, 0, 139));

    while (window.isOpen())

    {

    ///Input

        if (Keyboard::isKeyPressed(Keyboard::Escape))

        {

            window.close();

        }
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            std::cout << "the left button was pressed" << std::endl;
            std::cout << "mouse x: " << event.mouseButton.x << std::endl;
            std::cout << "mouse y: " << event.mouseButton.y << std::endl;
            cp.zoomOut();
            
        }
        if (event.mouseButton.button == sf::Mouse::Right)
        {
            std::cout << "the right button was pressed" << std::endl;
            std::cout << "mouse x: " << event.mouseButton.x << std::endl;
            std::cout << "mouse y: " << event.mouseButton.y << std::endl;
            cp.zoomIn();
            
        }

    ///Update




    ///Draw

    window.clear();

        //window.draw(...);

    window.display();

    }
}
