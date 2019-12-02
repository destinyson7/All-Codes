using namespace std;

#include <iostream>
#include <string>

typedef long long int ll;

string a[3005];
string b[3005];
string ans[3005];
string lec[3005];

int main()
{
    ll n, m;
    cin >> n >> m;

    for(ll i=0; i<m; i++)
    {
    	cin >> a[i];
    	cin >> b[i];

    	if(a[i].size()>b[i].size())
    	{
    		ans[i]=b[i];
    	}

    	else
    	{
    		ans[i]=a[i];
    	}
    }

    for(ll j=0; j<n; j++)
    {
    	cin >> lec[j];

    	for(ll k=0; k<m; k++)
    	{
    		if(lec[j]==a[k])
    		{
    			cout << ans[k] << " ";
    			break;
    		}
    	}
    }       

    return 0;
}
