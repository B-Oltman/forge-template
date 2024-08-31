#pragma once

#include "SignalGenerator.h"

class RenameMeSignalGenerator : public SignalGenerator {
public:
    RenameMeSignalGenerator(std::shared_ptr<ITradingPlatform> tp) : SignalGenerator(tp) {}
    std::vector<TradeSignal> GenerateSignals() override;
};
