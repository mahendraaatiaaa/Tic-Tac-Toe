#pragma once

#include <SFML/Graphics.hpp>

namespace blackstavern
{
    class InputManager
    {
        public :
            inputManager () {}
            ~InputManager () {}

        bool isSpriteClicked ( sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window ) ;
 
        sf::Vector2i GetMousePosition ( sf::RenderWindow &window ) ;
    };
}