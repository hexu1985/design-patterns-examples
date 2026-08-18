#include "ImmutablePerson.hpp"
#include "MutablePerson.hpp"

ImmutablePerson::ImmutablePerson(const MutablePerson& person)
    : name(person.getName()), address(person.getAddress()){
}
    
std::shared_ptr<MutablePerson> ImmutablePerson::getMutablePerson() const {
    return std::make_shared<MutablePerson>(*this);
}
