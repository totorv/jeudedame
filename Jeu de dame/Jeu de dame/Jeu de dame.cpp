// Jeu de dame.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Variables globales
char tab[10][10];
bool partie_finie = 0;

struct coord
{
	int x, y;
};

struct  mouv
{
	coord from, to;
};

void Ecrire_tab()
{
	cout << "  A B C D E F G H I J" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i << " ";
		for (int j = 0; j < 10; j++)
		{
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}
}

void MouvementBlanc()
{
	vector<mouv> mouvPossibles;

	for (int i = 0; i < 10; i++) //on cherche sur le platau
	{
		for (int j = 0; j < 10; j++)
		{
			if (tab[i][j] == 'B') //si on a un pion blanc
			{
				if (i + 1 < 10 && j - 1 > 0) //si la case en diagonale bas-gauche existe 
				{
					if (tab[i + 1][j - 1] == 0) //
					{
						mouv mouve;
						mouve.from.x = i;
						mouve.from.y = j;
						mouve.to.x = i + 1;
						mouve.to.y = j - 1;
						mouvPossibles.push_back(mouve); //on ajoute le mouv aux possibles
					}

				}

			}
		}
	}

}

void DeplacementJoueur()
{
	mouv mouve;
	string reponse;
	bool ok = 0;
	while (!ok)
	{
		cout << "quel pion voulez vous deplacer ?" << endl;
		cin >> reponse;
		cout << reponse[0] << " " << reponse[1] << endl;
		mouve.from.x = reponse[1];
		switch (reponse[0])
		{
		case 'a':
			mouve.from.y = 0;
			break;
		case 'B':
			mouve.from.y = 1;
			break;
		case 'C':
			mouve.from.y = 2;
			break;
		case 'D':
			mouve.from.y = 3;
			break;
		case 'E':
			mouve.from.y = 4;
			break;
		case 'F':
			mouve.from.y = 5;
			break;
		case 'G':
			mouve.from.y = 6;
			break;
		case 'H':
			mouve.from.y = 7;
			break;
		case 'I':
			mouve.from.y = 8;
			break;
		case 'J':
			mouve.from.y = 9;
			break;
		default:
			cout << "prob lettre" << endl;
		}
		cout << "regardons en " << mouve.from.x << " " << mouve.from.y << endl;
		if (tab[mouve.from.x][mouve.from.y] == 'B')
			ok = 1;
	}
	while (!ok)
	{
		cout << "Ou voulez vous allez ?" << endl;
		cin >> reponse;
		mouve.to.x = reponse[1];
		switch (reponse[0])
		{
		case 'A':
			mouve.to.y = 0;
			break;
		case 'B':
			mouve.to.y = 1;
			break;
		case 'C':
			mouve.to.y = 2;
			break;
		case 'D':
			mouve.to.y = 3;
			break;
		case 'E':
			mouve.to.y = 4;
			break;
		case 'F':
			mouve.to.y = 5;
			break;
		case 'G':
			mouve.to.y = 6;
			break;
		case 'H':
			mouve.to.y = 7;
			break;
		case 'I':
			mouve.to.y = 8;
			break;
		case 'J':
			mouve.to.y = 9;
			break;
		default:
			ok = 0;
		}
		if (mouve.to.x == mouve.from.x + 1)
			if (mouve.to.y == mouve.from.y + 1 || mouve.to.y == mouve.from.y - 1)
				ok = 1;
	}
	cout << "le pion en " << mouve.from.x << " " << mouve.from.y << " va en " << mouve.to.x << " " << mouve.to.y << endl;
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
		tab[0][2 * i] = 'B';
		tab[1][2 * i + 1] = 'B';
		tab[2][2 * i] = 'B';
		tab[3][2 * i + 1] = 'B';
	}
	//mettre les pions noirs
	for (int i = 0; i < 5; i++)
	{
		tab[6][2 * i] = 'N';
		tab[7][2 * i + 1] = 'N';
		tab[8][2 * i] = 'N';
		tab[9][2 * i + 1] = 'N';
	}

	//on test
	Ecrire_tab();

	//boucle de jeu
	while (!partie_finie)
	{
		DeplacementJoueur();
		Ecrire_tab();

	}

	getchar();

	return 0;
}

