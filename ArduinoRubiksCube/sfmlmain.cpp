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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) { cube.turn(side::front,rotation::clock_wise); }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) { cube.turn(side::back,rotation::clock_wise); }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) { cube.turn(side::left,rotation::clock_wise); }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) { cube.turn(side::right,rotation::clock_wise); }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) { cube.turn(side::top,rotation::clock_wise); }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) { cube.turn(side::bottom,rotation::clock_wise); }

    window.clear();
    cube.draw(window);
    window.display();
    sf::Clock clock;
    while (clock.getElapsedTime().asMilliseconds() < 50.0) {}
  }

}
