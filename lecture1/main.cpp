#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

struct Student {
  std::string name;
  std::string surname;
  std::vector<float> grades;

  float calculate_grade() {
    float sum = std::accumulate(grades.begin(), grades.end(), 0.0f);
    return sum / grades.size();
  }
};

int main() {
  Student s1{"John", "Smile", {2, 3, 4}};
  Student s2{"Roland", "Sobczak", {4, 5, 4}};

  cout << "grade = " << s1.calculate_grade() << endl;

  return 0;
}
