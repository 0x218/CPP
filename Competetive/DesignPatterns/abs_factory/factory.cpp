#ifndef __io__
#define __io__
#include <iostream>
using namespace std;
#endif

//Base specifics
class Body {
protected:
	string name;
	int strength;
public:
	Body(string n, int strength):name(n),strength(strength) {}
	string getName(){return name;}
	int getStrength() {return strength;}
};

//Extension of base specifics
class SimpleBody : public Body{
public:
	SimpleBody():Body("SimpleBody",75) {}
};

class LuxuryBody : public Body{
public:
	LuxuryBody():Body("LuxuryBody",100) {}
};
//===================================================================
//General framework
class Car {
protected:
	string name;
	Body *body; //car HAS body.
public:
	Car(string n):name(n) {}
	void setBody(Body* b) {	body = b;}//passing Body object
	void printDetails(){
		cout << endl << "Car: " << name << endl;
		cout << "Body: " << body->getName() << " Strength: " << body->getStrength() << endl << endl;
	}
};
//==================================================================
//factory...
class CarFactory {
private:
	Car *car;
protected:
	virtual Body * buildBody() = 0;
public:
	virtual Car* buildWholeCar() = 0;
};
//==========================================================
//extended implmentation of factory
class SimpleCarFactory : public CarFactory {
	Body * buildBody() {
		return new SimpleBody();
	}

	Car * buildWholeCar() {
		Car *car = new Car("SimpleCar");
		car->setBody(buildBody());
		return car;
	}
};

class LuxuryCarFactory : public CarFactory {
	Body * buildBody() {
		return new LuxuryBody();
	}
	Car * buildWholeCar() {
		Car *car = new Car("LuxuryCar");
		car->setBody(buildBody());
		return car;
	}
};
//======================================