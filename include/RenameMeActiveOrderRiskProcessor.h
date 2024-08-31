#pragma once

#include "ActiveOrderRiskProcessor.h"

class RenameMeActiveOrderRiskProcessor : public ActiveOrderRiskProcessor {
public:
    explicit RenameMeActiveOrderRiskProcessor(std::shared_ptr<ITradingPlatform> tradingPlatform)
        : ActiveOrderRiskProcessor(std::move(tradingPlatform)) {}

    RiskAssessment EvaluateActiveOrder(const ExecutedOrder& activeOrder) const override;
};
