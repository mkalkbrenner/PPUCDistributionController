/*
  PPUCDistributionController.h
  Created by Markus Kalkbrenner, 2020-2021.

  Play more pinball!
*/

#ifndef PPUCDISTRIBUTIONCONTROLLER_h
#define PPUCDISTRIBUTIONCONTROLLER_h

#include <Arduino.h>
#include <PPUCEventDispatcher.h>
#include <PPUCEventListener.h>

#include "PPUCVPXComLink.h"
#include "PPUCDistributionControllerTestButtons.h"

class PPUCDistributionController {
public:
    PPUCDistributionController(String controllerType, byte pf) {
        platform = pf;
        _eventDispatcher = new PPUCEventDispatcher();

        if (controllerType == "0.1.0") {
            _vpxComLink = new PPUCVPXComLink(_eventDispatcher, platform);
            _testButtons = new PPUCDistributionControllerTestButtons(_eventDispatcher);

            _eventDispatcher->addListener(_vpxComLink, EVENT_SOURCE_SWITCH);
        } else {
            Serial.print("Unsupported Effects Controller: ");
            Serial.println(controllerType);
        }
    }

    PPUCVPXComLink* vpxComLink();

    PPUCDistributionControllerTestButtons* testButtons();

    PPUCEventDispatcher* eventDispatcher();

    byte platform;

private:
    PPUCVPXComLink* _vpxComLink;
    PPUCDistributionControllerTestButtons* _testButtons;
    PPUCEventDispatcher* _eventDispatcher;
};

#endif
