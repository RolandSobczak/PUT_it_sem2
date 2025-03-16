#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

struct Student {
  std::string name;
  std::string surname;
  std::vector<float> grades;
};

float calculate_grade(const Student &student) {
  float sum =
      std::accumulate(student.grades.begin(), student.grades.end(), 0.0f);
  return sum / student.grades.size();
}

int main() {
  Student s1{"John", "Smile", {2, 3, 4}};
  Student s2{"Roland", "Sobczak", {4, 5, 4}};

  cout << "grade = " << calculate_grade(s1) << endl;

  return 0;
}
