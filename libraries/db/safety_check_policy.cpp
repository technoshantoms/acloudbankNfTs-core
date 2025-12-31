#include <graphene/db/safety_check_policy.hpp>

namespace graphene { namespace db {

// Implement virtual destructors in .cpp file to give vtables a place to live
safety_check_policy::~safety_check_policy() = default;
null_safety_check::~null_safety_check() = default;
database_lock_safety_check::~database_lock_safety_check() = default;

} } // namespace graphene::db

