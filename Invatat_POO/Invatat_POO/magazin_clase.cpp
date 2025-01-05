#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Produs {
protected:
    string nume;
    double pret;
public:
    Produs(const string& nume, double pret) : nume(nume), pret(pret) {}
    virtual ~Produs() {}
    virtual void afisare() const = 0;
    double getPret() const {
        return pret;
    }
};
class ProdusPerisabil : public Produs {
    int zilePanaLaExpirare;
public:
    ProdusPerisabil(const string& nume, double pret, int zile)
        : Produs(nume, pret), zilePanaLaExpirare(zile) {}

    void afisare() const override {
        cout << "Produs perisabil: " << nume
            << ", Pret: " << pret << " lei"
            << ", Expira in " << zilePanaLaExpirare << " zile" << endl;
    }
};
class ProdusNeperisabil : public Produs {
    string categorie;
public:
    ProdusNeperisabil(const string& nume, double pret, const string& categorie)
        : Produs(nume, pret), categorie(categorie) {}
    void afisare() const override {
        cout << "Produs neperisabil: " << nume
            << ", Pret: " << pret << " lei"
            << ", Categorie: " << categorie << endl;
    }
};
class Magazin {
    vector<Produs*> produse;
public:
    Magazin() {}
    ~Magazin() {
        for (auto produs : produse)
            delete produs;
    }
    Magazin(const Magazin& alt) {
        for (auto produs : alt.produse) {
            ProdusPerisabil* pp = dynamic_cast<ProdusPerisabil*>(produs);
            if (pp)
                produse.push_back(new ProdusPerisabil(*pp));
            else {
                ProdusNeperisabil* pnp = dynamic_cast<ProdusNeperisabil*>(produs);
                if (pnp)
                    produse.push_back(new ProdusNeperisabil(*pnp));
            }
        }
    }
    void adaugaProdus(Produs* produs) {
        produse.push_back(produs);
    }
    void afisareProduse() const {
        for (auto produs : produse)
            produs->afisare();
    }
};

int main() {
    Magazin magazin;
    magazin.adaugaProdus(new ProdusPerisabil("Lapte", 5.5, 7));
    magazin.adaugaProdus(new ProdusNeperisabil("Paste", 3.2, "Alimente de bază"));
    magazin.adaugaProdus(new ProdusPerisabil("Fructe", 10.0, 5));
    cout << "Produse in magazin:" << endl;
    magazin.afisareProduse();
    Magazin magazinCopie = magazin;
    cout << "\nProduse in copia magazinului:" << endl;
    magazinCopie.afisareProduse();

    return 0;
}