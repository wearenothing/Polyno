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

void Attach(int coef, int expon, Poly rear)
{
	Poly S = (Poly)malloc(sizeof(struct PNode));
	S->coef = coef;
	S->expon = expon;
	S->next = NULL;
	rear->next = S;
	rear = S;
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
			{
				Poly S= (Poly)malloc(sizeof(struct PNode));
				S->coef = sum;
				S->expon = P1->expon;
				S->next = NULL;
				rear->next = S;
				rear = S;
			}
			P1 = P1->next;
			P2 = P2->next;
		}
		else if (P1->expon > P2->expon)
		{
			Poly S = (Poly)malloc(sizeof(struct PNode));
			S->coef = P1->coef;
			S->expon = P1->expon;
			S->next = NULL;
			rear->next = S;
			rear = S;
			P1 = P1->next;
		}
		else
		{
			Poly S = (Poly)malloc(sizeof(struct PNode));
			S->coef = P2->coef;
			S->expon = P2->expon;
			S->next = NULL;
			rear->next = S;
			rear = S;
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
//Áã¶àÏîÊ½


int main()
{
	int n1,n2;
	cin >> n1;
	PNode P1;//change PNode to Poly ,try? or try Poly Node=(Poly)malloc(sizeof(struct PNode)); watch P
	P1.next = NULL;
	Poly rear1 = &P1;
	for (int i = 0; i < n1; i++)
	{
		Poly S = (Poly)malloc(sizeof(struct PNode));
		cin >> S->coef >> S->expon;
		S->next = NULL;
		rear1->next = S;
		rear1 = S;
	}

	cin >> n2;
	Poly P2= (Poly)malloc(sizeof(struct PNode));//change PNode to Poly ,try? or try Poly Node=(Poly)malloc(sizeof(struct PNode)); watch P
	P2->next = NULL;
	Poly rear2 = P2;
	for (int i = 0; i < n2; i++)
	{
		Poly S = (Poly)malloc(sizeof(struct PNode));
		cin >> S->coef >> S->expon;
		S->next = NULL;
		rear2->next = S;
		rear2 = S;
	}
	Poly t1 = P1.next;
	Poly t2 = P2->next;
	Poly P = AddPoly(t1, t2);

	return 0;
}