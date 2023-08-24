#include<iostream>
using namespace std;

class CPU {
public:
	virtual void info() = 0;
};
class GPU {
public:
	virtual void info() = 0;
};

class GamingCPU : public CPU{
public:
	void info() override {
		cout << "Gaming CPU" << endl;
	}
};

class GamingGPU : public GPU {
public:
	void info() override {
		cout << "Gaming GPU" << endl;
	}
};

class OfficeCPU : public CPU {
public:
	void info() override {
		cout << "Office CPU" << endl;
	}
};

class OfficeGPU : public GPU {
public:
	void info() override {
		cout << "Office GPU" << endl;
	}
};

class AbstractFactory {
public:
	virtual CPU* createCPU() = 0;
	virtual GPU* createGPU() = 0;
};

class GamingPCFactory : public AbstractFactory {
public:
	CPU* createCPU() override {
		return new GamingCPU();
	}
	GPU* createGPU() override {
		return new GamingGPU();
	}
};

class OfficePCFactory : public AbstractFactory {
public:
	CPU* createCPU() override {
		return new OfficeCPU();
	}
	GPU* createGPU() override {
		return new OfficeGPU();
	}
};

int main() {
	AbstractFactory* factory;

	factory = new GamingPCFactory();
	CPU* gamingCPU = factory->createCPU();
	GPU* gamingGPU = factory->createGPU();

	gamingCPU->info();
	gamingGPU->info();


	factory = new OfficePCFactory();
	CPU* officeCPU = factory->createCPU();
	GPU* officeGPU = factory->createGPU();

	officeCPU->info();
	officeGPU->info();

}