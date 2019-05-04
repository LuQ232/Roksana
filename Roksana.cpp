#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

///////////////////////////////////////////////KLASA PUNKT_1D///////////////////////////////////////////////
class Punkt_1D
{

public:
    double Wspolrzedna_X;

    Punkt_1D ();//KONSTRUKTOR
    Punkt_1D(double);
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

Punkt_1D::Punkt_1D(double x)
{
Wspolrzedna_X=x;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////KLASA PUNKT_2D///////////////////////////////////////////////
class Punkt_2D: public Punkt_1D
{

public:
    double Wspolrzedna_Y;

    Punkt_2D();//KONSTRUKTOR DOMYSLNY
    Punkt_2D(double,double);
    void wypisz();//Wypisanie wspolrzednych 
};

void Punkt_2D::wypisz()
{
cout<<"Wspolrzedna 0X:  "<<Wspolrzedna_X<<endl;
cout<<"Wspolrzedna 0Y:  "<<Wspolrzedna_Y<<endl;
}

Punkt_2D::Punkt_2D():Punkt_1D()
{
//TUTAJ WCZYTUJE TYLKO WSPOLRZEDNE IGREKOWE, BO IKSOWE WCZYTAM Z KONSTRUKTORA PUNKTU_1D///
cout<<"Podaj wspolrzedna 0Y: ";
double tmp_y;
cin>>tmp_y;
Wspolrzedna_Y=tmp_y;
}

Punkt_2D::Punkt_2D(double x, double y):Punkt_1D(x)
{
//TUTAJ WCZYTUJE TYLKO WSPOLRZEDNE IGREKOWE, BO IKSOWE WCZYTAM Z KONSTRUKTORA PUNKTU_1D///
Wspolrzedna_Y=y;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////KLASA PUNKT_2D///////////////////////////////////////////////
class Punkt_3D: public Punkt_2D
{

public:
    double Wspolrzedna_Z;

    Punkt_3D();//KONSTRUKTOR 
     Punkt_3D(double,double,double);
    void wypisz();//Wypisanie wspolrzednych 
};

void Punkt_3D::wypisz()
{
cout<<"Wspolrzedna 0X:  "<<Wspolrzedna_X<<endl;
cout<<"Wspolrzedna 0Y:  "<<Wspolrzedna_Y<<endl;
cout<<"Wspolrzedna 0Z:  "<<Wspolrzedna_Z<<endl;
}

Punkt_3D::Punkt_3D():Punkt_2D()
{
//TUTAJ WCZYTUJE TYLKO WSPOLRZEDNE ZETOWE, BO IKSOWE WCZYTAM Z KONSTRUKTORA PUNKTU_1D, A IGREKOWE Z KONSTRUKTORA PUNKTU_2D///
cout<<"Podaj wspolrzedna 0Z: ";
double tmp_z;
cin>>tmp_z;
Wspolrzedna_Z=tmp_z;
}

Punkt_3D::Punkt_3D(double x, double y,double z):Punkt_2D(x,y)
{
//TUTAJ WCZYTUJE TYLKO WSPOLRZEDNE IGREKOWE, BO IKSOWE WCZYTAM Z KONSTRUKTORA PUNKTU_1D///
Wspolrzedna_Z=z;
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
        string OX;
        string OY;
        string OZ;
        
        plik >> OX>>OY>>OZ;
 
        if( !plik.fail() )
        {
          if(OY==".")
          {
           double tmp=stod(OX,NULL);
            Punkt_1D punktTmp(tmp);
            cout<<"TO JEST PUNKT 1D: "<<endl;
            punktTmp.wypisz();
          }else if(OZ==".")
          {
           double tmp_x=stod(OX,NULL);
           double tmp_y=stod(OY,NULL);
            Punkt_2D punktTmp(tmp_x,tmp_y);
            cout<<"TO JEST PUNKT 2D: "<<endl;
            punktTmp.wypisz();
          }else
          {
          double tmp_x=stod(OX,NULL);
           double tmp_y=stod(OY,NULL);
           double tmp_z=stod(OZ,NULL);
            Punkt_3D punktTmp(tmp_x,tmp_y,tmp_z);
            cout<<"TO JEST PUNKT 3D: "<<endl;
            punktTmp.wypisz();
          }


        }
        else
             break; //zakończ wczytywanie danych - wystąpił jakiś błąd (np. nie ma więcej danych w pliku)
       
    } //while
    return true;
}



int main()
{
Punkt_1D TablicaPunktow1D[10];
Punkt_1D punkt1;
zapiszPunkt_1DDoPliku(punkt1);
Punkt_2D TablicaPunktow2D[10];

Punkt_2D punkt2;
zapiszPunkt_2DDoPliku(punkt2);
Punkt_3D TablicaPunktow3D[10];

Punkt_3D punkt3;
zapiszPunkt_3DDoPliku(punkt3);





if( !WczytajPlik() )
         std::cout << "Nie udalo sie otworzyc pliku!" << std::endl;


return 0;
}

