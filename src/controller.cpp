#include "controller.h"

User *SignUp::signup(std::string, std::string, std::string)
{
  return new User("TEST_ID", "TEST_PASSWORD", "01011112222");
}

User *Login::login(std::string, std::string)
{
  return new User("TEST_ID", "TEST_PASSWORD", "01011112222");
}

User *Logout::logout()
{
  return new User("TEST_ID", "TEST_PASSWORD", "01011112222");
}

Bike *RegisterBike::registerBike(std::string id, std::string name)
{
  return new Bike(id, name);
}

Bike *RentalBike::rentalBike(std::string id)
{
  return new Bike("TEST_BIKE_ID", "TEST_BIKE_NAME");
}

std::vector<Bike *> ViewRental::viewRentals()
{
  return std::vector<Bike *>{new Bike("TEST_BIKE_ID", "TEST_BIKE_NAME")};
}
