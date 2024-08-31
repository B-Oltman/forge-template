#pragma once

#include "IPendingOrderFilter.h"

class RenameMeMarketTimingOrderFilter : public IPendingOrderFilter {
public:
    std::vector<PendingOrder> FilterPendingOrders(const std::vector<PendingOrder>& pendingOrders) override;
};

