#include "entity.h"

User *UserCollection::addUser(std::string id, std::string password, std::string phone)
{
  users.push_back(User(id, password, phone));
  return &users.back();
}

User *UserCollection::setLoginUser(User *user)
{
  loginUser = user;
  return loginUser;
}

void UserCollection::unsetLoginUser(User *user)
{
  loginUser = nullptr;
}

User *UserCollection::getUserById(std::string id)
{
  for (auto &user : users)
    if (user.getId() == id)
      return &user;
  return nullptr;
}

User *UserCollection::getLoginUser()
{
  return loginUser;
}

Bike *BikeCollection::addBike(std::string id, std::string name)
{
  bikes.push_back(Bike(id, name));
  return &bikes.back();
}

Bike *BikeCollection::setRentalBike(Bike *bike, User *user)
{
  bike->setRentedUser(user);
  rentedBikes.push_back(bike);
  return rentedBikes.back();
}

Bike *BikeCollection::getBikeById(std::string id)
{
  for (auto &bike : bikes)
    if (bike.getId() == id)
      return &bike;
  return nullptr;
}

std::vector<Bike *> BikeCollection::getRentedBikesByUser(User *user)
{
  std::vector<Bike *> results;

  for (auto rentedBike : rentedBikes)
    if (rentedBike->getRentedUser()->getId() == user->getId())
      results.push_back(rentedBike);

  return results;
}