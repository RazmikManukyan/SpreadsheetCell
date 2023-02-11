#include <iostream>
#include <string>
#include "Spreadsheet.h"
#include "Cell.h"
#include "Date.h"
#include "Color.h"

void testSetValue() {
  Cell c;
  if(c.toInt() != 41) 
    std::cout << "Test Failed!";
  else 
    std::cout << "Test Passed";
  

}

