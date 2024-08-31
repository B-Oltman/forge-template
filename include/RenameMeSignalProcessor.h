#pragma once

#include "SignalProcessor.h"

class RenameMeSignalProcessor : public SignalProcessor {
public:    
    RenameMeSignalProcessor(std::shared_ptr<ITradingPlatform> tp) : SignalProcessor(tp) {}
    std::optional<std::vector<PendingOrder>> ProcessSignals() override;
};

