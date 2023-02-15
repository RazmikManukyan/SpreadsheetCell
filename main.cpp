#include <iostream>
#include "Spreadsheet.h"
#include "Cell.h"
#include "Date.h"

int main() {
  Spreadsheet sh (3, 3);
  Cell cl1, cl2, cl3;
  cl1.setValue("100");
  cl2.setValue("200");
  cl3.setValue("300");
  sh.setCellAt(0, 0, cl1);
  sh.setCellAt(0, 1, "0");
  sh.setCellAt(0, 2, "0");
  sh.setCellAt(1, 1, cl2);
  sh.setCellAt(1, 0, "0");
  sh.setCellAt(1, 2, "0");
  sh.setCellAt(2, 2, cl3);
  sh.setCellAt(2, 0, "0");
  sh.setCellAt(2, 1, "0");
  // sh.addRow(3);
  // sh.addRow(1);
  //sh.addRow(0);
  //sh.addColumn(0);
  //sh.removeRow(1);
  //sh.removeColumn(1);
  //sh.swapRow(0, 1);
  sh.swapColumn(0, 2);
  sh.print();
}