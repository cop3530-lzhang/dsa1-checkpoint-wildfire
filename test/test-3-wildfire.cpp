#include <sstream>

#include "../wildfire.hpp"
#include "catch/catch.hpp"

TEST_CASE("Testing startFire from a W cell") {
  std::string mapText = "5\n4\nW W W W\nW T T W\nW T T W\nW W W W\nW T T W\n";
  Wildfire wf(mapText);
  wf.startFire(0, 0);
  CHECK("W W W W \nW T T W \nW T T W \nW W W W \nW T T W \n" == wf.info());
}

TEST_CASE("Testing startFire from out of range cells") {
  std::string mapText = "5\n4\nW W W W\nW T T W\nW T T W\nW W W W\nW T T W\n";
  Wildfire wf(mapText);
  wf.startFire(6, 6);
  CHECK("W W W W \nW T T W \nW T T W \nW W W W \nW T T W \n" == wf.info());
  Wildfire wf1(mapText);
  wf.startFire(-1, -1);
  CHECK("W W W W \nW T T W \nW T T W \nW W W W \nW T T W \n" == wf.info());
}
