#pragma once

#include <fstream>
#include "ui.h"
#include "entity.h"

class Controller
{
  UI *ui;

public:
  Controller(UI *ui) : ui(ui)
  {
    ui->set_controller(this);
    ui->startUI();
  }
};

class SignUp : public Controller
{
  UserCollection *userCollection;

public:
  SignUp(UI *ui, UserCollection *userCollection)
      : Controller(ui), userCollection(userCollection) {}

  User *signup(std::string, std::string, std::string);
};

class Login : public Controller
{
  UserCollection *userCollection;

public:
  Login(UI *ui, UserCollection *userCollection)
      : Controller(ui), userCollection(userCollection) {}

  User *login(std::string, std::string);
};

class Logout : public Controller
{
  UserCollection *userCollection;

public:
  Logout(UI *ui, UserCollection *userCollection)
      : Controller(ui), userCollection(userCollection) {}

  User *logout();
};

class RegisterBike : public Controller
{
  BikeCollection *bikeCollection;

public:
  RegisterBike(UI *ui, BikeCollection *bikeCollection)
      : Controller(ui), bikeCollection(bikeCollection) {}

  Bike *registerBike(std::string, std::string);
};

class RentalBike : public Controller
{
  UserCollection *userCollection;
  BikeCollection *bikeCollection;

public:
  RentalBike(UI *ui, UserCollection *userCollection, BikeCollection *bikeCollection)
      : Controller(ui), userCollection(userCollection), bikeCollection(bikeCollection) {}

  Bike *rentalBike(std::string);
};

class ViewRental : public Controller
{
  UserCollection *userCollection;
  BikeCollection *bikeCollection;

public:
  ViewRental(UI *ui, UserCollection *userCollection, BikeCollection *bikeCollection)
      : Controller(ui), userCollection(userCollection), bikeCollection(bikeCollection) {}

  std::vector<Bike *> viewRentals();
};
