#include "RenameMeParameterTuner.h"

std::optional<MachineLearningInput> RenameMeParameterTuner::ProcessData(const TradeSystemParameterGroup& parameterGroup, const DataBlob& newData) {
    MachineLearningInput mlInput;

    // Example processing: add the new data blobs to the ML input
    aggregateBlobs.push_back(newData);

    // Aggregate blob data.
    // Once data length is > 5, submit to server for processing.
    if(aggregateBlobs.size() > 5) {        
        for(const auto blob : aggregateBlobs) {
            mlInput.dataBlobs.push_back(blob);
        }
        aggregateBlobs.clear();

        // Example processing: add the existing parameters to the ML input            
        mlInput.parameters = parameterGroup.GetParameters();    

        return mlInput;
    }   

    // Additional processing logic for the opposing hammer strategy can be added here

    // Return nullopt if no data is ready to be processed
    // This will prevent the server from being overloaded with requests
    return std::nullopt;
}
