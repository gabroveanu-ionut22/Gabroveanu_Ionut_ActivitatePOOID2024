#include<iostream>
#include<string>

using namespace std;

class Autobuz {
private:
	static int nrAutobuze;
	const int idAutobuz;
	int capacitate;
	int nrPersoaneImbarcate;
	char* producator;

public:
	Autobuz() :idAutobuz(++nrAutobuze) {
		this->capacitate = 0;
		this->nrPersoaneImbarcate = 0;
		this->producator = nullptr;

	}

	Autobuz(int capacitate, int nrPers, char* prod) :idAutobuz(++nrAutobuze) {
		this->capacitate = capacitate;
		this->producator = new char[strlen(prod) + 1];
		strcpy(this->producator, prod);
		if (nrPers <= this->capacitate)
		{
			this->nrPersoaneImbarcate = nrPers;
		}
		else
		{
			cout << "Datele introduse nu sunt valide. Numarul de persoane imbarcate depaseste capacitatea autobuzului " << this->idAutobuz << ".";
			nrAutobuze--;
			throw runtime_error("Eroare.");
		}


	}

	Autobuz(const Autobuz& a) :idAutobuz(++nrAutobuze) {
		this->capacitate = a.capacitate;
		this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
		if (a.producator != nullptr) {
			this->producator = new char[strlen(a.producator) + 1];
			strcpy(this->producator, a.producator);
		}
		else this->producator = nullptr;

	}


	~Autobuz() {
		cout << "Obiect sters.";
		if (this->producator != nullptr) {
			delete[] producator;
		}

	}



	int getCapacitate() {
		return this->capacitate;
	}

	void setCapacitate(int cap) {
		this->capacitate = cap;
	}
	int getNrPersoaneImbarcate() {
		return this->nrPersoaneImbarcate;
	}
	void setNrPersoaneImbarcate(int nrPersoaneImbarcate) {
		if (nrPersoaneImbarcate <= this->capacitate) {
			this->nrPersoaneImbarcate = nrPersoaneImbarcate;
		}
		else cout << "Actualizare esuata. Numarul de pasageri este mai mare decat capacitatea autobuzului.";
	}
	int getNumarLocuriLibere() {
		return this->capacitate - this->nrPersoaneImbarcate;
	}


	const Autobuz& operator=(const Autobuz& at) {
		if (this == &at) {
			return *this;
		}
		this->capacitate = at.capacitate;
		this->nrPersoaneImbarcate = at.nrPersoaneImbarcate;
		if (this->producator != nullptr) {
			delete[] this->producator;
		}
		this->producator = new char[strlen(at.producator) + 1];
		strcpy(this->producator, at.producator);
		return *this;
	}

	operator int() const {
		return this->nrPersoaneImbarcate;
	}

	bool operator>(const Autobuz& at) {
		if (this->capacitate > at.capacitate) {
			return true;
		}
		else return false;
	}

};

int Autobuz::nrAutobuze = 0;
int main() {
	Autobuz alfa;
	char test[] = "test";
	Autobuz beta(30, 25, test);
	Autobuz delta(41, 15, test);

	cout << beta.getNumarLocuriLibere() << "\n";
	cout << int(beta) << "\n";
	cout << (delta > beta) << "\n";

	Autobuz gama(beta);
	alfa = beta;

	beta.setCapacitate(40);
	cout << beta.getCapacitate() << "\n";
	beta.setNrPersoaneImbarcate(23);
	cout << beta.getNrPersoaneImbarcate() << "\n";

}
