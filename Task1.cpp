#include<iostream>

using namespace std;

//Domeniu: CINEMATOGRAFIE

class Film {
public:
	static int nrFilme;
	const int serieFilm;
	string numeFilm;
	float buget;
	int nrActori;
	string* actor;

	static int getnrFilme()
	{
		return nrFilme;
	}

	Film():serieFilm(nrFilme++) 
	{
		this->numeFilm = "SpiderMan";
		this->buget = 500.5;
		this->nrActori = 0;
		this->actor = NULL;
	}

	Film(string numeFilm, float buget) :serieFilm(nrFilme) 
	{
		nrFilme++;
		this->numeFilm = numeFilm;
		this->buget = buget;
		this->nrActori = 0;
		this->actor = NULL;
	}
	
	Film(string numeFilm, float buget, int nrActori, string* actor) :serieFilm(nrFilme) 
	{
		nrFilme++;
		this->numeFilm = numeFilm;
		this->buget = buget;
		this->nrActori = nrActori;
		this->actor = new string[nrActori];
		for (int i = 0; i < nrActori; i++) 
		{
			this->actor[i] = actor[i];
		}
	}

	~Film() {
		if (this->actor != NULL) 
		{
			delete[]this->actor;
		}
	}

	void afisareFilm() 
	{
		cout << "Filmul " << numeFilm << " a avut bugetul de " << buget << " milioane dolari, jucand in acesta " << nrActori << " actor/i, precum: ";
		if (nrActori > 0) 
		{
			for (int i = 0; i < nrActori; i++) 
			{

				cout << actor[i] << ", ";
			}
		}
		else 
		{
			cout << "NA";
		}
		cout << endl;
	}

	void adaugareActori(string actor) {
				string* aux = new string[this->nrActori + 1];
				for (int i = 0; i < this->nrActori; i++) {
					aux[i] = this->actor[i];
				}
				aux[this->nrActori] = actor;
				this->nrActori++;
				if (this->actor) {
					delete[]this->actor;
				}
				this->actor = aux;
			}

};

int Film::nrFilme = 100;

class Actor{
public:
	static int fani;
	const int id;
	string nume;
	float screenTime;
	int varsta;
	int nrFilmeJucate;
	string* filmeJucate;
	
	static int getFani() 
	{
		return fani;
	}

	Actor() : id(fani++) 
	{
		this->nume = "Chris Hemsworth";
		this->screenTime = 100.3;
		this->varsta = 37;
		this->nrFilmeJucate = 0;
		this->filmeJucate = NULL;
	}

	Actor(string nume, float screenTime) : id(fani)
	{
		fani++;
		this->nume = nume;
		this->screenTime = screenTime;
		this->varsta = 27;
		this->nrFilmeJucate = 0;
		this->filmeJucate = NULL;
	}

	Actor(string nume, float screenTime, int varsta, int nrFilmeJucate, string* filmeJucate) : id(fani)
	{
		fani++;
		this->nume = nume;
		this->screenTime = screenTime;
		this->varsta = varsta;
		this->nrFilmeJucate = nrFilmeJucate;
		this->filmeJucate = new string[nrFilmeJucate];
		for (int i = 0; i < nrFilmeJucate; i++)
		{
			this->filmeJucate[i] = filmeJucate[i];
		}
	}

	~Actor() {
		if (this->filmeJucate != NULL)
		{
			delete[]this->filmeJucate;
		}
	}

	void afisareActor() 
	{
		cout << "Actorul " << nume << " in varsta de " << varsta << " are un Screen-Time total de " << screenTime << " ore, jucand in "<<nrFilmeJucate <<" filme, precum:";
		if (nrFilmeJucate > 0) {
			for (int i = 0; i < nrFilmeJucate; i++) {
				cout << filmeJucate[i] << ", ";
			}
		}
		else {
			cout << "NA";
		}
		cout << endl;
	}

	void adaugareFilme(string filmeJucate) {
		string* aux = new string[this->nrFilmeJucate + 1];
		for (int i = 0; i < this->nrFilmeJucate; i++) {
			aux[i] = this->filmeJucate[i];
		}
		aux[this->nrFilmeJucate] = filmeJucate;
		this->nrFilmeJucate++;
		if (this->filmeJucate) {
			delete[]this->filmeJucate;
		}
		this->filmeJucate = aux;
	}

};
int Actor::fani = 300;

class Cinema {
public:
	static int nrFilmeDifuzate;
	const int cod;
	string locatie;
	int pretBilet;
	int sali;
	int nrFilme;
	string* filme;

	static int getnrFilmeDifuzate()
	{
		return nrFilmeDifuzate;
	}

	Cinema() :cod(nrFilmeDifuzate++)
	{
		this->locatie = "Afi-Cotroceni";
		this->pretBilet = 23.5;
		this->sali = 0;
		this->nrFilme = 0;
		this->filme = NULL;
	}

	Cinema(string locatie, float pretBilet) :cod(nrFilmeDifuzate)
	{
		nrFilmeDifuzate++;
		this->locatie = locatie;
		this->pretBilet = pretBilet;
		this->sali = 0;
		this->nrFilme = 0;
		this->filme = NULL;
	}

	Cinema(string locatie, float pretBilet, int sali, int nrFilme, string* filmeDifuzate) :cod(nrFilmeDifuzate)
	{
		nrFilmeDifuzate++;
		this->locatie = locatie;
		this->pretBilet = pretBilet;
		this->sali = sali;
		this->nrFilme = 0;
		this->filme = new string[nrFilme];
		for (int i = 0; i < nrFilme; i++)
		{
			this->filme[i] = filme[i];
		}
	}

	~Cinema() {
		if (this->filme != NULL)
		{
			delete[]this->filme;
		}
	}

	void afisareCinema()
	{
		cout << "Cinematograful Cinema-City din " << locatie << " este dotat cu " << sali << " sali, biletele fiind vandute cu pretul de " << pretBilet << " lei, difuzandu-se un numar de filme de: " << nrFilme << ", precum: ";
		if (nrFilme > 0)
		{
			for (int i = 0; i < nrFilme; i++)
			{
				cout << filme[i] << ", ";
			}
		}
		else {
			cout << "NA";
		}
		cout << endl;
	}

	
	void adaugare(string filme) {
		string* aux = new string[this->nrFilme + 1];
		for (int i = 0; i < this->nrFilme; i++) {
			aux[i] = this->filme[i];
		}
		aux[this->nrFilme] = filme;
		this->nrFilme++;
		if (this->filme) {
			delete[]this->filme;
		}
		this->filme = aux;
	}

};
int Cinema::nrFilmeDifuzate = 20;

void main()
{
	Film film1;
	film1.adaugareActori("Tom Holland");
	film1.afisareFilm();

	Film film2("TheProposal", 400.6);
	film2.adaugareActori("Ryan Reynolds");
	film2.afisareFilm();

	string* actor = new string[2];
	actor[0] = "Liam Hemsworth";
	actor[1] = "Josh Hutcherson";
	Film film3("The Hunger Games", 700.8, 2, actor);
	film3.adaugareActori("Jennifer Lawrence");
	film3.afisareFilm();
	
	cout << Film::getnrFilme() << endl;

	

	Actor actor1;
	actor1.adaugareFilme("Thor");
	actor1.afisareActor();

	Actor actor2("Ryan Gosling", 100.6);
	actor2.adaugareFilme("The Notebook");
	actor2.afisareActor();

	string* filmeJucate = new string[2];
	filmeJucate[0] = "Harry Potter";
	filmeJucate[1] = "Beauty and the Beast";
	Actor actor3("Emma Watson", 90.8, 33, 2, filmeJucate);
	actor3.adaugareFilme("Little Women");
	actor3.afisareActor();

	cout << Actor::getFani() << endl;



	Cinema cinema1;
	cinema1.adaugare("IT");
	cinema1.afisareCinema();

	Cinema cinema2("Baneasa",27);
	cinema2.adaugare("This Means War");
	cinema2.afisareCinema();

	string* filme = new string[2];
	filme[0] = "Avatar";
	filme[1] = "Piratii din Caraibe";
	Cinema cinema3("Plaza", 26, 8,2, filme);
	cinema3.afisareCinema();

	cout << Cinema::getnrFilmeDifuzate() << endl;

}