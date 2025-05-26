#pragma once

#include <fstream>

class Controller;

class UI
{
protected:
  std::ifstream &fin;
  std::ofstream &fout;

  Controller *controller;

public:
  UI(std::ifstream &fin, std::ofstream &fout) : fin(fin), fout(fout) {}

  void set_controller(Controller *controller) { this->controller = controller; };
  void startUI() {}
  virtual void interact() = 0;
};

class SignUpUI : public UI
{
public:
  SignUpUI(std::ifstream &fin, std::ofstream &fout) : UI(fin, fout) {}

  void interact() override;
};

class LoginUI : public UI
{
public:
  LoginUI(std::ifstream &fin, std::ofstream &fout) : UI(fin, fout) {}

  void interact() override;
};

class LogoutUI : public UI
{
public:
  LogoutUI(std::ifstream &fin, std::ofstream &fout) : UI(fin, fout) {}

  void interact() override;
};

class RegisterBikeUI : public UI
{
public:
  RegisterBikeUI(std::ifstream &fin, std::ofstream &fout) : UI(fin, fout) {}

  void interact() override;
};

class RentalBikeUI : public UI
{
public:
  RentalBikeUI(std::ifstream &fin, std::ofstream &fout) : UI(fin, fout) {}

  void interact() override;
};

class ViewRentalUI : public UI
{
public:
  ViewRentalUI(std::ifstream &fin, std::ofstream &fout) : UI(fin, fout) {}

  void interact() override;
};
