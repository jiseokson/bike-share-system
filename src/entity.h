#pragma once

#include <string>
#include <vector>

class User
{
  std::string id;
  std::string password;
  std::string phone;

public:
  User(std::string id, std::string password, std::string phone)
      : id(id), password(password), phone(phone) {}

  std::string getId() const
  {
    return id;
  }

  std::string getPassword() const
  {
    return password;
  }

  std::string getPhone() const
  {
    return phone;
  }
};

class Bike
{
  std::string id;
  std::string name;
  User *rentedUser;

public:
  Bike(std::string id, std::string name)
      : id(id), name(name), rentedUser(nullptr) {}

  std::string getId() const
  {
    return id;
  }

  std::string getName() const
  {
    return name;
  }

  User *setRentedUser(User *user)
  {
    rentedUser = user;
    return rentedUser;
  }

  User *getRentedUser() const
  {
    return rentedUser;
  }
};

class UserCollection
{
  std::vector<User> users;
  User *loginUser;

public:
  UserCollection() : users{User("admin", "admin", "")}, loginUser(nullptr) {}

  User *addUser(std::string, std::string, std::string);
  User *setLoginUser(User *);
  void unsetLoginUser(User *);

  User *getUserById(std::string);
  User *getLoginUser();
};

class BikeCollection
{
  std::vector<Bike> bikes;
  std::vector<Bike *> rentedBikes;

public:
  Bike *addBike(std::string, std::string);
  Bike *setRentalBike(Bike *, User *);

  Bike *getBikeById(std::string);
  std::vector<Bike *> getRentedBikesByUser(User *);
};
