#include<cstdlib>
#include<iostream>
using namespace std;
typedef struct PNode* Poly;
struct PNode
{
	int coef;
	int expon;
	struct PNode* next;
};

void Attach(int coef, int expon, Poly* rear)
{
	Poly S = (Poly)malloc(sizeof(struct PNode));
	S->coef = coef;
	S->expon = expon;
	S->next = NULL;
	(*rear)->next = S;
	*rear = S;
}

Poly AddPoly(Poly P1, Poly P2)
{
	Poly front, rear;
	rear = (Poly)malloc(sizeof(struct PNode));
	rear->next = NULL;
	front = rear;
	if (P1->coef == 0 && P1->expon == 0)
		return P2;
	else if (P2->coef == 0 && P2->expon == 0)
		return P1;
	while (P1&&P2)
	{
		if (P1->expon == P2->expon)
		{
			int sum = P1->coef + P2->coef;
			if (sum)
			Attach(sum, P1->expon, &rear);
			P1 = P1->next;
			P2 = P2->next;
		}
		else if (P1->expon > P2->expon)
		{
			Attach(P1->coef, P1->expon, &rear);
			P1 = P1->next;
		}
		else
		{
			Attach(P2->coef, P2->expon, &rear);
			P2 = P2->next;
		}
	}
	if (P1)
	{
		rear->next = P1;
	}
	else
	{
		rear->next = P2;
	}
	Poly t = front;
	front = t->next;
	free(t);
	return front;
}
Poly MultPoly(Poly P1, Poly P2)
{
    if(!P1||!P2)
    return NULL;
	Poly P = (Poly)malloc(sizeof(struct PNode));
	P->next = NULL;
	
	bool tag = false;
	Poly t1 = P1;
	while (t1)
	{
		Poly Pt = (Poly)malloc(sizeof(struct PNode));
		Pt->next = NULL;
		Poly rear = Pt;
		Poly t2 = P2;
		while (t2)
		{
			Attach(t1->coef*t2->coef, t1->expon + t2->expon, &rear);
			t2 = t2->next;
		}
		Poly t = Pt;
		Pt = Pt->next;
		free(t);
		if(tag)
			P = AddPoly(P, Pt);
		else
		{
			P = Pt;
			tag = true;
		}
		t1 = t1->next;
	}
	return P;
}
void PrintPoly(Poly P)
{
	//int count = 0;
	bool tag = false;
	if (P)
	{
		Poly t = P;
		while (t)
		{
			if (!tag)
			{
				cout << t->coef << " " << t->expon;
				tag = true;
			}
			else
				cout <<" "<< t->coef << " " << t->expon;
			t = t->next;
		}
		cout << endl;
	}
	else
		cout << "0 0" << endl;
}

int main()
{
	int n1,n2;
	cin >> n1;
	Poly P1 = (Poly)malloc(sizeof(struct PNode));
	P1->next = NULL;
	Poly rear1 = P1; 
	for (int i = 0; i < n1; i++)
	{
		int coef, expon;
		cin >> coef >> expon;
		Attach(coef, expon, &rear1);
	}

	cin >> n2;
	Poly P2= (Poly)malloc(sizeof(struct PNode));
	P2->next = NULL;
	Poly rear2 = P2;
	for (int i = 0; i < n2; i++)
	{
		int coef, expon;
		cin >> coef >> expon;
		Attach(coef, expon, &rear2);
	}
	P1 = P1->next;
	P2 = P2->next;
	if (!P1)
	{
		cout << "0 0" << endl;
		PrintPoly(P2);
	}
	else if (!P2)
	{
		cout << "0 0" << endl;
		PrintPoly(P1);
	}
	else
	{
		Poly P = AddPoly(P1, P2);
		Poly PP = MultPoly(P1, P2);
		PrintPoly(PP);
		PrintPoly(P);
	}
	return 0;
}
