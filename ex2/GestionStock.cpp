#include <iostream>
#include <exception>
#include <string>

class StockInsuffisantException : public std::exception {
    std::string message;
public:
    StockInsuffisantException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class Produit {
    int stock;
public:
    Produit(int stockInitial) : stock(stockInitial) {}
    void vendre(int quantite) {
        if (quantite > stock) {
            throw StockInsuffisantException("Stock insuffisant pour la vente.");
        }
        stock -= quantite;
    }
    int getStock() const {
        return stock;
    }
};

int main() {
    Produit p(5);

    try {
        p.vendre(3);
        std::cout << "Stock après vente: " << p.getStock() << std::endl;

        p.vendre(4);  
    } catch (const StockInsuffisantException& e) {
        std::cout << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}
