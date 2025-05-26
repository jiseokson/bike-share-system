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

  UserCollection *userCollection = new UserCollection;

  SignUpUI *signUpUI = new SignUpUI(fin, fout);

  SignUp *signUp = new SignUp(signUpUI, userCollection);

  signUpUI->interact();
}
