#include<stdio.h>
#include<stdlib.h>

typedef struct tf *tp;
	struct tf
	{
		int am;
		tp next;
	};
tp h, t;

void Push(tp *h, tp *t, int da);
void print1(tp h);
void print2(tp h);
void Pop(tp *h, tp *t);

int main(void)
{
	h = NULL;
	t = NULL;
	int da;
	int choice = 1;
	while (choice)
	{
		char xar;
		printf("\nEnter D to Pop, I to Push, P to print list and E to exit\n");
		scanf("%c", &xar);
		switch (xar)
		{
		case 'D':
			{
				if(h==NULL)
					printf("\nList is empty!");
				else
				{
					Pop(&h, &t);
					print1(h);
				}
			}
			break;
		case 'I':
			{
				printf("\nGive me the AM integer: ");
				scanf("%d", &da);
				Push(&h, &t, da);	
			}
			break;
		case 'P':
			{
				if(h==NULL)
					printf("\nList is empty!");
				else
					print1(h);	
				break;
			}
		case 'p':
			{
				if(h==NULL)
					printf("\nList is empty!");
				else
					print2(h);	
				break;
			}	
		case 'E':
				choice = 0;
				break;
		default:
			printf("Wrong input!");
		}
		getchar();
	}
	return 0;
}
void Push(tp *h, tp *t, int da)
{
	tp temp, aux;
		
	temp = (tp)malloc(sizeof(struct tf));
	temp->am = da;
	temp->next = NULL;
	printf("\nThe AM of temp is %d\n", temp->am);
	if(*h == NULL)
	{
		printf("I1\n");
		*h = temp;
		*t = temp;
		printf("\nh = %d\nt = %d", *h, *t);
	}
	else
	{
		printf("I2\n");
		temp->next = *h;
		*h = temp;
		printf("\nh = %d\nt = %d", *h, *t);
	}
}
void print1(tp h)
{
	tp aux;
	aux = h;
	while(aux != NULL)
	{
		printf("\n%d", aux->am);
		aux = aux->next;
	}
}
void print2(tp h)
{
	if(h != NULL)
	{
		printf("\n%d", h->am);
		print2(h->next);
	}
	else return;
}
void Pop(tp *h, tp *t)
{
	tp temp, aux;
	printf("\nh kai t before POP\nh = %d\nt = %d\n", *h, *t);
		printf("D1\n");
		aux = *h;
		*h = (*h)->next;
		free(aux);
		aux = NULL;
		if(*h == NULL)
		{
			*t = NULL;
			printf("\nList is empty!");
		}
	printf("\nh = %d\nt = %d\n", *h, *t);	
} 
