#include "sfmlrubikscube.h"

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <boost/math/constants/constants.hpp>
#include <SFML/Graphics/ConvexShape.hpp>

sfml_rubiks_cube::sfml_rubiks_cube()
  : m_rubiks_cube{},
    m_view{side::front} {

}

sf::ConvexShape create_shape(
  const sf::Vector2f& p1,
  const sf::Vector2f& p2,
  const sf::Vector2f& p3,
  const sf::Vector2f& p4,
  const color any_color
)
{
  sf::ConvexShape s;
  s.setPointCount(4);
  s.setPoint(0,p1);
  s.setPoint(1,p2);
  s.setPoint(2,p3);
  s.setPoint(3,p4);
  s.setFillColor(to_sfml_color(any_color));
  s.setOutlineThickness(1);
  s.setOutlineColor(sf::Color::Black);
  return s;
}

void sfml_rubiks_cube::draw(sf::RenderWindow& window) const noexcept {

/*

           +---+---+                                  +---+---+
           |0.0|0.1|                                  |       |
           |   |   |                                  |       |
           +---+---+                                  +  top  +
           |1.0|1.1|                                  |       |
           |   |   |                                  |       |
   +---+---+---+---+---+---+                  +---+---+---+---+---+---+
   |0.0|0.1|0.0|0.1|0.0|0.1|                  |       |       |       |
   |   |   |   |   |   |   |                  |       |       |       |
   +---+---+---+---+---+---+                  + left  + front + right +
   |1.0|1.1|1.0|1.1|1.0|1.1|                  |       |       |       |
   |   |   |   |   |   |   |                  |       |       |       |
   +---+---+---+---+---+---+                  +---+---+---+---+---+---+
           |0.0|0.1|                                  |       |
           |   |   |                                  |       |
           +---+---+                                  +bottom +
           |1.0|1.1|                                  |       |
           |   |   |                                  |       |
           +---+---+                                  +---+---+
           |0.0|0.1|                                  |       |
           |   |   |                                  |       |
           +---+---+                                  + back  +
           |1.0|1.1|                                  |       |
           |   |   |                                  |       |
           +---+---+                                  +---+---+

*/


  /*



  +     +----+----+
       / E  / F  /|
      /    /    / |
     +----+----+J +
    / G  / H  /| /|
   /    /    / |/ |
  +----+----+I +L +
  | A  | B  | /| /
  |    |    |/ |/
  +----+----+K +  /
  | C  | D  | /  /
  |    |    |/  / alpha
  +----+----+  +---------

*/

  assert(m_view == side::front);

  const double pi = boost::math::constants::pi<double>();
  const double alpha{pi / 3.0};
  const auto a = m_rubiks_cube.get_color(side::front,0,0);
  const auto b = m_rubiks_cube.get_color(side::front,0,1);
  const auto c = m_rubiks_cube.get_color(side::front,1,0);
  const auto d = m_rubiks_cube.get_color(side::front,1,1);

  const auto e = m_rubiks_cube.get_color(side::top,0,0);
  const auto f = m_rubiks_cube.get_color(side::top,0,1);
  const auto g = m_rubiks_cube.get_color(side::top,1,0);
  const auto h = m_rubiks_cube.get_color(side::top,1,1);

  const auto i = m_rubiks_cube.get_color(side::right,1,0);
  const auto j = m_rubiks_cube.get_color(side::right,0,0);
  const auto k = m_rubiks_cube.get_color(side::right,1,1);
  const auto l = m_rubiks_cube.get_color(side::right,0,1);

/*

  0     1----2----3
       /    /    /|
      /    /    / |
     4----5----6 17
    /    /    /| /|
   /    /    / |/ |
  7----8----9 16 19
  |    |    | /| /
  |    |    |/ |/
 10---11---12 18  /
  |    |    | /  /
  |    |    |/  / alpha
 13---14---15  +---------

  |====|
   scale

  */


  const double scale = 100.0;
  const double dx = std::cos(alpha)*scale;
  const double dy = std::sin(alpha)*scale;
  assert(dx >= 0.0);
  assert(dy >= 0.0);
  using coordinat = sf::Vector2f;
  const coordinat p_0(10.0,10.0);
  const coordinat p_7 {p_0  + coordinat(0.0      ,dy*2.0   )};
  const coordinat p_4 {p_7  + coordinat(dx       ,-dy      )};
  const coordinat p_1 {p_4  + coordinat(dx       ,-dy      )};
  const coordinat p_10{p_7  + coordinat(0.0      ,1.0*scale)};
  const coordinat p_13{p_10 + coordinat(0.0      ,1.0*scale)};
  const coordinat p_2 {p_1  + coordinat(1.0*scale,0.0      )};
  const coordinat p_3 {p_2  + coordinat(1.0*scale,0.0      )};
  const coordinat p_5 {p_4  + coordinat(1.0*scale,0.0      )};
  const coordinat p_6 {p_5  + coordinat(1.0*scale,0.0      )};
  const coordinat p_8 {p_7  + coordinat(1.0*scale,0.0      )};
  const coordinat p_9 {p_8  + coordinat(1.0*scale,0.0      )};
  const coordinat p_11{p_10 + coordinat(1.0*scale,0.0      )};
  const coordinat p_12{p_11 + coordinat(1.0*scale,0.0      )};
  const coordinat p_14{p_13 + coordinat(1.0*scale,0.0      )};
  const coordinat p_15{p_14 + coordinat(1.0*scale,0.0      )};
  const coordinat p_16{p_12 + coordinat(dx       ,-dy      )};
  const coordinat p_17{p_16 + coordinat(dx       ,-dy      )};
  const coordinat p_18{p_15 + coordinat(dx       ,-dy      )};
  const coordinat p_19{p_18 + coordinat(dx       ,-dy      )};

  const sf::ConvexShape s_a = create_shape(p_7 ,p_8 ,p_11,p_10,a);
  const sf::ConvexShape s_b = create_shape(p_8 ,p_9 ,p_12,p_11,b);
  const sf::ConvexShape s_c = create_shape(p_10,p_11,p_14,p_13,c);
  const sf::ConvexShape s_d = create_shape(p_11,p_12,p_15,p_14,d);

  const sf::ConvexShape s_e = create_shape(p_1 ,p_2 ,p_5 ,p_4 ,e);
  const sf::ConvexShape s_f = create_shape(p_2 ,p_3 ,p_6 ,p_5 ,f);
  const sf::ConvexShape s_g = create_shape(p_4 ,p_5 ,p_8 ,p_7 ,g);
  const sf::ConvexShape s_h = create_shape(p_5 ,p_6 ,p_9 ,p_8 ,h);

  const sf::ConvexShape s_i = create_shape(p_6 ,p_16,p_12,p_9 ,i);
  const sf::ConvexShape s_j = create_shape(p_3 ,p_17,p_16,p_6 ,j);
  const sf::ConvexShape s_k = create_shape(p_16,p_18,p_15,p_12,k);
  const sf::ConvexShape s_l = create_shape(p_17,p_19,p_18,p_16,l);

  window.draw(s_a);
  window.draw(s_b);
  window.draw(s_c);
  window.draw(s_d);
  window.draw(s_e);
  window.draw(s_f);
  window.draw(s_g);
  window.draw(s_h);
  window.draw(s_i);
  window.draw(s_j);
  window.draw(s_k);
  window.draw(s_l);

}

sf::Color to_sfml_color(const color any_color) noexcept
{
  switch (any_color) {
    case color::blue  : return sf::Color::Blue;
    case color::green : return sf::Color::Green;
    case color::orange: return sf::Color(255,128,0);
    case color::red   : return sf::Color::Red;
    case color::violet: return sf::Color(238,130,238);
    case color::yellow: return sf::Color::Yellow;
  }
  assert(!"Should not get here");
  throw std::logic_error("to_sfml_color: unknown color");
}
