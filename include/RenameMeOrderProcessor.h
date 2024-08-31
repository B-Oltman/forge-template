#pragma once

#include "IOrderProcessor.h"

class RenameMeOrderProcessor : public IOrderProcessor {
public:
    std::optional<std::vector<ExecutedOrder>> ProcessPendingOrder(const PendingOrder& pendingOrder, std::shared_ptr<ITradingPlatform> tp) override;
    std::optional<std::vector<ExecutedOrder>> ProcessActiveOrder(const ExecutedOrder& activeOrder, std::shared_ptr<ITradingPlatform> tp) override;
};

