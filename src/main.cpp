#include <fstream>

#include "ui.h"
#include "entity.h"
#include "controller.h"

#define INPUT_FILENAME "input.txt"
#define OUTPUT_FILENAME "output.txt"

int main()
{
  std::ifstream fin(INPUT_FILENAME);
  std::ofstream fout(OUTPUT_FILENAME);

  // 사용자 및 자전거 정보를 관리하는 컬렉션 객체 생성
  UserCollection *userCollection = new UserCollection;
  BikeCollection *bikeCollection = new BikeCollection;

  // UI 인스턴스 생성
  SignUpUI *signUpUI = new SignUpUI(fin, fout);
  LoginUI *loginUI = new LoginUI(fin, fout);
  LogoutUI *logoutUI = new LogoutUI(fin, fout);
  RegisterBikeUI *registerBikeUI = new RegisterBikeUI(fin, fout);
  RentalBikeUI *rentalBikeUI = new RentalBikeUI(fin, fout);
  ViewRentalUI *viewRentalUI = new ViewRentalUI(fin, fout);

  // 컨트롤러 인스턴스 생성 및 UI에 연결
  SignUp *signUp = new SignUp(signUpUI, userCollection);
  Login *login = new Login(loginUI, userCollection);
  Logout *logout = new Logout(logoutUI, userCollection);
  RegisterBike *registerBike = new RegisterBike(registerBikeUI, bikeCollection);
  RentalBike *rentalBike = new RentalBike(rentalBikeUI, userCollection, bikeCollection);
  ViewRental *viewRental = new ViewRental(viewRentalUI, userCollection, bikeCollection);

  // 메뉴 입력을 처리하고 적절한 UI 동작을 호출
  while (true)
  {
    int menu1, menu2;
    fin >> menu1 >> menu2;

    if (menu1 == 1 && menu2 == 1)
      signUpUI->interact();

    else if (menu1 == 2 && menu2 == 1)
      loginUI->interact();

    else if (menu1 == 2 && menu2 == 2)
      logoutUI->interact();

    else if (menu1 == 3 && menu2 == 1)
      registerBikeUI->interact();

    else if (menu1 == 4 && menu2 == 1)
      rentalBikeUI->interact();

    else if (menu1 == 5 && menu2 == 1)
      viewRentalUI->interact();

    else if (menu1 == 6 && menu2 == 1)
    {
      fout << "6.1. 종료";
      break;
    }
  }

  // 파일 스트림 종료
  fin.close();
  fout.close();

  // 동적 할당된 객체 삭제
  delete userCollection;
  delete bikeCollection;

  delete signUpUI;
  delete loginUI;
  delete logoutUI;
  delete registerBikeUI;
  delete rentalBikeUI;
  delete viewRentalUI;

  delete signUp;
  delete login;
  delete logout;
  delete registerBike;
  delete rentalBike;
  delete viewRental;
}
