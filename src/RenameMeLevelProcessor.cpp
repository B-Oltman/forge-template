#include "RenameMeLevelProcessor.h"
#include "LevelUtilities.h"

std::vector<TradeSignal> RenameMeLevelProcessor::ProcessLevels(const std::unordered_map<double, std::vector<BaseLevel>>& levels, double currentPrice) {
    std::vector<TradeSignal> signals;
    
    levelsToClear_.clear();

    auto levelsInRange = LevelUtilities::GetLevelsInRange(levels, currentPrice, currentPrice + tp->GetTickSize() * 8);
    for (const auto& level : levelsInRange) {                
            TradeSignal signal;
            signal.price = tp->GetCurrentPrice();
            signal.sellSignal = true;
            signal.signalKey = "Gap_Touch";            
            signals.push_back(signal);

            levelsToClear_.push_back(level);        
    }

    return signals;
}

std::vector<BaseLevel> RenameMeLevelProcessor::GetLevelsToClear(const std::unordered_map<double, std::vector<BaseLevel>>& levels, double currentPrice) {    
    return levelsToClear_;        
}
