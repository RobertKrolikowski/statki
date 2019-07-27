#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
char poleG[10][10];
char poleK[10][10];
char poleK1[10][10];
char przycisk;
int	nrK = 0, nrW = 0, statekW, statekK = -1, statek = 3, koniec = 1, trafienieG = 0;
int knrW, knrK, trafienieK = 0, trafienieK1 = 0, strzalPion = 0;
//poziome
void roztawienie1()
{
	//lewo gora dol prawo
	if ((poleG[nrW][nrK] == '.') && ((poleG[nrW - 1][nrK] == '.') || nrW - 1 == -1) && ((poleG[nrW][nrK - 1] == '.') || nrK - 1 == -1) && ((poleG[nrW][nrK + 1] == '.') || nrK + 1 == 10) && ((poleG[nrW + 1][nrK] == '.') || nrW + 1 == 10))
		//skosy
		if ((poleG[nrW - 1][nrK - 1] == '.' || nrW - 1 == -1 || nrK - 1 == -1) && (poleG[nrW - 1][nrK + 1] == '.' || nrW - 1 == -1 || nrK + 1 == 10) && (poleG[nrW + 1][nrK - 1] == '.' || nrW + 1 == 10 || nrK - 1 == -1) && (poleG[nrW + 1][nrK + 1] == '.' || nrW + 1 == 10 || nrK + 1 == 10))
			//dlugosc statku srodek gora dol
			if ((poleG[nrW + statek][nrK] == '.' || nrW + statek == 10) && (poleG[nrW + statek][nrK - 1] == '.' || nrW + statek == 10 || nrK - 1 == -1) && (poleG[nrW + statek][nrK + 1] == '.' || nrW + statek == 10 || nrK + 1 == 10))
				//dlugosc statku+1 srodek gora dol
				if ((poleG[nrW + statek + 1][nrK] == '.' || nrW + statek + 1 == 10) && (poleG[nrW + statek + 1][nrK - 1] == '.' || nrW + statek + 1 == 10 || nrK - 1 == -1) && (poleG[nrW + statek + 1][nrK + 1] == '.' || nrW + statek + 1 == 10 || nrK + 1 == 10))
				{
					for (; statekW >= 0; statekW--)
						poleG[nrW + statekW][nrK] = 219;
					statekW = statek - 1;
					statek = statekW;
				}
}
//pionowe
void roztawienie2()
{
	//lewo gora dol prawo
	if ((poleG[nrW][nrK] == '.') && ((poleG[nrW - 1][nrK] == '.') || nrW - 1 == -1) && ((poleG[nrW][nrK - 1] == '.') || nrK - 1 == -1) && ((poleG[nrW][nrK + 1] == '.') || nrK + 1 == 10) && ((poleG[nrW + 1][nrK] == '.') || nrW + 1 == 10))
		//skosy
		if ((poleG[nrW - 1][nrK - 1] == '.' || nrW - 1 == -1 || nrK - 1 == -1) && (poleG[nrW - 1][nrK + 1] == '.' || nrW - 1 == -1 || nrK + 1 == 10) && (poleG[nrW + 1][nrK - 1] == '.' || nrW + 1 == 10 || nrK - 1 == -1) && (poleG[nrW + 1][nrK + 1] == '.' || nrW + 1 == 10 || nrK + 1 == 10))
			//dlugosc statku srodek gora dol
			if ((poleG[nrW][nrK + statek] == '.' || nrK + statek == 10) && (poleG[nrW - 1][nrK + statek] == '.' || nrK + statek == 10 || nrW - 1 == -1) && (poleG[nrW + 1][nrK + statek] == '.' || nrK + statek == 10 || nrW + 1 == 10))
				//dlugosc statku+1 srodek gora dol
				if ((poleG[nrW][nrK + statek + 1] == '.' || nrK + statek + 1 == 10) && (poleG[nrW - 1][nrK + statek + 1] == '.' || nrK + statek + 1 == 10 || nrW - 1 == -1) && (poleG[nrW + 1][nrK + statek + 1] == '.' || nrK + statek + 1 == 10 || nrW + 1 == 10))
				{

					for (; statekK >= 0; statekK--)
						poleG[nrW][nrK + statekK] = 219;
					statekK = statek - 1;
					statek = statekK;
				}
}


//wypelnienie planszy
void wypelnienie1()
{
	for (int b = 0; b < 10; b++)
		for (int a = 0; a < 10; a++)
			poleG[a][b] = '.';
}
void wypelnienie2()
{
	for (int b = 0; b < 10; b++)
		for (int a = 0; a < 10; a++)
			poleK[a][b] = '.';
}
void wypelnienie3()
{
	for (int b = 0; b < 10; b++)
		for (int a = 0; a < 10; a++)
			poleK1[a][b] = '.';
}
//poruszanie sie
void poruszanie()
{
	int wiersz = statekW, kolumna = statekK;
	if (kolumna == -1) kolumna = 0;
	if (wiersz == -1) wiersz = 0;
	if ((przycisk == 119) || (przycisk == 115) || (przycisk == 97) || (przycisk == 100))
		if (poleG[nrW][nrK] == '.')
			poleG[nrW][nrK] = '.';
	if (przycisk == 119)
	{
		if (nrK == 0) nrK = 9 - kolumna;
		else nrK--;
		//poleG[nrW][nrK]='*';
	}
	if (przycisk == 115)
	{
		if (nrK == 9 - kolumna) nrK = 0;
		else nrK++;
		//poleG[nrW][nrK]='*';
	}
	if (przycisk == 97)
	{
		if (nrW == 0) nrW = 9 - wiersz;
		else nrW--;
		//poleG[nrW][nrK]='*';
	}
	if (przycisk == 100)
	{
		if (nrW == 9 - wiersz) nrW = 0;
		else nrW++;
		//poleG[nrW][nrK]='*';
	}
}

//*****************************************************************************
//*****************************************************************************
int main()
{

	HANDLE hOut;
	srand(time(0));
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	wypelnienie1();
	wypelnienie2();
	printf("Witam w grze statki.\n");
	statekW = statek;
	do
	{
		printf("Roztaw swoj %d masztowiec.\n", statek + 1);
		printf("Poruszaneie WSAD-em,obrot R natomiast enter potwierdza dzialanie\n");
		//malowanie planszy
		printf("+");
		for (int a = 0; a < 10; a++)
		{
			printf("-");
		}
		printf("+\n");
		for (int b = 0, d = 0; b < 10; b++)
		{
			printf("|");
			for (int a = 0; a < 10; a++)
			{
				//kolorowanie pola w wierszu(poziomo)
				if ((a == nrW) && (b == nrK) && (statekK == -1))
				{


					for (int c = 0; c <= statekW; c++)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						printf("%c", poleG[a + c][b]);

					}
					a += statekW;
				}
				//kolorowanie polo w kolumnie(pionowo)
				else if ((a == nrW) && (b == nrK + d) && (statekW == -1))
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					printf("%c", poleG[a][b]);
					if (d == statekK)	d = 0;
					else
						d++;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					printf("%c", poleG[a][b]);
				}
			}
			//przypisanie zwyklego koloru
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			printf("|\n");
		}
		printf("+");
		for (int a = 0; a < 10; a++)
		{
			printf("-");
		}
		printf("+\n");
		//zczyanie klawisza		
		przycisk = _getch();
		poruszanie();
		//roztawienie statku
		if (przycisk == 13)
		{
			if (statekW != -1)
			{
				roztawienie1();
			}
			else
			{
				roztawienie2();
			}
		}
		//obracanie
		if ((przycisk == 114) && (statekW != -1) && (statek != 0))
		{
			statekK = statekW;
			statekW = -1;
			//zapobieganie zeby nie wyszlo poza zakres
			if ((nrK == 9) && (nrK + statek>9))
				nrK -= statek;
			else if ((nrK == 8) && (nrK + statek>9))
				nrK -= statek - 1;
			else if ((nrK == 7) && (nrK + statek>9))
				nrK -= statek - 2;
		}
		else if ((przycisk == 114) && (statekK != -1) && (statek != 0))
		{
			statekW = statekK;
			statekK = -1;
			//zapobieganie zeby nie wyszlo poza zakres
			if ((nrW == 9) && (nrW + statek>9))
				nrW -= statek;
			else if ((nrW == 8) && (nrW + statek>9))
				nrW -= statek - 1;
			else if ((nrW == 7) && (nrW + statek>9))
				nrW -= statek - 2;
		}
		system("cls");
	} while (statek != -1);
	//ustawienie statkow przez komputera
	wypelnienie3();
	statek = 3;
	do
	{
		int obrot;
		nrW = rand() % 10;
		nrK = rand() % 10;
		obrot = rand() % 2;
		//poziomo 0
		//lewo gora dol prawo
		if ((obrot == 0) && (poleK1[nrW][nrK] == '.') && ((poleK1[nrW - 1][nrK] == '.') || nrW - 1 == -1) && ((poleK1[nrW][nrK - 1] == '.') || nrK - 1 == -1) && ((poleK1[nrW][nrK + 1] == '.') || nrK + 1 == 10) && ((poleK1[nrW + 1][nrK] == '.') || nrW + 1 == 10))
			//skosy
			if ((poleK1[nrW - 1][nrK - 1] == '.' || nrW - 1 == -1 || nrK - 1 == -1) && (poleK1[nrW - 1][nrK + 1] == '.' || nrW - 1 == -1 || nrK + 1 == 10) && (poleK1[nrW + 1][nrK - 1] == '.' || nrW + 1 == 10 || nrK - 1 == -1) && (poleK1[nrW + 1][nrK + 1] == '.' || nrW + 1 == 10 || nrK + 1 == 10))
				//dlugosc statku srodek gora dol
				if ((poleK1[nrW + statek][nrK] == '.' || nrW + statek == 10) && (poleK1[nrW + statek][nrK - 1] == '.' || nrW + statek == 10 || nrK - 1 == -1) && (poleK1[nrW + statek][nrK + 1] == '.' || nrW + statek == 10 || nrK + 1 == 10))
					//dlugosc statku+1 srodek gora dol
					if ((poleK1[nrW + statek + 1][nrK] == '.' || nrW + statek + 1 == 10) && (poleK1[nrW + statek + 1][nrK - 1] == '.' || nrW + statek + 1 == 10 || nrK - 1 == -1) && (poleK1[nrW + statek + 1][nrK + 1] == '.' || nrW + statek + 1 == 10 || nrK + 1 == 10))
						if (nrW + statek + 1 < 10)
						{
							for (int a = statek; a >= 0; a--)
								poleK1[nrW + a][nrK] = 219;
							statek--;
						}
		//pionowo 1
		//lewo gora dol prawo
		if ((obrot == 1) && (poleK1[nrW][nrK] == '.') && ((poleK1[nrW - 1][nrK] == '.') || nrW - 1 == -1) && ((poleK1[nrW][nrK - 1] == '.') || nrK - 1 == -1) && ((poleK1[nrW][nrK + 1] == '.') || nrK + 1 == 10) && ((poleK1[nrW + 1][nrK] == '.') || nrW + 1 == 10))
			//skosy
			if ((poleK1[nrW - 1][nrK - 1] == '.' || nrW - 1 == -1 || nrK - 1 == -1) && (poleK1[nrW - 1][nrK + 1] == '.' || nrW - 1 == -1 || nrK + 1 == 10) && (poleK1[nrW + 1][nrK - 1] == '.' || nrW + 1 == 10 || nrK - 1 == -1) && (poleK1[nrW + 1][nrK + 1] == '.' || nrW + 1 == 10 || nrK + 1 == 10))
				//dlugosc statku srodek gora dol
				if ((poleK1[nrW][nrK + statek] == '.' || nrK + statek == 10) && (poleK1[nrW - 1][nrK + statek] == '.' || nrK + statek == 10 || nrW - 1 == -1) && (poleK1[nrW + 1][nrK + statek] == '.' || nrK + statek == 10 || nrW + 1 == 10))
					//dlugosc statku+1 srodek gora dol
					if ((poleK1[nrW][nrK + statek + 1] == '.' || nrK + statek + 1 == 10) && (poleK1[nrW - 1][nrK + statek + 1] == '.' || nrK + statek + 1 == 10 || nrW - 1 == -1) && (poleK1[nrW + 1][nrK + statek + 1] == '.' || nrK + statek + 1 == 10 || nrW + 1 == 10))
						if (nrK + statek + 1 < 10)
						{
							for (int a = statek; a >= 0; a--)
								poleK1[nrW][nrK + a] = 219;
							statek--;
						}
	} while (statek != -1);
	//wyzerowanie pozycji strzalu
	nrW = 0;
	nrK = 0;
	do
	{
		system("cls");
		printf("Jesli znalazles jakis blad napisz\"q\" chwilowo konczy program\n");
		printf("Poruszanie WSAD-em,enter strzal\n");
		printf("Twoje statki\tStatki przeciwnika(plansza komputera bedzie potem uktyta)\n\n");
		//rysowanie planszy gracza(1) i planszy komputera(2)
		//1
		printf("+");
		for (int a = 0; a < 10; a++)
		{
			printf("-");
		}
		printf("+\t");
		//2
		printf("+");
		for (int a = 0; a < 10; a++)
		{
			printf("-");
		}
		printf("+\n");

		for (int b = 0, d = 0; b < 10; b++)
		{	//1
			printf("|");
			for (int a = 0; a < 10; a++)
			{
				printf("%c", poleG[a][b]);
			}
			printf("|\t");
			//2
			printf("|");
			for (int a = 0; a < 10; a++)
			{
				if ((a == nrW) && (b == nrK))
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					printf("%c", poleK[a][b]);
				}
				else
				{
					printf("%c", poleK[a][b]);
				}
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			}
			printf("|\n");
		}
		//1
		printf("+");
		for (int a = 0; a < 10; a++)
		{
			printf("-");
		}
		printf("+\t");
		//2
		printf("+");
		for (int a = 0; a < 10; a++)
		{
			printf("-");
		}
		printf("+\n");
		//poruszanie
		przycisk = _getch();
		if (przycisk == 119)
		{
			if (nrK == 0) nrK = 9;
			else nrK--;
		}
		if (przycisk == 115)
		{
			if (nrK == 9) nrK = 0;
			else nrK++;
		}
		if (przycisk == 97)
		{
			if (nrW == 0) nrW = 9;
			else nrW--;
		}
		if (przycisk == 100)
		{
			if (nrW == 9) nrW = 0;
			else nrW++;
		}
		//strzal
		if ((przycisk == 13) && (poleK[nrW][nrK] == '.'))
		{
			//-37 to numer grafiki statku predzej byl (219)
			if (poleK1[nrW][nrK] == -37)
			{
				poleK[nrW][nrK] = 'X';
				poleK1[nrW][nrK] = 'X';
				trafienieG++;
				//sprawdzenie czy statek jest zatopiony(jednomasztowiec)
				if ((poleK1[nrW - 1][nrK] == '.' || nrW - 1 == -1) && (poleK1[nrW + 1][nrK] == '.' || nrW + 1 == 10) && (poleK1[nrW][nrK + 1] == '.' || nrK + 1 == 10) && (poleK1[nrW][nrK - 1] == '.' || nrK - 1 == -1))
				{
					//zatopienie jednomasztowca
					if (nrW - 1 != -1)
						poleK[nrW - 1][nrK] = 'O';
					if (nrW + 1 != 10)
						poleK[nrW + 1][nrK] = 'O';
					if (nrK - 1 != -1)
						poleK[nrW][nrK - 1] = 'O';
					if (nrK + 1 != 10)
						poleK[nrW][nrK + 1] = 'O';

					if (nrW - 1 != -1 && nrK - 1 != -1)
						poleK[nrW - 1][nrK - 1] = 'O';
					if (nrW - 1 != -1 && nrK + 1 != 10)
						poleK[nrW - 1][nrK + 1] = 'O';
					if (nrW + 1 != 10 && nrK - 1 != -1)
						poleK[nrW + 1][nrK - 1] = 'O';
					if (nrW + 1 != 10 && nrK + 1 != 10)
						poleK[nrW + 1][nrK + 1] = 'O';
				}
				//wielomasztowiec poziomy
				else if ((poleK1[nrW][nrK - 1] == '.' || nrK - 1 == -1) && (poleK1[nrW][nrK + 1] == '.' || nrK + 1 == 10))
				{

					for (int masztL = 1, masztP = 1;;)
					{
						if (poleK1[nrW - masztL][nrK] == -37)
							break;
						else if (poleK1[nrW + masztP][nrK] == -37)
							break;
						else if (poleK1[nrW - masztL][nrK] == 'X')
						{
							masztL++;
						}
						else if (poleK1[nrW + masztP][nrK] == 'X')
						{
							masztP++;
						}
						else if ((poleK1[nrW + masztP][nrK] == '.' || poleK1[nrW + masztP][nrK] == 'O' || nrW + 1 == 10))
						{
							//koniec prawy
							if ((nrW + masztP != 10) && (nrK - 1 != -1))
								poleK[nrW + masztP][nrK - 1] = 'O';
							if (nrW + masztP != 10)
								poleK[nrW + masztP][nrK] = 'O';
							if ((nrW + masztP != 10) && (nrK + 1 != 10))
								poleK[nrW + masztP][nrK + 1] = 'O';
							//koniec lewy
							if ((nrW - masztL != -1) && (nrK - 1 != -1))
								poleK[nrW - masztL][nrK - 1] = 'O';
							if (nrW - masztL != -1)
								poleK[nrW - masztL][nrK] = 'O';
							if ((nrW - masztL != -1) && (nrK + 1 != 10))
								poleK[nrW - masztL][nrK + 1] = 'O';
							//gora i do³
							for (int a = 0; a < masztL; a++)
							{
								if (nrK - 1 != -1)
									poleK[nrW - a][nrK - 1] = 'O';
								if (nrK + 1 != 10)
									poleK[nrW - a][nrK + 1] = 'O';
							}
							for (int a = 0; a < masztP; a++)
							{
								if (nrK - 1 != -1)
									poleK[nrW + a][nrK - 1] = 'O';
								if (nrK + 1 != 10)
									poleK[nrW + a][nrK + 1] = 'O';
							}
							break;
						}
					}
				}
				//wielomasztowiec pionowy masztL=G masztP=D
				else
				{
					//zmiana
					for (int masztG = 1, masztD = 1;;)
					{
						if (poleK1[nrW][nrK - masztG] == -37)
							break;
						else if (poleK1[nrW][nrK + masztD] == -37)
							break;
						else if (poleK1[nrW][nrK - masztG] == 'X')
						{
							masztG++;
						}
						else if (poleK1[nrW][nrK + masztD] == 'X')
						{
							masztD++;
						}
						else if ((poleK1[nrW][nrK + masztD] == '.' || poleK1[nrW][nrK + masztD] == 'O' || nrK + 1 == 10))
						{
							//koniec dol
							if ((nrK + masztD != 10) && (nrW - 1 != -1))
								poleK[nrW - 1][nrK + masztD] = 'O';
							if (nrK + masztD != 10)
								poleK[nrW][nrK + masztD] = 'O';
							if ((nrK + masztD != 10) && (nrW + 1 != 10))
								poleK[nrW + 1][nrK + masztD] = 'O';
							//koniec gora
							if ((nrK - masztG != -1) && (nrW - 1 != -1))
								poleK[nrW - 1][nrK - masztG] = 'O';
							if (nrK - masztG != -1)
								poleK[nrW][nrK - masztG] = 'O';
							if ((nrK - masztG != -1) && (nrK + 1 != 10))
								poleK[nrW + 1][nrK - masztG] = 'O';
							//gora i do³
							for (int a = 0; a < masztG; a++)
							{
								if (nrW - 1 != -1)
									poleK[nrW - 1][nrK - a] = 'O';
								if (nrW + 1 != 10)
									poleK[nrW + 1][nrK - a] = 'O';
							}
							for (int a = 0; a < masztD; a++)
							{
								if (nrW - 1 != -1)
									poleK[nrW - 1][nrK + a] = 'O';
								if (nrW + 1 != 10)
									poleK[nrW + 1][nrK + a] = 'O';
							}
							break;
						}
					}
				}

			}
			else
			{
				poleK[nrW][nrK] = 'O';
				//strzal komputera
				do
				{
					if (trafienieK == 0)
					{
						knrW = rand() % 10;
						knrK = rand() % 10;
					}
					//jesli trafi strzelaj wedlug schematu
					//poziomo
					else if ((strzalPion == 0) && (knrW - 1 != -1) && (poleG[knrW][knrK] != 'O') && (poleG[knrW - 1][knrK] != 'X'))
					{
						knrW--;
					}
					else if ((strzalPion == 0) && (poleG[knrW][knrK] == 'O'))
					{
						knrW += trafienieK + 1;
						if (poleG[knrW][knrK] == '.' || poleG[knrW][knrK] == 'O' || knrW == 10)
						{
							knrW--;
							strzalPion = 1;
						}
					}
					else if (strzalPion == 0)
					{
						if ((knrW - 1 == -1) && (poleG[knrW][knrK + 1] == 'X' || poleG[knrW][knrK + 1] == -37 || poleG[knrW][knrK - 1] == -37))
							strzalPion = 1;
						else
							knrW++;
					}//strzelanie w pionie
					else if ((strzalPion == 1) && (knrK - 1 != -1) && (poleG[knrW][knrK] != 'O') && (poleG[knrW][knrK - 1] != 'X'))
					{
						knrK--;
					}
					else if ((strzalPion == 1) && (poleG[knrW][knrK] == 'O'))
					{
						knrK += trafienieK + 1;
					}
					else if (strzalPion == 1)
					{
						knrK++;
					}


					if (poleG[knrW][knrK] == -37)
					{
						poleG[knrW][knrK] = 'X';
						trafienieK++;
						trafienieK1++;
						//trafienie i zatopienie jedno masztowca
						if ((poleG[knrW + 1][knrK] == '.' || poleG[knrW + 1][knrK] == 'O' || knrW + 1 == 10) && (poleG[knrW - 1][knrK] == '.' || poleG[knrW - 1][knrK] == 'O' || knrW - 1 == -1))
						{
							if ((poleG[knrW][knrK - 1] == '.' || poleG[knrW][knrK - 1] == 'O' || knrK - 1 == -1) && (poleG[knrW][knrK + 1] == '.' || poleG[knrW][knrK + 1] == 'O' || knrK + 1 == 10))
							{
								poleG[knrW][knrK] = 'X';
								//lewo prawo gora dol
								if (knrW - 1 != -1)
									poleG[knrW - 1][knrK] = 'O';
								if (knrW + 1 != 10)
									poleG[knrW + 1][knrK] = 'O';
								if (knrK - 1 != -1)
									poleG[knrW][knrK - 1] = 'O';
								if (knrK + 1 != 10)
									poleG[knrW][knrK + 1] = 'O';
								//skosy
								if (knrW - 1 != -1 || knrK - 1 != -1)
									poleG[knrW - 1][knrK - 1] = 'O';
								if (knrW - 1 != -1 || knrK + 1 != 10)
									poleG[knrW - 1][knrK + 1] = 'O';
								if (knrW + 1 != 10 || knrK - 1 != -1)
									poleG[knrW + 1][knrK - 1] = 'O';
								if (knrW + 1 != 10 || knrK + 1 != 10)
									poleG[knrW + 1][knrK + 1] = 'O';
								strzalPion = 0;
								trafienieK = 0;
							}
						}


						if ((poleG[knrW][knrK + 1] == '.' || poleG[knrW][knrK + 1] == 'O' || knrK + 1 == 10) && (poleG[knrW][knrK - 1] == '.' || poleG[knrW][knrK - 1] == 'O' || knrK - 1 == -1))
						{
							strzalPion = 0;
							//sprawdzanie w poziomie
							if ((((poleG[knrW + trafienieK][knrK] == '.' || poleG[knrW + trafienieK][knrK] == 'O' || knrW + trafienieK >= 10) && (poleG[knrW - 1][knrK] == '.' || poleG[knrW - 1][knrK] == 'O' || knrW - 1 == -1))
								|| ((poleG[knrW + 1][knrK] == '.' || poleG[knrW + 1][knrK] == 'O' || knrW + 1 == 10) && (poleG[knrW - trafienieK][knrK] == '.' || poleG[knrW - trafienieK][knrK] == 'O' || knrW - trafienieK == -1))))
							{

								//stafienie w srodek statku
								if (poleG[knrW - (trafienieK - 1)][knrK] == 'X')
								{
									if (knrK - 1 != -1)
										for (int a = 0; a < trafienieK; a++)
											poleG[knrW - a][knrK - 1] = 'O';

									if (knrK + 1 != 10)
										for (int a = 0; a < trafienieK; a++)
											poleG[knrW - a][knrK + 1] = 'O';

									if (knrW - trafienieK != -1 && knrK - 1 != -1)
										poleG[knrW - trafienieK][knrK - 1] = 'O';
									if (knrW - trafienieK != -1)
										poleG[knrW - trafienieK][knrK] = 'O';
									if (knrW - trafienieK != -1 && knrK + 1 != 10)
										poleG[knrW - trafienieK][knrK + 1] = 'O';


									if (knrW + 1 != 10 && knrK - 1 != -1)
										poleG[knrW + 1][knrK - 1] = 'O';
									if (knrW + 1 != 10)
										poleG[knrW + 1][knrK] = 'O';
									if (knrW + 1 != 10 && knrK + 1 != 10)
										poleG[knrW + 1][knrK + 1] = 'O';

								}//trafienie w prawy skrajny bok
								else if (poleG[knrW + (trafienieK - 1)][knrK] == 'X')
								{
									if (knrK - 1 != -1)
										for (int a = 0; a < trafienieK; a++)
											poleG[knrW + a][knrK - 1] = 'O';

									if (knrK + 1 != 10)
										for (int a = 0; a < trafienieK; a++)
											poleG[knrW + a][knrK + 1] = 'O';

									if (knrW - 1 != -1 && knrK - 1 != -1)
										poleG[knrW - 1][knrK - 1] = 'O';
									if (knrW - 1 != -1)
										poleG[knrW - 1][knrK] = 'O';
									if (knrW - 1 != -1 && knrK + 1 != 10)
										poleG[knrW - 1][knrK + 1] = 'O';

									if (knrW + trafienieK != 10 && knrK - 1 != -1)
										poleG[knrW + trafienieK][knrK - 1] = 'O';
									if (knrW + trafienieK != 10)
										poleG[knrW + trafienieK][knrK] = 'O';
									if (knrW + trafienieK != 10 && knrK + 1 != 10)
										poleG[knrW + trafienieK][knrK + 1] = 'O';

								}
								trafienieK = 0;
							}
						}//sprawdzanie w pionie
						else if (((strzalPion == 1) && (poleG[knrW][knrK + trafienieK] == '.' || poleG[knrW][knrK + trafienieK] == 'O' || knrK + trafienieK >= 10) && (poleG[knrW][knrK - 1] == '.' || poleG[knrW][knrK - 1] == 'O' || knrK - 1 == -1))
							|| ((poleG[knrW][knrK + 1] == '.' || poleG[knrW][knrK + 1] == 'O' || knrK + 1 == 10) && (poleG[knrW][knrK - trafienieK] == '.' || poleG[knrW][knrK - trafienieK] == 'O' || knrK - trafienieK == -1)))
						{

							//stafienie w srodek statku
							if (poleG[knrW][knrK - (trafienieK - 1)] == 'X')
							{
								if (knrW - 1 != -1)
									for (int a = 0; a < trafienieK; a++)
										poleG[knrW - 1][knrK - a] = 'O';

								if (knrW + 1 != 10)
									for (int a = 0; a < trafienieK; a++)
										poleG[knrW + 1][knrK - a] = 'O';

								if (knrK - trafienieK != -1 && knrW - 1 != -1)
									poleG[knrW - 1][knrK - trafienieK] = 'O';
								if (knrK - trafienieK != -1)
									poleG[knrW][knrK - trafienieK] = 'O';
								if (knrK - trafienieK != -1 && knrW + 1 != 10)
									poleG[knrW + 1][knrK - trafienieK] = 'O';


								if (knrK + 1 != 10 && knrW - 1 != -1)
									poleG[knrW - 1][knrK + 1] = 'O';
								if (knrK + 1 != 10)
									poleG[knrW][knrK + 1] = 'O';
								if (knrK + 1 != 10 && knrW + 1 != 10)
									poleG[knrW + 1][knrK + 1] = 'O';

							}//trafienie w dolny skrajny bok
							else if (poleG[knrW][knrK + (trafienieK - 1)] == 'X')
							{
								if (knrW - 1 != -1)
									for (int a = 0; a < trafienieK; a++)
										poleG[knrW - 1][knrK + a] = 'O';

								if (knrW + 1 != 10)
									for (int a = 0; a < trafienieK; a++)
										poleG[knrW + 1][knrK + a] = 'O';

								if (knrK - 1 != -1 && knrW - 1 != -1)
									poleG[knrW - 1][knrK - 1] = 'O';
								if (knrK - 1 != -1)
									poleG[knrW][knrK - 1] = 'O';
								if (knrK - 1 != -1 && knrW + 1 != 10)
									poleG[knrW + 1][knrK - 1] = 'O';


								if (knrK + trafienieK != 10 && knrW - 1 != -1)
									poleG[knrW - 1][knrK + trafienieK] = 'O';
								if (knrK + trafienieK != 10)
									poleG[knrW][knrK + trafienieK] = 'O';
								if (knrK + trafienieK != 10 && knrW + 1 != 10)
									poleG[knrW + 1][knrK + trafienieK] = 'O';

							}
							strzalPion = 0;
							trafienieK = 0;
						}
					}
					else if (poleG[knrW][knrK] == '.')
					{
						poleG[knrW][knrK] = 'O';
						break;
					}
				} while (1);
			}
		}
		//jeszcze brakuje strzelania gracza i komputera , sprawdzanie czy sie trafilo cos 
		//chwilowe zakonczenie programu
		if (przycisk == 'q' || trafienieG == 10 || trafienieK1 == 10)
			koniec = 0;
	} while (koniec == 1);
	system("cls");
	printf("Koniec gry\n");
	if (trafienieK1 == 10)
		printf("Wygral komputer\n");
	else
		printf("Gratulacje wygrales\n");
	_getch();
	return 0;
}
