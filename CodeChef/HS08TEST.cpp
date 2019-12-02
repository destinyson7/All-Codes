#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	float X, Y;
	cin >> X;
	cin >> Y;

	float ans;

	if((int)X%5==0)
	{
		if(Y - X - 0.5 >= 0)
		{
			ans = Y-X-0.5;
		}

		else
		{
			ans = Y;
		}
	}

	else
	{
		ans = Y;
	}

	printf("%.2f\n", ans);


	return 0;
}