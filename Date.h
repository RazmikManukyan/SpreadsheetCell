#ifndef Date_H
#define Date_H


class Date {
private:
  int year;
  int month;
  int day;
public:
  Date();
  ~Date();

  void setDate();
  void getDate();
};

#endif
