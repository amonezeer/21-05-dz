#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    void setEngine(const string& engine) {
        engine_ = engine;
    }

    void setBody(const string& body) {
        body_ = body;
    }

    void setHorsepower(int horsepower) {
        horsepower_ = horsepower;
    }

    void setWheels(int wheels) {
        wheels_ = wheels;
    }

    void setTransmission(const string& transmission) {
        transmission_ = transmission;
    }

    void showInfo() const {
        cout << "Engine: " << engine_ << endl;
        cout << "Body: " << body_ << endl;
        cout << "Horsepower: " << horsepower_ << endl;
        cout << "Wheels: " << wheels_ << endl;
        cout << "Transmission: " << transmission_ << endl;
    }

private:
    string engine_;
    string body_;
    int horsepower_;
    int wheels_;
    string transmission_;
};

class CarBuilder {
public:
    virtual void buildEngine() = 0;
    virtual void buildBody() = 0;
    virtual void buildHorsepower() = 0;
    virtual void buildWheels() = 0;
    virtual void buildTransmission() = 0;
    virtual Car* getCar() = 0;
};

class DaewooLanosBuilder : public CarBuilder {
public:
    DaewooLanosBuilder() {
        car_ = new Car();
    }

    void buildEngine() override {
        car_->setEngine("Daewoo Lanos");
    }

    void buildBody() override {
        car_->setBody("Sedan");
    }

    void buildHorsepower() override {
        car_->setHorsepower(98);
    }

    void buildWheels() override {
        car_->setWheels(13);
    }

    void buildTransmission() override {
        car_->setTransmission("Manual 5");
    }

    Car* getCar() override {
        return car_;
    }

private:
    Car* car_;
};

class FordProbeBuilder : public CarBuilder {
public:
    FordProbeBuilder() {
        car_ = new Car();
    }

    void buildEngine() override {
        car_->setEngine("Ford Probe");
    }

    void buildBody() override {
        car_->setBody("Coupe");
    }

    void buildHorsepower() override {
        car_->setHorsepower(160);
    }

    void buildWheels() override {
        car_->setWheels(14);
    }

    void buildTransmission() override {
        car_->setTransmission("Auto 4");
    }

    Car* getCar() override {
        return car_;
    }

private:
    Car* car_;
};


class HyundaiGetzBuilder : public CarBuilder {
public:
    HyundaiGetzBuilder() {
        car_ = new Car();
    }

    void buildEngine() override {
        car_->setEngine("Hyundai Getz");
    }

    void buildBody() override {
        car_->setBody("Hatchback");
    }

    void buildHorsepower() override {
        car_->setHorsepower(66);
    }

    void buildWheels() override {
        car_->setWheels(13);
    }

    void buildTransmission() override {
        car_->setTransmission("Auto 4");
    }

    Car* getCar() override {
        return car_;
    }

private:
    Car* car_;
};

class VolkswagenPassatBuilder : public CarBuilder {
public:
    VolkswagenPassatBuilder() {
        car_ = new Car();
    }

    void buildEngine() override {
        car_->setEngine("Volkswagen Passat");
    }

    void buildBody() override {
        car_->setBody("Wagon");
    }

    void buildHorsepower() override {
        car_->setHorsepower(200);
    }

    void buildWheels() override {
        car_->setWheels(16);
    }

    void buildTransmission() override {
        car_->setTransmission("Manual 6");
    }

    Car* getCar() override {
        return car_;
    }

private:
    Car* car_;
};

class Shop {
public:
    Car* constructCar(CarBuilder* builder) {
        builder->buildEngine();
        builder->buildBody();
        builder->buildHorsepower();
        builder->buildWheels();
        builder->buildTransmission();
        return builder->getCar();
    }
};

void showMenu() {
    cout << "Выберите автомобиль:" << endl;
    cout << "1. Daewoo Lanos" << endl;
    cout << "2. Ford Probe" << endl;
    cout << "3. Hyundai Getz" << endl;
    cout << "4. Volkswagen Passat" << endl;
    cout << "Введите свой выбор: ";
    
}

int main() {
    system("chcp 1251");

    Shop shop;
    int choice;

    showMenu();
    cin >> choice;

    Car* car = nullptr;
    cout << "--------------------- \n";
    switch (choice) {
    case 1: {
        DaewooLanosBuilder builder;
        car = shop.constructCar(&builder);
        cout << "Daewoo Lanos:" << endl;
        car->showInfo();
        delete car;
        break;
    }
    case 2: {
        FordProbeBuilder builder;
        car = shop.constructCar(&builder);
        cout << "Ford Probe:" << endl;
        car->showInfo();
        delete car;
        break;
    }
    case 3: {
        HyundaiGetzBuilder builder;
        car = shop.constructCar(&builder);
        cout << "Hyundai Getz:" << endl;
        car->showInfo();
        delete car;
        break;
    }
    case 4: {
        VolkswagenPassatBuilder builder;
        car = shop.constructCar(&builder);
        cout << "Volkswagen Passat:" << endl;
        car->showInfo();
        delete car;
        break;
    }
    default:
        cout << "Неверный выбор!" << endl;
        break;
    }

    return 0;
}
