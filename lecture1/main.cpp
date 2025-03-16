#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Student {
private:
  std::string name;
  std::string surname;
  std::vector<float> grades;

public:
  Student(std::string name, std::string surname)
      : name{name}, surname{surname} {}

  float calculate_grade() {
    float sum = std::accumulate(grades.begin(), grades.end(), 0.0f);
    return sum / grades.size();
  }

  void print() {
    cout << name << " " << surname << " grade: " << calculate_grade() << endl;
  }

  bool add_grade(float grade) {
    if (grade >= 2.0 && grade <= 5.0) {
      grades.push_back(grade);
      return true;
    }
    return false;
  }
};

int main() {
  Student s1{"John", "Smile"};
  s1.add_grade(2);
  s1.add_grade(3);
  s1.add_grade(4);
  Student s2{"Roland", "Sobczak"};
  s2.add_grade(4);
  s2.add_grade(5);
  s2.add_grade(4);

  s1.print();
  s2.print();

  return 0;
}
