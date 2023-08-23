#ifndef VAGAS_HPP_INCLUDED 
#define VAGAS_HPP_INCLUDED

    void Vaga::insertLocation(int loc) {
        location = loc;
        if (location == 1) {
            setPrice(2000);
        } else if (location == 2) {
            setPrice(5000);
        }
    }
    void Vaga::insertOcupado            (bool x) { ocupado = x;       }
    void Vaga::insertPrice            (double x) { price = x;         }
    void Vaga::insertAcumulaPrice(long double x) { acumulaPrice += x; } 

#endif  