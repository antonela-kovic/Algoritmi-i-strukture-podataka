#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct _polinom;
typedef struct _polinom* Position;

struct _polinom
{
	int Koeficijent;
	int Exponent;
	Position Next;
};
typedef struct _polinom polinom;

void ReadPolynom(Position);
void PrintPolynom(Position);
void SumPolynom(Position, Position, Position);
void MulPolynom(Position, Position, Position);


int main() {
	polinom P, Q, S, M;
	P.Next = NULL;
	Q.Next = NULL;
	S.Next = NULL;
	M.Next = NULL;

	ReadPolynom(&P);
	ReadPolynom(&Q);
	printf("\n");

	printf("\nP(x) = ");
	PrintPolynom(P.Next);
	printf("\nQ(x) = ");
	PrintPolynom(Q.Next);

	printf("\n");
	SumPolynom(P.Next, Q.Next, &S);
	printf("\nS(x) = P(x) + Q(x) = ");
	PrintPolynom(S.Next);

	printf("\n");
	MulPolynom(P.Next, Q.Next, &M);
	printf("\nM(x) = P(x) * Q(x) = ");
	PrintPolynom(M.Next);
	printf("\n");
	printf("\n");

	return 0;
}

void ReadPolynom(Position P)
{
	char ime_dat[20];
	FILE* f = NULL;
	Position q, i;

	printf("Unesite ime datoteke za citanje polinoma : ");
	scanf(" %s", ime_dat);

	f=fopen(ime_dat, "r");
	if (f == NULL)
		printf("\nGreska!Datoteka %s nije otvorena.", ime_dat);
	else
	{
		while (!feof(f))
		{
			q = (Position)malloc(sizeof(polinom));
			fscanf_s(f, " %d %d", &q->Koeficijent, &q->Exponent);

			if (q->Koeficijent == 0)
				free(q);
			else
			{
				i = P;

				while (i->Next != NULL && i->Next->Exponent > q->Exponent)
					i = i->Next;
				if (i->Next != NULL && i->Next->Exponent == q->Exponent)
				{
					i->Next->Koeficijent += q->Koeficijent;
					free(q);
					if (i->Next->Koeficijent == 0)
					{
						q = i->Next;
						i->Next = q->Next;
						free(q);
					}
				}
				else
				{
					q->Next = i->Next;
					i->Next = q;
				}
			}
		}
		fclose(f);
	}
}

void PrintPolynom(Position P)
{
	while (P != NULL)
	{
		if (P->Koeficijent == 1 && P->Exponent == 0)
			printf("1");
		else if (P->Koeficijent == -1 && P->Exponent == 0)
			printf("- 1");
		else if (P->Koeficijent == 1 && P->Exponent > 0)
			printf("x^%d", P->Exponent);
		else if (P->Koeficijent == 1 && P->Exponent < 0)
			printf("x^(%d)", P->Exponent);
		else if (P->Koeficijent > 0 && P->Koeficijent != 1 && P->Exponent > 0)
		    printf("%dx^%d", P->Koeficijent, P->Exponent);
		else if (P->Koeficijent < 0 && P->Koeficijent != -1 && P->Exponent > 0)
		     printf("-%dx^%d", (-1) * P->Koeficijent, P->Exponent);
		else if (P->Koeficijent > 0 && P->Koeficijent != 1 && P->Exponent < 0)
		     printf("%dx^(%d)", P->Koeficijent, P->Exponent);
		else if (P->Koeficijent < 0 && P->Koeficijent != -1 && P->Exponent < 0)
		     printf("-%dx^(%d)", (-1) * P->Koeficijent, P->Exponent);
		else if (P->Koeficijent == 1 && P->Exponent == 0)
			printf(" + 1");
		else if (P->Koeficijent == -1 && P->Exponent == 0)
			printf(" - 1");
		else if (P->Koeficijent == 1 && P->Exponent > 0)
			printf(" + x^%d", P->Exponent);
		else if (P->Koeficijent == 1 && P->Exponent < 0)
			printf(" + x^(%d)", P->Exponent);
		else if (P->Koeficijent > 0 && P->Exponent > 0)
			printf(" + %dx^%d", P->Koeficijent, P->Exponent);
		else if (P->Koeficijent < 0 && P->Exponent > 0)
			printf(" - %dx^%d", (-1) * P->Koeficijent, P->Exponent);
		else if (P->Koeficijent > 0 && P->Exponent < 0)
			printf(" + %dx^(%d)", P->Koeficijent, P->Exponent);
		else if (P->Koeficijent < 0 && P->Exponent < 0)
			printf(" - %dx^(%d)", (-1) * P->Koeficijent, P->Exponent);
		

		P = P->Next;
	}
	printf("\n");
}

void SumPolynom(Position P, Position Q, Position S)
{
	Position q, i;
	while (P != NULL && Q != NULL)
	{
		q = (Position)malloc(sizeof(polinom));

		if (P->Exponent > Q->Exponent)
		{
			q->Exponent = P->Exponent;
			q->Koeficijent = P->Koeficijent;

			P = P->Next;
		}
		else if (P->Exponent < Q->Exponent)
		{
			q->Exponent = Q->Exponent;
			q->Koeficijent = Q->Koeficijent;

			Q = Q->Next;
		}
		else
		{
			q->Exponent = P->Exponent;
			q->Koeficijent = P->Koeficijent + Q->Koeficijent;

			P = P->Next;
			Q = Q->Next;
		}

		q->Next = S->Next;
		S->Next = q;
		S = S->Next;
	}

	if (P == NULL)
		i = Q;
	else
		i = P;

	while (i != NULL)
	{
		q = (Position)malloc(sizeof(polinom));

		q->Exponent = i->Exponent;
		q->Koeficijent = i->Koeficijent;

		i = i->Next;

		q->Next = S->Next;
		S->Next = q;
		S = S->Next;
	}
}

void MulPolynom(Position P, Position Q, Position M)
{
	Position q, i, j, tmp;

	i = P;
	while (i != NULL)
	{
		j = Q;
		while (j != NULL)
		{
			q = (Position)malloc(sizeof(polinom));

			q->Exponent = i->Exponent + j->Exponent;
			q->Koeficijent = i->Koeficijent * j->Koeficijent;

			tmp = M;

			while (tmp->Next != NULL && tmp->Next->Exponent > q->Exponent)
				tmp = tmp->Next;

			if (tmp->Next != NULL && tmp->Next->Exponent == q->Exponent)
			{
				tmp->Next->Koeficijent += q->Koeficijent;
				free(q);
			}
			else
			{
				q->Next = tmp->Next;
				tmp->Next = q;
			}
			j = j->Next;
		}
		i = i->Next;
	}
}