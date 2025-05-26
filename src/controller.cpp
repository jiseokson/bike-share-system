#include "controller.h"

User *SignUp::signup(std::string id, std::string password, std::string phone)
{
  return userCollection->addUser(id, password, phone);
}

User *Login::login(std::string id, std::string password)
{
  User *user = userCollection->getUserById(id);
  if (user->getPassword() == password)
    return userCollection->setLoginUser(user);
  return nullptr;
}

User *Logout::logout()
{
  User *user = userCollection->getLoginUser();
  userCollection->unsetLoginUser();
  return user;
}

Bike *RegisterBike::registerBike(std::string id, std::string name)
{
  return bikeCollection->addBike(id, name);
}

Bike *RentalBike::rentalBike(std::string id)
{
  User *user = userCollection->getLoginUser();
  Bike *bike = bikeCollection->getBikeById(id);
  bikeCollection->setRentalBike(bike, user);
  return bike;
}

std::vector<Bike *> ViewRental::viewRentals()
{
  User *user = userCollection->getLoginUser();
  return bikeCollection->getRentedBikesByUser(user);
}
