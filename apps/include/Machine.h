#ifndef __MACHINE__
#define __MACHINE__

#include "Controller.h"

class Machine {
 public:
  explicit Machine(Controller& controller_) : controller(controller_){};
  void calibration();
  int getBlack();
  int getWhite();

 private:
  int setBrightness();

  Controller controller;
  int black;
  int white;
};

#endif
