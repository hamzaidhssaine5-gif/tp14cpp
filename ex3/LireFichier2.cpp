#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

void lireFichier(const std::string& nomFichier) {
    std::ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        throw std::runtime_error("Erreur : fichier introuvable");
    }

    std::string ligne;
    while (std::getline(fichier, ligne)) {
        std::cout << ligne << std::endl;
    }
    fichier.close();
}

int main() {
    try {
        lireFichier("monfichier.txt");
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
