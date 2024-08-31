#pragma once

#include "ITuningDataProcessor.h"
#include "CommonTypes.h"
#include <vector>
#include <string>
#include <unordered_map>

class RenameMeParameterTuner : public ITuningDataProcessor {
public:
    std::optional<MachineLearningInput> ProcessData(const TradeSystemParameterGroup& parameterGroup, const DataBlob& newData) override;

private:
    std::vector<DataBlob> aggregateBlobs;
    // Add any private methods or members here if necessary
};
