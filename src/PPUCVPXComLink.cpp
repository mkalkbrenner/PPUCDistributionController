#include <Keyboard.h>
#include "PPUCVPXComLink.h"

void PPUCVPXComLink::update() {
    if (Serial.available() >= 5) {
        byte startByte = Serial.read();
        if (startByte == 255) {
            byte sourceId = Serial.read();
            if (sourceId != 0) {
                word eventId = word(Serial.read(), Serial.read());
                if (eventId != 0) {
                    byte value = Serial.read();
                    byte stopByte = Serial.read();
                    if (stopByte == 255) {
                        eventDispatcher->dispatch(new PPUCEvent((char) sourceId, eventId, value));
                    }
                }
            }
        }
    }
}

void PPUCVPXComLink::handleEvent(PPUCEvent* event) {
    if (event->sourceId == EVENT_SOURCE_SWITCH) {
        if (platform == PLATFORM_SYS11) {
            switch (event->eventId) {
                case 63:
                    if (event->value) {
                        Keyboard.press(KEY_END);
                    } else {
                        Keyboard.release(KEY_END);
                    }
                    break;
                case 64:
                    if (event->value) {
                        Keyboard.press(KEY_PAGE_UP);
                    } else {
                        Keyboard.release(KEY_PAGE_UP);
                    }
                    break;
            }
        }
    }
}
