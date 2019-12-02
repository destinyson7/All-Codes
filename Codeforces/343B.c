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
	node *temp = (node*)malloc(sizeof(node));

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

char top(node *head)
{
	return head->data;
}

ll isEmpty(node* head)
{
	return head==NULL;
}

char s[100005];

int main()
{
	node *head = NULL;

	scanf("%s", s);

	ll n = strlen(s);

	for(ll i=0; i<n; i++)
	{
		if(!isEmpty(head) && top(head)==s[i])
		{
			head = pop(head);
		}

		else
		{
			head = push(head, s[i]);
		}
	}

	if(isEmpty(head))
	{
		printf("Yes\n");
	}

	else
	{
		printf("No\n");
	}

	
	return 0;
}