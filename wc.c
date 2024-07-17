#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wc.h"


void ouverture(FILE **f,char *fichier)
{		
	*f=fopen(fichier,"r");
	if(f==NULL)
		printf("impossible d'ouvrir le fichier\n");
}	
int ligne(FILE *f,char *chaine)
{	
	
	int l=0;
	while((fgets(chaine,100,f)) != NULL)
	{
		l++;
	}
	return l;			
}
int caractere(FILE *f)
{	
	char actuel;
	int c=0;
	while((actuel = fgetc(f)) != EOF)
	{
		c++;
	}	
	return c;
}

int mot(FILE *f,char *chaine)
{	
	int m=0;
	while(feof(f) != 1)
	{
		fscanf(f,"%s",chaine);
		m++;
	}
	return m-1;
}
int max(FILE *f, char *chaine)
{
	int max=0,l=ligne(f,chaine),i,j=0;
	int tab[l];
	rewind(f);
	while((fgets(chaine,100,f)) != NULL)
	{
		tab[j] = strlen(chaine);
		j++;
	}
	max=tab[0];
	for(i=0 ; i<l-1 ; i++)
	{
		if(max<tab[i])
			max=tab[i];
	}
	return max-1;
}
void option(FILE *f,char *fichier,char *option,char *chaine)
{	
	int l,c,o,m,maxi;
	///int i;
	if(strcmp(option,"-m") == 0)
	{	
		///for(i=2 ; i<argc ; i++)
		///{
		c=caractere(f);
		printf(" %d %s\n",c,fichier);
		
	}                                 
	else if(strcmp(option,"-l") == 0)
	{
		l=ligne(f,chaine);
		printf(" %d %s\n",l,fichier);
	}
	else if(strcmp(option,"-c") == 0)
	{
		o=caractere(f);
		printf(" %d %s\n",o,fichier);
	} 
	else if(strcmp(option,"-w") == 0)
	{	
		m=mot(f,chaine);
		printf(" %d %s\n",m,fichier);
	}  
	else if(strcmp(option,"-L") == 0)
	{	
		maxi=max(f,chaine);
		printf("%d %s\n",maxi,fichier);
	} 
}
void wcss(FILE *f,int argc,char* fichier,char *chaine)
{	
	int l,c ,m;
	l=ligne(f,chaine);
	rewind(f);
	c=caractere(f);
	rewind(f);
	m=mot(f,chaine);
	rewind(f);
	printf(" %d %d %d %s\n",l,m,c,fichier);
}

void boucle(int argc,char *argv[],char *chaine,FILE *f)
{	
	int i=0;
	if(argv[1][0]=='-')
	{	
		for( i=1 ; i<argc-1; i++)
		{
			ouverture(&f,argv[i+1]);
			option(f,argv[i+1],argv[1],chaine);
		}
	}
	else
	{
		for( i=1 ; i<argc; i++)
		{
			ouverture(&f,argv[i]);
			wcss(f,argc,argv[i],chaine);
		}
	}
	fclose(f);
}

