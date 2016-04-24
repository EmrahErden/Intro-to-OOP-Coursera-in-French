#include <iostream>
using namespace std;

class Souris
{
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
public:
  Souris(double p, string c, int a=0, int ev=36): poids(p), couleur(c), age(a), esperance_vie(ev) {cout << "Une nouvelle souris !\n";}
  Souris(Souris const& clony): poids(clony.poids), couleur(clony.couleur), age(clony.age), esperance_vie(clony.esperance_vie*4/5), clonee(true) {cout << "Clonage d'une souris !\n";}
  ~Souris(){cout << "Fin d'une souris...\n";}
  
  void afficher()
  {
	  cout << "Une souris " << couleur; 
	  if(clonee) 
	  {
		  cout << ", clonee,";
	  }
	  cout << " de " << age << " mois et pesant " << poids << " grammes\n";
  }
  
  void vieillir()
  {
	  age++;
	  if ((age>(esperance_vie/2))&&(clonee))
	  {
		  couleur="verte";
	  }
  }
  
  void evolue()
  {
	  while(age<esperance_vie)
	  {
		  vieillir();
	  } //vieillir till death
  }
  
private:
  double poids;
  int age;
  string couleur;
  int esperance_vie;
  bool clonee=false;
  
  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

}; // fin de la classe Souris

int main()
{
  Souris s1(50.0, "blanche", 2);
  Souris s2(45.0, "grise");
  Souris s3(s2);
  // ... un tableau peut-être...
  s1.afficher();
  s2.afficher();
  s3.afficher();
  s1.evolue();
  s2.evolue();
  s3.evolue();
  s1.afficher();
  s2.afficher();
  s3.afficher();
  return 0;
}
