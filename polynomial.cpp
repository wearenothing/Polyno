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
//零多项式
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
				tag = true;
			else
				cout <<" ";
			cout<< t->coef << " " << t->expon;
			t = t->next;
		}
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
	Poly P = AddPoly(P1, P2);
	PrintPoly(P);
	return 0;
}
