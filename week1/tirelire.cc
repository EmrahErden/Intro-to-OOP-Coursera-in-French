#include <iostream>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/
class Tirelire
{
	private:
		double montant;
	public:
		double getMontant() {return montant;}
		void afficher();			// display
		void secouer();
		void remplir(double a);		// add positive amount
		void vider() {montant=0;}	// empty the bank
		void puiser(double a);		// remove money
		bool montant_suffisant(double spending, double &remainder);
		
};

void Tirelire::afficher()
{
	if (montant==0)
	{
		cout << "Vous etes sans le sou.\n"; 
	}else
	{
		cout << "Vous avez : " << montant << " euros dans votre tirelire.\n";
	}
}

void Tirelire::remplir(double a)
{
	if (a>0)
	{
		montant+=a;
	}
}

void Tirelire::puiser (double a)
{
	if(a<0)
	{
		// do nothing
	}
	
	if(a>montant)
	{
		montant=0;
	}else
	{
		montant-=a;
	}
}

void Tirelire::secouer() 
{
	if (montant>0)
	{
		cout << "Bing bing\n";
	}
}

bool Tirelire::montant_suffisant(double spending, double &remainder)
{
	if(spending>montant)
	{	
		double base;
		if (montant<0) 
		{
			base=0;
		}else 
		{
			base=montant;
		}
		remainder = spending-base;
		return false;
	}else
	{
		remainder = montant-spending;
		return true;
	}
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Tirelire piggy;

  piggy.vider();
  piggy.secouer();
  piggy.afficher();

  piggy.puiser(20.0);
  piggy.secouer();
  piggy.afficher();

  piggy.remplir(550.0);
  piggy.secouer();
  piggy.afficher();

  piggy.puiser(10.0);
  piggy.puiser(5.0);
  piggy.afficher();

  cout << endl;

  // le budget de vos vacances de rève.
  double budget;

  cout << "Donnez le budget de vos vacances : ";
  cin >> budget;

  // ce qui resterait dans la tirelire après les
  // vacances
  double solde(0.0);

  if (piggy.montant_suffisant(budget, solde)) {
    cout << "Vous êtes assez riche pour partir en vacances !"
         << endl
         << "Il vous restera " << solde << " euros"
         << " à la rentrée." << endl << endl;
    piggy.puiser(budget);
  } else {
    cout << "Il vous manque " << solde << " euros"
         << " pour partir en vacances !" << endl << endl;
  }
  return 0;
}
