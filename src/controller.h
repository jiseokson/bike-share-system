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
      : Controller(ui) {}
};

class Login
{
};

class Logout
{
};

class RentalBike
{
};

class ViewRental
{
};

class RegisterBike
{
};