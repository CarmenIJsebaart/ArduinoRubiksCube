#include "rubikscube.h"

#include <cassert>
#include <iostream>


rubiks_cube::rubiks_cube()
  : m_array
    {
      //Front
      {
        { color::red, color::red},
        { color::red, color::red}
      },
      //Back
      {
        { color::yellow, color::yellow},
        { color::yellow, color::yellow}
      },
      //Left
      {
        { color::green, color::green},
        { color::green, color::green}
      },
      //Right
      {
        { color::orange, color::orange},
        { color::orange, color::orange}
      },
      //Top
      {
        { color::blue, color::blue},
        { color::blue, color::blue}
      },
      //Bottom
      {
        { color::violet, color::violet},
        { color::violet, color::violet}
      }
    }
{
}

void rubiks_cube::set_color(const side any_side, const int col, const int row, const color color)
{
  assert(col >= 0);
  assert(col <= 1);
  assert(row >= 0);
  assert(row <= 1);
  int side_index = 0;
  switch (any_side)
  {
    case side::front : side_index = 0; break;
    case side::back  : side_index = 1; break;
    case side::left  : side_index = 2; break;
    case side::right : side_index = 3; break;
    case side::top   : side_index = 4; break;
    case side::bottom: side_index = 5; break;
  }
  assert(side_index >= 0);
  assert(side_index  < 6);
  m_array[side_index][col][row] = color;
}

color rubiks_cube::get_color(const side any_side, const int col, const int row) const
{
  assert(col >= 0);
  assert(col <= 1);
  assert(row >= 0);
  assert(row <= 1);
  int side_index = 0;
  switch (any_side)
  {
    case side::front : side_index = 0; break;
    case side::back  : side_index = 1; break;
    case side::left  : side_index = 2; break;
    case side::right : side_index = 3; break;
    case side::top   : side_index = 4; break;
    case side::bottom: side_index = 5; break;
  }
  assert(side_index >= 0);
  assert(side_index  < 6);
  return m_array[side_index][col][row];
}

void rubiks_cube::turn(const side any_side, rotation any_rotation) noexcept
{
  switch (any_side)
  {
    case side::back  : turn_back(any_rotation  ); break;
    case side::bottom: turn_bottom(any_rotation); break;
    case side::front : turn_front(any_rotation ); break;
    case side::left  : turn_left(any_rotation  ); break;
    case side::right : turn_right(any_rotation ); break;
    case side::top   : turn_top(any_rotation   ); break;
  }
}

void rubiks_cube::turn_front(rotation any_rotation) noexcept
{
  if(any_rotation == rotation::clock_wise)
  {
    assert(any_rotation == rotation::clock_wise); //TODO: support both ways
    //Clock-wise rotation
    //Collect colors
    //Begin at front:
    const color front_squares[4] =
    {
      get_color(side::front,0,0), //[0]
      get_color(side::front,0,1), //[1]
      get_color(side::front,1,0), //[2]
      get_color(side::front,1,1)  //[3]
    };
    // 0,0 gets the color of [?]
    set_color(side::front,0,0,front_squares[2]);
    set_color(side::front,0,1,front_squares[0]);
    set_color(side::front,1,0,front_squares[3]);
    set_color(side::front,1,1,front_squares[1]);

    //Do side
    const color side_squares[8] =
    {
      get_color(side::top   ,1,0), //[0]
      get_color(side::top   ,1,1), //[1]
      get_color(side::right ,0,0), //[2]
      get_color(side::right ,1,0), //[3]
      get_color(side::bottom,0,1), //[4]
      get_color(side::bottom,0,0), //[5]
      get_color(side::left  ,1,1), //[6]
      get_color(side::left  ,0,1)  //[7]
    };
    set_color(side::top,   1,0,side_squares[6]);
    set_color(side::top,   1,1,side_squares[7]);
    set_color(side::right, 0,0,side_squares[0]);
    set_color(side::right, 1,0,side_squares[1]);
    set_color(side::bottom,0,1,side_squares[2]);
    set_color(side::bottom,0,0,side_squares[3]);
    set_color(side::left,  1,1,side_squares[4]);
    set_color(side::left,  0,1,side_squares[5]);
  }
  else
  {
    //Counter clock-wise rotation
    //Collect colors
    //Begin at front:
    const color front_squares[4] =
    {
      get_color(side::front,0,0), //[0]
      get_color(side::front,0,1), //[1]
      get_color(side::front,1,0), //[2]
      get_color(side::front,1,1)  //[3]
    };
    // 0,0 gets the color of [?]
    set_color(side::front,0,0,front_squares[1]);
    set_color(side::front,0,1,front_squares[3]);
    set_color(side::front,1,0,front_squares[0]);
    set_color(side::front,1,1,front_squares[2]);

    //Do side
    const color side_squares[8] =
    {
      get_color(side::top   ,1,0), //[0]
      get_color(side::top   ,1,1), //[1]
      get_color(side::right ,0,0), //[2]
      get_color(side::right ,1,0), //[3]
      get_color(side::bottom,0,1), //[4]
      get_color(side::bottom,0,0), //[5]
      get_color(side::left  ,1,1), //[6]
      get_color(side::left  ,0,1)  //[7]
    };
    set_color(side::top,   1,0,side_squares[2]);
    set_color(side::top,   1,1,side_squares[3]);
    set_color(side::right, 0,0,side_squares[4]);
    set_color(side::right, 1,0,side_squares[5]);
    set_color(side::bottom,0,1,side_squares[6]);
    set_color(side::bottom,0,0,side_squares[7]);
    set_color(side::left,  1,1,side_squares[0]);
    set_color(side::left,  0,1,side_squares[1]);
  }
}

void rubiks_cube::turn_back(rotation any_rotation) noexcept
{
  if(any_rotation == rotation::clock_wise)
  {
    assert(any_rotation == rotation::clock_wise); //TODO: support both ways
    //Clock-wise rotation
    //Collect colors
    //Begin at front (in this case the back side is the front):
    const color front_squares[4] =
    {
      get_color(side::back,0,0), //[0]
      get_color(side::back,0,1), //[1]
      get_color(side::back,1,0), //[2]
      get_color(side::back,1,1)  //[3]
    };
    // 0,0 gets the color of [?]
    set_color(side::back,0,0,front_squares[2]);
    set_color(side::back,0,1,front_squares[0]);
    set_color(side::back,1,0,front_squares[3]);
    set_color(side::back,1,1,front_squares[1]);

    //Do side
    const color side_squares[8] =
    {
      get_color(side::bottom,1,0), //[0]
      get_color(side::bottom,1,1), //[1]
      get_color(side::right ,1,1), //[2]
      get_color(side::right ,0,1), //[3]
      get_color(side::top   ,0,1), //[4]
      get_color(side::top   ,0,0), //[5]
      get_color(side::left  ,0,0), //[6]
      get_color(side::left  ,1,0)  //[7]
    };
    set_color(side::bottom,1,0,side_squares[6]);
    set_color(side::bottom,1,1,side_squares[7]);
    set_color(side::right ,1,1,side_squares[0]);
    set_color(side::right ,0,1,side_squares[1]);
    set_color(side::top   ,0,1,side_squares[2]);
    set_color(side::top   ,0,0,side_squares[3]);
    set_color(side::left  ,0,0,side_squares[4]);
    set_color(side::left  ,1,0,side_squares[5]);
  }
  else
  {
    //Counter clock-wise rotation
    //Collect colors
    //Begin at front (in this case the back side is the front):
    const color front_squares[4] =
    {
      get_color(side::back,0,0), //[0]
      get_color(side::back,0,1), //[1]
      get_color(side::back,1,0), //[2]
      get_color(side::back,1,1)  //[3]
    };
    // 0,0 gets the color of [?]
    set_color(side::back,0,0,front_squares[1]);
    set_color(side::back,0,1,front_squares[3]);
    set_color(side::back,1,0,front_squares[0]);
    set_color(side::back,1,1,front_squares[2]);

    //Do side
    const color side_squares[8] =
    {
      get_color(side::bottom,1,0), //[0]
      get_color(side::bottom,1,1), //[1]
      get_color(side::right ,1,1), //[2]
      get_color(side::right ,0,1), //[3]
      get_color(side::top   ,0,1), //[4]
      get_color(side::top   ,0,0), //[5]
      get_color(side::left  ,0,0), //[6]
      get_color(side::left  ,1,0)  //[7]
    };
    set_color(side::bottom,1,0,side_squares[2]);
    set_color(side::bottom,1,1,side_squares[3]);
    set_color(side::right ,1,1,side_squares[4]);
    set_color(side::right ,0,1,side_squares[5]);
    set_color(side::top   ,0,1,side_squares[6]);
    set_color(side::top   ,0,0,side_squares[7]);
    set_color(side::left  ,0,0,side_squares[0]);
    set_color(side::left  ,1,0,side_squares[1]);
  }
}

void rubiks_cube::turn_left(rotation any_rotation) noexcept
{
  if(any_rotation == rotation::clock_wise)
  {
    assert(any_rotation == rotation::clock_wise); //TODO: support both ways
    //Clock-wise rotation
    //Collect colors
    //Begin at front (in this case the left side is the front):
    const color front_squares[4] =
    {
      get_color(side::left,0,0), //[0]
      get_color(side::left,0,1), //[1]
      get_color(side::left,1,0), //[2]
      get_color(side::left,1,1)  //[3]
    };
    // 0,0 gets the color of [?]
    set_color(side::left,0,0,front_squares[2]);
    set_color(side::left,0,1,front_squares[0]);
    set_color(side::left,1,0,front_squares[3]);
    set_color(side::left,1,1,front_squares[1]);

    //Do side
    const color side_squares[8] =
    {
      get_color(side::top   ,1,0), //[0]
      get_color(side::top   ,1,1), //[1]
      get_color(side::front ,0,0), //[2]
      get_color(side::front ,1,0), //[3]
      get_color(side::bottom,0,0), //[4]
      get_color(side::bottom,1,0), //[5]
      get_color(side::back  ,0,0), //[6]
      get_color(side::back  ,1,0)  //[7]
    };
    set_color(side::top   ,1,0,side_squares[6]);
    set_color(side::top   ,1,1,side_squares[7]);
    set_color(side::front ,0,0,side_squares[0]);
    set_color(side::front ,1,0,side_squares[1]);
    set_color(side::bottom,0,0,side_squares[2]);
    set_color(side::bottom,1,0,side_squares[3]);
    set_color(side::back  ,0,0,side_squares[4]);
    set_color(side::back  ,1,0,side_squares[5]);
  }
  else
  {
    //Counter clock-wise rotation
    //Collect colors
    //Begin at front (in this case the left side is the front):
    const color front_squares[4] =
    {
      get_color(side::left,0,0), //[0]
      get_color(side::left,0,1), //[1]
      get_color(side::left,1,0), //[2]
      get_color(side::left,1,1)  //[3]
    };
    // 0,0 gets the color of [?]
    set_color(side::left,0,0,front_squares[1]);
    set_color(side::left,0,1,front_squares[3]);
    set_color(side::left,1,0,front_squares[0]);
    set_color(side::left,1,1,front_squares[2]);

    //Do side
    const color side_squares[8] =
    {
      get_color(side::top   ,1,0), //[0]
      get_color(side::top   ,1,1), //[1]
      get_color(side::front ,0,0), //[2]
      get_color(side::front ,1,0), //[3]
      get_color(side::bottom,0,0), //[4]
      get_color(side::bottom,1,0), //[5]
      get_color(side::back  ,0,0), //[6]
      get_color(side::back  ,1,0)  //[7]
    };
    set_color(side::top   ,1,0,side_squares[2]);
    set_color(side::top   ,1,1,side_squares[3]);
    set_color(side::front ,0,0,side_squares[4]);
    set_color(side::front ,1,0,side_squares[5]);
    set_color(side::bottom,0,0,side_squares[6]);
    set_color(side::bottom,1,0,side_squares[7]);
    set_color(side::back  ,0,0,side_squares[0]);
    set_color(side::back  ,1,0,side_squares[1]);
  }
}

void rubiks_cube::turn_right(rotation any_rotation) noexcept
{
  if(any_rotation == rotation::clock_wise)
  {
    assert(any_rotation == rotation::clock_wise); //TODO: support both ways
    //Clock-wise rotation
    //Collect colors
    //Begin at front (in this case the right side is the front):
    const color front_squares[4] =
    {
      get_color(side::right,0,0), //[0]
      get_color(side::right,0,1), //[1]
      get_color(side::right,1,0), //[2]
      get_color(side::right,1,1)  //[3]
    };
    // 0,0 gets the color of [?]
    set_color(side::right,0,0,front_squares[2]);
    set_color(side::right,0,1,front_squares[0]);
    set_color(side::right,1,0,front_squares[3]);
    set_color(side::right,1,1,front_squares[1]);

    //Do side
    const color side_squares[8] =
    {
      get_color(side::top   ,1,1), //[0]
      get_color(side::top   ,0,1), //[1]
      get_color(side::back  ,1,1), //[2]
      get_color(side::back  ,0,1), //[3]
      get_color(side::bottom,1,1), //[4]
      get_color(side::bottom,0,1), //[5]
      get_color(side::front ,1,1), //[6]
      get_color(side::front ,0,1)  //[7]
    };
    set_color(side::top   ,1,1,side_squares[6]);
    set_color(side::top   ,0,1,side_squares[7]);
    set_color(side::back  ,1,1,side_squares[0]);
    set_color(side::back  ,0,1,side_squares[1]);
    set_color(side::bottom,1,1,side_squares[2]);
    set_color(side::bottom,0,1,side_squares[3]);
    set_color(side::front ,1,1,side_squares[4]);
    set_color(side::front ,0,1,side_squares[5]);
  }
  else
  {
    //Counter clock-wise rotation
    //Collect colors
    //Begin at front (in this case the right side is the front):
    const color front_squares[4] =
    {
      get_color(side::right,0,0), //[0]
      get_color(side::right,0,1), //[1]
      get_color(side::right,1,0), //[2]
      get_color(side::right,1,1)  //[3]
    };
    // 0,0 gets the color of [?]
    set_color(side::right,0,0,front_squares[1]);
    set_color(side::right,0,1,front_squares[3]);
    set_color(side::right,1,0,front_squares[0]);
    set_color(side::right,1,1,front_squares[2]);

    //Do side
    const color side_squares[8] =
    {
      get_color(side::top   ,1,1), //[0]
      get_color(side::top   ,0,1), //[1]
      get_color(side::back  ,1,1), //[2]
      get_color(side::back  ,0,1), //[3]
      get_color(side::bottom,1,1), //[4]
      get_color(side::bottom,0,1), //[5]
      get_color(side::front ,1,1), //[6]
      get_color(side::front ,0,1)  //[7]
    };
    set_color(side::top   ,1,1,side_squares[2]);
    set_color(side::top   ,0,1,side_squares[3]);
    set_color(side::back  ,1,1,side_squares[4]);
    set_color(side::back  ,0,1,side_squares[5]);
    set_color(side::bottom,1,1,side_squares[6]);
    set_color(side::bottom,0,1,side_squares[7]);
    set_color(side::front ,1,1,side_squares[0]);
    set_color(side::front ,0,1,side_squares[1]);
  }
}

void rubiks_cube::turn_top(rotation any_rotation) noexcept
{
  if(any_rotation == rotation::clock_wise)
  {
    assert(any_rotation == rotation::clock_wise); //TODO: support both ways
    //Clock-wise rotation
    //Collect colors
    //Begin at front (in this case the top side is the front):
    const color front_squares[4] =
    {
      get_color(side::top,0,0), //[0]
      get_color(side::top,0,1), //[1]
      get_color(side::top,1,0), //[2]
      get_color(side::top,1,1)  //[3]
    };
    // 0,0 gets the color of [?]
    set_color(side::top,0,0,front_squares[2]);
    set_color(side::top,0,1,front_squares[0]);
    set_color(side::top,1,0,front_squares[3]);
    set_color(side::top,1,1,front_squares[1]);

    //Do side
    const color side_squares[8] =
    {
      get_color(side::back ,1,0), //[0]
      get_color(side::back ,1,1), //[1]
      get_color(side::right,0,1), //[2]
      get_color(side::right,0,0), //[3]
      get_color(side::front,0,1), //[4]
      get_color(side::front,0,0), //[5]
      get_color(side::left ,0,1), //[6]
      get_color(side::left ,0,0)  //[7]
    };
    set_color(side::back ,1,0,side_squares[6]);
    set_color(side::back ,1,1,side_squares[7]);
    set_color(side::right,0,1,side_squares[0]);
    set_color(side::right,0,0,side_squares[1]);
    set_color(side::front,0,1,side_squares[2]);
    set_color(side::front,0,0,side_squares[3]);
    set_color(side::left ,0,1,side_squares[4]);
    set_color(side::left ,0,0,side_squares[5]);
  }
  else
  {
    //Counter clock-wise rotation
    //Collect colors
    //Begin at front (in this case the top side is the front):
    const color front_squares[4] =
    {
      get_color(side::top,0,0), //[0]
      get_color(side::top,0,1), //[1]
      get_color(side::top,1,0), //[2]
      get_color(side::top,1,1)  //[3]
    };
    // 0,0 gets the color of [?]
    set_color(side::top,0,0,front_squares[1]);
    set_color(side::top,0,1,front_squares[3]);
    set_color(side::top,1,0,front_squares[0]);
    set_color(side::top,1,1,front_squares[2]);

    //Do side
    const color side_squares[8] =
    {
      get_color(side::back ,1,0), //[0]
      get_color(side::back ,1,1), //[1]
      get_color(side::right,0,1), //[2]
      get_color(side::right,0,0), //[3]
      get_color(side::front,0,1), //[4]
      get_color(side::front,0,0), //[5]
      get_color(side::left ,0,1), //[6]
      get_color(side::left ,0,0)  //[7]
    };
    set_color(side::back ,1,0,side_squares[2]);
    set_color(side::back ,1,1,side_squares[3]);
    set_color(side::right,0,1,side_squares[4]);
    set_color(side::right,0,0,side_squares[5]);
    set_color(side::front,0,1,side_squares[6]);
    set_color(side::front,0,0,side_squares[7]);
    set_color(side::left ,0,1,side_squares[0]);
    set_color(side::left ,0,0,side_squares[1]);
  }
}

void rubiks_cube::turn_bottom(rotation any_rotation) noexcept
{
  if(any_rotation == rotation::clock_wise)
  {
    assert(any_rotation == rotation::clock_wise); //TODO: support both ways
    //Clock-wise rotation
    //Collect colors
    //Begin at front (in this case the bottom side is the front):
    const color front_squares[4] =
    {
      get_color(side::bottom,0,0), //[0]
      get_color(side::bottom,0,1), //[1]
      get_color(side::bottom,1,0), //[2]
      get_color(side::bottom,1,1)  //[3]
    };
    // 0,0 gets the color of [?]
    set_color(side::bottom,0,0,front_squares[2]);
    set_color(side::bottom,0,1,front_squares[0]);
    set_color(side::bottom,1,0,front_squares[3]);
    set_color(side::bottom,1,1,front_squares[1]);

    //Do side
    const color side_squares[8] =
    {
      get_color(side::front,1,0), //[0]
      get_color(side::front,1,1), //[1]
      get_color(side::right,1,0), //[2]
      get_color(side::right,1,1), //[3]
      get_color(side::back ,0,1), //[4]
      get_color(side::back ,0,0), //[5]
      get_color(side::left ,1,0), //[6]
      get_color(side::left ,1,1)  //[7]
    };
    set_color(side::front,1,0,side_squares[6]);
    set_color(side::front,1,1,side_squares[7]);
    set_color(side::right,1,0,side_squares[0]);
    set_color(side::right,1,1,side_squares[1]);
    set_color(side::back ,0,1,side_squares[2]);
    set_color(side::back ,0,0,side_squares[3]);
    set_color(side::left ,1,0,side_squares[4]);
    set_color(side::left ,1,1,side_squares[5]);
  }
  else
  {
    //Counter clock-wise rotation
    //Collect colors
    //Begin at front (in this case the bottom side is the front):
    const color front_squares[4] =
    {
      get_color(side::bottom,0,0), //[0]
      get_color(side::bottom,0,1), //[1]
      get_color(side::bottom,1,0), //[2]
      get_color(side::bottom,1,1)  //[3]
    };
    // 0,0 gets the color of [?]
    set_color(side::bottom,0,0,front_squares[1]);
    set_color(side::bottom,0,1,front_squares[3]);
    set_color(side::bottom,1,0,front_squares[0]);
    set_color(side::bottom,1,1,front_squares[2]);

    //Do side
    const color side_squares[8] =
    {
      get_color(side::front,1,0), //[0]
      get_color(side::front,1,1), //[1]
      get_color(side::right,1,0), //[2]
      get_color(side::right,1,1), //[3]
      get_color(side::back ,0,1), //[4]
      get_color(side::back ,0,0), //[5]
      get_color(side::left ,1,0), //[6]
      get_color(side::left ,1,1)  //[7]
    };
    set_color(side::front,1,0,side_squares[2]);
    set_color(side::front,1,1,side_squares[3]);
    set_color(side::right,1,0,side_squares[4]);
    set_color(side::right,1,1,side_squares[5]);
    set_color(side::back ,0,1,side_squares[6]);
    set_color(side::back ,0,0,side_squares[7]);
    set_color(side::left ,1,0,side_squares[0]);
    set_color(side::left ,1,1,side_squares[1]);
  }
}

std::ostream& operator<<(std::ostream& os, const rubiks_cube& cube)
{
  for (const side s: get_all_sides())
  {
    for (const int row: {0,1} )
    {
      for (const int col: {0,1} )
      {
        os << cube.get_color(s,col,row);
      }
      os << '\n';
    }
    os << '\n';
  }
  return os;
}

std::ostream& operator<<(std::ostream& os, const color any_color)
{
  switch (any_color)
  {
    case color::blue  : os << "blue"  ; break;
    case color::green : os << "green" ; break;
    case color::orange: os << "orange"; break;
    case color::red   : os << "red"   ; break;
    case color::violet: os << "violet"; break;
    case color::yellow: os << "yellow"; break;
  }
  return os;
}

std::vector<side> get_all_sides()
{
  return
  {
    side::front,
    side::back,
    side::left,
    side::right,
    side::top,
    side::bottom
  };
}

bool operator==(const rubiks_cube& lhs, const rubiks_cube& rhs) noexcept
{
  for (int i=0; i!=6; ++i)
    for (int j=0; j!=2; ++j)
      for (int k=0; k!=2; ++k)
        if (lhs.m_array[i][j][k] != rhs.m_array[i][j][k]) return false;
  return true;
}

bool operator!=(const rubiks_cube& lhs, const rubiks_cube& rhs) noexcept
{
  return !(lhs == rhs);
}
