// Jeu de dame.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//creation plateau
int tab[10][10];

void Ecrire_tab()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}

}

int main()
{
	//initialisation du jeu
//mettre toutes les cases vides
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			tab[i][j] = 0;
	//mettre les pions blancs
	for (int i = 0; i < 5; i++)
	{
		tab[0][2 * i] = 1;
		tab[1][2 * i + 1] = 1;
		tab[2][2 * i] = 1;
		tab[3][2 * i + 1] = 1;
	}
	//mettre les pions noirs
	for (int i = 0; i < 5; i++)
	{
		tab[6][2 * i] = 2;
		tab[7][2 * i + 1] = 2;
		tab[8][2 * i] = 2;
		tab[9][2 * i + 1] = 2;
	}

	//on test
	Ecrire_tab();

	getchar();

	return 0;
}

