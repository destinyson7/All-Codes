#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef long long int ll;

typedef struct node
{
	char data;
	struct node* next;
} node;

node *push(node *head, char data)
{
	node *temp = (node *)malloc(sizeof(node));

	temp->data = data;
	temp->next = head;
	head = temp;

	return head;
}

node *pop(node *head)
{
	node *temp = head;
	head = head->next;
	free(temp);

	return head;
}

char top(node* head)
{
	return head->data;
}

ll isEmpty(node *head)
{
	return head==NULL;
}

char s[1000005];

int main()
{
	scanf("%s", s);

	ll n = strlen(s);

	for(ll i=0; i<n; i++)
	{
		
	}

	
	return 0;
}