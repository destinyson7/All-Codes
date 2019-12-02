#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;


#define endl "\n"

ll modexp(ll a, ll b, ll c)
{
    a%=c;

    ll ans = 1;

    while(b)
    {
        if(b&1)
        {
            ans = (ans*a)%c;
        }

        a = (a*a)%c;
        b>>=1;
    }

    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
        
    ll t;
    cin >> t;

    while(t--)
    {
        ll a, b;
        cin >> a >> b;

        cout << modexp(a, b, 10) << endl;
    }


    return 0;
}