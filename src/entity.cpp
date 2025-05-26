#include "entity.h"

void *UserCollection::addUser(User *)
{
}

void UserCollection::setLoginUser(User *)
{
}

void UserCollection::unsetLoginUser(User *)
{
}

User *UserCollection::getUserById(std::string) const
{
}

User *UserCollection::getLoginUser() const
{
}

void BikeCollection::addBike()
{
}

void BikeCollection::setRentalBike(Bike *)
{
}

Bike *BikeCollection::getBikeById() const
{
}

std::vector<Bike *> BikeCollection::getRentedBikesByUser(User *) const
{
}