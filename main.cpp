#include <iostream>
#include "Spreadsheet.h"
#include "Cell.h"
#include "Date.h"

int main() {
  Spreadsheet sh (3, 3);
  Cell cl;
  cl.setValue("100");
  sh.setCellAt(0, 0, cl);
  sh.print();
}