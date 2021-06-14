#include <iostream>
#include <conio.h>
#include <windows.h>
#define R 20
#define C 50
#define V 7

using namespace std;

void  GotoXY(int x, int  y);

void font(int assex, int assey);

void introduzione();

void tutorial();

void impostazioni(int scelta1, int scelta2, int scelta3, int &intero);

void gioco(char comando, int x, int y, int a, int b, int e, int d, int l, int m, int k, int g, int j, int s, int r, char armatura[], char spada[], char chiavi[], char p, int punteggio, int n, int turni, char c, int t, int scelta);



int main()
{
	introduzione();

	cout << endl;
	system("pause");
	
	return 0;	
}

void font(int assex, int assey)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	 
	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX() ;
	 
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	 
	GetCurrentConsoleFontEx(hConsole,0,lpConsoleCurrentFontEx);
	 
	lpConsoleCurrentFontEx->dwFontSize.X = assex;
	lpConsoleCurrentFontEx->dwFontSize.Y = assey;
	 
	SetCurrentConsoleFontEx(hConsole,0,lpConsoleCurrentFontEx);
}

void  GotoXY(int x, int  y)
{
	COORD CursorPos = {x, y};
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, CursorPos);
}

void introduzione()
{
	char comando;
	int x = 1;
	int y = 18;
	int a = 33;
	int b = 18;
	int e;
	int d;
	int l;
	int m;
	int k;
	int g;
	int j = 0;
	int s = 0;
	int r = 0;
	char armatura[V];
	char spada[V];
	char chiavi[V];
	char p = 148;
	int punteggio = 0;
	int n = 3;
	int turni = 0;
	char c;
	int t = 0;
	int scelta;
	int scelta1;
	int scelta2;
	int scelta3;
	int assex = 16;
	int assey = 16;
	int intero = 1;

	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	
	font(assex, assey);
	
	do{

		cout << "***************************************************" << endl;
		cout << "Il labirinto" << endl;
		cout << "Menu'" << endl;
		cout << "1. Gioca" << endl;
		cout << "2. Tutorial" << endl;
		cout << "3. Impostazioni" << endl;
		cout << "4/0. Esci" << endl;
		cout << "****************************************************" << endl;
		cout << "Open Beta - Versione 1.2.1" << endl;
		cin >> scelta;
	
		switch(scelta)
		{
			case 0:
				exit(1);
				break;
			case 1:
				system("cls");
				gioco(comando, x, y, a, b, e, d, l, m, k, g, j, s, r, armatura, spada, chiavi, p, punteggio, n, turni, c, t, scelta);
				break;
			case 2:
				tutorial();
				break;
			case 3:
				impostazioni(scelta1, scelta2, scelta3, intero);
				break;
			case 4:
				exit(1);
				break;
			default:
				system("cls");
				cout << "Scelta non valida, riprova!\n";
				break;
		}

	}while(scelta != 4);
}

void tutorial()
{
	char f = 159;
	char z = 244;
	char h = 245;
	
	system("cls");
	cout << "Lo scopo del gioco e'arrivare fino alla fine del labirinto, ovvero oltre il quadratino bianco, con piu' punti possibili.";
	cout << "\nI punti si possono ottenere raccogliendo questi simboli:\n. = 1 punto\n* = 5 punti\n# = 10 punti";
	cout << endl;
	system("pause");
	system("cls");
	cout << "Fai attenzione, e' possibile perdere 10 punti se si raccoglie questo simbolo '!'.";
	cout << endl;
	system("pause");
	system("cls");
	cout << "All'inizio hai a disposizione tre vite '@',\nfai attenzione a non andare sulle trappole 'w' e contro i mostri del labirinto '&' se non vuoi perdere vite.";
	cout << endl;
	system("pause");
	system("cls");
	cout << "E' possibile trovare la Spada Runica '" << f <<"' per uccidere un mostro senza perdere vite, cosi' facendo, pero', verra' distrutta.\nOltre alla spada e' possibile trovare anche l' Armatura Leggendaria '" << z <<"' che ti difende dall'attacco di una trappola senza perdere vite, anche essa, pero', verra' distrutta.\nFai bene attenzione a come utilizzi le tue armi.";
	cout << endl;
	system("pause");
	system("cls");
	cout << "Le porte rosse sono chiuse a chiave ed e' possibile aprirle solo raccogliendo le Chiavi Magiche '" << h <<"'.";
	cout << endl;
	system("pause");
	system("cls");
	cout << "Il punteggio finale verra' calcolato in base a come ti comporti durante il gioco e verra' seguito questo criterio:\n(punteggio - passi + spada + armatura + chiavi) x numero di vite\nLa spada, l'armatura e le chiavi valgono 1000 punti ciascuno.\nQuesti oggetti avranno un valore nel punteggio finale solo se vengono raccolti e non vengono utilizzati.";
	cout << endl;
	system("pause");
	system("cls");
	cout << "In alcuni casi e' necessario perdere punti per ottenere qualcosa di prezioso, in altri casi si deve essere disposti a perdere una vita pur di raggiungere un ricco obiettivo, spettera' a te decidere come muoverti!";
	cout << endl;
	system("pause");
	system("cls");
	cout << "Per muoverti puoi usare WASD e per terminare il gioco puoi premere 0 o 4.";
	cout << endl;
	system("pause");
	system("cls");
	cout << "Questo gioco e' stato programmato da Massimo Arnoni in C++ ed e' ancora in fase di sviluppo quindi e' possibile riscontare qualche problema o bug.\nPer segnalare un bug contattare il seguente indirrizzo e-mail: massimoarnoni@gmail.com";
	cout << endl;
	system("pause");
	system("cls");
	cout << "Buona Fortuna!";
	cout << endl;
	system("pause");
	system("cls");
}

void impostazioni(int scelta1, int scelta2, int scelta3, int &intero)
{
	int assex;
	int assey;
	
	do{
	
		system("cls");
		
		cout << "***************************************************" << endl;
		cout << "Impostazioni" << endl;
		cout << "1. Schermo" << endl;
		cout << "2. Dimensioni Carattere" << endl;
		cout << "3. Indietro" << endl;
		cout << "****************************************************" << endl;
		cin >> scelta1;
	
		switch(scelta1)
		{
			case 1:
				system("cls");
				do{
					cout << "Seleziona le dimensioni dello scherno: \n1. Schermo intero\n2. Finestra\n\n3. Indietro\n";
					cin >> scelta2;
					switch(scelta2)
					{
						case 1:
							if(intero == 0)
							{
								::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
								intero++;
							}
							
							else
							{
								cout << "lo schermo intero e' gia' impostato" << endl;
								cout << endl;
								system("pause");	
							}
							system("cls");
							break;
						case 2:
							if(intero == 1)
							{
								::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
								intero--;
							}
							
							else
							{
								cout << "lo schermo in finestra e' gia' impostato" << endl;
								cout << endl;
								system("pause");	
							}
							system("cls");
							break;
						case 3:
							system("cls");
							break;
						default:
							system("cls");
							cout << "Scelta non valida, riprova!\n";
							break;
					}
				}while(scelta2 > 3 || scelta2 < 1);
				break;
			case 2:
				system("cls");
				do{
					cout << "Seleziona le dimensioni del carattere: \n1. Piccolissimo\n2. Piccolo\n3. Medio\n4. Grande\n5. Grandissimo\n\n6. Indietro";
					cin >> scelta3;
					switch(scelta3)
					{
						case 1:
							assex = 16;
							assey = 16;
							font(assex, assey);
							system("cls");
							break;
						case 2:
							assex = 26;
							assey = 26;
							font(assex, assey);
							system("cls");
							break;
						case 3:
							assex = 36;
							assey = 36;
							font(assex, assey);
							system("cls");
							break;
						case 4:
							assex = 46;
							assey = 46;
							font(assex, assey);
							system("cls");
							break;
						case 5:
							assex = 56;
							assey = 56;
							font(assex, assey);
							system("cls");
							break;
						case 6:
							system("cls");
							break;
						default:
							system("cls");
							cout << "Scelta non valida, riprova!\n";
							break;	
					}
				}while(scelta3 > 6 || scelta3 < 1);
				break;
			case 3:
				system("cls");
				break;
			default:
				system("cls");
				cout << "Scelta non valida, riprova!\n";
				break;
		}
	}while(scelta1 > 3 || scelta1 < 1);	
}

void gioco(char comando, int x, int y, int a, int b, int e, int d, int l, int m, int k, int g, int j, int s, int r, char armatura[], char spada[], char chiavi[], char p, int punteggio, int n, int turni, char c, int t, int scelta)
{
	char labirinto[R][C] =
	{{'\0','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','\0'},
	{'|','O','|','\0','\0','\0','\0','\0','|',64,'|','\0','\0','\0','|',42,46,42,46,42,46,35,35,35,46,42,46,42,46,'|','O','|','|',35,38,244,38,42,42,'|',35,35,35,38,35,35,'|','\0','\0','|'},	
	{'|','\0','|','_','_','_','_','_','|','\0','|','_','_','_','|','\0','\0','_','_','_','_','\0',46,'\0','_','_','_',42,42,'|','\0','|','|',42,38,46,42,42,42,'|',35,35,'\0','_','\0',35,'|',219,219,'|'},
	{'|',46,'\0',46,'\0',46,'\0',46,'\0',46,'\0',46,'\0',46,'\0',46,'|','\0','_','\0','_','|',46,'|','_',35,35,'|',42,'|','\0','|','|','_','_','_','_',119,42,'|',35,35,'|','\0','|',35,'|',35,35,'|'},	
	{'|','\0','\0','_','_','_','_','_','_','_','\0','\0','\0','_','_','_','|','|',35,'|',64,'|',46,'|',64,'|',35,'|',42,'|',119,'|','_','_','_','_','_','|',42,'|',42,42,'|','\0','|',42,'|',35,35,'|'},
	{'|',46,'|','\0','\0','\0','\0','\0','\0','\0','|',35,'|','\0','\0','\0','\0','|',35,'|',42,'|','O','|',42,'|',35,'|',42,46,46,46,46,46,46,46,46,42,42,'|',38,'\0','|','\0','|','\0','|',35,35,'|'},	
	{'|','\0','|','\0','\0','\0','\0','_','\0','\0','|',33,'|','\0','\0','\0','\0','|',35,'|',42,'|',46,'|',42,'|',35,'|',42,'\0','_','_','_','_','_','_','_','_','_','|','\0','\0','|','\0','|',38,'|','_','_','|'},
	{'|',33,'|','\0','\0','\0','|','O','|','\0','|',33,'|','\0','\0','\0','\0','|',42,'|',46,'|',46,'|',46,'|',35,'|',42,'|','\0','\0','\0','|','\0',42,42,33,33,33,33,'\0','\0','\0',38,'\0','\0','\0','\0','|'},	
	{'|','\0','|','_','_','_','|','\0','|','_','|','\0','|','_','_','_','_','|',46,'|',46,'|',46,'|',46,'|',38,'|',42,'|','\0','\0','\0','|','\0',38,'_','_','_',38,'\0',38,'\0','\0','\0','\0','\0','\0',119,'|'},
	{'|',35,'\0',46,'\0',46,'\0',46,'\0',46,'\0',46,'\0',119,'\0',46,'\0',46,'\0',46,'\0',46,'\0',46,'\0',46,'\0','|',42,'|','\0','\0','\0','|','\0','|','\0','\0','\0','|',46,'|',42,46,42,46,'|',33,33,'|'},	
	{'|','\0','\0','_','_','_','_','_','_','\0',46,'\0','_','_','_','_',46,46,46,46,46,46,46,46,35,35,35,'|',42,'|','_','_','_','|','\0','|','_','_','_','|',46,'|',46,46,46,46,'|',33,33,'|'},
	{'|',46,'|',35,35,35,35,35,35,'|',46,'|',33,33,33,33,'|',119,35,46,46,46,35,33,33,35,46,46,33,46,46,'|',42,46,42,35,42,46,46,'|',46,'|',38,119,42,42,'|',33,33,'|'},	
	{'|','\0','|',35,35,35,35,35,35,'|',46,'|',33,33,33,33,'|','_','_',46,46,46,33,245,46,46,46,46,46,46,46,'|','_','_','_','_','_','_',46,'|',46,'|',46,42,42,38,'|',33,33,'|'},
	{'|',46,'|',35,35,'\0','_','_','_','|',46,'|','_','_','_',33,33,33,33,'|',42,35,42,42,35,42,42,119,119,119,119,'|','O','|',42,42,42,42,46,'|',46,'|',46,35,38,42,'|',33,33,'|'},	
	{'|','\0','|',35,35,'|',42,46,46,46,46,46,46,46,42,'|',33,33,33,'|',35,35,35,35,119,'\0',42,'_','_','_','_','|','\0','|',46,46,42,'_','_','|',46,'|',38,35,38,33,'|',33,33,'|'},
	{'|',46,'|',35,35,'|',46,'\0','_','_','_','_','_','\0',46,'|',33,33,33,'|',35,'\0','_','_','\0',35,'\0',119,46,46,46,46,46,'|',33,33,'|',35,38,46,46,'|',35,38,35,35,'|',33,33,'|'},	
	{'|','\0','|',35,35,'|',46,'|','\0','_','_','_','\0','|',46,'|',33,33,'O','|',33,'|','\0','\0','|',35,'\0','_','_','_','_','\0',46,'|',35,33,'|',42,245,46,33,'|',38,119,35,38,42,'|','O','|'},
	{'|',46,'|',35,35,'|',46,'|','_','|',64,'|','_','|',46,'|','_','_','_','|',46,'|','\0','\0','|','\0','|','\0','_','_','_','|',46,'|',35,35,'|','_','_','_','_','|',35,35,35,119,33,'|','_','|'},	
	{'|',148,'|',35,35,'|',46,46,46,46,46,46,46,46,46,46,46,35,46,46,46,'|','\0','\0','|','O','|','|',159,46,46,46,42,'|',42,42,46,46,46,46,46,46,35,46,46,46,46,46,35,'|'},
	{'|','_','|','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','|','_','|','|','_','_','_','_','_','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|'}};
	
	char vite[V] = {64,64,64,'\0','\0','\0','\0'};
	
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	
	
	for(int i = 0; i < V; i++)
	{
		armatura[i] = '\0';
	}
	
	for(int i = 0; i < V; i++)
	{
		spada[i] = '\0';
	}
	
	for(int i = 0; i < V; i++)
	{
		chiavi[i] = '\0';
	}

	for(int ir = 0; ir < R; ir++)
	{
		cout << "				";
		
		for(int ic = 0; ic < C; ic++)
		{
			if(((ir == 6) && (ic == 48)) || ((ir == 11) && (ic == 31)))
			{
				SetConsoleTextAttribute(color, 4);
				cout << labirinto[ir][ic];
			}
			
			else if((labirinto[ir][ic] == '|') || (labirinto[ir][ic] == '_'))
			{
				SetConsoleTextAttribute(color, 10);
				cout << labirinto[ir][ic];
			}
			
			else if((labirinto[ir][ic] == '&'))
			{
				SetConsoleTextAttribute(color, 4);
				cout << labirinto[ir][ic];
			}
			
			else if((labirinto[ir][ic] == 'w'))
			{
				SetConsoleTextAttribute(color, 9);
				cout << labirinto[ir][ic];
			}
			
			else if((labirinto[ir][ic] == '#'))
			{
				SetConsoleTextAttribute(color, 5);
				cout << labirinto[ir][ic];
			}
			
			else if((labirinto[ir][ic] == '*'))
			{
				SetConsoleTextAttribute(color, 13);
				cout << labirinto[ir][ic];
			}
			
			else if((labirinto[ir][ic] == '.'))
			{
				SetConsoleTextAttribute(color, 11);
				cout << labirinto[ir][ic];
			}
			
			else if((labirinto[ir][ic] == 'O'))
			{
				SetConsoleTextAttribute(color, 14);
				cout << labirinto[ir][ic];
			}
			
			else if((labirinto[ir][ic] == '!'))
			{
				SetConsoleTextAttribute(color, 1);
				cout << labirinto[ir][ic];
			}
			
			else if((labirinto[ir][ic] == '@'))
			{
				SetConsoleTextAttribute(color, 15);
				cout << labirinto[ir][ic];
			}
			
			else
			{
				SetConsoleTextAttribute(color, 7);
				cout << labirinto[ir][ic];
			}
			
		}
		
		cout << endl;
	}
	
	SetConsoleTextAttribute(color, 6);
	
	GotoXY(a, b);
	cout << p;

	do{

		if (comando == '0' || scelta == 3)
		{
			break;
		}

		///////////////   Interfaccia   ///////////////
		
		SetConsoleTextAttribute(color, 7);
			
		cout << "\n\nPunteggio: " << punteggio <<endl;
		cout << "Vite: ";
		
		for(int i = 0; i < V; i++)
		{
			cout << vite[i];
		}
		
		cout << "\nArmatura Leggendaria: ";
		
		for(int i = 0; i < V; i++)
		{
			cout << armatura[i];
		}
		
		cout << "\nSpada Runica: ";
		
		for(int i = 0; i < V; i++)
		{
			cout << spada[i];
		}
		
		cout << "\nChiavi Magiche: ";
		
		for(int i = 0; i < V; i++)
		{
			cout << chiavi[i];
		}
		
		cout << "\nPassi: " << turni;
		
		cout << endl;
		
		/////////////////////////////////////////////////
		
		comando = getch();
		
		/////////////////////////////////////////////////
		
		SetConsoleTextAttribute(color, 6);
		
		//////////////////   COMANDI   /////////////////
		
		if(comando == 'w' && labirinto[y-1][x] != '_' && labirinto[y-1][x] != '|')
		{	
			p = 148;
			y--;
			b--;
			
			if(labirinto[y][x] == 46)
			{
				punteggio++;
				labirinto[y][x] = '\0';
			}
			
			else if(labirinto[y][x] == 35)
			{
				punteggio = punteggio + 10;
				labirinto[y][x] = '\0';
			}
			
			else if(labirinto[y][x] == 42)
			{
				punteggio = punteggio + 5;
				labirinto[y][x] = '\0';
			}
			
			else if(labirinto[y][x] == 33)
			{
				punteggio = punteggio - 10;
				labirinto[y][x] = '\0';
			}	
			
			else if(labirinto[y][x] == 64)
			{
				vite[n] = 64;
				labirinto[y][x] = '\0';
				n++;
			}
			
			else if(((x == 23) && (y == 12) && (labirinto[y][x] != '\0')) || ((x == 38) && (y == 16) && (labirinto[y][x] != '\0')))
			{
				chiavi[r] = 245;
				labirinto[y][x] = '\0';
				r++;
			}
			
			else if((x == 35) && (y == 1) && (labirinto[y][x] != '\0'))
			{
				armatura[j] = 244;
				labirinto[y][x] = '\0';
				j++;
			}
			
			else if((x == 28) && (y == 18) && (labirinto[y][x] != '\0'))
			{
				spada[s] = 159;
				labirinto[y][x] = '\0';
				s++;
			}
			
			else if(labirinto[y][x] == 119)
			{
				if(armatura[0] != '\0')
				{
					armatura[0] = '\0';
				}
				
				else
				{
					n--;
					vite[n] = '\0';
					labirinto[y][x] = '\0';
				}
			}
			
			else if(labirinto[y][x] == 38)
			{
				if(spada[0] != '\0')
				{
					spada[0] = '\0';
				}
				
				else
				{
					n--;
					vite[n] = '\0';
					labirinto[y][x] = '\0';
				}
			}
			
			else if((chiavi[r-1] != '\0') && (x == 30) && (y == 11))
			{
				r--;
				chiavi[r] = '\0';
				labirinto[y][x+1] = '\0';

				k = 64;
				g = 11;
				GotoXY(k, g);
				cout << '\0';
				GotoXY(a, b);
				cout << p;
			}
			
			else if((chiavi[r-1] != '\0') && (x == 48) && (y == 7))
			{
				r--;
				chiavi[r] = '\0';
				labirinto[y-1][x] = '\0';

				k = 80;
				g = 6;
				GotoXY(k, g);
				cout << '\0';
				GotoXY(a, b);
				cout << p;
			}
			
			GotoXY(a, b);
    		cout << p;
    		GotoXY(a, b+1);
			cout << '\0';	
			labirinto[y][x] = p;
			labirinto[y+1][x] = '\0';
			
			turni++;
		}
		
		else if(comando == 's' && labirinto[y+1][x] != '_' && labirinto[y+1][x] != '|')
		{	
			p = 148;
			y++;
			b++;
			
			if(labirinto[y][x] == 46)
			{
				punteggio++;
				labirinto[y][x] = '\0';
			}
			
			else if(labirinto[y][x] == 35)
			{
				punteggio = punteggio + 10;
				labirinto[y][x] = '\0';
			}
			
			else if(labirinto[y][x] == 42)
			{
				punteggio = punteggio + 5;
				labirinto[y][x] = '\0';
			}
			
			else if(labirinto[y][x] == 33)
			{
				punteggio = punteggio - 10;
				labirinto[y][x] = '\0';
			}
			
			else if(labirinto[y][x] == 64)
			{
				vite[n] = 64;
				labirinto[y][x] = '\0';
				n++;
			}
			
			else if(((x == 23) && (y == 12) && (labirinto[y][x] != '\0')) || ((x == 38) && (y == 16) && (labirinto[y][x] != '\0')))
			{
				chiavi[r] = 245;
				labirinto[y][x] = '\0';
				r++;
			}
			
			else if((x == 35) && (y == 1) && (labirinto[y][x] != '\0'))
			{
				armatura[j] = 244;
				labirinto[y][x] = '\0';
				j++;
			}
			
			else if((x == 28) && (y == 18) && (labirinto[y][x] != '\0'))
			{
				spada[s] = 159;
				labirinto[y][x] = '\0';
				s++;
			}
			
			else if(labirinto[y][x] == 119)
			{
				if(armatura[0] != '\0')
				{
					armatura[0] = '\0';
				}
				
				else
				{
					n--;
					vite[n] = '\0';
					labirinto[y][x] = '\0';
				}
			}
			
			else if(labirinto[y][x] == 38)
			{
				if(spada[0] != '\0')
				{
					spada[0] = '\0';
				}
				
				else
				{
					n--;
					vite[n] = '\0';
					labirinto[y][x] = '\0';
				}
			}
			
			else if((chiavi[r-1] != '\0') && (x == 30) && (y == 11))
			{
				r--;
				chiavi[r] = '\0';
				labirinto[y][x+1] = '\0';

				k = 64;
				g = 11;
				GotoXY(k, g);
				cout << '\0';
				GotoXY(a, b);
				cout << p;
			}
			
			else if((chiavi[r-1] != '\0') && (x == 48) && (y == 7))
			{
				r--;
				chiavi[r] = '\0';
				labirinto[y][x+1] = '\0';

				k = 80;
				g = 6;
				GotoXY(k, g);
				cout << '\0';
				GotoXY(a, b);
				cout << p;
			}
			
			GotoXY(a, b);
    		cout << p;
    		GotoXY(a, b-1);
			cout << '\0';
			labirinto[y][x] = p;
			labirinto[y-1][x] = '\0';
			
			turni++;
		}
		
		else if(comando == 'd' && labirinto[y][x+1] != '_' && labirinto[y][x+1] != '|')
		{	
			p = 148;
			x++;
			a++;
			
			if(labirinto[y][x] == 46)
			{
				punteggio++;
				labirinto[y][x] = '\0';
			}
			
			else if(labirinto[y][x] == 35)
			{
				punteggio = punteggio + 10;
				labirinto[y][x] = '\0';
			}
			
			else if(labirinto[y][x] == 42)
			{
				punteggio = punteggio + 5;
				labirinto[y][x] = '\0';
			}
			
			else if(labirinto[y][x] == 33)
			{
				punteggio = punteggio - 10;
				labirinto[y][x] = '\0';
			}
			
			else if(labirinto[y][x] == 64)
			{
				vite[n] = 64;
				labirinto[y][x] = '\0';
				n++;
			}
			
			else if(((x == 23) && (y == 12) && (labirinto[y][x] != '\0')) || ((x == 38) && (y == 16) && (labirinto[y][x] != '\0')))
			{
				chiavi[r] = 245;
				labirinto[y][x] = '\0';
				r++;
			}
			
			else if((x == 35) && (y == 1) && (labirinto[y][x] != '\0'))
			{
				armatura[j] = 244;
				labirinto[y][x] = '\0';
				j++;
			}
			
			else if((x == 28) && (y == 18) && (labirinto[y][x] != '\0'))
			{
				spada[s] = 159;
				labirinto[y][x] = '\0';
				s++;
			}
			
			else if(labirinto[y][x] == 119)
			{
				if(armatura[0] != '\0')
				{
					armatura[0] = '\0';
				}
				
				else
				{
					n--;
					vite[n] = '\0';
					labirinto[y][x] = '\0';
				}
			}
			
			else if(labirinto[y][x] == 38)
			{
				if(spada[0] != '\0')
				{
					spada[0] = '\0';
				}
				
				else
				{
					n--;
					vite[n] = '\0';
					labirinto[y][x] = '\0';
				}
			}
			
			else if((chiavi[r-1] != '\0') && (x == 30) && (y == 11))
			{
				r--;
				chiavi[r] = '\0';
				labirinto[y][x+1] = '\0';

				k = 64;
				g = 11;
				GotoXY(k, g);
				cout << '\0';
				GotoXY(a, b);
				cout << p;
			}
			
			else if((chiavi[r-1] != '\0') && (x == 48) && (y == 7))
			{
				r--;
				chiavi[r] = '\0';
				labirinto[y-1][x] = '\0';

				k = 80;
				g = 6;
				GotoXY(k, g);
				cout << '\0';
				GotoXY(a, b);
				cout << p;
			}
			
			GotoXY(a, b);
    		cout << p;
    		GotoXY(a-1, b);
			cout << '\0';
			labirinto[y][x] = p;
			labirinto[y][x-1] = '\0';
			
			turni++;
		}
		
		else if(comando == 'a' && labirinto[y][x-1] != '_' && labirinto[y][x-1] != '|')
		{	
			p = 148;
			x--;
			a--;
			
			if(labirinto[y][x] == 245)
			{
				punteggio++;
				labirinto[y][x] = '\0';
			}
			
			else if(labirinto[y][x] == 35)
			{
				punteggio = punteggio + 10;
				labirinto[y][x] = '\0';
			}
			
			else if(labirinto[y][x] == 42)
			{
				punteggio = punteggio + 5;
				labirinto[y][x] = '\0';
			}
			
			else if(labirinto[y][x] == 33)
			{
				punteggio = punteggio - 10;
				labirinto[y][x] = '\0';
			}
			
			else if(labirinto[y][x] == 64)
			{
				vite[n] = 64;
				labirinto[y][x] = '\0';
				n++;
			}
			
			else if(((x == 23) && (y == 12) && (labirinto[y][x] != '\0')) || ((x == 38) && (y == 16) && (labirinto[y][x] != '\0')))
			{
				chiavi[r] = 245;
				labirinto[y][x] = '\0';
				r++;
			}
			
			else if((x == 35) && (y == 1) && (labirinto[y][x] != '\0'))
			{
				armatura[j] = 244;
				labirinto[y][x] = '\0';
				j++;
			}
			
			else if((x == 28) && (y == 18) && (labirinto[y][x] != '\0'))
			{
				spada[s] = 159;
				labirinto[y][x] = '\0';
				s++;
			}
			
			else if(labirinto[y][x] == 119)
			{
				if(armatura[0] != '\0')
				{
					armatura[0] = '\0';
				}
				
				else
				{
					n--;
					vite[n] = '\0';
					labirinto[y][x] = '\0';
				}
			}
			
			else if(labirinto[y][x] == 38)
			{
				if(spada[0] != '\0')
				{
					spada[0] = '\0';
				}
				
				else
				{
					n--;
					vite[n] = '\0';
					labirinto[y][x] = '\0';
				}
			}
			
			else if((chiavi[r-1] != '\0') && (x == 30) && (y == 11))
			{
				r--;
				chiavi[r] = '\0';
				labirinto[y][x+1] = '\0';

				k = 64;
				g = 11;
				GotoXY(k, g);
				cout << '\0';
				GotoXY(a, b);
				cout << p;
			}
			
			else if((chiavi[r-1] != '\0') && (x == 48) && (y == 7))
			{
				r--;
				chiavi[r] = '\0';
				labirinto[y-1][x] = '\0';

				k = 80;
				g = 6;
				GotoXY(k, g);
				cout << '\0';
				GotoXY(a, b);
				cout << p;
			}
			
			GotoXY(a, b);
    		cout << p;
    		GotoXY(a+1, b);
			cout << '\0';
			labirinto[y][x] = p;
			labirinto[y][x+1] = '\0';
			
			turni++;
		}
		
		else if (comando == '0' || comando == '4')
		{
			break;
		}
		
		/////////////////////////////////////////////////
		
		///////////////   Teletrasporto   ///////////////
		
		if((x == 1) && (y == 2))
		{
			p = 148;
			labirinto[y][x] = '\0';
			y = 15;
			x = 32;
			labirinto[y][x] = p;
			
			GotoXY(a, b);
			cout << '\0';
			a = 64;
			b = 15;
			GotoXY(a, b);
			cout << p;
		}
		
		else if((x == 32) && (y == 14))
		{
			p = 148;
			labirinto[y][x] = '\0';
			y = 3;
			x = 1;
			labirinto[y][x] = p;
			
			GotoXY(a, b);
			cout << '\0';
			a = 33;
			b = 3;
			GotoXY(a, b);
			cout << p;
		}
		
		else if((x == 30) && (y == 2))
		{
			p = 148;
			labirinto[y][x] = '\0';
			y = 9;
			x = 7;
			labirinto[y][x] = p;
			
			GotoXY(a, b);
			cout << '\0';
			a = 39;
			b = 9;
			GotoXY(a, b);
			cout << p;
		}
		
		else if((x == 7) && (y == 8))
		{
			p = 148;
			labirinto[y][x] = '\0';
			y = 3;
			x = 30;
			labirinto[y][x] = p;
			
			GotoXY(a, b);
			cout << '\0';
			a = 62;
			b = 3;
			GotoXY(a, b);
			cout << p;
		}
		
		else if((x == 25) && (y == 17))
		{
			p = 148;
			labirinto[y][x] = '\0';
			y = 12;
			x = 5;
			labirinto[y][x] = p;
			
			GotoXY(a, b);
			cout << '\0';
			a = 37;
			b = 12;
			GotoXY(a, b);
			cout << p;
		}
		
		else if(((x == 22) && (y == 6)) || ((x == 22) && (y == 4)))
		{
			p = 148;
			labirinto[y][x] = '\0';
			y = 11;
			x = 12;
			labirinto[y][x] = p;
			
			GotoXY(a, b);
			cout << '\0';
			a = 44;
			b = 11;
			GotoXY(a, b);
			cout << p;
		}
		
		else if(((x == 17) && (y == 16)) || ((x == 18) && (y == 15)))
		{
			p = 148;
			labirinto[y][x] = '\0';
			y = 14;
			x = 48;
			labirinto[y][x] = p;
			
			GotoXY(a, b);
			cout << '\0';
			a = 80;
			b = 14;
			GotoXY(a, b);
			cout << p;
		}
		
		else if((x == 48) && (y == 15))
		{
			p = 148;
			labirinto[y][x] = '\0';
			y = 15;
			x = 17;
			labirinto[y][x] = p;
			
			GotoXY(a, b);
			cout << '\0';
			a = 49;
			b = 15;
			GotoXY(a, b);
			cout << p;
		}
		
		///////////////////   Trappola   //////////////////
		
		if((x == 20) && (y == 4))
		{
			l = 8;
			m = 20;
			labirinto[l][m] = '_';
			
			GotoXY(a, b);
			cout << '\0';
			k = 52;
			g = 8;
			GotoXY(k, g);
			cout << "_";
			GotoXY(a, b);
			cout << p;
		}
		
		
		d = 20;
		e = 0;
		GotoXY(e, d);	

		for(d = 21; d < 25; d++)
		{
			for(e = 0; e < 30; e++)
			{
				GotoXY(e, d);
				cout << '\0';
			}
		}
		
		d = 18;
		e = 0;
		GotoXY(e, d);
	
	}while(vite[0] == 64 && labirinto[1][48] == '\0' && labirinto[1][47] == '\0');
	
	
	SetConsoleTextAttribute(color, 7);
	
	
	d = 18;
	e = 0;
	GotoXY(e, d);	

	for(d = 20; d < 25; d++)
	{
		for(e = 0; e < 30; e++)
		{
			GotoXY(e, d);
			cout << '\0';
		}
	}
	
	d = 18;
	e = 0;
	
	if(comando == '0' || comando == '4')
	{
		cout << "Fine Partita!";
	}
	
	else if(vite[0] == '\0')
	{
		cout << "Hai Perso!";
	}
	
	else
	{
		cout << "Hai Vinto!";
		j = j * 1000;
		s = s * 1000;
		r = r * 1000;
		t = (punteggio - turni + r + s + j) * n;
		cout << "\nEcco il tuo punteggio: " << t;
	}
	
	cout << endl;
	system("pause");
	
	system("cls");	
}
