#include <iostream>
#include <iomanip>
#include <fstream>
#include <unistd.h>

using namespace std;

///////////////////////////////////////////////KLASA PUNKT_1D///////////////////////////////////////////////
class Punkt_1D
{

public:
		double Wspolrzedna_X;

		Punkt_1D ();//KONSTRUKTOR
		void wypisz();//Wypisanie wspolrzednych 
		//void ZapisWspolrzednychDoPlikuPunkt_1D(ostream&     StrmWy);
		//bool PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku);
};

void Punkt_1D::wypisz()
{
cout<<"Wspolrzedna 0X:  "<<Wspolrzedna_X<<endl;
}

Punkt_1D::Punkt_1D()
{
cout<<"Podaj wspolrzedna 0X: ";
double tmp_x;
cin>>tmp_x;
Wspolrzedna_X=tmp_x;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////KLASA PUNKT_2D///////////////////////////////////////////////
class Punkt_2D: public Punkt_1D
{

public:
		double Wspolrzedna_Y;

		Punkt_2D();//KONSTRUKTOR 
		void wypisz();//Wypisanie wspolrzednych 
};

void Punkt_2D::wypisz()
{
cout<<"Wspolrzedna 0X:  "<<Wspolrzedna_X<<endl;
cout<<"Wspolrzedna 0Y:  "<<Wspolrzedna_Y<<endl;
}

Punkt_2D::Punkt_2D()
{
//TUTAJ WCZYTUJE TYLKO WSPOLRZEDNE IGREKOWE, BO IKSOWE WCZYTAM Z KONSTRUKTORA PUNKTU_1D///
cout<<"Podaj wspolrzedna 0Y: ";
double tmp_y;
cin>>tmp_y;
Wspolrzedna_Y=tmp_y;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////KLASA PUNKT_2D///////////////////////////////////////////////
class Punkt_3D: public Punkt_2D
{

public:
		double Wspolrzedna_Z;

		Punkt_3D();//KONSTRUKTOR 
		void wypisz();//Wypisanie wspolrzednych 
};

void Punkt_3D::wypisz()
{
cout<<"Wspolrzedna 0X:  "<<Wspolrzedna_X<<endl;
cout<<"Wspolrzedna 0Y:  "<<Wspolrzedna_Y<<endl;
cout<<"Wspolrzedna 0Z:  "<<Wspolrzedna_Z<<endl;
}

Punkt_3D::Punkt_3D()
{
//TUTAJ WCZYTUJE TYLKO WSPOLRZEDNE ZETOWE, BO IKSOWE WCZYTAM Z KONSTRUKTORA PUNKTU_1D, A IGREKOWE Z KONSTRUKTORA PUNKTU_2D///
cout<<"Podaj wspolrzedna 0Z: ";
double tmp_z;
cin>>tmp_z;
Wspolrzedna_Z=tmp_z;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////FUNKCJE ZAPISUJACE PUNKTY DO////////////////////////////////////////////////////
void zapiszPunkt_1DDoPliku(Punkt_1D punkt)
{
 fstream plik;
 plik.open("Baza.dat", ios::out|ios::app);
 plik<<punkt.Wspolrzedna_X<<" "<<'.'<<" "<<'.'<<'\n';
 plik.close();  
}
void zapiszPunkt_2DDoPliku(Punkt_2D punkt)
{
 fstream plik;
 plik.open("Baza.dat", ios::out|ios::app);
  plik<<punkt.Wspolrzedna_X<<" "<<punkt.Wspolrzedna_Y<<" "<<'.'<<'\n';
 plik.close();  
}
void zapiszPunkt_3DDoPliku(Punkt_3D punkt)
{
 fstream plik;
 plik.open("Baza.dat", ios::out|ios::app);
 plik<<punkt.Wspolrzedna_X<<" "<<punkt.Wspolrzedna_Y<<" "<<punkt.Wspolrzedna_Z<<'\n';
 plik.close();  
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////



bool WczytajPlik()
{
    ifstream plik;
    plik.open("Baza.dat");
    if( !plik.good() )
         return false;
   
    while( true ) //pętla nieskończona
    {
        char OX;
        char OY;
        char OZ;
        
        plik >> OX>>OY>>OZ;
 
        if( !plik.fail() )
        {
	        cout<<"OX: "<<OX<<endl;
	        cout<<"OY: "<<OY<<endl;
	        cout<<"OZ: "<<OZ<<endl;
        }
        else
             break; //zakończ wczytywanie danych - wystąpił jakiś błąd (np. nie ma więcej danych w pliku)
       
    } //while
    return true;
}



int main()
{

Punkt_1D punkt;
punkt.wypisz();


Punkt_2D punkt2;
punkt2.wypisz();

Punkt_3D punkt3;
punkt3.wypisz();

zapiszPunkt_1DDoPliku(punkt);
zapiszPunkt_2DDoPliku(punkt2);
zapiszPunkt_3DDoPliku(punkt3);

if( !WczytajPlik() )
         std::cout << "Nie udalo sie otworzyc pliku!" << std::endl;

return 0;
}











/*
void PrzykladZapisuWspolrzednychDoStrumienia( ostream&     StrmWy,Prostopadloscian Pr)
{
StrmWy<<Pr;
}

bool PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku,Prostopadloscian Pr)
{
  ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
	 << ":(  nie powiodla sie." << endl;
    return false;
  }

  PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy,Pr);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}
*/