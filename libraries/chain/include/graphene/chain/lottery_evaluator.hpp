#pragma once
#include <graphene/protocol/operations.hpp>
#include <graphene/chain/evaluator.hpp>
#include <graphene/chain/database.hpp>

namespace graphene { namespace chain {

   class ticket_purchase_evaluator : public evaluator<ticket_purchase_evaluator>
   {
      public:
         typedef ticket_purchase_operation operation_type;

         void_result do_evaluate( const ticket_purchase_operation& o );
         void_result do_apply( const ticket_purchase_operation& o );

         const asset_object* lottery;
         const asset_dynamic_data_object* asset_dynamic_data;
   };

   class lottery_reward_evaluator : public evaluator<lottery_reward_evaluator>
   {
      public:
         typedef lottery_reward_operation operation_type;

         void_result do_evaluate( const lottery_reward_operation& o );
         void_result do_apply( const lottery_reward_operation& o );

         const asset_object* lottery;
         const asset_dynamic_data_object* asset_dynamic_data;
   };

   class lottery_end_evaluator : public evaluator<lottery_end_evaluator>
   {
      public:
         typedef lottery_end_operation operation_type;

         void_result do_evaluate( const lottery_end_operation& o );
         void_result do_apply( const lottery_end_operation& o );

         const asset_object* lottery;
         const asset_dynamic_data_object* asset_dynamic_data;
   };
   
   class sweeps_vesting_claim_evaluator : public evaluator<sweeps_vesting_claim_evaluator>
   {
      public:
         typedef sweeps_vesting_claim_operation operation_type;

         void_result do_evaluate( const sweeps_vesting_claim_operation& o );
         void_result do_apply( const sweeps_vesting_claim_operation& o );

//         const asset_object* lottery;
//         const asset_dynamic_data_object* asset_dynamic_data;
   };

} } // graphene::chain
