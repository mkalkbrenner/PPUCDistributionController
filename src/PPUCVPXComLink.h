/*
  PPUCVPXComLink.h
  Created by Markus Kalkbrenner, 2021.

  Play more pinball!
*/

#ifndef PPUCVPXCOMLINK_h
#define PPUCVPXCOMLINK_h

#include <Arduino.h>
#include <PPUCEvent.h>
#include <PPUCEventDispatcher.h>
#include <PPUCEventListener.h>

class PPUCVPXComLink : public PPUCEventListener {
public:
    PPUCVPXComLink(PPUCEventDispatcher* eD, byte pf) {
        eventDispatcher = eD;
        platform = pf;
    }

    void update();

    void handleEvent(PPUCEvent* event);

private:
    PPUCEventDispatcher* eventDispatcher;

    byte platform;

};

#endif
