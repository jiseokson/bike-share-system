#include <fstream>

#include <iostream>

#include "ui.h"
#include "entity.h"
#include "controller.h"

#define INPUT_FILENAME "input.txt"
#define OUTPUT_FILENAME "output.txt"

int main()
{
  std::ifstream fin(INPUT_FILENAME);
  std::ofstream fout(OUTPUT_FILENAME);

  UserCollection *userCollection = new UserCollection;
  BikeCollection *bikeCollection = new BikeCollection;

  SignUpUI *signUpUI = new SignUpUI(fin, fout);
  LoginUI *loginUI = new LoginUI(fin, fout);
  LogoutUI *logoutUI = new LogoutUI(fin, fout);
  RegisterBikeUI *registerBikeUI = new RegisterBikeUI(fin, fout);
  RentalBikeUI *rentalBikeUI = new RentalBikeUI(fin, fout);
  ViewRentalUI *viewRentalUI = new ViewRentalUI(fin, fout);

  SignUp *signUp = new SignUp(signUpUI, userCollection);
  Login *login = new Login(loginUI, userCollection);
  Logout *logout = new Logout(logoutUI, userCollection);
  RegisterBike *registerBike = new RegisterBike(registerBikeUI, bikeCollection);
  RentalBike *rentalBike = new RentalBike(rentalBikeUI, userCollection, bikeCollection);
  ViewRental *viewRental = new ViewRental(viewRentalUI, userCollection, bikeCollection);

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

  // clean up all used resources here
}
