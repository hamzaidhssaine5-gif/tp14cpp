#include <iostream>
#include <stdexcept>

int diviser(int a, int b) {
    if (b == 0)
        throw std::runtime_error("Erreur : division par zéro interdite !");
    return a / b;
}

int main() {
    try {
        std::cout << diviser(10, 2) << std::endl;
        std::cout << diviser(5, 0) << std::endl;
        std::cout << diviser(15, 3) << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
