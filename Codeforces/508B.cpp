using namespace std;

#include <iostream>
#include <string>

typedef long long int ll;

int main()
{
	string n;
	cin >> n;

	ll len = n.length();

	ll flag=0;

	ll mini = 11, index;

	for(ll i=0; i<len; i++)
	{
		if(n[i]%2==0)
		{
			// cout << n[i] << " " << mini << " ";
			// cout << mini - n[i] << endl;
			if(n[i] - 48 < mini)
			{
				// cout << "mini is " << mini << endl;
				mini = n[i];
				index = i;
			}

			if(n[i] < n[len-1])
			{
				swap(n[i], n[len-1]);
				flag=1;
				break;
			}
		}
	}

	if(flag)
	{
		cout << n << endl;
	}

	else
	{
		if(mini==11)
		{
			cout << "-1" << endl;
		}

		else
		{
			swap(n[len-1], n[index]);
			cout << n << endl;
		}
	}

	return 0;
}