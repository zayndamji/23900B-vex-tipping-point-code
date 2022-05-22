#include "vex.h"

namespace rollers {
  double auton {95.0};
  double normal {95.0};
  double dir {0.0};

  void fwd() {
    Rollers.spin(forward);
    dir = 1.0;
  }

  void rev() {
    Rollers.spin(reverse);
    dir = -1.0;
  }

  void stp() {
    Rollers.stop();
    dir = 0.0;
  }
}