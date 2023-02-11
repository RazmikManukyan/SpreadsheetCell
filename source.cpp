#include <iostream>
#include <string>
#include "Spreadsheet.h"
#include "Cell.h"
#include "Date.h"
#include "Color.h"

Spreadsheet::Spreadsheet(int row, int column) {
  Cell** c = new Cell*[row];
  for(int i = 0; i < column; ++i) {
    c[i] = new Cell[column];
  }
}

void Spreadsheet::setCellAt(int r, int c,const Cell& cl) {

}

Spreadsheet::~Spreadsheet() {
}

Cell Spreadsheet::getCellAt(int r, int c) {

}


