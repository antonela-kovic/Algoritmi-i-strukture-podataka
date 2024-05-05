#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct studenti {
	char ime[20];
	char prezime[20];
	int bodovi;
};
typedef struct studenti Studenti;
int countData(char*);
int readData(char*, Studenti*, int);
void printData(Studenti*, int,int);
int maxBroj(char*, Studenti*);

int main() {
	char filename[20] = "/0";
	int countLines = 0; //za brojanje redaka
	int studentiCount = 0; //za izcitavanje studenata iz datoteke
	Studenti * pstudenti = NULL; //pokazivac tipa strukture za alokaciju memeorije
	int maxBodovi= 0;

	printf("Unesite ime datoteke: ");
	scanf(" %s", filename);

	//brojanje redaka
	countLines = countData(filename);
	if (countLines == 0) {
		printf("Datoteka je prazna ili se ne moze otvoriti");
		return 0;
	}

	//alokacija memorije
	pstudenti = (Studenti*)malloc(sizeof(Studenti) * countLines);
	if (pstudenti == NULL) {
		printf("Greska");
		return 0;
	}

	//izcitavanje(citanje) iz datoteke
	studentiCount = readData(filename, pstudenti, countLines);
	if (studentiCount != 0) {
		printf("Greska");
		free(pstudenti);
		return 0;

	}
	maxBodovi = maxBroj(filename, pstudenti);
	//ispis na konzolu
	printData(pstudenti, countLines,maxBodovi);

	free(pstudenti);
	

	return 0;
}
int countData(char* filename) {
	FILE* fp = NULL;
	char buffer[512] = "\0";
	int counter = 0;

	fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("Datoteka nije otvorena");
		return -1;
	}
	while (!feof(fp)) {
		strcpy(buffer, "\0"); //praznis buffer tj postavljas ga na prazan string
		fgets(buffer, 511, fp);
		if (strlen(buffer) > 0) { //stavljamo >0 jer ako je uvijet zadovoljen nesto ima u redku jer citamo redak po redak
			counter++;
		}
	}
	fclose(fp);
	return counter;
}
int readData(char* filename, Studenti* pstudenti, int countLines) {
	FILE* fp = NULL;
	int i = 0;

	fp = fopen(filename, "r");
	if (fp == NULL) {
		//printf("Greska");
		return -1;
	}

	for (i = 0; i < countLines; i++) {
		fscanf(fp, " %s %s %d ", pstudenti[i].ime, pstudenti[i].prezime, &pstudenti[i].bodovi);

	}

	fclose(fp);
	return 0;
}

void printData(Studenti* pstudenti, int countLines, int max) {
	int i = 0;
	float relativniBodovi = 0.0;

	for (i = 0; i < countLines; i++)
	{
		relativniBodovi = (((float)pstudenti[i].bodovi / max) * 100);
		printf("\nIme: %s Prezime: %s Bodovi(apsoluni): %d Bodovi(relativni): %f", pstudenti[i].ime, pstudenti[i].prezime, pstudenti[i].bodovi, relativniBodovi);

	}
}




int maxBroj(char* filename, Studenti* pstudent) {
	FILE* fp = NULL;
	int n = 0;
	fp = fopen(filename, "r");
	if (fp == NULL)
		return -1;

	while (!feof(fp))
	{
		fscanf(fp, " %s %s %d", pstudent->ime, pstudent->prezime, &pstudent->bodovi);
		if (pstudent->bodovi > n)
			n = pstudent->bodovi;
		pstudent++;
	}

	return n;


}
