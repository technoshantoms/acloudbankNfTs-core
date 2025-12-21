
#include <graphene/protocol/lottery_ops.hpp>

namespace graphene { namespace protocol {

void ticket_purchase_operation::validate() const 
{
   FC_ASSERT( fee.amount >= 0 );
   FC_ASSERT( tickets_to_buy > 0 );
}

share_type ticket_purchase_operation::calculate_fee( const fee_parameters_type& k )const
{
   return k.fee;
}

} } // namespace graphene::protocol
