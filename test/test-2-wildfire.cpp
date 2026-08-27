#include <sstream>

#include "../wildfire.hpp"
#include "catch/catch.hpp"

TEST_CASE("Testing custom map") {
  std::string mapText = "5\n4\nW W W W\nW T T W\nW T T W\nW W W W\nW T T W\n";
  Wildfire wf(mapText);
  CHECK("W W W W \nW T T W \nW T T W \nW W W W \nW T T W \n" == wf.info());
}

TEST_CASE("Testing startFire from a tree cell") {
  std::string mapText = "5\n4\nW W W W\nW T T W\nW T T W\nW W W W\nW T T W\n";
  Wildfire wf(mapText);
  wf.startFire(1, 1);
  CHECK("W W W W \nW F F W \nW F F W \nW W W W \nW T T W \n" == wf.info());

  wf.startFire(4, 1);
  CHECK("W W W W \nW F F W \nW F F W \nW W W W \nW F F W \n" == wf.info());
}
