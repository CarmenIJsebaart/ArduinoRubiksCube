#ifndef RUBIKSCUBE_H
#define RUBIKSCUBE_H
#include <iosfwd>
#include <string>
#include <vector>
#include "rubikscubecolor.h"
#include "rubikscubeside.h"
enum class rotation { clock_wise, counter_clock_wise };

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

class rubiks_cube
{
  public:
    rubiks_cube();

    void turn(const side any_side, rotation any_rotation) noexcept;

    // Read the color from a certain coordinate at a certain side
    color get_color(const side any_side, const int col, const int row) const;


  private:

    color m_array[6][2][2];
    color n_array[6][2][2];

    // Set a certain coordinate at a certain to a certain color
    void set_color(const side any_side, const int col, const int row, const color any_color);

    // Turn a side in a certain direction
    void turn_front (rotation any_rotation) noexcept;
    void turn_back  (rotation any_rotation) noexcept;
    void turn_left  (rotation any_rotation) noexcept;
    void turn_right (rotation any_rotation) noexcept;
    void turn_top   (rotation any_rotation) noexcept;
    void turn_bottom(rotation any_rotation) noexcept;

    friend bool operator== (const rubiks_cube& lhs, const rubiks_cube& rhs) noexcept;
};

std::ostream& operator<<(std::ostream &os, const rubiks_cube& any_rubiks_cube);
std::ostream& operator<<(std::ostream &os, const color any_color);
bool operator== (const rubiks_cube& lhs, const rubiks_cube& rhs) noexcept;
bool operator!= (const rubiks_cube& lhs, const rubiks_cube& rhs) noexcept;

std::vector<side> get_all_sides();

#endif // RUBIKSCUBE_H
