#include "Machine.h"

void Machine::calibration() {
  // スピーカ音量設定
  controller.speakerSetVolume(100);

  // 黒色の光設定
  controller.printDisplay(4, "Set black brightness");
  black = setBrightness();
  controller.speakerPlayTone(controller.noteFs6, 100);

  // 白色の光設定
  controller.printDisplay(4, "Set white brightness");
  white = setBrightness();
  controller.speakerPlayTone(controller.noteFs6, 100);
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