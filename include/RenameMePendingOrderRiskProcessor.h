#pragma once

#include "PendingOrderRiskProcessor.h"

class RenameMePendingOrderRiskProcessor : public PendingOrderRiskProcessor {
public:
    explicit RenameMePendingOrderRiskProcessor(std::shared_ptr<ITradingPlatform> tradingPlatform)
        : PendingOrderRiskProcessor(std::move(tradingPlatform)) {}

    RiskAssessment EvaluatePendingOrder(const PendingOrder& pendingOrder) const override;
};

