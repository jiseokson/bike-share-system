#pragma once

#include <fstream>

class Controller;

// UI 클래스는 사용자 인터페이스의 기반 클래스 역할을 하며
// 입력 스트림(fin)과 출력 스트림(fout)을 관리한다.
class UI
{
protected:
  std::ifstream &fin;
  std::ofstream &fout;
  Controller *controller;

public:
  // 생성자에서 입출력 스트림을 초기화
  UI(std::ifstream &fin, std::ofstream &fout) : fin(fin), fout(fout) {}

  // 컨트롤러 객체를 설정
  void setController(Controller *controller) { this->controller = controller; };

  // UI 동작 시작 함수
  void startUI() {}

  // 실제 인터페이스 동작을 구현할 순수 가상 함수
  virtual void interact() = 0;
};

// 회원가입 기능을 처리하는 UI 클래스
class SignUpUI : public UI
{
public:
  SignUpUI(std::ifstream &fin, std::ofstream &fout) : UI(fin, fout) {}
  void interact() override;
};

// 로그인 기능을 처리하는 UI 클래스
class LoginUI : public UI
{
public:
  LoginUI(std::ifstream &fin, std::ofstream &fout) : UI(fin, fout) {}
  void interact() override;
};

// 로그아웃 기능을 처리하는 UI 클래스
class LogoutUI : public UI
{
public:
  LogoutUI(std::ifstream &fin, std::ofstream &fout) : UI(fin, fout) {}
  void interact() override;
};

// 자전거 등록 기능을 처리하는 UI 클래스
class RegisterBikeUI : public UI
{
public:
  RegisterBikeUI(std::ifstream &fin, std::ofstream &fout) : UI(fin, fout) {}
  void interact() override;
};

// 자전거 대여 기능을 처리하는 UI 클래스
class RentalBikeUI : public UI
{
public:
  RentalBikeUI(std::ifstream &fin, std::ofstream &fout) : UI(fin, fout) {}
  void interact() override;
};

// 대여한 자전거 목록을 출력하는 UI 클래스
class ViewRentalUI : public UI
{
public:
  ViewRentalUI(std::ifstream &fin, std::ofstream &fout) : UI(fin, fout) {}
  void interact() override;
};

class ExitUI : public UI
{
public:
  ExitUI(std::ifstream &fin, std::ofstream &fout) : UI(fin, fout) {}
  void interact() override;
};
