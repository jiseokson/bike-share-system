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

public:
  Bike(std::string id, std::string name)
      : id(id), name(name) {}

  std::string getId() const
  {
    return id;
  }

  std::string getName() const
  {
    return name;
  }
};

class UserCollection
{
  std::vector<User *> users;

public:
  void *addUser(User *);
  void setLoginUser(User *);
  void unsetLoginUser(User *);

  User *getUserById(std::string) const;
  User *getLoginUser() const;
};

class BikeCollection
{
  std::vector<Bike *> bikes;
  std::vector<Bike *> rentedBikes;

public:
  void addBike();
  void setRentalBike(Bike *);

  Bike *getBikeById() const;
  std::vector<Bike *> getRentedBikesByUser(User *) const;
};
