#ifndef SFMLRUBIKSCUBE_H
#define SFMLRUBIKSCUBE_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "rubikscube.h"
#include "rubikscubeside.h"
#include "rubikscubecolor.h"

class sfml_rubiks_cube
{
public:
  sfml_rubiks_cube();


  void draw(sf::RenderWindow& window) const noexcept;

  void turn(const side any_side, rotation any_rotation) noexcept;

private:
  rubiks_cube m_rubiks_cube;
  side m_view;
};


sf::Color to_sfml_color(const color any_color) noexcept;

#endif // SFMLRUBIKSCUBE_H
