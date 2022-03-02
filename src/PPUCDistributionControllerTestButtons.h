/*
  PPUCDistributionControllerTestButtons.h
  Created by Markus Kalkbrenner, 2022.

  Play more pinball!
*/

#ifndef PPUCEffectControllerTestButtons_h
#define PPUCEffectControllerTestButtons_h

#include <Arduino.h>
#include <Bounce2.h>
#include <PPUCEvent.h>
#include <PPUCEventDispatcher.h>

class PPUCDistributionControllerTestButtons {
public:
    PPUCDistributionControllerTestButtons(PPUCEventDispatcher* eD);

    void update();

protected:
    PPUCEventDispatcher* eventDispatcher;
    Bounce2::Button* button[2];
};

#endif
