/**
 * Created by Roei Biton
 * Gmail: roei.biton33@gmail.com
 * */

#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief This is a class that describe a complex number
 */
class Complex {
private:
    double real;
    double imag;
    
public:

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    double getReal() const { return real; }

    void setReal(double r) { real = r; }

    double getImag() const { return imag; }

    void setImag(double i) { imag = i; }

    Complex operator + (const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    bool operator < (const Complex& other) const {
        //return this->real < other.real && this->imag < other.imag;
        return std::sqrt(real * real + imag * imag) < std::sqrt(other.real * other.real + other.imag * other.imag);
    }

    bool operator ==(const Complex& other) const{
        return this->real == other.real && this->imag == other.imag;
    }

    friend ostream& operator << (ostream& out, const Complex& c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }


};

