#include <iostream>
#include <cassert>
#include <string>

#include <SFML/Graphics.hpp>
#include "sfmlrubikscube.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 400), "Rubiks Cube");
  sfml_rubiks_cube cube;

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
    }

    window.clear();
    cube.draw(window);
    window.display();
  }
}
