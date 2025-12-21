
#pragma once
#include <graphene/protocol/base.hpp>

namespace graphene { namespace protocol {

   /**
    * @ingroup operations
    */
   struct ticket_purchase_operation : public base_operation
   {
      struct fee_parameters_type { 
         uint64_t fee = 0;
      };

      asset                   fee;
      // from what lottery is ticket
      asset_id_type           lottery;
      account_id_type         buyer;
      // count of tickets to buy
      uint64_t                tickets_to_buy;
      // amount that can spent
      asset                   amount;
      
      extensions_type         extensions;

      account_id_type fee_payer()const { return buyer; }
      void            validate()const;
      share_type      calculate_fee( const fee_parameters_type& k )const;
   };

   typedef static_variant<uint64_t, void_t> ticket_num;

   /**
    * @ingroup operations
    */
   struct lottery_reward_operation : public base_operation
   {
      struct fee_parameters_type { 
         uint64_t fee = 0;
      };

      asset                   fee;
      // from what lottery is ticket
      asset_id_type           lottery;
      // winner account
      account_id_type         winner;
      // amount that won 
      asset                   amount;
      // percentage of jackpot that user won
      uint16_t                win_percentage;
      // true if recieved from benefators section of lottery; false otherwise
      bool                    is_benefactor_reward;

      ticket_num              winner_ticket_id;

      account_id_type fee_payer()const { return account_id_type(); }
      void            validate()const {};
      share_type      calculate_fee( const fee_parameters_type& k )const { return k.fee; };
   };

   /**
    * @ingroup operations
    */
   struct lottery_end_operation : public base_operation
   {
      struct fee_parameters_type {
         uint64_t fee = 0;
      };

      asset                   fee;
      // from what lottery is ticket
      asset_id_type           lottery;

      map<account_id_type, vector< uint16_t> > participants;
      
      extensions_type               extensions;

      account_id_type fee_payer()const { return account_id_type(); }
      void            validate() const {}
      share_type      calculate_fee( const fee_parameters_type& k )const { return k.fee; } 
   };

} } // graphene::protocol

FC_REFLECT( graphene::protocol::ticket_purchase_operation,
            (fee)
            (lottery)
            (buyer)
            (tickets_to_buy)
            (amount)
            (extensions)
          )
FC_REFLECT( graphene::protocol::ticket_purchase_operation::fee_parameters_type, (fee) )

FC_REFLECT_TYPENAME( graphene::protocol::ticket_num )
FC_REFLECT( graphene::protocol::lottery_reward_operation,
            (fee)
            (lottery)
            (winner)
            (amount)
            (win_percentage)
            (is_benefactor_reward)
            (winner_ticket_id)
          )
FC_REFLECT( graphene::protocol::lottery_reward_operation::fee_parameters_type, (fee) )


FC_REFLECT( graphene::protocol::lottery_end_operation,
            (fee)
            (lottery)
            (participants)
            (extensions)
          )
FC_REFLECT( graphene::protocol::lottery_end_operation::fee_parameters_type, (fee) )
