//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<ctype.h>
//void Task1();
//void Task2();
//void Task3();
//void Task4();
//void calcMathResults(int, int, int*, int*, float*);
//int getData(int, int);
//void unos(struct datum);
//void danPrije(struct datum, struct datum);
//void danPoslije(struct datum, struct datum);
//void getString(char*);
//void getSubString(char*);
//int countSubstrOccurrences(char*, char[]);
//
//int main() {
//	//Task1();
//	//Task2();
//	//Task3();
//	Task4();
// return 0;
//}
//
//int getData(int* px, int* py) {
//	printf("Unesite dva broja.\n");
//	scanf("%d%d", px, py);
//	return 0;
//}
//
//void calcMathResults(int x, int y, int* psum, int* pprod, float* pdef)
//{
//
//	*psum = x + y;
//	*pprod = x * y;
//	*pdef = (float)x - y;
//	
//}
//
//struct datum
//{
//	int dan, mjesec, godina;
//};
//
//
//
//
//
//void unos(struct datum* pdan)
//{
//
//	printf("Unesite dan, mjesec i godinu. (DD MM YYYY)\n");
//	scanf("%d%d%d", &(*pdan).dan, &pdan->mjesec, &pdan->godina);
//
//}
//
//void danPrije(struct datum* date, struct datum* dBefore)
//{
//	if (date->dan > 1 && date->dan <= 31)
//		dBefore->dan--;
//	if (date->dan == 1)
//	{
//		dBefore->dan = 31;
//		if (date->mjesec == 1)
//		{
//			dBefore->mjesec = 12;
//			dBefore->godina--;
//		}
//		else
//			dBefore->mjesec--;
//	}
//}
//
//void danPoslije(struct datum* date, struct datum* dAfter)
//{
//	if (date->dan >= 1 && date->dan < 31)
//		dAfter->dan += 2;
//	if (date->dan == 31)
//	{
//		dAfter->dan = 1;
//		if (date->mjesec == 12)
//		{
//			dAfter->mjesec = 1;
//			dAfter->godina++;
//		}
//		else
//			dAfter->mjesec+= 2;
//	}
//}
//
//
//void Task1() {
//
//	int brojevi[10], * p_br = brojevi;
//	char znakovi[10], * p_zn = znakovi;
//	int i;
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("Unesite %d. element niza brojeva.\t", i + 1);
//		scanf("%d", p_br);
//		p_br++;
//	}
//
//	printf("\n\n");
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("Unesite %d. element niza znakova.\t", i + 1);
//		scanf(" %c", p_zn);
//		p_zn++;
//	}
//
//	p_br = brojevi;
//	p_zn = znakovi;
//
//	printf("\nNiz brojeva:\n");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *p_br);
//		p_br++;
//	}
//
//	printf("\nNiz znakova:\n");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%c ", *p_zn);
//		p_zn++;
//	}
//}
//void Task2() {
//	int x = 0;
//	int y = 0;
//	int sum = 0;
//	int prod = 0;
//	float def = 0;
//
//
//	getData(&x, &y);
//	calcMathResults(x, y, &sum, &prod, &def);
//	printf("Produkt: %d\nSuma: %d\nRazlika: %f\n", prod, sum, def);
//
//
//}
//void Task3() {
//	struct datum date1, dateBefore, dateAfter;
//	struct datum* p_date1 = &date1, * p_dateBefore = &dateBefore, * p_dateAfter = &dateAfter;
//	unos(p_date1);
//
//	p_dateBefore = p_date1;
//	p_dateAfter = p_date1;
//
//	danPrije(p_date1, p_dateBefore);
//	printf("Dan prije: %d. %d. %d.\n", p_dateBefore->dan, p_dateBefore->mjesec, p_dateBefore->godina);
//
//	danPoslije(p_date1, p_dateAfter);
//	printf("Dan poslije: %d. %d. %d.\n", p_dateAfter->dan, p_dateAfter->mjesec, p_dateAfter->godina);
//}
//
//void Task4() {
//	char str[50] = "\0";
//	char sub_str[30] = "\0";
//
//	getString(&str);
//	getSubString(&sub_str);
//
//	printf("Pod string %s se u stringu %s nalazi %d puta.\n",
//		str, sub_str, countSubstrOccurrences(&str, sub_str));
//}
//
//void getString(char* str) {
//	printf("Unesi string:  ");
//	scanf(" %s", str);
//}
//
//void getSubString(char* sub_str) {
//	printf("Unesi pod string:  ");
//	scanf(" %s", sub_str);
//}
//
//int countSubstrOccurrences(char* str, char sub_str[]) {
//	int n = 0, n_sub = 0;
//	n_sub = strlen(sub_str);
//
//	while (*str != '\0') {
//		if (strncmp(str, sub_str, n_sub) == 0) {
//			n++;
//			str += n_sub;
//		}
//		else
//			str++;
//	}
//	return n;
//}