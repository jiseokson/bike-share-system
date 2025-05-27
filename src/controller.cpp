#include <algorithm>
#include "controller.h"

// 사용자 정보를 userCollection에 추가
User *SignUp::signup(std::string id, std::string password, std::string phone)
{
  return userCollection->addUser(id, password, phone);
}

// 사용자 ID/PW 확인 후 로그인 처리
User *Login::login(std::string id, std::string password)
{
  User *user = userCollection->getUserById(id);
  if (user->getPassword() == password)
    return userCollection->setLoginUser(user);
  return nullptr;
}

// 현재 로그인된 사용자 로그아웃 처리
User *Logout::logout()
{
  User *user = userCollection->getLoginUser();
  userCollection->unsetLoginUser();
  return user;
}

// 자전거 정보를 bikeCollection에 등록
Bike *RegisterBike::registerBike(std::string id, std::string name)
{
  return bikeCollection->addBike(id, name);
}

// 자전거 대여: 현재 로그인된 사용자가 해당 자전거를 대여함
Bike *RentalBike::rentalBike(std::string id)
{
  User *user = userCollection->getLoginUser();
  Bike *bike = bikeCollection->getBikeById(id);
  bikeCollection->setRentalBike(bike, user);
  return bike;
}

// 로그인한 사용자가 대여 중인 자전거 목록 조회
std::vector<Bike *> ViewRental::viewRentals()
{
  User *user = userCollection->getLoginUser();
  auto rentedBikes = bikeCollection->getRentedBikesByUser(user);
  std::sort(rentedBikes.begin(), rentedBikes.end(), [](auto *a, auto *b) -> bool
            { return a->getId() < b->getId(); });
  return rentedBikes;
}
