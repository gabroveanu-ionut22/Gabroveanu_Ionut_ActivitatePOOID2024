#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Animal {
public:
    virtual string getNume() const = 0;
    virtual string getSunet() const = 0;
    virtual void mananca() = 0;
    virtual void doarme() = 0;
};
class Mamifer : public Animal {
public:
    Mamifer(const string& nume) : _nume(nume) {}
    string getNume() const override { return _nume; }
    virtual string getSunet() const override { return "Sunet generic de mamifer"; }
    void mananca() override { cout << _nume << " mananca." << endl; }
    void doarme() override { cout << _nume << " doarme." << endl; }

private:
    string _nume;
};
class Pasare : public Animal {
public:
    Pasare(const string& nume) : _nume(nume) {}
    string getNume() const override { return _nume; }
    virtual string getSunet() const override { return "Sunet generic de pasare"; }
    void mananca() override { cout << _nume << " mananca." << endl; }
    void doarme() override { cout << _nume << " doarme." << endl; }

private:
    string _nume;
};
class Leu : public Mamifer {
public:
    Leu() : Mamifer("Leu") {}
    string getSunet() const override { return "Roar!"; }
};
class Vultur : public Pasare {
public:
    Vultur() : Pasare("Vultur") {}
    string getSunet() const override { return "Screech!"; }
};
class GradinaZoologica {
public:
    void adaugaAnimal(Animal* animal) { _animale.push_back(animal); }
    void afiseazaAnimale() const {
        for (const auto& animal : _animale) {
            cout << animal->getNume() << " face: " << animal->getSunet() << endl;
        }
    }
    void hranesteAnimale() {
        for (const auto& animal : _animale) {
            animal->mananca();
        }
    }
private:
    vector<Animal*> _animale;
};
int main() {
    GradinaZoologica gradinaMea;
    gradinaMea.adaugaAnimal(new Leu());
    gradinaMea.adaugaAnimal(new Vultur());
    gradinaMea.afiseazaAnimale();
    gradinaMea.hranesteAnimale();
    for (const auto& animal : gradinaMea._animale) {
        delete animal;
    }
    return 0;
}