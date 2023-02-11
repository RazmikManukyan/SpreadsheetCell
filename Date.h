#ifndef Date_H
#define Date_H

class Year {
public:
  explicit Year (int y) {
    if (y < 1900 && y > 2023) {
      throw "Invalid argument for Year!";
    } else {
      year = y;
    }
  }
  int year;
};

class Month {
public:
  explicit Month (int m) {
    if(m <= 0 && m > 12) {
      throw "Invalid argument for Month!";
    } else {
      month = m;
    }
  }
  int month;
};

class Day {
public:
  explicit Day (int d) {
    if (d <= 0 && d > 31) {
      throw "Invalid argument for Month";
    } else {
      day = d;
    }
  } 
  int day;
};

class Date {
public:
  Date(Day d, Month m, Year y) 
  :m_day(d.day)
  ,m_month(m.month)
  ,m_year(y.year)
  {}

  int m_day;
  int m_month;
  int m_year;
};

#endif
