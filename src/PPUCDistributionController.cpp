#include "PPUCDistributionController.h"

PPUCVPXComLink* PPUCDistributionController::vpxComLink() {
    return _vpxComLink;
}

PPUCDistributionControllerTestButtons* PPUCDistributionController::testButtons() {
    return _testButtons;
}

PPUCEventDispatcher* PPUCDistributionController::eventDispatcher() {
    return _eventDispatcher;
}
