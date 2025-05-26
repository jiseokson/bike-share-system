#include "entity.h"

// 새로운 사용자 추가 및 해당 객체 반환
User *UserCollection::addUser(std::string id, std::string password, std::string phone)
{
  users.push_back(User(id, password, phone));
  return &users.back();
}

// 로그인 사용자 설정
User *UserCollection::setLoginUser(User *user)
{
  loginUser = user;
  return loginUser;
}

// 로그인 사용자 해제
void UserCollection::unsetLoginUser()
{
  loginUser = nullptr;
}

// ID에 해당하는 사용자 검색
User *UserCollection::getUserById(std::string id)
{
  for (auto &user : users)
    if (user.getId() == id)
      return &user;
  return nullptr;
}

// 현재 로그인한 사용자 반환
User *UserCollection::getLoginUser()
{
  return loginUser;
}

// 자전거 등록 및 해당 객체 반환
Bike *BikeCollection::addBike(std::string id, std::string name)
{
  bikes.push_back(Bike(id, name));
  return &bikes.back();
}

// 자전거를 사용자에게 대여 처리
Bike *BikeCollection::setRentalBike(Bike *bike, User *user)
{
  bike->setRentedUser(user);
  rentedBikes.push_back(bike);
  return rentedBikes.back();
}

// ID에 해당하는 자전거 검색
Bike *BikeCollection::getBikeById(std::string id)
{
  for (auto &bike : bikes)
    if (bike.getId() == id)
      return &bike;
  return nullptr;
}

// 특정 사용자에 의해 대여된 자전거 목록 반환
std::vector<Bike *> BikeCollection::getRentedBikesByUser(User *user)
{
  std::vector<Bike *> results;

  for (auto rentedBike : rentedBikes)
    if (rentedBike->getRentedUser()->getId() == user->getId())
      results.push_back(rentedBike);

  return results;
}
