#ifndef __ONOFFCONTROLLER__
#define __ONOFFCONTROLLER__

#include "LineTracer.h"

class OnOffController : public LineTracer {
 public:
  OnOffController(): isLeft(true){}
  void calcurate(const int& brightness, int& leftPwm, int& rightPwm);
  void setParam(const int& threthold_, const int& forward_, const int& turn_);
  void setIsLeft(bool isLeft_);

 private:
  int threthold; // OnOff閾値
  int forward; // 前進値
  int turn; // 回転値
  bool isLeft; // Lコースであるかどうか(trueならLコース)
};

#endif
