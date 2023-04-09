#ifdef __unix__
	#define CLS "clear"
#elif defined(_WIN32) || defined(WIN32)
	#define CLS "cls"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIGNE 4
#define COLONNE 4

void affichetab(char tab[LIGNE][COLONNE])
{
	for(int i=0; i<LIGNE; i++)
	{
		for(int j= 0; j<COLONNE; j++)
		{
			printf("[%c]",tab[i][j]);
		}
		printf("\n");
	}
}
void filltab(char tab[LIGNE][COLONNE])
{
	if(tab)
	tab[rand()%4][rand()%4]='2';
}
void move(char tab[LIGNE][COLONNE],int key)
{
	int j=0;
	if(key=='8')
		tab[0][j]='2';
	else if(key=='2')
		tab[3][j]='2';
	else if(key=='4')
		tab[1][0]='2';
	else if(key=='6')
		tab[1][3]='2';
}
int main(int argc, char **argv)
{
	srand(time(NULL));
	char tab[LIGNE][COLONNE];
	char key;

	for(int i=0; i<LIGNE; i++)
		for(int j= 0; j<COLONNE; j++)
			{tab[i][j]=' ';}
	affichetab(tab);
	printf("\n\n\n");
	filltab(tab);
	affichetab(tab);
	printf("Commandes 8 haut 2 bas 4 gauche 6 droite:");
	scanf("%c",&key);
	printf("\n\n\n");
	move(tab,key);	
	affichetab(tab);
	return 0;
}
