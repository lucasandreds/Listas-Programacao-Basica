#include "usuario.hpp"

Usuario::Usuario(const std::string& login, const std::string& password) {
    this->login = login;
    this->password = password;
  // TODO: Implemente este metodo
}

std::string Usuario::getLogin() const {
  // TODO: Implemente este metodo
  return login;
}

std::string Usuario::getPassword() const {
  // TODO: Implemente este metodo
  return password;
}

void Usuario::setPassword(const std::string& password) {
  // TODO: Implemente este metodo
  this->password = password;
}

void Usuario::setLogin(const std::string& login) {
  // TODO: Implemente este metodo
  this->login = login;
}