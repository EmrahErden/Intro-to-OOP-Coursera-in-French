#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
class Auteur //author
{
private:
  string Nom;
  bool Prix;
public:
  Auteur(string n, bool p=false): Nom(n), Prix(p) {}
  string getNom() const{return Nom;}
  bool getPrix() const{return Prix;}
};

class Oeuvre //book, it is unique, not possible to copy
{
public:
  Oeuvre(string t, const Auteur& a, string l): Titre(t), aut(a), Langue(l) {}
  ~Oeuvre(){cout << "L'oeuvre \"" << Titre << ", " << aut.getNom() <<", en " << Langue << "\" n'est plus disponible.\n";}
  Oeuvre(Oeuvre const&) = delete; // can not be coppied!!
  string getTitre() const {return Titre;}
  Auteur getAuteur() const {return aut;}
  string getLangue() const {return Langue;} 
  void affiche(){cout << Titre << ", " << aut.getNom() <<", en " << Langue << "\n";}
private:
  string Titre;
  const Auteur& aut;
  string Langue;
};

class Exemplaire
{
public:
  Exemplaire(Oeuvre &o):oeuv(&o){cout << "Nouvel exemplaire de : " << oeuv->getTitre() << ", " << oeuv->getAuteur().getNom() <<", en " << oeuv->getLangue() << "\n";}
  Exemplaire(Exemplaire const& e): oeuv(e.oeuv){cout << "Copie d'un exemplaire de : " << oeuv->getTitre() << ", " << oeuv->getAuteur().getNom() << " en " << oeuv->getLangue() << "\n";}
  ~Exemplaire(){cout << "Un exemplaire de \"" << oeuv->getTitre() <<" , " << oeuv->getAuteur().getNom() << ", en " << oeuv->getLangue() << "\" a été jeté !\n";}
  Oeuvre* getOeuvre()const{return oeuv;}
  void affiche() const {cout << "Exemplaire de : " << oeuv->getTitre() << ", " << oeuv->getAuteur().getNom() << ", en " << oeuv->getLangue() << " ";}
private:
  Oeuvre* oeuv;
};

class Bibliotheque
{
public:
  Bibliotheque(string n): Nom(n) {cout << "La bibliothèque " << Nom << " est ouverte !\n";}
  ~Bibliotheque()
  {
	cout << "La bibliothèque "<< Nom << " ferme ses portes,\n"<< "et détruit ses exemplaires :\n";
	for(unsigned int i=0; i<exemplaires.size(); i++)
	{
	  delete exemplaires[i];
	}
  }
  string getNom()const {return Nom;}
  void stocker(Oeuvre &o, int n=1) 
  {
    for(int i=0; i<n; i++)
    {
		Exemplaire* e = new Exemplaire(o);
		exemplaires.push_back(e);
	}
  }
  
  void lister_exemplaires(string l="")
  {
	  for (unsigned int i=0; i<exemplaires.size(); i++)
	  {
		if((l=="")||(l==exemplaires[i]->getOeuvre()->getLangue()))
		{
		  exemplaires[i]->affiche();
		  cout << "\n";
		}
	  }
  }
  
  int compter_exemplaires(Oeuvre& o)
  {
    int counter = 0;
	for (unsigned int i=0; i< exemplaires.size(); i++)
	{
	  if((o.getTitre()==exemplaires[i]->getOeuvre()->getTitre())&&(o.getLangue()==exemplaires[i]->getOeuvre()->getLangue()))
	  {
		counter++;
	  }
	}
	return counter;
  }
  
  void afficher_auteurs(bool b=false)
  {
    for (unsigned int i=0; i< exemplaires.size(); i++)
	{		
	  if(!b)
	  {
		cout << exemplaires[i]->getOeuvre()->getAuteur().getNom() << "\n";
	  }else
	  {
		if(exemplaires[i]->getOeuvre()->getAuteur().getPrix())
		{
	      cout << exemplaires[i]->getOeuvre()->getAuteur().getNom() << "\n";
		}
	  }		
	}    
  }
  
private:
  string Nom;
  vector<Exemplaire*> exemplaires;
};


/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int main()
{
  Auteur a1("Victor Hugo"),
         a2("Alexandre Dumas"),
         a3("Raymond Queneau", true);

  Oeuvre o1("Les Misérables"           , a1, "français" ),
         o2("L'Homme qui rit"          , a1, "français" ),
         o3("Le Comte de Monte-Cristo" , a2, "français" ),
         o4("Zazie dans le métro"      , a3, "français" ),
         o5("The Count of Monte-Cristo", a2, "anglais" );

  Bibliotheque biblio("municipale");
  biblio.stocker(o1, 2);
  biblio.stocker(o2);
  biblio.stocker(o3, 3);
  biblio.stocker(o4);
  biblio.stocker(o5);

  cout << "La bibliothèque " << biblio.getNom()
       << " offre les exemplaires suivants :" << endl;
  biblio.lister_exemplaires();

  const string langue("anglais");
  cout << " Les exemplaires en "<< langue << " sont :" << endl;
  biblio.lister_exemplaires(langue);

  cout << " Les auteurs à succès sont :" << endl;
  biblio.afficher_auteurs(true);

  cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
       << o3.getTitre() << endl;

  return 0;
}
