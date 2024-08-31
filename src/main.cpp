#include <sierrachart.h>
#include "RenameMeTradeSystem.h"
#include "RenameMeSignalGenerator.h"
#include "RenameMeSignalProcessor.h"
#include "RenameMeActiveOrderRiskProcessor.h"
#include "RenameMePendingOrderRiskProcessor.h"
#include "RenameMePositionRiskProcessor.h"
#include "RenameMeOrderProcessor.h"
#include "RenameMeMarketTimingOrderFilter.h"
#include "RenameMeLevelGenerator.h"
#include "RenameMeLevelProcessor.h"
#include "RenameMeParameterTuner.h"
#include "ParameterManager.h"
#include "TradeSystemBuilder.h"
#include "SingletonTradingPlatform.h"
#include <memory>

SCDLLName("RenameMeTradeSystem")

    // Main entry point for the Opposing Hammer Trade System study
    SCSFExport scsf_RenameMeTradeSystem(SCStudyInterfaceRef sc)
{
    static std::shared_ptr<RenameMeTradeSystem> tradeSystem;

    // Set default settings for the study
    if (sc.SetDefaults)
    {
        sc.GraphName = "Rename Me Trade System"; // Name of the study
        sc.GraphRegion = 0;                      // Region to draw the study
        sc.AutoLoop = 1;                         // Enable autoloop

        return;
    }

    // Update the sc reference in the singleton platform instance
    SingletonTradingPlatform::UpdateSCRef(&sc);

    // Initialize the trade system if it's not already created
    if (!tradeSystem)
    {
        // Build the trade system using the TradeSystemBuilder
        tradeSystem = TradeSystemBuilder<RenameMeTradeSystem>(&sc, ContextType::PaperTrading)
                          .WithSignalGenerator<RenameMeSignalGenerator>()                     // Set custom signal generator
                          .WithSignalProcessor<RenameMeSignalProcessor>()                     // Set custom signal processor
                          .WithActiveOrderRiskProcessor<RenameMeActiveOrderRiskProcessor>()   // Set custom active order risk processor
                          .WithPendingOrderRiskProcessor<RenameMePendingOrderRiskProcessor>() // Set custom pending order risk processor
                          .WithPositionRiskProcessor<RenameMePositionRiskProcessor>()         // Set custom system-wide risk processor
                          .WithOrderProcessor<RenameMeOrderProcessor>()                       // Set custom order processor
                          .WithPendingOrderFilter<RenameMeMarketTimingOrderFilter>()          // Set custom market timing order filter
                          .WithTuningDataProcessor<RenameMeParameterTuner>()                  // Set custom parameter tuner
                          .WithLevelGenerator<RenameMeLevelGenerator>()                       // Set custom level generator
                          .WithLevelProcessor<RenameMeLevelProcessor>()                       // Set custom level processor
                          .Build("RenameMe");                                                 // Build for backtesting context

        // Initialize the trade system
        tradeSystem->Initialize();
    }

    if (sc.LastCallToFunction)
    {
        // Reset the smart pointer to destruct the trade system.
        tradeSystem.reset();
        return;
    }

    // Process the trade system
    tradeSystem->Process();
}
