#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

string solution[405];

int main()
{
	ll t;
	cin >> t;

	while(t--)
	{
		string exp;
		cin >> exp;

		ll len = exp.length();

		ll cnt = 0, store = 0;

		stack <ll> s;

		for(ll i=0; i<len; i++)
		{
			if(exp[i]=='(')
			{
				// cout << "first if" << " ";
				cnt++;
			}

			else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='^')
			{
				// cout << "second if" << " ";
				s.push(exp[i]);
			}

			else if(exp[i]==')')
			{
				// cout << "third if" << " ";				
				solution[store++]=s.top();
				s.pop();
				cnt--;
			}

			else
			{
				// cout << "else" << " ";				
				solution[store++]=exp[i];
			}
		}

		// cout << s.size() << endl;
		// cout << "cnt: " << cnt << endl;
		for(ll j=0; j<store; j++)
		{
			cout << solution[j];
		}
		cout << endl;
	}



	return 0;
}