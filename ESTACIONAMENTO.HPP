#ifndef ESTACIONAMENTO_HPP_INCLUDED
#define ESTACIONAMENTO_HPP_INCLUDED

    int Estacionamento::choose_option() {
		int select;

		std::cout << '\n' << "================================== HEZIO ORG PARK ================================== " << '\n'
				  << '\n' << "CHOOSE OPTION"
				  << '\n' << "[1] Estacionar carro"
				  << '\n' << "[2] Carros estacionados (lista)" 
                  << '\n' << "[3] Ver vagas"
                  << '\n' << "[4] Remover do parque"
                  << '\n' << "[5] Historico de entradas"
                  << '\n' << "[6] Consultar viatura"
                  << '\n' << "[7] Dados"
                  << '\n' << "[8] Saldo do parque"
                  << '\n' << "[0] $air"
				  << '\n' << "::: ";
		std::cin  >> select; 

		return select;
	}

    int Estacionamento::vagaType(int x) {
        int select;
        if (x == 1) {
            Estacionamento aux, aux2;
            aux.setLocation(1);
            aux2.setLocation(2);
            std::cout << '\n' << "TIPO DE VAGA" 
                    << '\n' << "[1] Normal [" << aux.getPrice () << "$]" 
                    << '\n' << "[2] VIP    [" << aux2.getPrice() << "$]"
                    << '\n' << "[0] Cancel" << '\n' << "  > ";
        }
        else if (x == 2) {
            std::cout << '\n' << "TIPO DE VAGA" 
                      << '\n' << "[1] Normal"
                      << '\n' << "[2] VIP" 
                      << '\n' << "[3] Todas Viaturas" 
                      << '\n' << "[0] Cancel" << '\n' << "  > ";
        }
        else if(x == 3) {
            std::cout << '\n' << "ENCONTRAR UMA VIATURA EM VAGA:" 
                      << '\n' << "[1] Normal"
                      << '\n' << "[2] VIP"                       
                      << '\n' << "[0] Cancel" << '\n' << "  > ";
        } 

        std::cin >> select;

        return select;
    }

    int Estacionamento::removeOptions() {
        int select;

        std::cout << '\n' << "Que tipo de viatura deseja sair do parque?"
                  << '\n' << "[1] Viatura Normal"
                  << '\n' << "[2] Viatura VIP" 
                  << '\n' << "[0] Cancel" << '\n' << "  > ";
        std::cin >> select;

        return select;
    }

    void Estacionamento::entrada() {
        setTipo();
        setModelo();
        setCor();
        setMatricula();
    }
    
    void Estacionamento::parkedCars(Estacionamento car[], int quant) {
            for (int x = 0; x < quant; x++) {
                car[x].tFinal = clock() - car[x].tInicial;
                std::cout << '\n' << "[" << (x+1) << "] " << car[x].getTipo() << " " << car[x].getModelo() << '\t' << " ha " << (car[x].tFinal/CLOCKS_PER_SEC) << "secs.";  
            }
    }

    void Estacionamento::drawPark(Estacionamento *car, int type) {
        if (type == 1) {
            std::cout << '\n' << "============================ VAGAS NORMAIS ============================" << '\n' << '\n';
        }
        else {
            std::cout << '\n' << '\n' << '\n' << "============================== VAGAS VIP ==============================" << '\n' << '\n';
        }
        std::cout << '\n';
        std::cout << '\t' << '\t' << "  0   1   2   3   4   5   6   7   8   9" << '\n' << '\n'; 
        std::cout << '\n' << '\t' << '\t';
        for (int x = 0; x < 10; x++) {
            std::cout << " - -";
        }
        for (int x = 0; x < 4; x++) {
            std::cout << '\n' << '\t' << "    " << x << "   " << "| ";
            for (int y = 0; y < 10; y++) {
                std::cout << car->vagas[x][y].getOcupado() << " | ";
            }
            std::cout << '\n' << '\t' << '\t';
            for (int x = 0; x < 10; x++) {
                std::cout << " - -";
            }
            std::cout << '\n';
        }
        if (type == 1) {
            std::cout << '\n' << "============================ VAGAS NORMAIS ============================" << '\n' << '\n';
        }
        else {
            std::cout << '\n' << '\n' << '\n' << "============================== VAGAS VIP ==============================" << '\n' << '\n';
        }
    }

    void Estacionamento::selectVaga(Estacionamento *car, int quant) {
        int linha, coluna, select, confirm{0};
        srand(time(NULL));

        std::cout << '\n' << "[1] Escolher vaga"  << '\n' << "[2] Auto-Choose" << '\n' << "::: ";
        std::cin >> select;
        Estacionamento::clear();
        if (select == 1) {
            std::cout << '\n' << "LOCALIZACAO  DA VAGA"; 
            do {
                std::cout << '\n' << "Linha: ";
                std::cin  >> linha;
                std::cout << "Coluna: ";
                std::cin >> coluna;
                if (car->vagas[linha][coluna].getOcupado() == 1 || linha > 3 || linha < 0 || coluna > 9 || coluna < 0) {
                    Estacionamento::clear();
                    std::cout << '\n' << "Error! insert a new location for the car!" << '\n';
                }
            } while (car->vagas[linha][coluna].getOcupado() == 1 || linha > 3 || linha < 0 || coluna > 9 || coluna < 0);
            car->vagas[linha][coluna].setOcupado(1);
        }
        else {
            for (int x = 0; x < 4; x++) {
                for (int y = 0; y < 10; y++) {
                    if (car->vagas[x][y].getOcupado() == 0) {
                        car->vagas[x][y].setOcupado(1);
                        confirm = 1;
                        linha  = x;
                        coluna = y;
                        break;
                    } 
                }
                if (confirm == 1) {
                    break;
                }
            }
        }
        car[quant].line   = linha;
        car[quant].column = coluna;
    }

    void Estacionamento::saida(Estacionamento car[], int *quant) {
        std::string sair;
        int confirm;
        std::cout << "Matricula da viatura: ";
        std::cin >> sair;
        confirm = 0;
        Estacionamento::clear();
        for(int i=0; i < *quant; i++){
            if(car[i].getMatricula() == sair) {   
                std::cout << '\n' << "A viatura " << car[i].getTipo() << " " << car[i].getModelo() << " saiu do parque!";
                car[i] = car[*quant-1];
                car->vagas[car[i].line][car[i].column].setOcupado(0);
                --*quant;
                confirm = 1;
            break;
            }
        }
        if (confirm != 1) {
            std::cout << '\n' << "Viatura nao encontrada!";
        }
    }

    void Estacionamento::historico(Estacionamento historico[], int quant) {
        std::cout << "Data: " << historico->getEntryTime().tm_mday << "/ " << historico->getEntryTime().tm_mon << "/ " << historico->getEntryTime().tm_year + 1900; 
        for (int x{0}; x < quant; x++) {
            std::cout << '\n' << "[" << historico[x].getEntryTime().tm_hour << "h:" << historico[x].getEntryTime().tm_min << "]" << '\t' << historico[x].getTipo() << " " << historico[x].getModelo() << "[" << historico[x].getMatricula() << "]" << " entrou no parque!"; 
        }
    }

    void Estacionamento::infoVagaIndividual(Estacionamento cars[], int quantCars, bool type) {
       if (type == 0) {
            std::cout << '\n' << "============================ CARROS EM VAGAS NORMAIS ============================" << '\n';
        }
        else {
            std::cout << '\n' << '\n' << '\n' << "============================== CARROS EM VAGAS VIP ==============================" << '\n';
        }
        for(int i=0; i  < quantCars; i++) {
            std::cout << '\n';
            std::cout << "Tipo-----: " << cars[i].getTipo() << '\n';
            std::cout << "Cor------: " << cars[i].getCor() << '\n';
            std::cout << "Modelo---: " << cars[i].getModelo() << '\n';
            std::cout << "Matricula: " << cars[i].getMatricula() << '\n';
            std::cout << "Vaga: [" << cars[i].line << "][" << cars[i].column << "]" << '\n';
        }
        if (type == 0) {
            std::cout << '\n' << "============================ CARROS EM VAGAS NORMAIS ============================" << '\n' << '\n';
        }
        else {
            std::cout << '\n' << '\n' << '\n' << "============================== CARROS EM VAGAS VIP ==============================" << '\n' << '\n';
        }
    }

        void Estacionamento::infoVagaIndividual(Estacionamento *car, int x) {
        Estacionamento::clear();
        std::cout << '\n' << "Tipo-----: " << car[x].getTipo() 
                    << '\n' << "Modelo---: " << car[x].getModelo()
                    << '\n' << "Matricula: " << car[x].getMatricula()
                    << '\n' << "Cor------: " << car[x].getCor()
                    << '\n' << "Vaga-----: " << "[" << car[x].line << "][" << car[x].column << "]" <<'\n'; 
    }

    void Estacionamento::accessInfoVagaIndividual(Estacionamento* car, int quant) {
        Estacionamento::clear();
        int confirm{0};
        std::string mtr, modelo;
        std::cout << '\n' << "Informe a matricula: ";
        std::cin >> mtr;
        std::cout << "Informe o modelo---: ";
        std::cin >> modelo;
        for (int x{0}; x < quant; x++) {
            if (car[x].getMatricula() == mtr && car[x].getModelo() == modelo) {
                car->infoVagaIndividual(car, x);
                confirm = 1;
                break;
            }
        }
        if (confirm != 1) {
            Estacionamento::clear();
            std::cout << "Viatura nao encontrada!";
        }
    }

#endif