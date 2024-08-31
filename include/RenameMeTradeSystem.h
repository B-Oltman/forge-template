#pragma once

#include "TradeSystem.h"

class RenameMeTradeSystem : public TradeSystem {
public:
    RenameMeTradeSystem(
        std::shared_ptr<SignalManager> signalManager,
        std::shared_ptr<RiskManager> riskManager,
        std::shared_ptr<ContextManager> contextManager,
        std::shared_ptr<ITradingPlatform> tradingPlatform,
        std::shared_ptr<OrderManager> orderManager,
        std::optional<std::vector<std::shared_ptr<IPendingOrderFilter>>> pendingOrderFilters
    ) : TradeSystem(signalManager, riskManager, contextManager, tradingPlatform, orderManager, pendingOrderFilters) {}
};

