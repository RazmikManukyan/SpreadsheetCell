#ifndef Spreadsheet_H
#define Spreadsheet_H
#include <string>
#include "Cell.h"


class Spreadsheet {
public: 
  Spreadsheet(int, int);
  Spreadsheet(const Spreadsheet&);
  //Spreadsheet(Spreadsheet&&);
  ~Spreadsheet() {
    for (int i = 0; i < m_row; ++i) {
      delete[] m_cell[i];
    }
    delete[] m_cell;
    m_cell = nullptr;
  };

  Spreadsheet& operator=(const Spreadsheet&);
  //Spreadsheet& operator=(Spreadsheet&&);

  void setCellAt(int r, int c,const Cell& cl);
  void setCellAt(int r, int c,const std::string& cl);
  Cell getCellAt(int r, int c);
  void addRow(int r);
  void removeRow(int r);
  void addColumn(int c);
  void removeColumn(int c);
  void swapRow(int r1, int r2);
  void swapColumn(int c1, int c2);
  void cleanup();
  void print();
private:
  Cell** m_cell = nullptr;
  int m_row = 0;
  int m_column = 0;
  bool inRange (int, int) const;
};

#endif