#ifndef __MACHINE__
#define __MACHINE__

#include "Controller.h"
#include "OnOffController.h"

class Machine {
 public:
  // コンストラクタ
  explicit Machine(Controller& controller_) : controller(controller_), isLeft(true){};

  // キャリブレーション
  void calibration();

  // 走行
  void run();

  // ゲッター
  int getBlack() { return black; }
  int getWhite() { return white; }

 private:
  int setBrightness(); // 色の光を決定する
  void setLR(); // コースのLRを選択する。

  Controller controller;
  OnOffController onOffController;
  int black;  // 黒のBrightness
  int white; // 白のBrightness
  bool isLeft;
};

#endif
