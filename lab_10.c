#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NAME_LEN 50

//1. Napisati program u kojem korisnik unosi 2 proizvolna vremena (sat, minute i
//sekunde).Program treba zbrojiti unesena vremena te ispisati rezultat u konzolu.
//Za pohranu vremena koristiti strukturu struct Time, a zbrajanje i ispis
//implementirati u odvojenim funkcijama.
//Napomena : rezultat ne smije imati više od 60 sekundi i / ili više od 60 minuta.


//definirana struktura za vrijeme
typedef struct _Time {
	int h;
	int m;
	int s;
} Time;

//deklaracija funkcija
Time getTime();
Time addTimes(Time, Time);
void printTime(Time);

//int main() {
// Time t1;
// Time t2;
//
// Time total;
//
// //inicijalizacija
// t1.h = t1.m = t1.s = 0;
// t2.h = t2.m = t2.s = 0;
// total.h = total.m = total.s = 0;
//
// //dohvacamo vrijeme sa konzole funkcijom
// t1 = getTime();
// t2 = getTime();
//
// total = addTimes(t1, t2);
//
// //funcija za ispis sume
// printTime(total);
//
// return 0;
//}


//definicija fukncija

Time getTime() {
	Time t;
	t.h = t.m = t.s = 0;

	//prvjera je li korisnik unio ispravna vremena

	do {
		printf("unesi vrijeme ( <h> <m> <s> )\n");
		scanf(" %d %d %d", &t.h, &t.m, &t.s);


		if (t.h < 0) {
			printf("krivi unos sati \n");
			continue;
		}
		if (t.m < 0 || t.m > 60) {
			printf("krivi unos minuta \n");
			continue;
		}
		if (t.s < 0 || t.s > 60) {
			printf("krivi unos sekundi \n");
			continue;
		}

		break;

	} while (1);
	return t;
}

//funkcdija za sumiranje vremena
Time addTimes(Time t1, Time t2) {
	Time total;
	total.h = total.m = total.s = 0;
	total.s = t1.s + t2.s;
	while (total.s > 60) {
		total.s -= 60;
		total.m++;
	}

	total.m += t1.m + t2.m;
	while (total.m > 60) {
		total.m -= 60;
		total.h++;
	}

	total.h += t1.h + t2.h;

	return total;
}


void printTime(Time t) {
	printf("vrijeme je %d %d %d \n", t.h, t.m, t.s);
}



//2.Napisati program u kojem korisnik unosi datum (dan, mjesec godina). Program treba
//izraèunati dan prije i dan poslije unesenog te ih ispisati u konzolu.
//Za pohranu datuma treba koristiti strukturu struct Date.
//Proraèun dana prije i poslije treba implementirati u funkcijama
//calculateDateBefore() i calculateDateAfter(), a ispis dana prije i poslije treba
//implementirati u funkciji printDateBeforeAndAfter().

//definiranje strukture datum
typedef struct _Date {
	int y;
	int m;
	int d;
} Date;

Date getDate();
Date calculateDateBefore(Date);
Date calculateDateAfter(Date);
void printDateBeforeAndAfter(Date, Date, Date);
int getMaxDayForMonthAndYear(int, int);
int isLeapYeaar(int);

//int main() {
// Date today;
// Date yesterday;
// Date tomorrow;
//
// //inicijalizacija
// today.y = today.m = today.d = 0;
// yesterday.y = yesterday.m = yesterday.d = 0;
// tomorrow.y = tomorrow.m = tomorrow.d = 0;
//
// //funckije
// today = getDate();
// yesterday = calculateDateBefore(today);
// tomorrow = calculateDateAfter(today);
//
//
// //funcija za ipis datuma
// printDateBeforeAndAfter(yesterday, today, tomorrow);
//
// return 0;
//}

//definicija funkcija
Date getDate() {
	Date d;
	d.y = d.m = d.d = 0;
	do {
		printf("unesi datum (<dan>.<mjesec>.<godina>)\n");
		scanf(" %d.%d.%d", &d.d, &d.m, &d.y);

		if (d.m < 0 || d.m > 12) {
			printf("unos krivog mjeseca \n");
			continue;
		}

		if (d.d < 1 || d.d > getMaxDayForMonthAndYear(d.m, d.y)) {
			printf("unos krivog dana \n");
			continue;
		}
		break;

	} while (1);
	return d;
}

Date calculateDateBefore(Date today) {
	Date yesterday;
	yesterday.y = today.y;
	yesterday.m = today.m;
	yesterday.d = today.d - 1;

	if (yesterday.d == 0) {
		yesterday.m--;
		yesterday.d = getMaxDayForMonthAndYear(yesterday.m, yesterday.y);

	}
	if (yesterday.m == 0) {
		yesterday.y--;
		yesterday.m = 12;
	}
	return yesterday;
}


Date calculateDateAfter(Date today) {
	Date tomorrow;

	tomorrow.y = today.y;
	tomorrow.m = today.m;
	tomorrow.d = today.d + 1;

	if (tomorrow.d > getMaxDayForMonthAndYear(tomorrow.m, tomorrow.y)) {
		tomorrow.d = 1;
		tomorrow.m++;

	}
	if (tomorrow.m > 12) {
		tomorrow.m = 1;
		tomorrow.y++;
	}
	return tomorrow;
}



void printDateBeforeAndAfter(Date yesterday, Date today, Date tomorrow) {
	printf("datum prije: %d.%d.%d \n", yesterday.d, yesterday.m, yesterday.y);
	printf("datum sad: %d.%d.%d \n", today.d, today.m, today.y);
	printf("datum poslije: %d.%d.%d \n", tomorrow.d, tomorrow.m, tomorrow.y);
}


int getMaxDayForMonthAndYear(int m, int y) {
	switch (m) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;

	case 4:
	case 6:
	case 9:
	case 11:

		return 30;

	case 2:

		if (isLeapYeaar(y) == 1) {
			return 29;
		}
		else {
			return 28;
		}

	default:
		return -1;
	}
}

//za racunanje prijestupne godine
int isLeapYeaar(int y) {
	if (y % 400 == 0) {
		return 1;
	}
	if (y % 100 == 0) {
		return 0;
	}
	if (y % 4 == 0) {
		return 1;
	}
	return 0;
}



//3.Napisati program u kojem korisnik unosi podatke o 5 osoba (ime, prezime, datum i
//vrijeme roðenja).Program treba pronaæi i ispisati podatke o najstarijoj osobi te osobi
//prvoj po abecedi.
//Za pohranu podataka treba koristiti 3 strukture: struct Person, struct Date i
//struct Time.
// Unos podataka treba implementirati u funkciji getPeopleData(), a pronalazak i ispis
// najstarije osobe i osobne prve po abecedi treba implementirati u funkciji
// findAndPrintOldestPerson() i findAndPrintAlphaFirstPerson().

typedef struct _Person {
	char firstName[NAME_LEN];
	char lastName[NAME_LEN];

	Date dayOfBirth;
	Time timeOfBirth;

}Person;


void getPeopleData(Person[]);
Person findOldestPerson(Person[]);
Person findAlphaFirstPerson(Person[]);





int main() {
	Person people[5];

	Person oldest;
	Person alphaFirst;

	getPeopleData(people);

	oldest = findOldestPerson(people);
	alphaFirst = findAlphaFirstPerson(people);

	printf("Najstarija osoba je %s %s \n", oldest.firstName, oldest.lastName);
	printf("Prva osoba po abecedi je %s %s \n", alphaFirst.firstName, alphaFirst.lastName);

	return 0;
}

void getPeopleData(Person people[]) {
	int i = 0;

	for (i = 0; i < 5; i++) {
		printf("unesi podatke za osobu %d \n", i + 1);

		printf("Ime, prezime \n");
		scanf(" %s %s", people[i].firstName, people[i].lastName);

		printf("datum rodjenja \n");
		people[i].dayOfBirth = getDate();

		printf("vrijeme rodjenja \n");
		people[i].timeOfBirth = getTime();

	}
}



Person findOldestPerson(Person people[]) {
	int i = 0;
	int oldest = 0;

	for (i = 1; i < 5; i++) {
		if (people[i].dayOfBirth.y < people[oldest].dayOfBirth.y) {
			//pronaden po godini
			oldest = i;
		}
		else if (people[i].dayOfBirth.y == people[oldest].dayOfBirth.y) {
			//nije pronaden po godinama, trazi se po mjesecu
			if (people[i].dayOfBirth.m < people[oldest].dayOfBirth.m) {
				oldest = i;
			}
			else if (people[i].dayOfBirth.m == people[oldest].dayOfBirth.m) {
				//nije naden po mjesecu, trazi se dan
				if (people[i].dayOfBirth.d < people[oldest].dayOfBirth.d) {
					//naden po danu
					oldest = i;
				}
				else if (people[i].dayOfBirth.d == people[oldest].dayOfBirth.d) {
					//nije naden ni po danu, trazenje po satu
					if (people[i].timeOfBirth.h < people[oldest].timeOfBirth.h) {
						//trazenje po satu
						oldest = i;
					}
					else if (people[i].timeOfBirth.h == people[oldest].timeOfBirth.h) {
						//nije pronaden po satu, trazi se po minuti
						if (people[i].timeOfBirth.m < people[oldest].timeOfBirth.m) {
							//trazenje po minuti
							oldest = i;
						}
						else if (people[i].timeOfBirth.m == people[oldest].timeOfBirth.m) {
							//provejra po sekundama
							if (people[i].timeOfBirth.s < people[oldest].timeOfBirth.s) {
								//nadeno po sekundi
								oldest = i;
							}
						}
					}
				}
			}

		}
	}

	return people[oldest];
}




Person findAlphaFirstPerson(Person people[])
{
	int i = 0;
	int alphaFirst = 0;

	for (i = 1; i < 5; i++)
	{
		if (strcmp(people[i].lastName, people[alphaFirst].lastName) < 0)
		{
			//trazenje po prezimenu
			alphaFirst = i;
		}
		else if (strcmp(people[i].lastName, people[alphaFirst].lastName) == 0)
		{
			// ako su prezimena jednaka, trazenje po imenu
			if (strcmp(people[i].firstName, people[alphaFirst].firstName) < 0)
			{
				// trazenje po imenu
				alphaFirst = i;
			}
		}
	}
	return people[alphaFirst];
}