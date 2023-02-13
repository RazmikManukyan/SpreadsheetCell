#ifndef Cell_H
#define Cell_H
#include <string>
#include "Date.h"

enum class Color {read, blue, green};


class Cell {
public:
  Cell();
  Cell(std::string, Color);
  Cell(const Cell&);
  

  void setValue(const std::string&);
  std::string getValue();
  int toInt();
  double toDouble();
  Date toDate();
  void reset();
private:
  std::string m_value;
  Color m_color;
};

#endif