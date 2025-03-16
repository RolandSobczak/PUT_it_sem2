
#include <iostream>

using namespace std;

class Complex {
private:
  float real;
  float imaginary;

public:
  Complex(float real) : real{real}, imaginary{0} {}
  Complex(float real, float imaginary) : real{real}, imaginary{imaginary} {}

  void set_im(float im) { imaginary = im; }
  void set_real(float re) { real = re; }
  float get_real() const { return real; }
  float get_im() const { return imaginary; }

  Complex add(const Complex &rhs) {
    return Complex{real + rhs.get_real(), imaginary + rhs.get_im()};
  }

  void print() {
    cout << "<Complex real=" << real << " imaginary=" << imaginary << ">"
         << endl;
  }
};

int main() {

  Complex a(1.0, -2.0); // creates 1-2i
  Complex b(3.14);      // creates 3.14

  b.set_im(-5);

  Complex c = a.add(b);

  c.print(); // prints 4.14-7i

  return 0;
}
