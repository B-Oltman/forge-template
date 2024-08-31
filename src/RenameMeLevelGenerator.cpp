#include "RenameMeLevelGenerator.h"

std::vector<BaseLevel> RenameMeLevelGenerator::GenerateLevels(double currentPrice) {
    std::vector<BaseLevel> levels;
    
    // Your logic to generate levels based on the Opposing Hammer pattern goes here
    // This is just a placeholder logic for demonstration purposes
    auto bar = tp->GetBarByOffsetFromCurrent(0);
    auto prevBar = tp->GetBarByOffsetFromCurrent(1);

    if(!bar.has_value() || !prevBar.has_value()) {
        return std::vector<BaseLevel>();
    }    

    auto currentBar = bar.value();
    auto previousBar = prevBar.value();
    
    if (currentBar.open > (previousBar.high + tp->GetTickSize())) { // Replace with your actual logic
        auto level = BaseLevel(currentPrice, "Small_Gap", DateTime());
        level.clearOnTouch = true;        
        levels.push_back(level);
    }

    return levels;
}
