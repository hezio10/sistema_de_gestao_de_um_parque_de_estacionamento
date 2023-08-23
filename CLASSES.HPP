#ifndef CLASSES_HPP_INCLUDED
#define  CLASSES_HPP_INCLUDED

class Veiculo { 
    private:
        std::string modelo;
        std::string cor;
        std::string matricula;
        std::string tipo;
        int carID;
 
        std::string getgetModelo   () { return modelo;    }
        std::string getgetCor      () { return cor;       }
        std::string getgetMatricula() { return matricula; }
        std::string getgetTipo     () { return tipo;      }
        int         getgetCarID    () { return carID;     }

        void insertModelo   ();
        void insertCor      ();
        void insertMatricula();
        void insertTipo     ();
        void insertCarID    ();

    public:
        std::string getModelo   () { return getgetModelo   (); }
        std::string getCor      () { return getgetCor      (); }
        std::string getMatricula() { return getgetMatricula(); }
        std::string getTipo     () { return getgetTipo     (); }
        int         getCarID    () { return getgetCarID    (); }
        
        void setModelo   () { insertModelo   (); }
        void setCor      () { insertCor      (); }
        void setMatricula() { insertMatricula(); }
        void setTipo     () { insertTipo     (); }
};

class Vaga {
    private:
        int location; 
        bool ocupado;
        double price;
        long double acumulaPrice;

        int getgetLocation () { return location; }
        bool getgetOcupado () { return ocupado;  }
        double getgetPrice () { return price;    }
        long double getgetAcumulaPrice() { return acumulaPrice; }

        void insertLocation(int loc);
        void insertOcupado  (bool x);
        void insertPrice  (double x);
        void insertAcumulaPrice(long double x);

    public:
        Vaga() {
            ocupado = 0;
            acumulaPrice = 0;
        }

        int getLocation () { getgetLocation(); }
        bool getOcupado () { getgetOcupado (); }
        double getPrice () { getgetPrice   (); }
        long double getAcumulaPrice() { return getgetAcumulaPrice(); }

        void setLocation  (int y) { insertLocation(y); }
        void setOcupado  (bool y) { insertOcupado (y); }
        void setPrice  (double y) { insertPrice   (y); }
        void setAcumulaPrice(long double x) { insertAcumulaPrice(x); }
};

class Ticket : public Veiculo, public Vaga {
    public:
        void setEntryTime     () { insertEntryTime       (); }
        struct tm getEntryTime() { return getgetEntryTime(); }
        
    private:
        time_t t;
        struct tm tempo;

        void insertEntryTime();
        struct tm getgetEntryTime() { return tempo; }
};

class Estacionamento : public Ticket {
    public:
        int line, column;
        Vaga vagas[4][10];
        time_t tInicial, tFinal;

        static void clear() { system("cls"); }
        static int  vagaType(int x);
        static int  choose_option();
        static int  removeOptions();

        static void parkedCars(Estacionamento car[], int quant);
        static void selectVaga(Estacionamento *car, int quant);
        static void drawPark(Estacionamento *car, int type);
        static void saida(Estacionamento *car, int *quant);
        static void historico(Estacionamento historico[], int quant);
        static void infoVagaIndividual(Estacionamento car[], int quantCars, bool type);
        static void infoVagaIndividual(Estacionamento *car, int x);

        void accessDrawPark(Estacionamento *car, int type) { drawPark(car, type); }
        void accessInfoVagaIndividual(Estacionamento* car, int quant);
        void entrada();
};
#endif