#include "ui.h"
#include "controller.h"

// 회원가입 UI 로직: 입력 받은 정보로 회원 가입 수행
void SignUpUI::interact()
{
  std::string id, password, phone;
  fin >> id >> password >> phone;

  User *user = ((SignUp *)controller)->signup(id, password, phone);

  fout << "1.1. 회원가입" << std::endl;
  fout << "> " << user->getId() << ' ' << user->getPassword() << ' ' << user->getPhone() << std::endl;
  fout << std::endl;
}

// 로그인 UI 로직: 입력 받은 정보로 로그인 수행
void LoginUI::interact()
{
  std::string id, password;
  fin >> id >> password;

  User *user = ((Login *)controller)->login(id, password);

  fout << "2.1. 로그인" << std::endl;
  fout << "> " << user->getId() << ' ' << user->getPassword() << std::endl;
  fout << std::endl;
}

// 로그아웃 UI 로직: 현재 로그인한 사용자 로그아웃
void LogoutUI::interact()
{
  User *user = ((Logout *)controller)->logout();

  fout << "2.2. 로그아웃" << std::endl;
  fout << "> " << user->getId() << std::endl;
  fout << std::endl;
}

// 자전거 등록 UI 로직: 입력 받은 정보로 자전거 등록
void RegisterBikeUI::interact()
{
  std::string id, name;
  fin >> id >> name;

  Bike *bike = ((RegisterBike *)controller)->registerBike(id, name);

  fout << "3.1. 자전거 등록" << std::endl;
  fout << "> " << bike->getId() << ' ' << bike->getName() << std::endl;
  fout << std::endl;
}

// 자전거 대여 UI 로직: 입력 받은 자전거 ID로 대여 처리
void RentalBikeUI::interact()
{
  std::string id;
  fin >> id;

  Bike *bike = ((RentalBike *)controller)->rentalBike(id);

  fout << "4.1. 자전거 대여" << std::endl;
  fout << "> " << bike->getId() << ' ' << bike->getName() << std::endl;
  fout << std::endl;
}

// 대여한 자전거 목록을 출력하는 UI 로직
void ViewRentalUI::interact()
{
  std::vector<Bike *> rentedBikes = ((ViewRental *)controller)->viewRentals();

  fout << "5.1. 자전거 대여 리스트" << std::endl;
  for (auto bike : rentedBikes)
    fout << "> " << bike->getId() << ' ' << bike->getName() << std::endl;
  fout << std::endl;
}

void ExitUI::interact()
{
  ((Exit *)controller)->exit();
  fout << "6.1. 종료";
}
