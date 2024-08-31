#pragma once

#include "LevelGenerator.h"
#include "ITradingPlatform.h"
#include <vector>
#include <memory>

class RenameMeLevelGenerator : public LevelGenerator {
public:
    RenameMeLevelGenerator(std::shared_ptr<ITradingPlatform> tradingPlatform) : LevelGenerator(tradingPlatform) {}
    std::vector<BaseLevel> GenerateLevels(double currentPrice) override;
};
