#include <sstream>
#include <string>

#include "../wildfire.hpp"
#include "catch/catch.hpp"

TEST_CASE("Testing default constructor") {
  Wildfire wf;
  CHECK("T T T T T \nT T T T T \nT T T T T \nT T T T T \nT T T T T \n" ==
        wf.info());
}
TEST_CASE("Testing startFire with a default map of all trees") {
  Wildfire wf;
  wf.startFire(-1, 4);  // wrong coordinates
  CHECK("T T T T T \nT T T T T \nT T T T T \nT T T T T \nT T T T T \n" ==
        wf.info());
  wf.startFire(0, 0);
  CHECK("F F F F F \nF F F F F \nF F F F F \nF F F F F \nF F F F F \n" ==
        wf.info());
}
