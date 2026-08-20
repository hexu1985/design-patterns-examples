#include "MutablePerson.hpp"
#include "ImmutablePerson.hpp"

MutablePerson::MutablePerson(const ImmutablePerson& person)
    : name(person.getName()), address(person.getAddress()) {
}

std::shared_ptr<ImmutablePerson> MutablePerson::getImmutablePerson() const {
    return std::make_shared<ImmutablePerson>(*this);
}
