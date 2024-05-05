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
position findPrev(position);
void insertAfter(position);
void insertBefore(position);
void sortList(position);
void printDatafromList(position);
void readDatafromList(position);
void Insert(position);

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
	printf("6. dodavanje novog elemementa iza oderedenog elementa\n");
	printf("7. dodavanje novog elementa ispred odredenog elementa\n");
	printf("8. sortiranje liste po prezimenu\n");
	printf("9. Upis liste u datoteku\n");
	printf("10. Citanje liste iz datoteke\n");
	printf("-1. izlaz\n");

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
		insertAfter(&head);
		break;
	case 7:
		insertBefore(&head);
		break;
	case 8:
		sort(&head);
		break;
	case 9:
		printDatafromList(head.next);
		break;
	case 10:
		readDatafromList(&head)
		break;
	case -1:
		break;
	default:
		printf("krivi unos");
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
//gore povic je 2 vjezba i radi sve 
//ovo dole 3 vjezba
position findPrev(position p,char* temp) {
	position previous = p;
	/*char temp[20] = { 0 };
	printf("Unesite zeljeno prezime\n");
	scanf("%s", temp);*/
	p=p->next;
	while (_strcmpi(p->prezime,temp) != NULL && p != NULL) {
		previous = p;
		p = p->next;
		if (p == NULL) {
			return 0;
		}
		else
			return previous;
	}
}
void Insert(position p){
	position q;

	q = (position)malloc(sizeof(osoba));
	if (q == NULL)
		printf("\r\nGRESKA!\r\nAlokacija memorije neuspjela.\r\n");
	else
	{
		printf("Unesite ime, prezime i godinu rodenja studenta :\r\n");
		scanf_s(" %s %s %d", q->ime, 20, q->prezime, 20 ,&q->godina_rodenja);

		q->Next = p->Next;
		p->Next = q;
	}
}
void insertAfter(position p) {
	char temp[20] = { 0 };
	printf("Unesite zeljeno prezime\n");
	scanf("%s", temp);
	p = findPrev(p, temp);
	if (p->prezime == NULL) {
		printf("Element nije pronaden\n");
		return -1;
	}
	p = p->next;
	return Insert(p);
	//2.nacin bez f-je insert
	/*if (p != NULL) {
		q = (position)malloc(sizeof(osoba));
		q->prezime = temp;
		q->next = p->next;
		p->next = q;
	}*/
	//return 0;
}
void insertBefore(position p) {
	//position q;
	char temp[20] = { 0 };
	printf("Unesite zeljeno prezime\n");
	scanf("%s", temp);
	p = findPrev(p, temp);
	if (p->next == NULL) {
	return -1
    }
	Insert(p);
	//2.nacin bez funcje insert
	/*if (p != NULL) {
		q = (position)malloc(sizeof(osoba));
		q->prezime = temp;
		q->next = p->next;
		p->next = q;
	}
	return 0;*/
}
void sortList(position p) {
	position end = NULL, i, j, prev_j, tmp;

	while (p->next != end)
	{
		i = P;
		prev_j = i->next;
		j = prev_j->next;

		while (j != end)
		{
			if (_strcmpi(prev_j->prezime, j->prezime) < 0)
			{
				prev_j->next = j->next;
				i->next = j;
				j->next = prev_j;
			}
			else
				i = prev_j;
			prev_j = j;
			j = j->next;
		}
		end = prev_j;
	}
}
void printDatafromList(position p) {
	FILE* f = NULL;
	char filename[20] = { 0 };
	printf("Unesite ime datoteke\n");
	scanf("%s", filename);
	f = fopen(filename, "w");
	if (f == NULL) {
		printf("Greska,datoteka nije otvorena\n");
	}
    while (p != NULL) {
		
		fprintf(filename, "%s %s %d\r\n", p->ime, p->prezime, p->godina);
		p = p->next;
	
	}
	fclose(f);
	
}
void readDatafromList(position p) {

	FILE* f=NULL;
	char filename[20] = {0};
	position q;

	printf("Unesite ime datoteke\n");
	scanf(" %s",filename);

	f=fopen(filename, "r");
	
	if (f == NULL)
		printf("Greska, datoteka nije otvorena\n");

	while (!feof(f)) {
		q = (position)malloc(sizeof(osoba));
			if (q == NULL)
				printf("\r\nGRESKA!\r\nAlokacija memorije neuspjela.\r\n");
			else
			{
				fscanf_s(f, " %s %s %d", q->ime, 20, q->prezime, 20, &q->godina_rodenja);

				q->Next = p->Next;
				p->Next = q;
			}
	}
	fclose(f);
	
}
