#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Flacon
{
private:
  string nom;
  double volume;
  double pH;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
public:
  string getNom(void) const {return nom;}
  double getVolume(void) const {return volume;}
  double getPH(void) const {return pH;}
  
  Flacon(string n, double v, double p) : nom(n), volume(v), pH(p) {}
  
  ostream& etiquette(ostream& sortie) const
  {
	sortie << nom << " : " << volume << " ml, pH " << pH ;
	return sortie;
  }
};

ostream& operator<<(ostream& sortie, Flacon const& z)
{
	return z.etiquette(sortie);
}

const Flacon operator+(Flacon const& z1, Flacon const& z2) 
{
  string n = z1.getNom() + " + " + z2.getNom();
  double v = z1.getVolume() + z2.getVolume();
  double p = -log10((z1.getVolume()*pow(10,-z1.getPH()) + z2.getVolume()*pow(10,-z2.getPH()))/(z1.getVolume()+z2.getVolume()));
  Flacon flac(n, v, p);
  return flac;	
}
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void afficher_melange(Flacon const& f1, Flacon const& f2)
{
  cout << "Si je mélange " << endl;
  cout << "\t\"" << f1 << "\"" << endl;
  cout << "avec" << endl;
  cout << "\t\"" << f2 << "\"" << endl;
  cout << "j'obtiens :" << endl;
  cout << "\t\"" << (f1 + f2) << "\"" << endl;
}

int main()
{
  Flacon flacon1("Eau", 600.0, 7.0);
  Flacon flacon2("Acide chlorhydrique", 500.0, 2.0);
  Flacon flacon3("Acide perchlorique",  800.0, 1.5);

  afficher_melange(flacon1, flacon2);
  afficher_melange(flacon2, flacon3);

  return 0;

}
