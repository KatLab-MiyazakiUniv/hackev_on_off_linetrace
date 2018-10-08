#ifndef __MACHINE__
#define __MACHINE__

#include "Controller.h"

class Machine {
 public:
  // コンストラクタ
  explicit Machine(Controller& controller_) : controller(controller_){};

  // キャリブレーション
  void calibration();

  // 走行
  void run();

  // セッター
  void setLineTracePwm(const int& forward_, const int& turn_);

  // ゲッター
  int getBlack() { return black; }
  int getWhite() { return white; }

 private:
  int setBrightness(); // 色の光を決定する
  int limitPwm(const int& power); // PWMの制限をする

  Controller controller;
  int black; // 黒のBrightness
  int white; // 白のBrightness
  int forward; // 前進値
  int turn; // 回転値
};

#endif
