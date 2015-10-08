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

  //Show cube
  std::ostream& operator <<(std::ostream &os, const rubiks_cube &Cube);
  std::cout << cube << std::endl;
}
