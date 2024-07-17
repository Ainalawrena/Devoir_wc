#ifndef WC_H
#define WC_H

void ouverture(FILE **f,char *fichier);
int ligne(FILE *f,char *chaine);
int caractere(FILE *f);
int mot(FILE *f,char *chaine);
int max(FILE *f, char *chaine);
void option(FILE *f,char *fichier,char *option,char *chaine);
void wcss(FILE *f,int argc,char* fichier,char *chaine);
void boucle(int argc,char *argv[],char *chaine,FILE *f);


#endif
