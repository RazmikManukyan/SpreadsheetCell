#include <iostream>
#include "Cell.h"
#include "Spreadsheet.h"

void Spreadsheet::print() {
    for(int i = 0; i < m_row; ++i) {
      for(int j = 0; j < m_column; ++j) {
        std::cout << m_cell[i][j].getValue() << " ";
      }
      std::cout << std::endl;
    }
  }

Spreadsheet::Spreadsheet(const Spreadsheet& oth) 
:m_row(oth.m_row), m_column(oth.m_column)
{
  for(int i = 0; i < m_row; ++i) {
    for(int j = 0; j < m_column; ++j) {
      m_cell[i][j] = oth.m_cell[i][j];
    }
  }
}

bool Spreadsheet::inRange(int x, int y) const {
  if(x < 0 && x > y - 1) {
    return false;
  }
  return true;
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& oth) {
  if(this == &oth) {
    return *this;
  }

  for(int i = 0; i < m_row; ++i){
    delete[] m_cell[i];
  }
  delete[] m_cell;
  m_cell = nullptr;

  m_row = oth.m_row;
  m_column = oth.m_column;

  for(int i = 0; i < m_row; ++i) {
    for(int j = 0; i < m_column; ++j) {
      m_cell[i][j] = oth.m_cell[i][j];
    }
  }

  return *this;
}


void Spreadsheet::setCellAt(int r, int c,const Cell& cl) {
  if(!inRange(r, m_row)) {
    throw "Invalid argument for Row!";
  }
  if(!inRange(c, m_column)) {
    throw "Invalid argument for Column";
  }
  m_cell[r][c] = cl;
}

void Spreadsheet::setCellAt(int r, int c,const std::string& str) {
  if(!inRange(r, m_row)) {
    throw "Invalid argument for Row!";
  }
  if(!inRange(c, m_column)) {
    throw "Invalid argument for Column";
  }
  m_cell[r][c].setValue(str);
}

Cell Spreadsheet::getCellAt(int r, int c) {
  if(!inRange(r, m_row)) {
    throw "Invalid argument for Row!";
  }
  if(!inRange(c, m_column)) {
    throw "Invalid argument for Column";
  }
  return m_cell[r][c];
}

void Spreadsheet::cleanup() noexcept{
  for(int i {0}; i < m_row; ++i) {
    delete[] m_cell[i];
  }
  delete[] m_cell;
  m_cell = nullptr;
}

void Spreadsheet::addRow(int r) {
  if(r < 0 && r >= m_row) {
    throw "Invaild argument";
  }

  if(r == 0) {
    Cell** tmp = new Cell*[m_row + 1];
    for(int i = 0; i < m_column; ++i) {
      tmp[i] = new Cell[m_column];
    }
    
    for(int i = 0; i < m_row; ++i) {
      for(int j = 0; i < m_column; ++j) {
        tmp[i + 1][j] = m_cell[i][j];
      } 
    }

    m_row += 1;
    m_cell = tmp;
    tmp = nullptr;
  }

  if(r > 0 && r < m_row) {
    Cell** tmp = new Cell*[m_row + 1];
    for(int i = 0; i < m_column; ++i) {
      tmp[i] = new Cell[m_column];
    }

    for(int i = 0; i < r; ++i) {
      for(int j = 0; i < m_column; ++j){
        tmp[i][j] = m_cell[i][j];
      }
    }

    for(int i = r; i < m_row; ++i) {
      for(int j = 0; j < m_column; ++j) {
        tmp[i + 1][j] = m_cell[i][j]; 
      }
    }

    m_row += 1;
    m_cell = tmp;
    tmp = nullptr;
  }

  if(r == m_row - 1) {
    Cell** tmp = new Cell*[m_row + 1];
    for(int i = 0; i < m_column; ++i) {
      tmp[i] = new Cell[m_column];
    }

    for(int i = 0; i < m_row; ++i) {
      for(int j = 0; i < m_column; ++j) {
        tmp[i][j] = m_cell[i][j];
      }
    }

    m_row += 1;
    m_cell = tmp;
    tmp = nullptr;
    
  }

}