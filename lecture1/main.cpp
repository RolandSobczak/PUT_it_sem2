#include <cstdint>
#include <iostream>
#include <numeric>
#include <stdint.h>
#include <vector>

using namespace std;

class Student {
private:
  std::string name;
  std::string surname;
  int album_number;
  std::vector<float> grades;

public:
  Student(std::string name, std::string surname, int album_number)
      : name{name}, surname{surname}, album_number{album_number} {}

  float calculate_grade() {
    float sum = std::accumulate(grades.begin(), grades.end(), 0.0f);
    return sum / grades.size();
  }

  void print() {
    cout << name << " " << surname << " grade: " << calculate_grade()
         << " album number: " << album_number << endl;
  }

  bool add_grade(float grade) {
    if (grade >= 2.0 && grade <= 5.0) {
      grades.push_back(grade);
      return true;
    }
    return false;
  }

  void set_name(std::string name) { this->name = name; }
  void set_surname(std::string surname) { this->surname = surname; }
  void set_album_no(int album_number) { this->album_number = album_number; }

  bool check_passed() { return calculate_grade() > 2.0f; }
};

int main() {
  Student s1{"John", "Smile", 99};
  s1.add_grade(2);
  s1.add_grade(3);
  s1.add_grade(4);
  Student s2{"Roland", "Sobczak", 100};
  s2.add_grade(4);
  s2.add_grade(5);
  s2.add_grade(4);

  s1.print();
  s2.print();

  return 0;
}
