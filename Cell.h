#ifndef Cell_H
#define Cell_H
#include <string>
#include "Color.h"
#include "Date.h"

class Cell {
private:
  std::string m_value;
  Color m_color;
public:
  Cell();
  ~Cell();

  void setValue(const std::string& v);
  std::string getValue();
  int toInt();
  double toDouble();
  Date toDate();
  void reset();
};

#endif