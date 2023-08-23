#ifndef START_HPP_INCLUDED
#define START_HPP_INCLUDED
 
void start() {
    int tipo, chooseVagaType, opc, chooseTable, opcRemove,opcParaInfo;
    int quantCarsNormal{0}, quantCarsVIP{0}, quantEntradas{0};
    Vaga *vg = new Vaga();
    Estacionamento carNormal[20];
    Estacionamento carVIP[20];
    Estacionamento historico[60];
    
    do {
        Estacionamento::clear();
        opc = Estacionamento::choose_option();
        switch(opc) {
            default:
                if (opc != 0) {
                    Estacionamento::clear();
                    std::cout << '\n' << "Invalid option!";
                    getch();
                }
            break;

            case 1:
                Estacionamento::clear();
                tipo = Estacionamento::vagaType(1);
                switch(tipo) {
                    case 1:
                        Estacionamento::clear();
                        std::cout << "======================== ENTRADA NORMAL =======================" << '\n' << '\n';
                        carNormal[quantCarsNormal].setLocation(tipo);
                        carNormal[quantCarsNormal].entrada();
                        Estacionamento::clear();
                        carNormal->selectVaga(carNormal, quantCarsNormal);
                        carNormal[quantCarsNormal].tInicial = clock();
                        carNormal[quantCarsNormal].setEntryTime();
                        historico[quantEntradas] = carNormal[quantCarsNormal];
                        vg->setAcumulaPrice(2000);
                        std::cout << '\n' << '\n' << "UM " << carNormal[quantCarsNormal].getModelo() << " ENTROU NO PARQUE!"; 
                        ++quantCarsNormal;
                        ++quantEntradas;
                        getch();
                    break;

                    case 2:
                        Estacionamento::clear();
                        std::cout << "======================== ENTRADA VIP =======================" << '\n' << '\n';
                        carVIP[quantCarsVIP].setLocation(tipo);
                        carVIP[quantCarsVIP].entrada();
                        Estacionamento::clear();
                        carVIP[quantCarsVIP].selectVaga(carVIP, quantCarsVIP);
                        carVIP[quantCarsVIP].tInicial = clock();
                        carVIP[quantCarsVIP].setEntryTime();
                        historico[quantEntradas] = carVIP[quantCarsVIP];
                        vg->setAcumulaPrice(5000);
                        std::cout << '\n' << '\n' << "UM " << carVIP[quantCarsVIP].getModelo() << " ENTROU NO PARQUE!"; 
                        ++quantCarsVIP;
                        ++quantEntradas;
                        getch();
                    break;
                }
            break;

            case 2:
                Estacionamento::clear();
                if (quantCarsNormal == 0 && quantCarsVIP == 0) {
                    std::cout << '\n' << "O parque esta vazio!";
                }
                else {
                    do {
                        Estacionamento::clear();
                        chooseVagaType = Estacionamento::vagaType(2);
                        Estacionamento::clear();
                        if      (chooseVagaType == 1 && quantCarsNormal > 0) { Estacionamento::parkedCars(carNormal, quantCarsNormal); }
                        else if (chooseVagaType == 2 && quantCarsVIP    > 0) { Estacionamento::parkedCars(carVIP, quantCarsVIP);       }
                        else if (chooseVagaType == 3) { 
                            Estacionamento::parkedCars(carNormal, quantCarsNormal);
                            Estacionamento::parkedCars(carVIP, quantCarsVIP);
                        }
                        if (chooseVagaType != 0) {
                            getch();
                        }
                    } while(chooseVagaType != 0);  
                }
            break;

            case 3:
                do {
                    Estacionamento::clear();
                    chooseTable = Estacionamento::vagaType(2);
                    switch (chooseTable) {
                        default:
                            if (chooseTable != 0) {
                                Estacionamento::clear();
                                std::cout << '\n' << "Error! Invalid option!";
                                getch();
                            }
                        break;

                        case 1:
                            Estacionamento::clear();
                            carNormal->accessDrawPark(carNormal, chooseTable);
                            getch();
                        break;
                        
                        case 2:
                            Estacionamento::clear();
                            carVIP->accessDrawPark(carVIP, chooseTable);
                            getch();
                        break;

                        case 3:
                            Estacionamento::clear();
                            carNormal->accessDrawPark(carNormal, 1);
                            carVIP->accessDrawPark(carVIP, 2);
                            getch();
                        break;
                    }
                } while (chooseTable != 0);
            break;

            case 4:
                Estacionamento::clear();
                if (quantCarsNormal == 0 && quantCarsVIP == 0) {
                    std::cout << "Erro! O parque esta vazio!";
                }
                else {
                    do {
                        Estacionamento::clear();
                        opcRemove = Estacionamento::removeOptions();
                        switch(opcRemove) {
                            default:
                                if (chooseTable != 0) {
                                    Estacionamento::clear();
                                    std::cout << '\n' << "Error! Invalid option!";
                                    getch();
                                }
                            break;

                            case 1:
                                Estacionamento::clear();
                                Estacionamento::saida(carNormal, &quantCarsNormal);
                                getch();
                            break;

                            case 2:
                                Estacionamento::clear();
                                Estacionamento::saida(carVIP, &quantCarsVIP);
                                getch();
                            break;
                        }
                    } while (opcRemove != 0);
                }
            break;

            case 5:
                Estacionamento::clear();
                if (quantEntradas == 0) {
                    std::cout << "Sem entradas recentes!";
                }
                else {
                    Estacionamento::historico(historico, quantEntradas);
                }
                getch();
            break;

            case 6:
                Estacionamento::clear();
                opcParaInfo = Estacionamento::vagaType(3);
                if (opcParaInfo == 1) {
                    carNormal->accessInfoVagaIndividual(carNormal, quantCarsNormal);
                }
                else if (opcParaInfo == 2) {
                    carVIP->accessInfoVagaIndividual(carVIP, quantCarsVIP);
                }
                getch();
            break;

            case 7:
                Estacionamento::clear();
                if(quantCarsNormal != 0) {
                    Estacionamento::infoVagaIndividual(carNormal,quantCarsNormal,0);
                    std::cout << "Quantidade de carros em vagas normais: " << quantCarsNormal;
                } 
                if (quantCarsVIP != 0) {
                    Estacionamento::infoVagaIndividual(carVIP,quantCarsVIP,1);
                    std::cout << "Quantidade de carros em vagas VIP: " << quantCarsVIP;
                }
                getch();
            break;

            case 8:
                Estacionamento::clear();
                std::cout << '\n' << "Saldo da Empresa: " << vg->getAcumulaPrice() << "$";
                getch();
            break;
            
        }
    } while (opc != 0);
}

#endif