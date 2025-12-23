#include <graphene/protocol/nft_ops.hpp>
#include <graphene/protocol/nft_lottery.hpp>
#include <graphene/protocol/operations.hpp>
#include <numeric> // Required for std::accumulate

namespace graphene { namespace chain {

void nft_lottery_options::validate() const {
    // Assert maximum number of winning tickets
    FC_ASSERT(winning_tickets.size() <= 64, "Cannot have more than 64 winning tickets.");
    
    // Assert minimum ticket price
    FC_ASSERT(ticket_price.amount >= 1, "Ticket price must be at least 1 unit.");

    // Calculate total distribution share using std::accumulate for clarity
    uint16_t total_shares = 0;
    
    // Sum benefactor shares
    for (const auto& benefactor : benefactors) {
        total_shares += benefactor.share;
    }
    
    // Sum winning ticket shares
    for (const auto& share : winning_tickets) {
        total_shares += share;
    }

    // Assert that the total distribution equals 100%
    FC_ASSERT(total_shares == GRAPHENE_100_PERCENT, "Total distribution percentage must equal 100%. Current total: ${total}", ("total", total_shares));

    // Assert that the lottery has a defined ending condition
    FC_ASSERT(ending_on_soldout == true || end_date != time_point_sec(), "Lottery must end on sold out or have a valid end date.");
}

share_type nft_lottery_token_purchase_operation::calculate_fee(const fee_parameters_type& k) const {
    return k.fee;
}

void nft_lottery_token_purchase_operation::validate() const {
    // Assert fee is non-negative
    FC_ASSERT(fee.amount >= 0, "Fee must not be negative.");
    
    // Assert that at least one ticket is being purchased
    FC_ASSERT(tickets_to_buy > 0, "Must purchase at least 1 ticket.");
}

} // namespace chain
} // namespace graphene