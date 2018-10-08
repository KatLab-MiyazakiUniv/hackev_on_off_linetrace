#ifndef __ONOFFCONTROLLER__
#define __ONOFFCONTROLLER__

class OnOffController {
 public:
  OnOffController() = default;
  void calcurate(const int& brightness, int& leftPwm, int& rightPwm);
  void setParam(const int& threthold_, const int& forward_, const int& turn_);

 private:
  int threthold;
  int forward;
  int turn;
};

#endif
