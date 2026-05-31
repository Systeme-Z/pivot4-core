#include <cstdint>
#include <stdexcept>

class Pivot4 {
private:
    int32_t valeur;

public:
    // La seule règle : l'alignement strict.
    Pivot4(int32_t val) : valeur(val) {
        if (val % 4 != 0) {
            throw std::invalid_argument("Violation d'alignement");
        }
    }

    int32_t raw() const { 
        return valeur; 
    }

    float toFloat() const { 
        return static_cast<float>(valeur) / 4.0f; 
    }

    // Le Fusionneur interne : l'addition est la seule opération primitive.
    Pivot4 operator+(const Pivot4& other) const {
        return Pivot4(valeur + other.valeur);
    }

    // Transformations structurelles neutres.
    Pivot4 scaleUp() const { 
        return Pivot4(valeur << 2); 
    }

    Pivot4 scaleDown() const { 
        return Pivot4(valeur >> 2); 
    }
};
