#ifndef VEICULO_HPP_INCLUDEDE
#define VEICULO_HPP_INCLUDEDE

    void Veiculo::insertTipo() {
        std::cout << "Tipo de veiculo: ";
        std::cin >> tipo;
    }
    void Veiculo::insertModelo() {
        std::cout << "Modelo---------: "; 
        std::cin >> modelo;
    }
    void Veiculo::insertCor() {
        std::cout << "Cor------------: ";
        std::cin >> cor;
    }
    void Veiculo::insertMatricula() {
        std::cout << "Matricula------: "; 
        std::cin >> matricula;
    }
#endif 