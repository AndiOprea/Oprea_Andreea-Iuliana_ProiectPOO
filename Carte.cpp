#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


class Carte {
private:
	static int nrVolume;
	const int editie;
	string titlu;
	float pret;
	bool bestseller;
	int nrPersonaje;
	string* numePersonaje;

public:
	static int getNrVolme()
	{
		return nrVolume;
	}

	Carte() : editie(nrVolume++) {
		this->titlu = "Throne of Glass";
		this->pret = 50.7;
		this->bestseller = true;
		this->nrPersonaje = 0;
		this->numePersonaje = NULL;
	}

	Carte(string titlu, float pret) :editie(nrVolume)
	{
		nrVolume++;
		this->titlu = titlu;
		this->pret = pret;
		this->bestseller = true;
		this->nrPersonaje = 0;
		this->numePersonaje = NULL;
	}

	Carte(string titlu, float pret, bool bestseller, int nrPersonaje, string* numePersonaje) : editie(nrVolume)
	{
		nrVolume++;
		this->titlu = titlu;
		this->pret = pret;
		this->bestseller = bestseller;
		this->nrPersonaje = nrPersonaje;
		this->numePersonaje = new string[nrPersonaje];
		for (int i = 0; i < nrPersonaje; i++)
		{
			this->numePersonaje[i] = numePersonaje[i];
		}
	}

	Carte(const Carte& carte1) :editie(nrVolume++)
	{
		this->titlu = carte1.titlu;
		this->pret = carte1.pret;
		this->bestseller = carte1.bestseller;
		this->nrPersonaje = carte1.nrPersonaje;
		this->numePersonaje = new string[carte1.nrPersonaje];
		for (int i = 0; i < carte1.nrPersonaje; i++)
		{
			this->numePersonaje[i] = carte1.numePersonaje[i];
		}
	}

	Carte operator=(const Carte& carte1)
	{
		if (this != &carte1)
		{
			this->titlu = carte1.titlu;
			this->pret = carte1.pret;
			this->bestseller = carte1.bestseller;
			this->nrPersonaje = carte1.nrPersonaje;
			if (this->numePersonaje != NULL)
			{
				delete[]this->numePersonaje;
			}
			this->numePersonaje = new string[carte1.nrPersonaje];
			for (int i = 0; i < carte1.nrPersonaje; i++)
			{
				this->numePersonaje[i] = carte1.numePersonaje[i];
			}
		}
		return *this;
	}

	Carte operator+(Carte c)
	{
		Carte aux = *this;
		aux.titlu = this->titlu + c.titlu;
		aux.pret = this->pret + c.pret;
		aux.nrPersonaje = this->nrPersonaje + c.nrPersonaje;
		if (aux.numePersonaje != NULL)
		{
			delete[]aux.numePersonaje;
		}
		aux.numePersonaje = new string[aux.nrPersonaje];
		for (int i = 0; i < this->nrPersonaje; i++)
		{
			aux.numePersonaje[i] = this->numePersonaje[i];
		}
		for (int i = this->nrPersonaje; i < aux.nrPersonaje; i++)
		{
			aux.numePersonaje[i] = c.numePersonaje[i - this->nrPersonaje];
		}
		return aux;
	}

	friend ostream& operator<<(ostream& monitor, const Carte& c)
	{
		monitor << "Titlu: " << c.titlu << endl;;
		monitor << "Pret: " << c.pret << endl;
		monitor << "Nr personaje: " << c.nrPersonaje << endl;
		monitor << "Personajele sunt: ";
		for (int i = 0; i < c.nrPersonaje; i++)
		{
			monitor << c.numePersonaje[i] << ", ";
		}
		monitor << endl;
		monitor << (c.bestseller ? "Cartea este bestseller" : "Nu e bestseller");
		return monitor;
	}

	friend istream& operator>>(istream& intr, Carte& c)
	{
		cout << "Titlu: ";
		intr >> c.titlu;
		cout << "Pret: ";
		intr >> c.pret;
		cout << "Bestseller: 0-NU, altceva-DA ";
		intr >> c.bestseller;
		cout << "Numar de personaje: ";
		intr >> c.nrPersonaje;
		if (c.numePersonaje != NULL)
		{
			delete[]c.numePersonaje;
		}
		cout << "Personajele sunt: ";
		c.numePersonaje = new string[c.nrPersonaje];
		for (int i = 0; i < c.nrPersonaje; i++)
		{
			intr >> c.numePersonaje[i];
		}
		return intr;
	}

	friend ofstream& operator<<(ofstream& monitor, const Carte& c)
	{
		monitor << c.titlu << endl;
		monitor << c.pret << endl;
		monitor << c.nrPersonaje << endl;
		if (c.nrPersonaje > 0)
		{
			for (int i = 0; i < c.nrPersonaje; i++)
			{
				monitor << c.numePersonaje[i] << ", ";
			}
		}
		monitor << endl;
		monitor << c.bestseller;
		return monitor;
	}

	friend ifstream& operator>>(ifstream& intr, Carte& c)
	{
		intr >> c.titlu;
		intr >> c.pret;
		intr >> c.bestseller;
		intr >> c.nrPersonaje;
		if (c.numePersonaje != NULL)
		{
			delete[]c.numePersonaje;
		}
		c.numePersonaje = new string[c.nrPersonaje];
		for (int i = 0; i < c.nrPersonaje; i++)
		{
			intr >> c.numePersonaje[i];
		}
		return intr;
	}

	int getEditie()
	{
		return editie;
	}

	string getTitlu()
	{
		return titlu;
	}

	float getPret()
	{
		return pret;
	}

	bool getBestseller()
	{
		return bestseller;
	}

	int getnrPersonaje()
	{
		return nrPersonaje;
	}

	string* getNumePersonaje()
	{
		return numePersonaje;
	}

	void setPret(float pret)
	{
		if (pret > 0)
		{
			this->pret = pret;
		}
	}

	void setPersonaje(int nrPersonaje, string* numePersonaje)
	{
		if (nrPersonaje > 0)
		{
			this->nrPersonaje = nrPersonaje;
			if (this->nrPersonaje != NULL)
			{
				delete[]this->numePersonaje;
			}
			this->numePersonaje = new string[nrPersonaje];
			for (int i = 0; i < nrPersonaje; i++)
			{
				this->numePersonaje[i] = numePersonaje[i];
			}
		}
	}

	void setBestseller(bool bestseller)
	{
		if (bestseller == true)
		{
			this->bestseller = bestseller;
		}
		else this->bestseller = bestseller;
	}

	void setNrPersonaje(int nrPersonaje)
	{
		if (nrPersonaje > 0)
			this->nrPersonaje = nrPersonaje;
	}

	void setTitlu(string titlu)
	{
		if (titlu.length() > 3)
			this->titlu = titlu;
	}

	~Carte() {
		if (this->numePersonaje != NULL)
		{
			delete[]this->numePersonaje;
		}
	}

	void afisareCarte()
	{
		cout << "Cartea " << titlu << " are prettul de " << pret << " lei ";
		if (bestseller == true)cout << " si a catigat titlul de bestseller, avand un numar de " << nrPersonaje << " personaj/e: ";
		else cout << " si desi nu este bestseller, este o carte care se merita citita datorita celor " << nrPersonaje << " personaje: ";
		if (nrPersonaje > 0)
		{
			for (int i = 0; i < nrPersonaje; i++)\
			{
				cout << numePersonaje[i];
			}
		}
		else cout << "NA";
		cout << endl;
	}

	void adaugarePersonaj(string numePersonaje)
	{
		string* aux = new string[this->nrPersonaje + 1];
		for (int i = 0; i < this->nrPersonaje; i++)
		{
			aux[i] = this->numePersonaje[i];
		}
		aux[this->nrPersonaje] = numePersonaje;
		this->nrPersonaje++;
		if (this->numePersonaje)
		{
			delete[]this->numePersonaje;
		}
		this->numePersonaje = aux;
	}

	friend string getSirPersonaje(const Carte& c);
	friend int getNrPersonaje(const Carte& c);
};

int Carte::nrVolume = 7;

string getSirPersonaje(const Carte& c)
{
	string aux = "";
	for (int i = 0; i < c.nrPersonaje; i++)
	{
		aux += c.numePersonaje[i] + ",";
	}
	return aux;
}

int getNrPersonaje(const Carte& c)
{
	return c.nrPersonaje;
}

class Autor
{
private:
	string numeAutor;
	int varsta;
	Carte carte;
public:

	Autor()
	{
		this->numeAutor = "Sarah J. Mass";
		this->varsta = 40;
	}

	Autor(string numeAutor, int varsta, Carte& carte)
	{
		this->numeAutor = numeAutor;
		this->varsta = varsta;
		this->carte = carte;
	}

	Autor(Carte& carte)
	{
		this->numeAutor = "Sarah J. Mass";
		this->varsta = 40;
		this->carte = carte;
	}

	string getNumeAutor()
	{
		return numeAutor;
	}

	void setNumeAutor(string numeAutor)
	{
		this->numeAutor = numeAutor;
	}

	int getVarsta()
	{
		return varsta;
	}

	void setVarsta(int varsta)
	{
		if (this->varsta > 0)
		{
			this->varsta = varsta;
		}
	}

	int getCarteAutor()
	{
		cout << "Cartea " << carte.getTitlu() << " a fost scrisa de " << numeAutor << " ,in varsta de ";
		return varsta;
	}

	void setCarteAutor(Carte& carte)
	{
		this->carte = carte;
	}

	Autor operator=(const Autor& a)
	{
		this->numeAutor = a.numeAutor;
		this->varsta = a.varsta;
		this->carte = a.carte;
		return *this;
	}

	friend ostream& operator<<(ostream& afis, const Autor& a)
	{
		afis << "Numele autorului: " << a.numeAutor << endl;
		afis << "Varsta autorului: " << a.varsta << endl;
		afis << "Informatii despre cartea autorului: " << a.carte;
		return afis;
	}

	friend istream& operator>>(istream& cit, Autor& a)
	{
		cout << "Numele autorului: ";
		cit >> a.numeAutor;
		cout << "Varsta autorului: ";
		cit >> a.varsta;
		cout << "Cartea autorului: ";
		cit >> a.carte;
		return cit;
	}


	void afisareAutor()
	{
		cout << "Numele autorului este: " << numeAutor << " ,in varsta de " << varsta << " de ani." << endl;
		carte.afisareCarte();
	}
};



class Album {
private:
	static int nrAlbum;
	const int anAlbum;
	string numeAlbum;
	string artist;
	int nrPiese;
	string* titluPiese;
public:
	static int getnrAlbum()
	{
		return nrAlbum;
	}

	Album() :anAlbum(nrAlbum++)
	{
		this->numeAlbum = "Midnights";
		this->artist = "Taylor Swift";
		this->nrPiese = 0;
		this->titluPiese = NULL;
	}

	Album(string numeAlbum, string artist) : anAlbum(nrAlbum)
	{
		nrAlbum++;
		this->numeAlbum = numeAlbum;
		this->artist = artist;
		this->nrPiese = 0;
		this->titluPiese = NULL;
	}

	Album(string numeAlbum, string artist, int nrPiese, string* titluPiese) : anAlbum(nrAlbum)
	{
		nrAlbum++;
		this->numeAlbum = numeAlbum;
		this->artist = artist;
		this->nrPiese = nrPiese;
		this->titluPiese = new string[nrPiese];
		for (int i = 0; i < nrPiese; i++)
		{
			this->titluPiese[i] = titluPiese[i];
		}
	}

	Album(const Album& album2) : anAlbum(nrAlbum++)
	{
		this->numeAlbum = album2.numeAlbum;
		this->artist = album2.artist;
		this->nrPiese = album2.nrPiese;
		this->titluPiese = new string[album2.nrPiese];
		for (int i = 0; i < album2.nrPiese; i++)
		{
			this->titluPiese[i] = album2.titluPiese[i];
		}
	}

	Album operator=(const Album& album1)
	{
		if (this != &album1)
			this->numeAlbum = album1.numeAlbum;
		this->artist = album1.artist;
		this->nrPiese = album1.nrPiese;
		if (this->titluPiese != NULL)
		{
			delete[]this->titluPiese;
		}
		this->titluPiese = new string[album1.nrPiese];
		for (int i = 0; i < album1.nrPiese; i++)
		{
			this->titluPiese[i] = album1.titluPiese[i];
		}
		return *this;
	}

	Album operator+=(const Album& a)
	{
		int auxNrPiese = this->nrPiese + a.nrPiese;
		string* auxTitluPiese = new string[auxNrPiese];
		for (int i = 0; i < this->nrPiese; i++)
		{
			auxTitluPiese[i] = this->numeAlbum[i];
		}
		for (int i = this->nrPiese; i < auxNrPiese; i++)
		{
			auxTitluPiese[i] = a.titluPiese[i - this->nrPiese];
		}
		this->nrPiese = auxNrPiese;
		if (this->titluPiese != NULL)
		{
			delete[]this->titluPiese;
		}
		this->titluPiese = auxTitluPiese;
		return *this;
	}

	friend ostream& operator<<(ostream& monitor, const Album& a)
	{
		monitor << "Nume album: " << a.numeAlbum << " ";
		monitor << "Artist: " << a.artist << endl;
		monitor << "Nr piese" << a.nrPiese << endl;
		monitor << "Piesele sunt: ";
		for (int i = 0; i < a.nrPiese; i++)
		{
			monitor << a.titluPiese[i] << ", ";
		}
		monitor << endl;
		return monitor;
	}

	friend istream& operator>>(istream& intr, Album& a)
	{
		cout << "Nume album: ";
		intr >> a.numeAlbum;
		cout << "Artist: ";
		intr >> a.artist;
		cout << "Numar piese: ";
		intr >> a.nrPiese;
		if (a.titluPiese != NULL)
		{
			delete[]a.titluPiese;
		}
		cout << "Piesele sunt: ";
		a.titluPiese = new string[a.nrPiese];
		for (int i = 0; i < a.nrPiese; i++)
		{
			intr >> a.titluPiese[i];
		}
		return intr;
	}

	friend ofstream& operator<<(ofstream& monitor, const Album& a)
	{
		monitor << a.numeAlbum << " ";
		monitor << a.artist << endl;
		monitor << a.nrPiese << endl;
		for (int i = 0; i < a.nrPiese; i++)
		{
			monitor << a.titluPiese[i] << ", ";
		}
		monitor << endl;
		return monitor;
	}

	friend ifstream& operator>>(ifstream& intr, Album& a)
	{
		intr >> a.numeAlbum;
		intr >> a.artist;
		intr >> a.nrPiese;
		if (a.titluPiese != NULL)
		{
			delete[]a.titluPiese;
		}
		a.titluPiese = new string[a.nrPiese];
		for (int i = 0; i < a.nrPiese; i++)
		{
			intr >> a.titluPiese[i];
		}
		return intr;
	}

	bool operator!=(Album& a)
	{
		return this->nrPiese != a.nrPiese;
	}

	bool operator<(Album& a)
	{
		return this->nrPiese < a.nrPiese;
	}

	int getAnAlbum()
	{
		return anAlbum;
	}

	string getNumeAlbum()
	{
		return numeAlbum;
	}

	string getArtist()
	{
		return artist;
	}

	int getNrPiese()
	{
		return nrPiese;
	}

	string* getTitluPiese()
	{
		return titluPiese;
	}

	void setNumeAlbum(string numeAlbum)
	{
		if (numeAlbum.length() > 3)
			this->numeAlbum = numeAlbum;
	}

	void setArtist(string artist)
	{
		if (artist.length() > 3)
			this->artist = artist;
	}

	void setNrPiese(int nrPiese)
	{
		if (nrPiese > 0)
			this->nrPiese = nrPiese;
	}

	void setTitluPiese(int nrPiese, string* titluPiese)
	{
		if (nrPiese > 0)
		{
			this->nrPiese = nrPiese;
			if (this->nrPiese != NULL)
			{
				delete[]this->titluPiese;
			}
			this->titluPiese = new string[nrPiese];
			for (int i = 0; i < nrPiese; i++)
			{
				this->titluPiese[i] = titluPiese[i];
			}
		}
	}

	~Album()
	{
		if (this->titluPiese != NULL)
		{
			delete[]this->titluPiese;
		}
	}

	void afisareAlbum()
	{
		cout << artist << " a scos albumulul " << numeAlbum << " ce contine " << nrPiese << " melodii, precum: ";
		if (nrPiese > 0)
		{
			for (int i = 0; i < nrPiese; i++)
			{
				cout << titluPiese[i] << ", ";
			}
		}
		else cout << "NA";
		cout << endl;
	}

	void adaugarePiese(string titluPiese)
	{
		string* aux = new string[this->nrPiese + 1];
		for (int i = 0; i < this->nrPiese; i++)
		{
			aux[i] = this->titluPiese[i];
		}
		aux[this->nrPiese] = titluPiese;
		this->nrPiese++;
		if (this->titluPiese)
		{
			delete[]this->titluPiese;
		}
		this->titluPiese = aux;
	}

	friend string getSirNumePiese(const Album& a);

	friend int getNrPiese1(const Album& a);
};

int Album::nrAlbum = 0;

string getSirNumePiese(const Album& a)
{
	string aux = "";
	for (int i = 0; i < a.nrPiese; i++)
	{
		aux += a.titluPiese[i] + ",";
	}
	return aux;
}

int getNrPiese1(const Album& a)
{
	return a.nrPiese;
}



class Tablou {
private:
	static int nrTablou;
	const int serie;
	string denumire;
	string pictor;
	int nrLucrari;
	string* numeLucrari;
public:
	static int getnrTablou()
	{
		return nrTablou;
	}

	Tablou() : serie(nrTablou++)
	{
		this->denumire = "Noapte";
		this->pictor = "Ana Popescu";
		this->nrLucrari = 0;
		this->numeLucrari = NULL;
	}

	Tablou(string denumire, string pictor) : serie(nrTablou)
	{
		nrTablou++;
		this->denumire = denumire;
		this->pictor = pictor;
		this->nrLucrari = 0;
		this->numeLucrari = NULL;
	}

	Tablou(string denumire, string pictor, int nrLucrari, string* numeLucrari) : serie(nrTablou)
	{
		nrTablou++;
		this->denumire = denumire;
		this->pictor = pictor;
		this->nrLucrari = nrLucrari;
		this->numeLucrari = new string[nrLucrari];
		for (int i = 0; i < nrLucrari; i++)
		{
			this->numeLucrari[i] = numeLucrari[i];
		}
	}

	Tablou(const Tablou& tablou3) :serie(nrTablou++)
	{
		this->denumire = tablou3.denumire;
		this->pictor = tablou3.pictor;
		this->nrLucrari = tablou3.nrLucrari;
		this->numeLucrari = new string[tablou3.nrLucrari];
		for (int i = 0; i < tablou3.nrLucrari; i++)
		{
			this->numeLucrari[i] = tablou3.numeLucrari[i];
		}
	}

	Tablou operator=(Tablou& tablou3)
	{
		if (this != NULL)
		{
			this->denumire = tablou3.denumire;
			this->pictor = tablou3.pictor;
			this->nrLucrari = tablou3.nrLucrari;
			if (this->numeLucrari != NULL)
			{
				delete[]this->numeLucrari;
			}
			this->numeLucrari = new string[tablou3.nrLucrari];
			for (int i = 0; i < tablou3.nrLucrari; i++)
			{
				this->numeLucrari[i] = tablou3.numeLucrari[i];
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& monitor, const Tablou& t)
	{
		monitor << "Denumire: " << t.denumire << " ";
		monitor << "Pictor: " << t.pictor << endl;
		monitor << "Nr lucrari" << t.nrLucrari << endl;
		monitor << "Lucrarile sunt: ";
		for (int i = 0; i < t.nrLucrari; i++)
		{
			monitor << t.numeLucrari[i] << ", ";
		}
		monitor << endl;
		return monitor;
	}

	friend istream& operator>>(istream& intr, Tablou& t)
	{
		cout << "Denumire: ";
		intr >> t.denumire;
		cout << "Pictor: ";
		intr >> t.pictor;
		cout << "Numar lucrari: ";
		intr >> t.nrLucrari;
		if (t.numeLucrari != NULL)
		{
			delete[]t.numeLucrari;
		}
		cout << "Lucrarile sunt: ";
		t.numeLucrari = new string[t.nrLucrari];
		for (int i = 0; i < t.nrLucrari; i++)
		{
			intr >> t.numeLucrari[i];
		}
		return intr;
	}

	bool operator>(Tablou t)
	{
		return this->nrLucrari > t.nrLucrari;
	}

	bool operator<=(Tablou t)
	{
		return this->nrLucrari <= t.nrLucrari;
	}

	string operator[](int i)
	{
		if (i >= 0 && i < nrLucrari)
		{
			return numeLucrari[i];
		}
	}

	int getSerie()
	{
		return serie;
	}

	string getDenumire()
	{
		return denumire;
	}

	string getPictor()
	{
		return pictor;
	}

	int getNrLucrari()
	{
		return nrLucrari;
	}

	string* getNumeLucrari()
	{
		return numeLucrari;
	}

	void setDenumire(string denumire)
	{
		if (denumire.length() > 3)
			this->denumire = denumire;
	}

	void setPictor(string pictor)
	{
		if (pictor.length() > 3)
			this->pictor = pictor;
	}

	void setNrLucrari(int nrLucrari)
	{
		if (nrLucrari > 0)
			this->nrLucrari = nrLucrari;
	}

	void setNumeLucrari(int nrLucrari, string* numeLucrari)
	{
		if (nrLucrari > 0)
		{
			this->nrLucrari = nrLucrari;
			if (this->nrLucrari != NULL)
			{
				delete[]this->numeLucrari;
			}
			this->numeLucrari = new string[nrLucrari];
			for (int i = 0; i < nrLucrari; i++)
			{
				this->numeLucrari[i] = numeLucrari[i];
			}
		}
	}

	~Tablou()
	{
		if (this->numeLucrari != 0)
		{
			delete[]this->numeLucrari;
		}
	}

	void afisareTablou()
	{
		cout << "Artistul " << pictor << " a realizat tabloul " << denumire << ", iar inainte de acesta se putea lauda cu " << nrLucrari << " tablouri, precum: ";
		if (nrLucrari > 0)
		{
			for (int i = 0; i < nrLucrari; i++)
			{
				cout << numeLucrari[i] << ", ";
			}
		}
		else cout << "NA";
		cout << endl;
	}

	void adaugareLucrare(string numeLucrari)
	{
		string* aux = new string[this->nrLucrari + 1];
		for (int i = 0; i < this->nrLucrari; i++)
		{
			aux[i] = this->numeLucrari[i];
		}
		aux[this->nrLucrari] = numeLucrari;
		this->nrLucrari++;
		if (this->numeLucrari)
		{
			delete[]this->numeLucrari;
		}
		this->numeLucrari = aux;
	}

	friend string getSirNumeLucrari(const Tablou& t);

	friend int getNrLucrari1(const Tablou& t);
};

int Tablou::nrTablou = 0;

string getSirNumeLucrari(const Tablou& t)
{
	string aux = "";
	for (int i = 0; i < t.nrLucrari; i++)
	{
		aux += t.numeLucrari[i] + ",";
	}
	return aux;
}

int getNrLucrari1(const Tablou& t)
{
	return t.nrLucrari;
}


//void main()
//{
//	//task01
//
//	Carte carte1;
//	carte1.adaugarePersonaj("Aelin Ashryver.");
//	carte1.afisareCarte();
//
//	Carte carte2("Red Rising", 60);
//	carte2.adaugarePersonaj("Darrow O'Lykos.");
//	carte2.afisareCarte();
//
//	string* numePersonaje = new string[3];
//	numePersonaje[0] = "Pippa Fitz-Amobi, ";
//	numePersonaje[1] = "Ravi Singh, ";
//	numePersonaje[2] = "Andie Bell. ";
//	Carte carte3("A Good Girl's Guide to Murder", 57.6, false, 3, numePersonaje);
//	carte3.afisareCarte();
//
//	//task02
//
//	Carte carte4 = carte1;
//	carte4.afisareCarte();
//
//	cout << carte1.getNrVolme() << endl;
//
//	cout << carte1.getEditie() << endl;
//
//	cout << carte3.getTitlu() << endl;
//	carte3.setTitlu("Hunger Games");
//	cout << carte3.getTitlu() << endl;
//
//	cout << carte2.getPret() << endl;
//	carte2.setPret(34.5);
//	cout << carte2.getPret() << endl;
//
//	cout << carte1.getBestseller() << endl;
//	carte1.setBestseller(false);
//	cout << carte1.getBestseller() << endl;
//
//	cout << carte2.getnrPersonaje() << endl;
//	//carte2.setNrPersonaje(3);
//	cout << carte2.getnrPersonaje() << endl;
//
//	cout << carte3.getNumePersonaje()[1] << endl;
//	string* vector = new string[2]{ "Rowan Whitethorn, ", " Dorian Havilliard" };
//	carte3.setPersonaje(2, vector);
//	carte3.afisareCarte();
//
//	cout << getSirPersonaje(carte1) << endl;
//	cout << getNrPersonaje(carte2) << endl;
//
//	//task03
//
//	//Carte carte5 = carte4;
//
//
//	cout << endl << endl;
//	///carte5 = carte4;
//
//	cout << carte1 << endl << carte2;
//
//
//	Carte carte5 = carte1 + carte2;
//
//	cout << carte5;
//
//	/*Carte carte6;
//	cin >> carte6;
//	cout << carte6;*/
//
//	//task04
//
//	const int numar_obiecteC = 2;
//	std::vector<Carte> vectorCarte(numar_obiecteC);
//
//	for (int i = 0; i < numar_obiecteC; ++i) 
//	{
//		cout << "Introduceti datele pentru obiectul Carte la pozitia " << i << ":\n";
//		cin >> vectorCarte[i];
//	}
//	cout << endl << endl;
//	for (int i = 0; i < numar_obiecteC; ++i) 
//	{
//		cout << "Afisare obiect Carte la pozitia " << i << ":\n";
//		cout << vectorCarte[i];
//	}
//
//	const int numar_linii = 2;
//	const int numar_coloane = 2;
//
//	Carte matriceCarte[numar_linii][numar_coloane];
//
//	for (int i = 0; i < numar_linii; ++i) 
//	{
//		for (int j = 0; j < numar_coloane; ++j) 
//		{
//			cout << "Introduceti datele pentru obiectul Carte la pozitia [" << i << "][" << j << "]:\n";
//			cin >> matriceCarte[i][j];
//			cout << endl;
//		}
//	}
//
//	for (int i = 0; i < numar_linii; ++i) 
//	{
//		for (int j = 0; j < numar_coloane; ++j) 
//		{
//			cout << "Afisare obiect Carte la pozitia [" << i << "][" << j << "]:\n";
//			cout << matriceCarte[i][j];
//		}
//	}
//
//
//	//task01
//
//	Album album1;
//	album1.adaugarePiese("Karma");
//	album1.afisareAlbum();
//
//	Album album2("Death of an Optimist", "Grandson");
//	album2.adaugarePiese("Bury with my face down");
//	album2.afisareAlbum();
//
//	string* titluPiese = new string[2];
//	titluPiese[0] = "Bones";
//	titluPiese[1] = "Lonely";
//	Album album3("Mercury", "Imagine Dragons", 2, titluPiese);
//	album3.adaugarePiese("Sharks");
//	album3.afisareAlbum();
//
//	//task02
//
//	Album album4 = album2;
//	album4.afisareAlbum();
//
//	cout << Album::getnrAlbum() << endl;
//
//	cout << album1.getAnAlbum() << endl;
//
//	cout << album1.getNumeAlbum() << endl;
//	album1.setNumeAlbum("Reputation");
//	cout << album1.getNumeAlbum() << endl;
//
//	cout << album2.getArtist() << endl;
//	album2.setArtist("Eminem");
//	cout << album2.getArtist() << endl;
//
//	cout << album3.getNrPiese() << endl;
//	album3.setNrPiese(2);
//	cout << album3.getNrPiese() << endl;
//
//	cout << album3.getTitluPiese()[2] << endl;
//	string* vector1 = new string[2]{ "Demons, ", " Life" };
//	album3.setTitluPiese(2, vector1);
//	album3.afisareAlbum();
//
//	cout << getSirNumePiese(album1) << endl;
//
//	cout << getNrPiese1(album2) << endl;
//
//	//task03
//	Album album5;
//	album5 = album3;
//
//	//task04
//	cout << album4;
//
//	const int numar_obiecteA = 2;
//	std::vector<Album> vectorAlbum(numar_obiecteC);
//
//	for (int i = 0; i < numar_obiecteA; ++i) 
//	{
//		cout << "Introduceti datele pentru obiectul Album la pozitia " << i << ":\n";
//		cin >> vectorAlbum[i];
//	}
//	cout << endl << endl;
//	for (int i = 0; i < numar_obiecteA; ++i)
//	{
//		cout << "Afisare obiect Album la pozitia " << i << ":\n";
//		cout << vectorAlbum[i];
//	}
//
//	const int numar_linii1 = 2;
//	const int numar_coloane1 = 2;
//
//	Album matriceAlbum[numar_linii1][numar_coloane1];
//
//	for (int i = 0; i < numar_linii1; ++i) 
//	{
//		for (int j = 0; j < numar_coloane1; ++j) 
//		{
//			cout << "Introduceti datele pentru obiectul Album la pozitia [" << i << "][" << j << "]:\n";
//			cin >> matriceAlbum[i][j];
//			cout << endl;
//		}
//	}
//
//	for (int i = 0; i < numar_linii1; ++i) 
//	{
//		for (int j = 0; j < numar_coloane1; ++j) 
//		{
//			cout << "Afisare obiect Album la pozitia [" << i << "][" << j << "]:\n";
//			cout << matriceAlbum[i][j];
//		}
//	}
//
//
//	//task01
//
//	Tablou tablou1;
//	tablou1.adaugareLucrare("Dimineata");
//	tablou1.afisareTablou();
//
//	Tablou tablou2("Viziune", "Sebastian Stan");
//	tablou2.adaugareLucrare("Intuneric");
//	tablou2.afisareTablou();
//
//	string* numeLucrari = new string[2];
//	numeLucrari[0] = "In afara";
//	numeLucrari[1] = "Exclus";
//	Tablou tablou3("Reluare", "Andrei Petrescu", 2, numeLucrari);
//	tablou3.adaugareLucrare("Trecut");
//	tablou3.afisareTablou();
//
//	//task02
//
//	Tablou tablou4 = tablou3;
//	tablou4.afisareTablou();
//
//	cout << Tablou::getnrTablou() << endl;
//
//	cout << tablou1.getSerie() << endl;
//
//	cout << tablou1.getDenumire() << endl;
//	tablou1.setDenumire("Apus de Soare");
//	cout << tablou1.getDenumire() << endl;
//
//	cout << tablou2.getPictor() << endl;
//	tablou2.setPictor("Mihai Anghel");
//	cout << tablou2.getPictor() << endl;
//
//	cout << tablou3.getNrLucrari() << endl;
//	tablou3.setNrLucrari(3);
//	cout << tablou3.getNrLucrari() << endl;
//
//	cout << tablou1.getNumeLucrari()[0] << endl;
//	string* vector2 = new string[1]{ " Demoni " };
//	tablou1.setNumeLucrari(1, vector2);
//	tablou1.afisareTablou();
//
//	cout << getSirNumeLucrari(tablou1) << endl;
//
//	cout << getNrLucrari1(tablou2) << endl;
//
//	//task03
//
//	Tablou tablou5;
//	tablou5 = tablou2;
//
//	//task04
//
//	cout << tablou5;
//
//	const int numar_obiecteT = 2;
//	std::vector <Tablou> vectorTablou(numar_obiecteC);
//
//	for (int i = 0; i < numar_obiecteT; ++i) 
//	{
//		cout << "Introduceti datele pentru obiectul Tablou la pozitia " << i << ":\n";
//		cin >> vectorTablou[i];
//	}
//	cout << endl << endl;
//	for (int i = 0; i < numar_obiecteT; ++i) 
//	{
//		cout << "Afisare obiect Tablou la pozitia " << i << ":\n";
//		cout << vectorTablou[i];
//	}
//
//	const int numar_linii2 = 2;
//	const int numar_coloane2 = 2;
//
//	Tablou matriceTablou[numar_linii2][numar_coloane2];
//
//	for (int i = 0; i < numar_linii2; ++i) 
//	{
//		for (int j = 0; j < numar_coloane2; ++j) 
//		{
//			cout << "Introduceti datele pentru obiectul Tablou la pozitia [" << i << "][" << j << "]:\n";
//			cin >> matriceTablou[i][j];
//			cout << endl;
//		}
//	}
//
//	for (int i = 0; i < numar_linii2; ++i) 
//	{
//		for (int j = 0; j < numar_coloane2; ++j) 
//		{
//			cout << "Afisare obiect Tablou la pozitia [" << i << "][" << j << "]:\n";
//			cout << matriceTablou[i][j];
//		}
//	}
//}

void main()
{
	Carte c1;
	cin >> c1;
	string* numePersonaje = new string[3];
	numePersonaje[0] = " ";
	numePersonaje[1] = " ";
	numePersonaje[2] = " ";
	Carte c2("The_Maze_Runner", 58.9, 1, 3, numePersonaje);
	ofstream afisare("carte.txt", ios::out);
	afisare << c2;
	afisare.close();

	ifstream citire("carte.txt", ios::in);
	citire >> c2;
	cout << c2;
	citire.close();

	char sir[100] = "text salvat in fisier binar";

	float pret = 50.7;
	fstream f("carte.bin", ios::out | ios::binary);

	f.write((char*)&pret, sizeof(float));
	int lungime = strlen(sir) + 1;
	f.write((char*)&lungime, sizeof(int));
	f.write((char*)sir, lungime);
	f.close();

	fstream g("carte.bin", ios::binary | ios::in);

	float pretCitit;
	char* pSir;
	int lungimeCitita;

	g.read((char*)&pretCitit, sizeof(float));

	g.read((char*)&pretCitit, sizeof(float));
	g.read((char*)&lungimeCitita, sizeof(int));
	pSir = new char[lungimeCitita];
	g.read((char*)pSir, lungimeCitita);
	g.close();
	cout << pretCitit << " " << pSir;
	delete[]pSir;
}
