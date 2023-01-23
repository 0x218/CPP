#include <iostream>
#include <string>

typedef int Cable;

/* Adaptee interface */
class EuropeanSocketInterface
{
    public:
        virtual int voltage() = 0;
        virtual Cable live() = 0;
        virtual Cable neutral() = 0; 
        virtual Cable earth() = 0;
};

/* Adaptee */ 
//Here is a EU socket 
class Socket : public EuropeanSocketInterface
{
    public:
        int voltage() { return 230; }
        Cable live() { return 1; }
        Cable neutral() { return -1; }
        Cable earth() { return 0; }
};


/* Target interface */
//We are in London and has some US appliances, so we will need a adaptor for US appliance.
class USASocketInterface
{
    public:
        virtual int voltage() = 0;
        virtual Cable live() = 0;
        virtual Cable neutral() = 0;
};

/* The Adapter */
class Adapter : public USASocketInterface
{
    EuropeanSocketInterface* socket;

    public:
        void plugIn(EuropeanSocketInterface* outlet)
        {
            socket = outlet;
        }
        
        int voltage() { return 110; }
        Cable live() { return 1; }
        Cable neutral() { return socket->neutral(); }
};



//we have a US electric kettle
class CoffeePot
{
    USASocketInterface* power;

    public:
        void plugIn(USASocketInterface* supply)
        {
            power = supply;
        }

        void boil()
        {
            if (power->voltage() > 110)
            {
                std::cout << "Coffee pot is on fire!" << std::endl;
                return;
            }

            if (power->live() == 1 && power->neutral() == -1)
            {
                std::cout << "Coffee time!" << std::endl;
            }
        }
};


int main()
{
    Socket* socket = new Socket; //EU socket
    Adapter* adapter = new Adapter; //US adaptor
    CoffeePot* pot = new CoffeePot; //US appliance

  
    adapter->plugIn(socket);
    pot->plugIn(adapter);

    pot->boil();

    return 0;
}
