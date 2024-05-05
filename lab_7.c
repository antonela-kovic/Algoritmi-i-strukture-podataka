#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#define N 10

//
//4. Napisati program koji od korisnika traži unos 5 imena osoba i zapisuje ih u niz
//stringova.Zatim(redom) :
//	a.pronalazi indeks imena prvog po abecedi i ispisuje indeks i ime;
//b.pronalazi indeks imena zadnjeg po abecedi i ispisuje indeks i ime;
//c.sortira imena po abecedi i ispisuje ih.
//Rezultati ne smiju razlikovati velika i mala slova(tj.moraju biti case-insensitive)
int main() {
	char imena[5][20] = { 0 };
	int i = 0;
	int j = 0;
	char temp[20] = { 0 };
	int min = 0;
	int max = 0;

	for (i = 0; i < 5; i++) {
		printf("Unesiite ime %d. osobe\n", i + 1);
		gets(imena[i]);

	}
	//min = imena[0];
	for (i = 0; i < 5; i++) {
		if (_strcmpi(imena[i], imena[min]) < 0)
			min = i;
	}
	printf("Prvi po abecedi je %d\t %s\n", min, imena[min]);
	for (i = 0; i < 5; i++) {
		if (_strcmpi(imena[i], imena[max]) > 0)
			max = i;
	}
	printf("Zadnji po abecedi je %d\t %s\n", max, imena[max]);

	for (i = 0; i < 5; i++) {
		for (j = i + 1; j < 5; j++) {
			if (_strcmpi(imena[j], imena[i]) < 0) {
				strcpy(temp, imena[j]);
				strcpy(imena[j], imena[i]);
				strcpy(imena[i], temp);

			}

		}
	}
	for (i = 0; i < 5; i++) {
		printf("Sortirani niz je %s\n", imena[i]);

	}

	return 0;
}

