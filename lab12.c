#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

struct _osoba;
typedef struct _osoba* position;
struct _osoba
{
	char ime[20];
	char prezime[20];
	int godina;
	position next;

};
typedef struct _osoba osoba;
void insertFront(position);
void insertBack(position);
position findElement(position);
void printList(position);
void deleteElement(position);

int main()
{
	int broj = 0;
	osoba head;
	head.next = NULL;
	printf("izaberite jednu od mogucnosti \n");
	printf("1. dodavanje elementa na pocetak liste\n");
	printf("2. dodavanje elementa na kraj liste\n");
	printf("3. pronalazak elementa liste\n");
	printf("4. ispis liste\n");
	printf("5. brisanje elementa liste\n");
	printf("6. izlaz\n");

	scanf("%d", &broj);

	switch (broj)
	{
	case 1:
		insertFront(&head);
		break;
	case 2:
		insertBack(&head);
		break;
	case 3:
		findElement(head.next);
		break;
	case 4:
		printList(head.next);
		break;
	case 5:
		deleteElement(&head);
		break;
	case 6:
		break;
	default:
		printf("Krivi unos");
		break;
	}

	return 0;
}

void insertFront(position head) {
	position q;
	q = (position)malloc(sizeof(osoba));
	if (q == NULL) {
		printf("Greska\n");
	}
	else {
		printf("Unesite ime, prezime i godinu rodenja studenta :\n");
		scanf_s(" %s %s %d", q->ime, 20, q->prezime, 20, &q->godina);
		q->next = NULL;
		q->next = head->next;
		head->next = q;
	}

}
void insertBack(position previous) {
	position q;
	q = (position)malloc(sizeof(osoba));
	if (q == NULL) {
		printf("Greska");
	}
	while (previous->next != NULL) {
		previous = previous->next;
		//q->next = previous->next;
		previous->next = q;

	}

}

position findElement(position p) {
	char prezime[20] = { 0 };
	printf("Unesite trazeno/zeljeno prezime");
	scanf("%s", prezime);

	while (p != NULL && _strcmpi(p->prezime, prezime) != 0) {
		p = p->next;
	}
	if (p == NULL) {
		printf("Nije pronadeno\n");
	}
	else {
		printf("Pronadeno");
	}
	return p;
}
void printList(position p) {
	while (p != NULL) {
		printf("%s %s %d", p->ime, p->prezime, &p->godina);
		p = p->next;
	}
}
void deleteElement(position p) {
	position tmp;
	char prez[20];

	printf("\nUnesite prezime koje zelite izbrisati : ");
	scanf(" %s", prez);
	while (p->next != NULL && _strcmpi(p->next->prezime, prez) != 0) {
		p = p->next;
	}
	tmp = p->next;
	if (tmp != NULL)
	{
		p->next = tmp->next;
		printf("\nIz liste se brise : %s %s %d", tmp->ime, tmp->prezime, tmp->godina);
		free(tmp);
	}


}