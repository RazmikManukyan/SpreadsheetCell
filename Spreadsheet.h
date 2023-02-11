#ifndef Spreadsheet_H
#define Spreadsheet_H
#include <string>
#include "Cell.h"


class Spreadsheet {
private:
  Cell** m_cell;
public: 
  Spreadsheet(int , int, const Cell&);
  Spreadsheet(const Spreadsheet&);
  Spreadsheet(Spreadsheet&&) noexcept;
  ~Spreadsheet();

  Spreadsheet& operator=(const Spreadsheet&);
  Spreadsheet& operator=(Spreadsheet&&) noexcept;

  void setCellAt(int r, int c,const Cell& cl);
  void setCellAt(int r, int c,const std::string& cl);
  Cell getCellAt(int r, int c);
  void addRow(int r);
  void removeRow(int r);
  void addColumn(int c);
  void removeColumn(int c);
  void swapRow(int r1, int r2);
  void swapColumn(int c1, int c2);
};

#endif