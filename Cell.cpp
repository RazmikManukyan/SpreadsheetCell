#include <iostream>
#include <string>
#include "Cell.h"
#include "Date.h"


void Cell::setValue(const std::string& str) {
  m_value = str;
}

std::string Cell::getValue() {
  return this->m_value;
}

int Cell::toInt(){
  return stoi(this->m_value);
}

double Cell::toDouble() {
  return stod(this->m_value);
}

Date Cell::toDate() {
}


