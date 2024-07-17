#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wc.h"

int main(int argc,char *argv[])
{
	FILE *f=NULL;
	char chaine[1000];
	boucle(argc,argv,chaine,f);
	return 0;
}

