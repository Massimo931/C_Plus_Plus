#include <iostream>
#include <string>

using namespace std;

struct Libri
{
	string Titolo;
	string Editore;
	string Autore;
	int Copie;
	int Pagine;
	int ISBN;
	float CostoG;
	float CostoM;
	int Noleggio;
};

void ricerca(Libri biblioteca[], int NumLib, int &IndiceLibro);

void registrazione(Libri biblioteca[], int NumLib);

void prenotazione(Libri biblioteca[], int NumLib);

void restituzione(Libri biblioteca[], int NumLib);

void libro(Libri biblioteca[], int NumLib);

void datilibro(Libri biblioteca[], int IndiceLibro);

void archivio(Libri biblioteca[], int NumLib);

int main()
{
	int scelta;
	int NumLib;
	
	cout << "Benvenuto\n\n";
	
	do{
		cout << "Inserisci il numero di libri da registrare nella biblioteca: ";
		cin >> NumLib;
		cout << endl;
	}while(NumLib == 0);
	
	Libri biblioteca[NumLib];
	
	registrazione(biblioteca, NumLib);
	
	do{
		system("cls");
		cout << "Menu'\n1) Prenota un libro\n2) Restituisci un libro\n3) Visualizza i dati di un libro\n4) Visualizza i dati di tutti i libri in archivio\n5) Esci\n";
		cin >> scelta;
	
		switch(scelta)
		{
			case 1:
				system("cls");
				
				prenotazione(biblioteca, NumLib);
				
				system("pause");
				break;
				
			case 2:
				system("cls");
				
				restituzione(biblioteca, NumLib);
				
				system("pause");
				break;
				
			case 3:
				
				system("cls");
				
				libro(biblioteca, NumLib);
				
				system("pause");
				break;
				
			case 4:
			
				system("cls");
				
				archivio(biblioteca, NumLib);
				
				system("pause");
				break;

			case 5:
				exit(1);
				break;
				
			default:
				cout << "Comando non valido, riprova.\n";
				system("pause");
				break;
		}
		
		system("cls");	
		
	}while (scelta != 0);
	
	system("pause");

	return 0;	
}

void ricerca(Libri biblioteca[], int NumLib, int &IndiceLibro)
{
	int numc;
	bool esiste = false;
	
	for(;;)
	{
		cout << "Inserisci un codice ISBN valido: ";
		cin >> numc;
		
		for(int j = 0; j < NumLib; j++)
		{
			if(numc == biblioteca[j].ISBN)
			{
				esiste = true;
				
				IndiceLibro = j;
				
				break;
			}
			
			else
			{
				esiste = false;
			}
		}
		
		if(esiste == true)
		{
			break;
		}
		
		else
		{
			cout << "Non e' stato trovato nessun libro associato a questo codice ISBN.\nTi invitiamo a riprovare.\n";
		}
	}
}

void registrazione(Libri biblioteca[], int NumLib)
{
	int a;
	bool esiste = true;
	
	for(int i = 0; i < NumLib; i++)
	{
		cout << "Inserisci il titolo del libro numero " << i + 1 << " : ";
		std::getline(std::cin >> std::ws, biblioteca[i].Titolo);
		
		cout << "Inserisci la casa editrice del libro numero " << i + 1 << " : ";
		std::getline(std::cin >> std::ws, biblioteca[i].Editore);
		
		cout << "Inserisci l'autore del libro numero " << i + 1 << " : ";
		std::getline(std::cin >> std::ws, biblioteca[i].Autore);
		
		cout << "Inserisci il numero di copie disponibili del libro numero " << i + 1 << " : ";
		cin >> biblioteca[i].Copie;
		
		cout << "Inserisci il numero di pagine del libro numero " << i + 1 << " : ";
		cin >> biblioteca[i].Pagine;

		for(;;)
		{
			cout << "Inserisci il codice ISBN del libro numero " << i + 1 << " : ";
			cin >> a;
			
			for(int j = 0; j < NumLib; j++)
			{
				if(a != biblioteca[j].ISBN)
				{
					esiste = false;
				}
				
				else
				{
					esiste = true;
					
					break;
				}
			}
			
			if(esiste == false)
			{
				biblioteca[i].ISBN = a;
				break;
			}
			
			else
			{
				cout << "Questo ISBN e' gia' associato ad un altro libro, ti preghiamo di riprovare.\n";
			}
		}
	
		cout << "Inserisci il prezzo del noleggio giornaliero del libro numero " << i + 1 << " : ";
		cin >> biblioteca[i].CostoG;
		
		cout << "Inserisci il prezzo del noleggio mensile del libro numero " << i + 1 << " : ";
		cin >> biblioteca[i].CostoM;
		
		biblioteca[i].Noleggio = 0;
		
		cout << endl;
	}
}

void prenotazione(Libri biblioteca[], int NumLib)
{
	int IndiceLibro;
	int scelta;
	int noleggio;
	
	cout << "Prenotazione un libro\n";
	
	for(;;)
	{	
		ricerca(biblioteca, NumLib, IndiceLibro);
		
		if(biblioteca[IndiceLibro].Copie == 0)
		{
			cout << "Le copie disponibili per questo libro sono esaurite, ti preghiamo di riprovare\n";
		}
		
		else
		{
			break;
		}
	}
	
	datilibro(biblioteca, IndiceLibro);
	
	do{
		cout << "\nScegliere la modalita' di noleggio che si vuole effettuare\n1) Noleggio giornaliero (" << biblioteca[IndiceLibro].CostoG << " Euro)\n2) Noleggio mensile (" << biblioteca[IndiceLibro].CostoM << " Euro)\n";
		cin >> scelta;
		
		switch(scelta)
		{
			case 1:
				cout << "\nInserire il numero di giorni per il quale si vuole noleggiare il libro: ";
				cin >> noleggio;
				cout << "Noleggio effettuato, prezzo finale: " << biblioteca[IndiceLibro].CostoG * noleggio << " Euro.";
				
				biblioteca[IndiceLibro].Copie = biblioteca[IndiceLibro].Copie - 1;
				
				biblioteca[IndiceLibro].Noleggio = biblioteca[IndiceLibro].Noleggio + 1;
				
				break;
			case 2:
				cout << "Inserire il numero di mesi per il quale si vuole noleggiare il libro: ";
				cin >> noleggio;
				cout << "\nNoleggio effettuato, prezzo finale: " << biblioteca[IndiceLibro].CostoM * noleggio << " Euro.";
				
				biblioteca[IndiceLibro].Copie = biblioteca[IndiceLibro].Copie - 1;
				
				biblioteca[IndiceLibro].Noleggio = biblioteca[IndiceLibro].Noleggio + 1;
				
				break;
			default:
				cout << "Scelta non valida, ti preghiamo di riprovare.\n\n";
				
				break;
		}
	}while(scelta > 2);
	
	cout << "\nCopie disponibili per questo libro attualmente: " << biblioteca[IndiceLibro].Copie << endl;
}

void restituzione(Libri biblioteca[], int NumLib)
{
	int IndiceLibro;
	int scelta;
	int noleggio;
	
	cout << "Restituisci un libro\n";
	
	for(;;)
	{	
		ricerca(biblioteca, NumLib, IndiceLibro);
		
		if(biblioteca[IndiceLibro].Noleggio == 0)
		{
			cout << "Questo libro non puo' essere restituito perche' non e' stato mai noleggiato, ti preghiamo di riprovare.\n";
		}
		
		else
		{
			break;
		}
	}
	
	datilibro(biblioteca, IndiceLibro);
	
	cout << "\n\nRestituzione effettuata, grazie per esserti servito da noi :)";
	
	biblioteca[IndiceLibro].Copie = biblioteca[IndiceLibro].Copie + 1;
	
	biblioteca[IndiceLibro].Noleggio = biblioteca[IndiceLibro].Noleggio - 1;
	
	cout << "\nCopie disponibili per questo libro attualmente: " << biblioteca[IndiceLibro].Copie << endl;
}

void libro(Libri biblioteca[], int NumLib)
{
	int IndiceLibro;
	
	cout << "Inserisci il codice ISBN del libro che si desidera cercare\n";
	
	ricerca(biblioteca, NumLib, IndiceLibro);
	
	datilibro(biblioteca, IndiceLibro);
}

void datilibro(Libri biblioteca[], int IndiceLibro)
{
	cout << "Titolo: " << biblioteca[IndiceLibro].Titolo << "\nAutore: " << biblioteca[IndiceLibro].Autore << "\nCasa Editrice: " << biblioteca[IndiceLibro].Editore << "\nPagine: " << biblioteca[IndiceLibro].Pagine << "\nCopie disponibili: " << biblioteca[IndiceLibro].Copie << "\nISBN: " << biblioteca[IndiceLibro].ISBN << "\nCosto noleggio giornaliero: " << biblioteca[IndiceLibro].CostoG << "\nCosto noleggio mensile: " << biblioteca[IndiceLibro].CostoM << endl;
}

void archivio(Libri biblioteca[], int NumLib)
{
	for(int IndiceLibro = 0; IndiceLibro < NumLib; IndiceLibro++)
	{
		cout << "Titolo: " << biblioteca[IndiceLibro].Titolo << "\nAutore: " << biblioteca[IndiceLibro].Autore << "\nCasa Editrice: " << biblioteca[IndiceLibro].Editore << "\nPagine: " << biblioteca[IndiceLibro].Pagine << "\nCopie disponibili: " << biblioteca[IndiceLibro].Copie << "\nISBN: " << biblioteca[IndiceLibro].ISBN << "\nCosto noleggio giornaliero: " << biblioteca[IndiceLibro].CostoG << "\nCosto noleggio mensile: " << biblioteca[IndiceLibro].CostoM << "\n\n";
	}
}
