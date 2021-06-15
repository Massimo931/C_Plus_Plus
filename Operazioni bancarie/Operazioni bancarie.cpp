#include <iostream>
#include <string.h>

using namespace std;

struct Conto
{
	string Nome;
	string Cognome;
	int Numero;
	float Saldo;
	string Valuta;
};

void ricerca(Conto profili[], int ProfSize, int &IndiceConto);

void registrazione(Conto profili[], int ProfSize);

void versamento(Conto profili[], int ProfSize);

void prelievo(Conto profili[], int ProfSize);

void dati(Conto profili[], int ProfSize);

void dati_tutti(Conto profili[], int ProfSize);

void cambio(Conto profili[], int ProfSize);

void bonifico(Conto profili[], int ProfSize);

int main()
{
	int ProfSize;
	int scelta;
	string valuta = "Euro";
	
	/* 
		1 EURO
		2 DOLLARO
		3 STERLINA
		4 YEN
		5 FRANCO SVIZZERO
	*/
	
	cout << "Benvenuto\nInserisci il numero di conti correnti che si desidera creare: ";
	cin >> ProfSize;
	cout << endl;
	
	Conto profili[ProfSize];
	
	registrazione(profili, ProfSize);
	
	do{
		system("cls");
		cout << "Menu'\n1) Effettua un versamento\n2) Effettua un prelievo\n3) Visualizza i dati di un conto corrente\n4) Visualizza i dati di tutti i conti correnti\n5) Converti la valuta del saldo di un conto corrente\n6) Effettua un trasferimento di denaro\n7) Esci\n";
		cin >> scelta;
	
		switch(scelta)
		{
			case 1:
				system("cls");
				
				versamento(profili, ProfSize);
				
				system("pause");
				break;
				
			case 2:
				system("cls");
				
				prelievo(profili, ProfSize);
				
				system("pause");
				break;
				
			case 3:
				
				system("cls");
				
				dati(profili, ProfSize);
				
				system("pause");
				break;
				
			case 4:
			
				system("cls");
				
				dati_tutti(profili, ProfSize);
				
				system("pause");
				break;
			case 5:
				
				system("cls");
				
				cambio(profili, ProfSize);
				
				system("pause");
				break;
			case 6:
				
				system("cls");
				
				bonifico(profili, ProfSize);
				
				system("pause");
				
				break;
			case 7:
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

void ricerca(Conto profili[], int ProfSize, int &IndiceConto)
{
	int numc;
	bool esiste = false;
	
	for(;;)
	{
		cout << "Inserisci un numero di conto valido: ";
		cin >> numc;
		
		for(int j = 0; j < ProfSize ; j++)
		{
			if(numc == profili[j].Numero)
			{
				esiste = true;
				
				IndiceConto = j;
				
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
			cout << "Non e' stato trovato nessun conto corrente associato a questo numero.\nTi invitiamo a riprovare.\n";
		}
	}
}

void registrazione(Conto profili[], int ProfSize)
{
	int a;
	bool esiste = true;
	
	for(int i = 0; i < ProfSize; i++)
	{
		cout << "Inserisci il nome del conto numero " << i + 1 << " : ";
		cin >> profili[i].Nome;
		
		cout << "Inserisci il cognome del conto numero " << i + 1 << " : ";
		cin >> profili[i].Cognome;
		
		if(i == 0)
		{
			cout << "Inserisci il numero identificativo del conto numero " << i + 1 << " : ";
			cin >> profili[0].Numero;
		}
		
		else
		{
			for(;;)
			{
				cout << "Inserisci il numero identificativo del conto " << i + 1 << " : ";
				cin >> a;
				
				for(int j = 0; j < ProfSize ; j++)
				{
					if(a != profili[j].Numero)
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
					profili[i].Numero = a;
					break;
				}
				
				else
				{
					cout << "Questo numero di conto e' gia' associato ad un altro conto corrente, ti preghiamo di utilizzarne un altro.\n";
				}
			}
		}
		
		cout << "Inserisci Saldo del conto numero " << i + 1 << " (Euro) : ";
		cin >> profili[i].Saldo;
		
		profili[i].Valuta = "Euro";
		
		cout << endl;
	}
}

void versamento(Conto profili[], int ProfSize)
{
	float versamento;
	int IndiceConto;
	
	ricerca(profili, ProfSize, IndiceConto);
	
	cout << "\n\nSaldo disponibile del conto selezionato: " << profili[IndiceConto].Saldo << " " << profili[IndiceConto].Valuta << "\n\n";
	
	cout << "Immettere il quantitativo di soldi che si desidera versare (" << profili[IndiceConto].Valuta << ") : ";
	cin >> versamento;
	
	profili[IndiceConto].Saldo = profili[IndiceConto].Saldo + versamento;
	
	cout << "Adesso su questo conto ci sono: " << profili[IndiceConto].Saldo << " " << profili[IndiceConto].Valuta <<endl;
}

void prelievo(Conto profili[], int ProfSize)
{
	float prelievo;
	int IndiceConto;
	
	ricerca(profili, ProfSize, IndiceConto);
	
	cout << "\n\nSaldo disponibile del conto selezionato: " << profili[IndiceConto].Saldo << " " << profili[IndiceConto].Valuta << "\n\n";
	
	do{
		cout << "Immettere il quantitativo di soldi che si desidera prelevare (" << profili[IndiceConto].Valuta << ") : ";
		cin >> prelievo;
		
		if(profili[IndiceConto].Saldo - prelievo < 0)
		{
			cout << "Saldo insufficiente, ti preghiamo di riprovare.\n";
		}
			
	}while (prelievo - profili[IndiceConto].Saldo > 0);
	
	profili[IndiceConto].Saldo = profili[IndiceConto].Saldo - prelievo;
	
	cout << "Adesso su questo conto ci sono: " << profili[IndiceConto].Saldo << " " << profili[IndiceConto].Valuta <<endl;
}

void dati(Conto profili[], int ProfSize)
{
	int IndiceConto;		

	ricerca(profili, ProfSize, IndiceConto);
	
	system("cls");
	
	cout << "Nome: " << profili[IndiceConto].Nome << endl;
	cout << "Cognome: " << profili[IndiceConto].Cognome << endl;
	cout << "Numero del conto: " << profili[IndiceConto].Numero << endl;
	cout << "Saldo (" << profili[IndiceConto].Valuta << ") : " << profili[IndiceConto].Saldo << endl;
}

void dati_tutti(Conto profili[], int ProfSize)
{
	for(int i = 0; i < ProfSize; i++)
	{
		cout << "Nome: " << profili[i].Nome << endl;
		cout << "Cognome: " << profili[i].Cognome << endl;
		cout << "Numero del conto: " << profili[i].Numero << endl;
		cout << "Saldo (" << profili[i].Valuta << ") : " << profili[i].Saldo << endl << endl;
	}
}

void cambio(Conto profili[], int ProfSize)
{
	int IndiceConto;
	int scelta;		
	
	ricerca(profili, ProfSize, IndiceConto);
	
	cout << "\n\nSaldo disponibile del conto selezionato: " << profili[IndiceConto].Saldo << " " << profili[IndiceConto].Valuta << "\n\n";
	
	cout << "Scegliere in quale tipo di valuta si desidera cambiare:\n1 Euro\n2 Dollaro\n3 Sterlina\n4 Yen\n5 Franco Svizzero\n";
	cin >> scelta;
	
	switch(scelta)
	{
		case 1:
			system("cls");
			
			if(profili[IndiceConto].Valuta == "Euro")
			{
				cout << "La valuta del saldo del conto corrente e' gia' in Euro.\n";
			}
			
			else
			{
				if(profili[IndiceConto].Valuta == "Dollari")
				{
					profili[IndiceConto].Saldo = profili[IndiceConto].Saldo * 0.85;
				}
				
				else if(profili[IndiceConto].Valuta == "Sterline")
				{
					profili[IndiceConto].Saldo = profili[IndiceConto].Saldo	* 1.10;
				}
				
				else if(profili[IndiceConto].Valuta == "Yen")
				{
					profili[IndiceConto].Saldo = profili[IndiceConto].Saldo * 0.0081;
				}
				
				else if(profili[IndiceConto].Valuta == "Franchi Svizzeri")
				{
					profili[IndiceConto].Saldo = profili[IndiceConto].Saldo * 0.93;
				}
				
				profili[IndiceConto].Valuta = "Euro";
				
				cout << "Conversione della valuta eseguita con successo, adesso il saldo del conto corrente equivale a: " << profili[IndiceConto].Saldo << " Euro.\n";
			}
			
			break;
		case 2:
			system("cls");
			
			if(profili[IndiceConto].Valuta == "Dollari")
			{
				cout << "La valuta del saldo del conto corrente e' gia' in Dollari.\n";
			}
			
			else
			{
				if(profili[IndiceConto].Valuta == "Euro")
				{
					profili[IndiceConto].Saldo = profili[IndiceConto].Saldo * 1.17;
				}
				
				else if(profili[IndiceConto].Valuta == "Sterline")
				{
					profili[IndiceConto].Saldo = profili[IndiceConto].Saldo	* 1.28;
				}
				
				else if(profili[IndiceConto].Valuta == "Yen")
				{
					profili[IndiceConto].Saldo = profili[IndiceConto].Saldo * 0.0095;
				}
				
				else if(profili[IndiceConto].Valuta == "Franchi Svizzeri")
				{
					profili[IndiceConto].Saldo = profili[IndiceConto].Saldo * 1.09;
				}
				
				profili[IndiceConto].Valuta = "Dollari";
				
				cout << "Conversione della valuta eseguita con successo, adesso il saldo del conto corrente equivale a: " << profili[IndiceConto].Saldo << " Dollari.\n";
			}
			
			break;
		case 3:
			
			system("cls");
			
			if(profili[IndiceConto].Valuta == "Sterline")
			{
				cout << "La valuta del saldo del conto corrente e' gia' in Sterline.\n";
			}
			
			else
			{
				if(profili[IndiceConto].Valuta == "Euro")
				{
					profili[IndiceConto].Saldo = profili[IndiceConto].Saldo * 0.91;
				}
				
				else if(profili[IndiceConto].Valuta == "Dollari")
				{
					profili[IndiceConto].Saldo = profili[IndiceConto].Saldo	* 0.78;
				}
				
				else if(profili[IndiceConto].Valuta == "Yen")
				{
					profili[IndiceConto].Saldo = profili[IndiceConto].Saldo * 0.0074;
				}
				
				else if(profili[IndiceConto].Valuta == "Franchi Svizzeri")
				{
					profili[IndiceConto].Saldo = profili[IndiceConto].Saldo * 0.85;
				}
				
				profili[IndiceConto].Valuta = "Sterline";
				
				cout << "Conversione della valuta eseguita con successo, adesso il saldo del conto corrente equivale a: " << profili[IndiceConto].Saldo << " Sterline.\n";
			}
			
			break;
		case 4:
			
			system("cls");
			
			if(profili[IndiceConto].Valuta == "Yen")
			{
				cout << "La valuta del saldo del conto corrente e' gia' in Yen.\n";
			}
			
			else
			{
				if(profili[IndiceConto].Valuta == "Euro")
				{
					profili[IndiceConto].Saldo = profili[IndiceConto].Saldo * 123.98;
				}
				
				else if(profili[IndiceConto].Valuta == "Dollari")
				{
					profili[IndiceConto].Saldo = profili[IndiceConto].Saldo	* 105.70;
				}
				
				else if(profili[IndiceConto].Valuta == "Sterline")
				{
					profili[IndiceConto].Saldo = profili[IndiceConto].Saldo * 135.83;
				}
				
				else if(profili[IndiceConto].Valuta == "Franchi Svizzeri")
				{
					profili[IndiceConto].Saldo = profili[IndiceConto].Saldo * 114.80;
				}
				
				profili[IndiceConto].Valuta = "Yen";
				
				cout << "Conversione della valuta eseguita con successo, adesso il saldo del conto corrente equivale a: " << profili[IndiceConto].Saldo << " Yen.\n";
			}
			
			break;
		case 5:
			
			system("cls");
			
			if(profili[IndiceConto].Valuta == "Franchi Svizzeri")
			{
				cout << "La valuta del saldo del conto corrente e' gia' in Franchi Svizzeri.\n";
			}
			
			else
			{
				if(profili[IndiceConto].Valuta == "Euro")
				{
					profili[IndiceConto].Saldo = profili[IndiceConto].Saldo * 1.08;
				}
				
				else if(profili[IndiceConto].Valuta == "Dollari")
				{
					profili[IndiceConto].Saldo = profili[IndiceConto].Saldo	* 0.92;
				}
				
				else if(profili[IndiceConto].Valuta == "Sterline")
				{
					profili[IndiceConto].Saldo = profili[IndiceConto].Saldo * 1.18;
				}
				
				else if(profili[IndiceConto].Valuta == "Yen")
				{
					profili[IndiceConto].Saldo = profili[IndiceConto].Saldo * 0.0087;
				}
				
				profili[IndiceConto].Valuta = "Franchi Svizzeri";
				
				cout << "Conversione della valuta eseguita con successo, adesso il saldo del conto corrente equivale a: " << profili[IndiceConto].Saldo << " Franchi Svizzeri.\n";
			}
			
			break;
		default:
			cout << "Comando non valido, riprova.\n";
			break;
	}
}

void bonifico(Conto profili[], int ProfSize)
{
	int numc1;
	int numc2;
	int IndiceConto1;
	int IndiceConto2;
	bool esiste1 = false;
	bool esiste2 = false;
	float invio;
				
	for(;;)
	{
		cout << "Inserisci un numero di conto valido con il quale si vuole effettuare un bonifico bancario: ";
		cin >> numc1;
		
		for(int j = 0; j < ProfSize ; j++)
		{
			if(numc1 == profili[j].Numero)
			{
				esiste1 = true;
				
				IndiceConto1 = j;
				
				break;
			}
			
			else
			{
				esiste1 = false;
			}
		}
		
		if(esiste1 == true)
		{
			break;
		}
		
		else
		{
			cout << "Non e' stato trovato nessun conto corrente associato a questo numero.\nTi invitiamo a riprovare.\n";
		}
	}
	
	for(;;)
	{
		cout << "Inserisci il numero di conto verso il quale si vuole effettuare il bonifico bancario: ";
		cin >> numc2;
		
		for(int j = 0; j < ProfSize ; j++)
		{
			if(numc2 == profili[j].Numero)
			{
				esiste2 = true;
				
				IndiceConto2 = j;
				
				break;
			}
			
			else
			{
				esiste2 = false;
			}
		}
		
		if(esiste2 == true)
		{
			break;
		}
		
		else
		{
			cout << "Non e' stato trovato nessun conto corrente associato a questo numero.\nTi invitiamo a riprovare.\n";
		}
	}
	
	if(profili[IndiceConto2].Valuta != profili[IndiceConto1].Valuta)
	{
		cout << "Impossibile inviare un bonifico bancario verso un conto con una valuta diversa.\n";
	}
	
	else
	{
		cout << "\n\nMittente: " << profili[IndiceConto1].Saldo << " " << profili[IndiceConto1].Valuta << " disponibili\n";
		cout << "Destinatario: " << profili[IndiceConto2].Saldo << " " << profili[IndiceConto2].Valuta << " disponibili\n\n";
		
		do{
		
		cout << "Inserisci il quantitativo di soldi da inviare (" << profili[IndiceConto1].Valuta << ") : ";
		cin >> invio;
		
		if(profili[IndiceConto1].Saldo - invio < 0)
		{
			cout << "Saldo insufficiente, ti preghiamo di riprovare.\n";
		}
		
	}while (invio - profili[IndiceConto1].Saldo > 0);
	
	profili[IndiceConto1].Saldo = profili[IndiceConto1].Saldo - invio;
	
	profili[IndiceConto2].Saldo = profili[IndiceConto2].Saldo + invio;
	
	cout << "\n\nBonifico effettuato con successo, adesso sul conto numero " << profili[IndiceConto1].Numero << " (mittente) ci sono " <<  profili[IndiceConto1].Saldo << " " << profili[IndiceConto1].Valuta << ".\n";
	cout << "Sul conto numero " << profili[IndiceConto2].Numero << " (destinatario) ci sono " <<  profili[IndiceConto2].Saldo << " " << profili[IndiceConto2].Valuta << ".\n";
	}
}
