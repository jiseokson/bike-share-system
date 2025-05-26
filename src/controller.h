#pragma once

#include <fstream>
#include "ui.h"
#include "entity.h"

// UI와 연결되는 기본 Controller 클래스
class Controller
{
  UI *ui;

public:
  // UI 객체와 연결하고 양방향 참조 설정
  Controller(UI *ui) : ui(ui)
  {
    ui->setController(this);
  }
};

// 회원가입 로직을 담당하는 컨트롤러
class SignUp : public Controller
{
  UserCollection *userCollection;

public:
  SignUp(UI *ui, UserCollection *userCollection)
      : Controller(ui), userCollection(userCollection) {}

  User *signup(std::string, std::string, std::string);
};

// 로그인 로직을 담당하는 컨트롤러
class Login : public Controller
{
  UserCollection *userCollection;

public:
  Login(UI *ui, UserCollection *userCollection)
      : Controller(ui), userCollection(userCollection) {}

  User *login(std::string, std::string);
};

// 로그아웃 로직을 담당하는 컨트롤러
class Logout : public Controller
{
  UserCollection *userCollection;

public:
  Logout(UI *ui, UserCollection *userCollection)
      : Controller(ui), userCollection(userCollection) {}

  User *logout();
};

// 자전거 등록 로직을 담당하는 컨트롤러
class RegisterBike : public Controller
{
  BikeCollection *bikeCollection;

public:
  RegisterBike(UI *ui, BikeCollection *bikeCollection)
      : Controller(ui), bikeCollection(bikeCollection) {}

  Bike *registerBike(std::string, std::string);
};

// 자전거 대여 로직을 담당하는 컨트롤러
class RentalBike : public Controller
{
  UserCollection *userCollection;
  BikeCollection *bikeCollection;

public:
  RentalBike(UI *ui, UserCollection *userCollection, BikeCollection *bikeCollection)
      : Controller(ui), userCollection(userCollection), bikeCollection(bikeCollection) {}

  Bike *rentalBike(std::string);
};

// 대여한 자전거 목록을 반환하는 컨트롤러
class ViewRental : public Controller
{
  UserCollection *userCollection;
  BikeCollection *bikeCollection;

public:
  ViewRental(UI *ui, UserCollection *userCollection, BikeCollection *bikeCollection)
      : Controller(ui), userCollection(userCollection), bikeCollection(bikeCollection) {}

  std::vector<Bike *> viewRentals();
};
