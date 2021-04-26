#include <iostream>
#include "array.h"
#include "Complex.h"

int main() {

    Array<int> intArray;
    (((intArray += 5) += 7) += -1) += 2;

    std::cout << intArray.toString() << std::endl;
    std::cout << intArray.min() << std::endl;
    std::cout << intArray.sum() << std::endl;
    std::cout << intArray.product() << std::endl;

    Array<Complex> complexArray;
    Complex a(1, 2);
    Complex b(6, 7);
    Complex c(-2, 4);
    (((complexArray += a) += b) += c);

    std::cout << complexArray.toString() << std::endl;
    std::cout << (std::string) complexArray.min() << std::endl;
    std::cout << (std::string) complexArray.sum() << std::endl;
    std::cout << (std::string) complexArray.product() << std::endl;
    return 0;
}
