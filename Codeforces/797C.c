#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef long long int ll;

char s[100005];
char ans[100005];
ll last_occrence[1005];
ll pushed[100005];

char mini(char a, char b)
{
	if(a<b)
	{
		return a;
	}

	return b;
}

typedef struct node
{
	char data;
	struct node* next;
} node;

ll isEmpty(node *head)
{
	return head==NULL;
}

node* push(node *head, char data)
{
	node *temp = (node*) malloc(sizeof(node));

	temp->data = data;
	temp->next = head;

	head = temp;

	return head;
}

node* pop(node *head)
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

int main()
{
	node *head = NULL;

	ll n;
	// scanf("%lld", &n);

	scanf("%s", s);

	n = strlen(s);

	ll min = 0, cnt = 0, j=0;

	for(ll b='a'; b<='z'; b++)
	{
		last_occrence[b] = -1;
	}

	for(ll a=0; a<n; a++)
	{
		last_occrence[s[a]] = a;
	}

	last_occrence[(ll)'a'-1]=-1;
	ll flag = 0;
	for(ll i='a'; i<='z'; i++)
	{
		while(!isEmpty(head) && top(head)<=(char)i)
		{
			ans[cnt++] = top(head);
			head = pop(head);
		}

		for(ll k=last_occrence[i-1]+1; k<=last_occrence[i]; k++)
		{
			if(s[k]==(char)i && pushed[k]==0)
			{
				// printf("added %c when string was %s\n", (char)i, ans);
				ans[cnt++] = (char)i;
				pushed[k] = 1;
			}

			else
			{
				if(pushed[k]==0)
				{
					// printf("pushed %c at k=%lld\n", s[k], k);
					head = push(head, s[k]);
					pushed[k] = 1;
				}
			}

			if(k==n-1)
			{
				flag = 1;
				break;
			}
		}

		if(flag==1)
		{
			break;
		}

		// char min = 'a';

		// for(ll j=last_occrence[i]+1; j<n; j++)
		// {
		// 	min = mini(min, s[j]);
		// }

		// while(!isEmpty(head) && top(head)<min)
		// {
		// 	ans[cnt++] = top(head);
		// 	head = pop(head);
		// }
	}

	// printf("%s\n", ans);

	while(!isEmpty(head))
	{
		// printf("while loop\n");
		ans[cnt++] = top(head);
		head = pop(head);
	}

	printf("%s\n", ans);	
	
	return 0;
}