#pragma once

#include "PositionRiskProcessor.h"

class RenameMePositionRiskProcessor : public PositionRiskProcessor {
public:
    explicit RenameMePositionRiskProcessor(std::shared_ptr<ITradingPlatform> tradingPlatform)
        : PositionRiskProcessor(std::move(tradingPlatform)) {}

    RiskAssessment EvaluatePositionRisk(const PositionData& positionData) const override;
};

