int continued_clawing();
int continued_arming();

namespace turn {
  extern double auton, normal, amount;
  void left(double turns); void left(double turns, bool block_program);
  void right(double turns); void right(double turns, bool block_program);
}

namespace drive {
  extern double auton, normal, amount; extern vex::brakeType stopping;
  void forwards(double blocks); void forwards(double blocks, bool block_program);
  void backwards(double blocks); void backwards(double blocks, bool block_program); 
}

namespace arm { 
  extern double auton, normal, amount, start; extern vex::brakeType stopping;
  void up(); void up(double custom); void up(bool block_program); void up(double custom, bool block_program);
  void down(); void down(double custom); void down(bool block_program); void down(double custom, bool block_program);
  void reset(); void reset(bool block_program);
  void unreset(); void unreset(bool block_program);
}

namespace claw {
  extern double auton, normal, amount; extern vex::brakeType stopping;
  void up(); void up(double custom); void up(bool block_program); void up(double custom, bool block_program);
  void down(); void down(double custom); void down(bool block_program); void down(double custom, bool block_program);
}

namespace lift {
  extern double auton, normal, amount; extern vex::brakeType stopping;
  void up(); void up(double custom); void up(bool block_program); void up(double custom, bool block_program);
  void down(); void down(double custom); void down(bool block_program); void down(double custom, bool block_program);
  void reset(); void reset(bool block_program);
}

namespace rollers {
  extern double auton, normal, dir;
  void stp(); void rev(); void fwd();
}