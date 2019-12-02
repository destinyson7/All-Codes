#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector <ll> v;
ll hashi[1005];

int main()
{
	ll n;
	cin >> n;

	while(n)
	{
		// cout << n << endl;
		for(ll a=0; a<1005; a++)
		{
			hashi[a]=0;		
		}

		for(ll i=0; i<n; i++)
		{
			ll temp;
			cin >> temp;
			v.push_back(temp);
		}

		ll current = 1;
		
		ll j=0;
		// cout << "j= " << j << " and v[j]= " << v[j] << " and v[0]= " << v[0] << endl;

		stack <ll> s;

		ll ite = 1;
		while(current<=n && j<n)
		{
			// cout << "1" << " ";
			if(!s.empty() && s.top()==current)
			{
				// cout << "first if ";
				hashi[current++]=1;
				s.pop();
			}

			else if(v[j]==current)
			{
				// cout << "else if ";
				hashi[current++]=1;
				j++;
			}

			else
			{
				// cout << "else ";
				s.push(v[j]);
				j++;
			}

			// cout << current << " at iteration no.: " << ite++ << endl;
		}
		// cout << endl;

		ll flag = 0;

		// cout << s.size() << " ";

		while(!s.empty())
		{
			// cout << s.top() << " ";

			if(s.top()==current)
			{
				hashi[current++]=1;
				s.pop();
			}

			else
			{
				flag = 1;
				// cout << "while ";
				break;
			}

		}

		if(!flag)
		{
			for(ll k=1; k<=n; k++)
			{
				if(hashi[k]==0)
				{
					flag=1;
					break;
				}
			}	
		}
			
		if(flag)
		{
			cout << "no" << endl;
		}

		else
		{
			cout << "yes" << endl;
		}

		
		cin >> n;

		v.clear();
	}

	return 0;
}
