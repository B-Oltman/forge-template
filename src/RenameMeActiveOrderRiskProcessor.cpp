#include "RenameMeActiveOrderRiskProcessor.h"

RiskAssessment RenameMeActiveOrderRiskProcessor::EvaluateActiveOrder(const ExecutedOrder& activeOrder) const {
    // Custom active order risk processing logic
    RiskAssessment riskAssessment;

    riskAssessment.acceptable = true; 
    return riskAssessment;    
}
