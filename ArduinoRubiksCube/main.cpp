#include <iostream>
#include <cassert>
#include <string>
#include "rubikscube.h"

int main()
{
  //
  //           Top color: blue
  //
  //           Back color: yellow
  //
  //              +---+---+
  //             /   /   /|
  //            +---+---+ +
  //           /   /   /|/|
  // Left     +---+---+ + +
  // side     |   |   |/|/
  // color:   +---+---+ +  Right side color: orange
  // green    |   |   |/
  //          +---+---+
  //
  //         Front color: red
  //
  //         Bottom color: violet
  //

  assert(rubiks_cube() == rubiks_cube());

  rubiks_cube cube;

  if(cube.get_color(side::front,0,1) != color::red) { std::cerr << "ERROR"; exit(1); }
  assert(cube.get_color(side::front,0,0) == color::red);
  assert(cube.get_color(side::front,1,0) == color::red);
  assert(cube.get_color(side::front,1,1) == color::red);

  if(cube.get_color(side::back,0,1) != color::yellow) { std::cerr << "ERROR"; exit(1); }
  assert(cube.get_color(side::back,0,0) == color::yellow);
  assert(cube.get_color(side::back,1,0) == color::yellow);
  assert(cube.get_color(side::back,1,1) == color::yellow);

  if(cube.get_color(side::right,0,1) != color::orange) { std::cerr << "ERROR"; exit(1); }
  assert(cube.get_color(side::right,0,0) == color::orange);
  assert(cube.get_color(side::right,1,0) == color::orange);
  assert(cube.get_color(side::right,1,1) == color::orange);

  if(cube.get_color(side::left,0,1) != color::green) { std::cerr << "ERROR"; exit(1); }
  assert(cube.get_color(side::left,0,0) == color::green);
  assert(cube.get_color(side::left,1,0) == color::green);
  assert(cube.get_color(side::left,1,1) == color::green);

  if(cube.get_color(side::top,0,1) != color::blue) { std::cerr << "ERROR"; exit(1); }
  assert(cube.get_color(side::top,0,0) == color::blue);
  assert(cube.get_color(side::top,1,0) == color::blue);
  assert(cube.get_color(side::top,1,1) == color::blue);

  if(cube.get_color(side::bottom,0,1) != color::violet) { std::cerr << "ERROR"; exit(1); }
  assert(cube.get_color(side::bottom,0,0) == color::violet);
  assert(cube.get_color(side::bottom,1,0) == color::violet);
  assert(cube.get_color(side::bottom,1,1) == color::violet);

  //Turning front side clock-wise
  cube.turn(side::front,rotation::clock_wise); //When turning 1 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::front,rotation::clock_wise); //When turning 2 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::front,rotation::clock_wise); //When turning 3 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::front,rotation::clock_wise); //When turning 4 time, original state is restored
  assert(cube == rubiks_cube() && "After doing this, Cube is identical again to a new Rubik's cube");

  //Turning front side counter clock-wise
  cube.turn(side::front,rotation::counter_clock_wise); //When turning 1 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::front,rotation::counter_clock_wise); //When turning 2 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::front,rotation::counter_clock_wise); //When turning 3 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::front,rotation::counter_clock_wise); //When turning 4 time, original state is restored
  assert(cube == rubiks_cube() && "After doing this, Cube is identical again to a new Rubik's cube");

  //Turning back side clock-wise
  cube.turn(side::back,rotation::clock_wise); //When turning 1 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::back,rotation::clock_wise); //When turning 2 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::back,rotation::clock_wise); //When turning 3 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::back,rotation::clock_wise); //When turning 4 time, original state is restored
  assert(cube == rubiks_cube() && "After doing this, Cube is identical again to a new Rubik's cube");

  //Turning back side counter clock-wise
  cube.turn(side::back,rotation::counter_clock_wise); //When turning 1 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::back,rotation::counter_clock_wise); //When turning 2 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::back,rotation::counter_clock_wise); //When turning 3 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::back,rotation::counter_clock_wise); //When turning 4 time, original state is restored
  assert(cube == rubiks_cube() && "After doing this, Cube is identical again to a new Rubik's cube");

  //Turning right side clock-wise
  cube.turn(side::right,rotation::clock_wise); //When turning 1 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::right,rotation::clock_wise); //When turning 2 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::right,rotation::clock_wise); //When turning 3 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::right,rotation::clock_wise); //When turning 4 time, original state is restored
  assert(cube == rubiks_cube() && "After doing this, Cube is identical again to a new Rubik's cube");

  //Turning right side counter clock-wise
  cube.turn(side::right,rotation::counter_clock_wise); //When turning 1 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::right,rotation::counter_clock_wise); //When turning 2 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::right,rotation::counter_clock_wise); //When turning 3 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::right,rotation::counter_clock_wise); //When turning 4 time, original state is restored
  assert(cube == rubiks_cube() && "After doing this, Cube is identical again to a new Rubik's cube");

  //Turning left side clock-wise
  cube.turn(side::left,rotation::clock_wise); //When turning 1 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::left,rotation::clock_wise); //When turning 2 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::left,rotation::clock_wise); //When turning 3 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::left,rotation::clock_wise); //When turning 4 time, original state is restored
  assert(cube == rubiks_cube() && "After doing this, Cube is identical again to a new Rubik's cube");

  //Turning left side counter clock-wise
  cube.turn(side::left,rotation::counter_clock_wise); //When turning 1 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::left,rotation::counter_clock_wise); //When turning 2 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::left,rotation::counter_clock_wise); //When turning 3 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::left,rotation::counter_clock_wise); //When turning 4 time, original state is restored
  assert(cube == rubiks_cube() && "After doing this, Cube is identical again to a new Rubik's cube");

  //Turning top side clock-wise
  cube.turn(side::top,rotation::clock_wise); //When turning 1 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::top,rotation::clock_wise); //When turning 2 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::top,rotation::clock_wise); //When turning 3 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::top,rotation::clock_wise); //When turning 4 time, original state is restored
  assert(cube == rubiks_cube() && "After doing this, Cube is identical again to a new Rubik's cube");

  //Turning top side counter clock-wise
  cube.turn(side::top,rotation::counter_clock_wise); //When turning 1 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::top,rotation::counter_clock_wise); //When turning 2 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::top,rotation::counter_clock_wise); //When turning 3 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::top,rotation::counter_clock_wise); //When turning 4 time, original state is restored
  assert(cube == rubiks_cube() && "After doing this, Cube is identical again to a new Rubik's cube");

  //Turning bottom side clock-wise
  cube.turn(side::bottom,rotation::clock_wise); //When turning 1 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::bottom,rotation::clock_wise); //When turning 2 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::bottom,rotation::clock_wise); //When turning 3 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::bottom,rotation::clock_wise); //When turning 4 time, original state is restored
  assert(cube == rubiks_cube() && "After doing this, Cube is identical again to a new Rubik's cube");

  //Turning bottom side counter clock-wise
  cube.turn(side::bottom,rotation::counter_clock_wise); //When turning 1 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::bottom,rotation::counter_clock_wise); //When turning 2 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::bottom,rotation::counter_clock_wise); //When turning 3 time, something happened
  assert(cube != rubiks_cube() && "After doing this, Cube is not identical to a new Rubik's cube");
  cube.turn(side::bottom,rotation::counter_clock_wise); //When turning 4 time, original state is restored
  assert(cube == rubiks_cube() && "After doing this, Cube is identical again to a new Rubik's cube");

  //Check in detail a clockwise turn at the front side
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

  //Turn front side
  {
    rubiks_cube r;
    assert(cube.get_color(side::front,0,0) == color::red);
    assert(cube.get_color(side::front,0,1) == color::red);
    assert(cube.get_color(side::front,1,0) == color::red);
    assert(cube.get_color(side::front,1,1) == color::red);
    assert(cube.get_color(side::right,0,0) == color::orange);
    assert(cube.get_color(side::right,0,1) == color::orange);
    assert(cube.get_color(side::right,1,0) == color::orange);
    assert(cube.get_color(side::right,1,1) == color::orange);
    assert(cube.get_color(side::left,0,0) == color::green);
    assert(cube.get_color(side::left,0,1) == color::green);
    assert(cube.get_color(side::left,1,0) == color::green);
    assert(cube.get_color(side::left,1,1) == color::green);
    assert(cube.get_color(side::top,0,0) == color::blue);
    assert(cube.get_color(side::top,0,1) == color::blue);
    assert(cube.get_color(side::top,1,0) == color::blue);
    assert(cube.get_color(side::top,1,1) == color::blue);
    assert(cube.get_color(side::bottom,0,0) == color::violet);
    assert(cube.get_color(side::bottom,0,1) == color::violet);
    assert(cube.get_color(side::bottom,1,0) == color::violet);
    assert(cube.get_color(side::bottom,1,1) == color::violet);
    r.turn(side::front,rotation::clock_wise);
    assert(r.get_color(side::front,0,0)==color::red);
    assert(r.get_color(side::front,0,1)==color::red);
    assert(r.get_color(side::front,1,0)==color::red);
    assert(r.get_color(side::front,1,1)==color::red);
    assert(r.get_color(side::top,1,0)==color::green);
    assert(r.get_color(side::top,1,1)==color::green);
    assert(r.get_color(side::right,0,0)==color::blue);
    assert(r.get_color(side::right,1,0)==color::blue);
    assert(r.get_color(side::bottom,0,0)==color::orange);
    assert(r.get_color(side::bottom,0,1)==color::orange);
    assert(r.get_color(side::left,0,1)==color::violet);
    assert(r.get_color(side::left,1,1)==color::violet);
  }

  //Random shuffle the cube 20 times
  for(int i = 0; i < 20; ++i)
  {
    side random_side = static_cast<side>(rand() % 5);
    rotation random_rotation = static_cast<rotation>(rand() % 1);
    cube.turn(random_side, random_rotation);
  }

  //Show cube after shuffle
  std::ostream& operator <<(std::ostream &os, const rubiks_cube &cube);
  std::cout << cube << std::endl;

  //Check if after turning the colors are in the right place

  //Turning front side clock-wise
  //Check the front:
  cube.turn(side::front,rotation::clock_wise); //When turning 1 time, something happened
  if(cube.get_color(side::front,    0,1) != color::blue) { std::cerr << "ERROR7"; exit(1); }
  assert(cube.get_color(side::front,0,0) == color::green);
  assert(cube.get_color(side::front,1,0) == color::red);
  assert(cube.get_color(side::front,1,1) == color::green);
  //Check the sides
  if(cube.get_color(side::top       ,1,0) != color::red) { std::cerr << "ERROR8"; exit(1); }
  assert(cube.get_color(side::top   ,1,1) == color::orange);
  assert(cube.get_color(side::right ,0,0) == color::red);
  assert(cube.get_color(side::right ,1,0) == color::yellow);
  assert(cube.get_color(side::bottom,0,1) == color::blue);
  assert(cube.get_color(side::bottom,0,0) == color::orange);
  assert(cube.get_color(side::left  ,1,1) == color::violet);
  assert(cube.get_color(side::left  ,0,1) == color::blue);

  //Turning front side counter clock-wise
  //Check the front:
  cube.turn(side::front,rotation::counter_clock_wise); //When turning 1 time, something happened (same cube as begin cube)
  if(cube.get_color(side::front    ,0,1) != color::green) { std::cerr << "ERROR9"; exit(1); }
  assert(cube.get_color(side::front,0,0) == color::blue);
  assert(cube.get_color(side::front,1,0) == color::green);
  assert(cube.get_color(side::front,1,1) == color::red);
  //Check the sides
  if(cube.get_color(side::top       ,1,0) != color::red) { std::cerr << "ERROR10"; exit(1); }
  assert(cube.get_color(side::top   ,1,1) == color::yellow);
  assert(cube.get_color(side::right ,0,0) == color::blue);
  assert(cube.get_color(side::right ,1,0) == color::orange);
  assert(cube.get_color(side::bottom,0,1) == color::violet);
  assert(cube.get_color(side::bottom,0,0) == color::blue);
  assert(cube.get_color(side::left  ,1,1) == color::red);
  assert(cube.get_color(side::left  ,0,1) == color::orange);

  //Turning back side clock-wise
  //Check the front (in this case the back side is the front):
  cube.turn(side::back,rotation::clock_wise); //When turning 1 time, something happened
  if(cube.get_color(side::back    ,0,1) != color::yellow) { std::cerr << "ERROR11"; exit(1); }
  assert(cube.get_color(side::back,0,0) == color::green);
  assert(cube.get_color(side::back,1,0) == color::orange);
  assert(cube.get_color(side::back,1,1) == color::green);
  //Check the sides
  if(cube.get_color(side::bottom    ,1,0) != color::yellow) { std::cerr << "ERROR12"; exit(1); }
  assert(cube.get_color(side::bottom,1,1) == color::orange);
  assert(cube.get_color(side::right ,1,1) == color::blue);
  assert(cube.get_color(side::right ,0,1) == color::red);
  assert(cube.get_color(side::top   ,0,1) == color::violet);
  assert(cube.get_color(side::top   ,0,0) == color::yellow);
  assert(cube.get_color(side::left  ,0,0) == color::violet);
  assert(cube.get_color(side::left  ,1,0) == color::violet);

  //Turning back side counter clock-wise
  //Check the front (in this case the back side is the front):
  cube.turn(side::back,rotation::counter_clock_wise); //When turning 1 time, something happened (same cube as begin cube)
  if(cube.get_color(side::back    ,0,1) != color::green) { std::cerr << "ERROR13"; exit(1); }
  assert(cube.get_color(side::back,0,0) == color::yellow);
  assert(cube.get_color(side::back,1,0) == color::green);
  assert(cube.get_color(side::back,1,1) == color::orange);
  //Check the sides
  if(cube.get_color(side::bottom    ,1,0) != color::blue) { std::cerr << "ERROR14"; exit(1); }
  assert(cube.get_color(side::bottom,1,1) == color::red);
  assert(cube.get_color(side::right ,1,1) == color::violet);
  assert(cube.get_color(side::right ,0,1) == color::yellow);
  assert(cube.get_color(side::top   ,0,1) == color::violet);
  assert(cube.get_color(side::top   ,0,0) == color::violet);
  assert(cube.get_color(side::left  ,0,0) == color::yellow);
  assert(cube.get_color(side::left  ,1,0) == color::orange);

  //Turning left side clock-wise
  //Check the front (in this case the left side is the front):
  cube.turn(side::left,rotation::clock_wise); //When turning 1 time, something happened
  if(cube.get_color(side::left,0,1) != color::yellow) { std::cerr << "ERROR15"; exit(1); }
  assert(cube.get_color(side::left,0,0) == color::orange);
  assert(cube.get_color(side::left,1,0) == color::red);
  assert(cube.get_color(side::left,1,1) == color::orange);
  //Check the sides
  if(cube.get_color(side::top       ,0,0) != color::yellow) { std::cerr << "ERROR16"; exit(1); }
  assert(cube.get_color(side::top   ,1,0) == color::green);
  assert(cube.get_color(side::front ,0,0) == color::violet);
  assert(cube.get_color(side::front ,1,0) == color::red);
  assert(cube.get_color(side::bottom,0,0) == color::blue);
  assert(cube.get_color(side::bottom,1,0) == color::green);
  assert(cube.get_color(side::back  ,0,0) == color::blue);
  assert(cube.get_color(side::back  ,1,0) == color::blue);

  //Turning left side counter clock-wise
  //Check the front (in this case the left side is the front):
  cube.turn(side::left,rotation::counter_clock_wise); //When turning 1 time, something happened (same cube as begin cube)
  if(cube.get_color(side::left    ,0,1) != color::orange) { std::cerr << "ERROR17"; exit(1); }
  assert(cube.get_color(side::left,0,0) == color::yellow);
  assert(cube.get_color(side::left,1,0) == color::orange);
  assert(cube.get_color(side::left,1,1) == color::red);
  //Check the sides
  if(cube.get_color(side::top       ,0,0) != color::violet) { std::cerr << "ERROR18"; exit(1); }
  assert(cube.get_color(side::top   ,1,0) == color::red);
  assert(cube.get_color(side::front ,0,0) == color::blue);
  assert(cube.get_color(side::front ,1,0) == color::green);
  assert(cube.get_color(side::bottom,0,0) == color::blue);
  assert(cube.get_color(side::bottom,1,0) == color::blue);
  assert(cube.get_color(side::back  ,0,0) == color::yellow);
  assert(cube.get_color(side::back  ,1,0) == color::green);

  //Turning right side clock-wise
  //Check the front (in this case the right side is the front):
  cube.turn(side::right,rotation::clock_wise); //When turning 1 time, something happened
  if(cube.get_color(side::right    ,0,1) != color::blue) { std::cerr << "ERROR19"; exit(1); }
  assert(cube.get_color(side::right,0,0) == color::orange);
  assert(cube.get_color(side::right,1,0) == color::violet);
  assert(cube.get_color(side::right,1,1) == color::yellow);
  //Check the sides
  if(cube.get_color(side::top       ,1,1) != color::red) { std::cerr << "ERROR20"; exit(1); }
  assert(cube.get_color(side::top   ,0,1) == color::green);
  assert(cube.get_color(side::back  ,1,1) == color::yellow);
  assert(cube.get_color(side::back  ,0,1) == color::violet);
  assert(cube.get_color(side::bottom,1,1) == color::orange);
  assert(cube.get_color(side::bottom,0,1) == color::green);
  assert(cube.get_color(side::front ,1,1) == color::red);
  assert(cube.get_color(side::front ,0,1) == color::violet);

  //Turning right side counter clock-wise
  //Check the front (in this case the right side is the front):
  cube.turn(side::right,rotation::counter_clock_wise); //When turning 1 time, something happened (same cube as begin cube)
  if(cube.get_color(side::right    ,0,1) != color::yellow) { std::cerr << "ERROR21"; exit(1); }
  assert(cube.get_color(side::right,0,0) == color::blue);
  assert(cube.get_color(side::right,1,0) == color::orange);
  assert(cube.get_color(side::right,1,1) == color::violet);
  //Check the sides
  if(cube.get_color(side::top       ,1,1) != color::yellow) { std::cerr << "ERROR22"; exit(1); }
  assert(cube.get_color(side::top   ,0,1) == color::violet);
  assert(cube.get_color(side::back  ,1,1) == color::orange);
  assert(cube.get_color(side::back  ,0,1) == color::green);
  assert(cube.get_color(side::bottom,1,1) == color::red);
  assert(cube.get_color(side::bottom,0,1) == color::violet);
  assert(cube.get_color(side::front ,1,1) == color::red);
  assert(cube.get_color(side::front ,0,1) == color::green);

  //Turning top side clock-wise
  //Check the front (in this case the top side is the front):
  cube.turn(side::top,rotation::clock_wise); //When turning 1 time, something happened
  if(cube.get_color(side::top,0,1) != color::violet) { std::cerr << "ERROR23"; exit(1); }
  assert(cube.get_color(side::top,0,0) == color::red);
  assert(cube.get_color(side::top,1,0) == color::yellow);
  assert(cube.get_color(side::top,1,1) == color::violet);
  //Check the sides
  if(cube.get_color(side::back,1,0) != color::orange) { std::cerr << "ERROR24"; exit(1); }
  assert(cube.get_color(side::back,1,1) == color::yellow);
  assert(cube.get_color(side::right,0,1) == color::green);
  assert(cube.get_color(side::right,0,0) == color::orange);
  assert(cube.get_color(side::front,0,1) == color::yellow);
  assert(cube.get_color(side::front,0,0) == color::blue);
  assert(cube.get_color(side::left,0,1) == color::green);
  assert(cube.get_color(side::left,0,0) == color::blue);

  //Turning top side couter clock-wise
  //Check the front (in this case the top side is the front):
  cube.turn(side::top,rotation::counter_clock_wise); //When turning 1 time, something happened (same cube as begin cube)
  if(cube.get_color(side::top,0,1) != color::violet) { std::cerr << "ERROR25"; exit(1); }
  assert(cube.get_color(side::top,0,0) == color::violet);
  assert(cube.get_color(side::top,1,0) == color::red);
  assert(cube.get_color(side::top,1,1) == color::yellow);
  //Check the sides
  if(cube.get_color(side::back,1,0) != color::green) { std::cerr << "ERROR26"; exit(1); }
  assert(cube.get_color(side::back,1,1) == color::orange);
  assert(cube.get_color(side::right,0,1) == color::yellow);
  assert(cube.get_color(side::right,0,0) == color::blue);
  assert(cube.get_color(side::front,0,1) == color::green);
  assert(cube.get_color(side::front,0,0) == color::blue);
  assert(cube.get_color(side::left,0,1) == color::orange);
  assert(cube.get_color(side::left,0,0) == color::yellow);

  //Turning bottom side clock-wise
  //Check the front (in this case the bottom side is the front):
  cube.turn(side::bottom,rotation::clock_wise); //When turning 1 time, something happened
  if(cube.get_color(side::bottom,0,1) != color::blue) { std::cerr << "ERROR27"; exit(1); }
  assert(cube.get_color(side::bottom,0,0) == color::blue);
  assert(cube.get_color(side::bottom,1,0) == color::red);
  assert(cube.get_color(side::bottom,1,1) == color::violet);
  //Check the sides
  if(cube.get_color(side::front,1,0) != color::orange) { std::cerr << "ERROR28"; exit(1); }
  assert(cube.get_color(side::front,1,1) == color::red);
  assert(cube.get_color(side::right,1,0) == color::green);
  assert(cube.get_color(side::right,1,1) == color::red);
  assert(cube.get_color(side::back,0,1) == color::orange);
  assert(cube.get_color(side::back,0,0) == color::violet);
  assert(cube.get_color(side::left,1,0) == color::green);
  assert(cube.get_color(side::left,1,1) == color::yellow);

  //Turning bottom side counter clock-wise
  //Check the front (in this case the bottom side is the front):
  cube.turn(side::bottom,rotation::counter_clock_wise); //When turning 1 time, something happened (same cube as begin cube)
  if(cube.get_color(side::bottom,0,1) != color::violet) { std::cerr << "ERROR29"; exit(1); }
  assert(cube.get_color(side::bottom,0,0) == color::blue);
  assert(cube.get_color(side::bottom,1,0) == color::blue);
  assert(cube.get_color(side::bottom,1,1) == color::red);
  //Check the sides
  if(cube.get_color(side::front,1,0) != color::green) { std::cerr << "ERROR30"; exit(1); }
  assert(cube.get_color(side::front,1,1) == color::red);
  assert(cube.get_color(side::right,1,0) == color::orange);
  assert(cube.get_color(side::right,1,1) == color::violet);
  assert(cube.get_color(side::back,0,1) == color::green);
  assert(cube.get_color(side::back,0,0) == color::yellow);
  assert(cube.get_color(side::left,1,0) == color::orange);
  assert(cube.get_color(side::left,1,1) == color::red);


  //Show cube
  std::ostream& operator <<(std::ostream &os, const rubiks_cube &Cube);
  std::cout << cube << std::endl;
}
