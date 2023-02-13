#include <iostream>
#include <string>
#include "Cell.h"
#include "Date.h"

Cell::Cell(const Cell& oth) 
:m_value(oth.m_value)
,m_color(oth.m_color)
{}

Cell::Cell(std::string str, Color c) {
  m_value = str;
  m_color = c;
}

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

void Cell::reset() {
  m_value = "";
}

