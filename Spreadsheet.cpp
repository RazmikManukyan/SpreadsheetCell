#include <iostream>
#include "Cell.h"
#include "Spreadsheet.h"

Spreadsheet::Spreadsheet(int row, int column) 
:m_row(row)
,m_column(column) 
{
  m_cell = new Cell*[m_row];
  for(int i = 0; i < m_row; ++i) {
    m_cell[i] = new Cell[m_column];
  }
};

void Spreadsheet::print() {
  for(int i = 0; i < m_row; ++i) {
    for(int j = 0; j < m_column; ++j) {
      std::cout << m_cell[i][j].getValue() << " ";
    }
    std::cout << std::endl;
  }
}

Spreadsheet::Spreadsheet(const Spreadsheet& oth) 
:m_row(oth.m_row)
,m_column(oth.m_column)
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

void Spreadsheet::cleanup() {
  for(int i {0}; i < m_row; ++i) {
    delete[] m_cell[i];
  }
  delete[] m_cell;
  m_cell = nullptr;
}

void Spreadsheet::addRow(int r) {
  if(r < 0 && r >= m_row) {
    throw std::invalid_argument("Invalid argument");
  }

  if(r == 0) {
    Cell** tmp = new Cell*[m_row + 1];
    for(int i = 0; i < m_row + 1; ++i) {
      tmp[i] = new Cell[m_column];
    }
    
    for(int j = 0; j < m_column; ++j) {
      tmp[0][j] = Cell("0", Color::white);
    }
    
    for(int i = 1; i < m_row + 1; ++i) {
      for(int j = 0; j < m_column; ++j) {
        tmp[i][j] = m_cell[i - 1][j];
      } 
    }

    for(int i = 0; i < m_row; ++i) {
      delete[] m_cell[i];
    }
    delete[] m_cell;
    m_cell = tmp;
    m_row += 1;

  }

  if (r > 0 && r < m_row) {
    Cell** tmp = new Cell*[m_row + 1];
    for (int i = 0; i < m_row + 1; ++i) {
      tmp[i] = new Cell[m_column];
    }

    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < m_column; ++j) {
        tmp[i][j] = m_cell[i][j];
      }
    }

    for (int j = 0; j < m_column; ++j) {
      tmp[r][j] = Cell("0", Color::white);
    }

    for (int i = r + 1; i < m_row + 1; ++i) {
      for (int j = 0; j < m_column; ++j) {
        tmp[i][j] = m_cell[i - 1][j]; 
      }
    }

    for(int i = 0; i < m_row; ++i) {
      delete[] m_cell[i];
    }
    delete[] m_cell;
    m_cell = tmp;
    tmp = nullptr;
    m_row += 1;
  }

  if(r == m_row) {
    Cell** tmp = new Cell*[m_row + 1];
    for(int i = 0; i < m_row + 1; ++i) {
      tmp[i] = new Cell[m_column];
    }

    for(int i = 0; i < m_row; ++i) {
      for(int j = 0; j < m_column; ++j) {
        tmp[i][j] = m_cell[i][j];
      }
    }
    
    for(int j = 0; j < m_column; ++j) {
      tmp[r][j] = Cell("0", Color::white);
    }

    for(int i = 0; i < m_row; ++i) {
      delete[] m_cell[i];
    }
    delete[] m_cell;
    m_cell = tmp;
    tmp = nullptr;
    m_row += 1;
  }
}

void Spreadsheet::removeRow(int r) {
  if(r < 0 && r >= m_row) {
    throw std::invalid_argument("Invalid argument");
  }

  if(r == 0) {
    Cell** tmp = new Cell*[m_row - 1];
    for(int i = 0; i < m_row - 1; ++i) {
      tmp[i] = new Cell[m_column];
    }

    for(int i = 1; i < m_row; ++i) {
      for(int j = 0; j < m_column; ++j) {
        tmp[i - 1][j] = m_cell[i][j];
      }
    }

    for(int i = 0; i < m_row; ++i) {
      delete[] m_cell[i];
    }
    delete[] m_cell;
    m_cell = tmp;
    m_row -= 1;
  }

  if(r > 0 && r < m_row) {
    Cell** tmp = new Cell*[m_row - 1];
    for(int i = 0; i < m_row - 1; ++i) {
      tmp[i] = new Cell[m_column];
    }

    for(int i = 0; i < r; ++i) {
      for(int j = 0; j < m_column; ++j) {
        tmp[i][j] = m_cell[i][j];
      }
    }

    for(int i = r + 1; i < m_row; ++i) {
      for(int j = 0; j < m_column; ++j) {
        tmp[i - 1][j] = m_cell[i][j];
      }
    }

    for(int i = 0; i < m_row; ++i) {
      delete[] m_cell[i];
    }
    delete[] m_cell;
    m_cell = tmp;
    m_row -= 1;
  }

  if(r == m_row) {
    Cell** tmp = new Cell*[m_row - 1];
    for(int i = 0; i < m_row - 1; ++i) {
      tmp[i] = new Cell[m_column];
    }

    for(int i = 0; i < m_row - 1; ++i) {
      for(int j = 0; j < m_column; ++j) {
        tmp[i][j] = m_cell[i][j];
      }
    }

    for(int i = 0; i < m_row; ++i) {
      delete[] m_cell[i];
    }
    delete[] m_cell;
    m_cell = tmp;
    m_row -= 1;
  }

}

void Spreadsheet::addColumn(int c) {
  if(c < 0 && c >= m_row) {
    throw std::invalid_argument("Invalid argument");
  }

  Cell** tmp = new Cell*[m_row];
    for(int i = 0; i < m_row; ++i) {
      tmp[i] = new Cell[m_column + 1];
    } 

  for(int i = 0; i < m_row; ++i) {
    for(int j = 0; j < m_column; ++j) {
      if(j < c) {
        tmp[i][j] = m_cell[i][j];
      } else {
        tmp[i][j + 1] = m_cell[i][j];
      }
    }
  }

  for(int i = 0; i < m_row; ++i) {
    tmp[i][c] = Cell("0", Color::white);
  }

  if(c == m_column) {
    for(int i = 0; i < m_row; ++i) {
      tmp[i][c] = Cell("0", Color::white);
    }
  }

  for(int i = 0; i < m_row; ++i) {
    delete[] m_cell[i];
  }
  delete[] m_cell;
  m_cell = tmp;
  tmp = nullptr;
  m_column += 1;
}

void Spreadsheet::removeColumn(int c) {
  if(c < 0 && c >= m_row) {
    throw std::invalid_argument("Invalid argument");
  }

  if(c == 0) {
    Cell** tmp = new Cell*[m_row];
    for(int i = 0; i < m_row; ++i) {
      tmp[i] = new Cell[m_column - 1];
    }

    for(int i = 0; i < m_row; ++i) {
      for(int j = 1; j < m_column; ++j) {
        tmp[i][j - 1] = m_cell[i][j];
      }
    }

    for(int i = 0; i < m_row; ++i) {
      delete[] m_cell[i];
    }
    delete[] m_cell;
    m_cell = tmp;
    m_column -= 1;
  }

  if(c > 0 && c < m_column) {
    Cell** tmp = new Cell*[m_row];
    for(int i = 0; i < m_row; ++i) {
      tmp[i] = new Cell[m_column - 1];
    }

    for(int i = 0; i < m_row; ++i) {
      for(int j = 0; j < c; ++j) {
        tmp[i][j] = m_cell[i][j];
      }
    }

    for(int i = 0; i < m_row; ++i) {
      for(int j = c + 1; j < m_column; ++j) {
        tmp[i][j - 1] = m_cell[i][j];
      }
    }

    for(int i = 0; i < m_row; ++i) {
      delete[] m_cell[i];
    }
    delete[] m_cell;
    m_cell = tmp;
    m_column -= 1;
  }

  if(c == m_column) {
    Cell** tmp = new Cell*[m_row];
    for(int i = 0; i < m_row; ++i) {
      tmp[i] = new Cell[m_column - 1];
    }

    for(int i = 0; i < m_row; ++i) {
      for(int j = 0; j < m_column - 1; ++j) {
        tmp[i][j] = m_cell[i][j];
      }
    }

    for(int i = 0; i < m_row; ++i) {
      delete[] m_cell[i];
    }
    delete[] m_cell;
    m_cell = tmp;
    m_column -= 1;
  }
}

void Spreadsheet::swapRow(int r1, int r2) {
  for(int i = 0; i < m_column; ++i) {
    std::swap(m_cell[r1], m_cell[r2]);
  }
}

void Spreadsheet::swapColumn(int c1, int c2) {
  for(int i = 0; i < m_row; ++i) {
    std::swap(m_cell[i][c1], m_cell[i][c2]);
  }
}

