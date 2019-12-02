#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl "\n"
#define sz(a) (ll)a.size()

ll modexp(ll a, ll b, ll c)
{
    ll ans = 1;
    a%=c;

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
    
    ll T;
    cin >> T;

    while(T--)
    {
        string a;
        ll b;
        cin >> a >> b;

        ll n = a[sz(a)-1] - '0';

        cout << modexp(n, b, 10) << endl;
    }

    return 0;
}