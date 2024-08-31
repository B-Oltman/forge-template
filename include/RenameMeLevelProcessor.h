#pragma once

#include "LevelProcessor.h"
#include "ITradingPlatform.h"
#include <vector>
#include <unordered_map>
#include <memory>

class RenameMeLevelProcessor : public LevelProcessor {
public:
    RenameMeLevelProcessor(std::shared_ptr<ITradingPlatform> tradingPlatform) : LevelProcessor(tradingPlatform) {}
    std::vector<TradeSignal> ProcessLevels(const std::unordered_map<double, std::vector<BaseLevel>>& levels, double currentPrice) override;
    std::vector<BaseLevel> GetLevelsToClear(const std::unordered_map<double, std::vector<BaseLevel>>& levels, double currentPrice) override;
private:
    std::vector<BaseLevel> levelsToClear_;
};
