#include<stdio.h>

int main()
{
int T, y;

scanf("%d", &T);

for(int i=1; i<=T; i++)
{
    int N, X, S;

    scanf("%d %d %d", &N, &X, &S);
    for(int j=1; j<=S; j++)
    {
	int A, B;

	scanf("%d %d", &A, &B);

	if(A==X)
	   X=B;

	else if(B==X)
	    X=A;
	   	
    }

    printf("%d\n", X);

}

    return 0;
}
