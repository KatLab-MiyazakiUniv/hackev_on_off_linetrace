#include "Machine.h"

void Machine::calibration() {
  // スピーカ音量設定
  controller.speakerSetVolume(100);

  // LRコースの選択
  controller.printDisplay(4, "Choose L or R course");
  setLR();
  onOffController.setIsLeft(isLeft);

  // 黒色の光設定
  controller.printDisplay(4, "Set black brightness");
  black = setBrightness();
  controller.speakerPlayTone(controller.noteFs6, 100);

  // 白色の光設定
  controller.printDisplay(4, "Set white brightness");
  white = setBrightness();
  controller.speakerPlayTone(controller.noteFs6, 100);

  // forward値、turn値の設定
  if (isLeft) {
    // Lコースの場合
    onOffController.setParam((black + white) / 2, 30, 10);
  } else {
    // Rコースの場合
    onOffController.setParam((black + white) / 2, 30, 10);
  }
}

void Machine::run() {
  while (1) {
    if (controller.buttonIsPressedEnter() == true) {
      controller.tslpTsk(500); /* 500msecウェイト */
      break;
    }
    controller.tslpTsk(4);
  }

  controller.speakerPlayTone(controller.noteFs6, 100);

  int leftPwm = 0;
  int rightPwm = 0;
  while (1) {
    if (controller.buttonIsPressedBack() == true) {
      controller.tslpTsk(500); /* 500msecウェイト */
      controller.leftWheel.setPWM(0);
      controller.rightWheel.setPWM(0);
      break;
    }

    auto brightness = controller.getBrightness();
    onOffController.calcurate(brightness, leftPwm, rightPwm);
    controller.leftWheel.setPWM(leftPwm);
    controller.rightWheel.setPWM(rightPwm);

    controller.tslpTsk(4);
  }
}

void Machine::setLR() {
  controller.printDisplay(5, "isLeft: true");
  while (1) {
    if ((controller.buttonIsPressedRight() == true) ||
        (controller.buttonIsPressedLeft() == true)) {
      controller.speakerPlayTone(controller.noteFs6, 100);
      if (isLeft) {
        isLeft = false;
        controller.printDisplay(5, "isLeft: false");
      } else {
        isLeft = true;
        controller.printDisplay(5, "isLeft: true");
      }
      controller.tslpTsk(500); /* 500msecウェイト */
    } else if (controller.buttonIsPressedEnter() == true) {
      controller.speakerPlayTone(controller.noteFs6, 100);
      controller.tslpTsk(500); /* 500msecウェイト */
      return;
    }
    controller.tslpTsk(4); /* 4msecウェイト */
  }
}

int Machine::setBrightness() {
  while (1) {
    if (controller.buttonIsPressedEnter() == true) {
      controller.tslpTsk(500); /* 500msecウェイト */
      break;
    }
    auto brightness = controller.getBrightness();
    controller.printDisplay(5, "BRIGHTNESS: %d", brightness);

    controller.tslpTsk(4); /* 4ms wait */
  }

  int result = 0;
  constexpr int num = 10;
  for (int i = 0; i < num; i++) {
    result += controller.getBrightness();
    controller.tslpTsk(4); /* 4ms wait */
  }
  result /= num;

  return result;
}