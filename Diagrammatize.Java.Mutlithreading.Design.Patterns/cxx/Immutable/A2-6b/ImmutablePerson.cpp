#include "ImmutablePerson.hpp"
#include "MutablePerson.hpp"

ImmutablePerson::ImmutablePerson(const MutablePerson& person) {
    // 使用RAII自动管理锁
    auto lock = person.getLock();
    name = person.getName();
    address = person.getAddress();
    // 锁在离开作用域时自动释放
}
    
std::shared_ptr<MutablePerson> ImmutablePerson::getMutablePerson() const {
    return std::make_shared<MutablePerson>(*this);
}
