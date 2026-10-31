// Copyright 2018 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>

Complexo::Complexo() : img_(0), real_(0) {
}

Complexo::Complexo(double a) : img_(0), real_(a) {}

Complexo::Complexo(double a, double b) : img_(b), real_(a) {}

double Complexo::real() const {
  return real_;
}

double Complexo::imag() const {
  return img_;
}

bool Complexo::operator==(Complexo x) const {
    if ((x.imag() == img_) && (x.real() == real_)){
        return true;
    }
    return false;
}

void Complexo::operator=(Complexo x) {
  img_ = x.imag();
  real_ = x.real();
} 

double Complexo::modulo() const {
  double modulo = sqrt(pow(real_,2) + pow(img_,2));
  return modulo;
}

Complexo Complexo::conjugado() const {
  Complexo c = Complexo(real_,(-img_));
  return c;
}

Complexo Complexo::operator-() const {
  Complexo c = Complexo((-real_),(-img_));
  return c;
}

Complexo Complexo::inverso() const {
  Complexo i = Complexo((real_/(pow(real_,2) + pow(img_,2))),((-img_)/(pow(real_,2) + pow(img_,2))));    
  return i;
}

Complexo Complexo::operator+(Complexo y) const {
  Complexo s = Complexo(real_ + y.real(), img_ + y.imag());
  return s;
}

Complexo Complexo::operator-(Complexo y) const {
  Complexo s = Complexo(real_ - y.real(), img_ - y.imag());
  return s;
}

Complexo Complexo::operator*(Complexo y) const {
  Complexo p = Complexo(((real_ * y.real()) - (img_ * y.imag())) , ((real_ * y.imag()) + (img_ * y.real())));
  return p;
}

Complexo Complexo::operator/(Complexo y) const {
  return (*this) * y.inverso();
}
