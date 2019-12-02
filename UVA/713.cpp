#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

ll gcd(ll a, ll b)
{
    if(b==0)
    {
        return a;
    }

    return gcd(b, a%b);
}

const ll L = 1e5+5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T;
    cin >> T;

    while(T--)
    {
        string a, b;
        cin >> a >> b;
        
        reverse(all(a));
        reverse(all(b));

        ll lena = sz(a);
        ll lenb = sz(b);

        vector <ll> v(500, 0);

        for(ll i=0; i<min(lena, lenb); i++)
        {
            ll p = a[lena-i-1]-48;
            ll q = b[lenb-i-1]-48;
            p+=q;

            // cout << p << endl;

            v[499-i]+=p;
            v[499-i-1]+=(v[499-i]/10);
            v[499-i]%=10;
        }

        for(ll i = min(lena, lenb); i<lena; i++)
        {
            v[499-i]+=(a[lena-i-1]-48);
            v[499-i-1]+=(v[499-i]/10);
            v[499-i]%=10;

            // cout << v[499-i] << " " << v[499-i-1] << endl;
        }

        for(ll i = min(lena, lenb); i<lenb; i++)
        {
            v[499-i]+=(b[lenb-i-1]-48);
            v[499-i-1]+=(v[499-i]/10);
            v[499-i]%=10;
        }

        reverse(all(v));

        ll start = 0;
        ll end = 499;

        while(v[start] == 0)
        {
            start++;
        }

        while(v[end] == 0)
        {
            end--;
        }

        // cout << start << " " << end << endl;

        for(ll i=start; i<=end; i++)
        {
            cout << v[i];
        }
        cout << endl;
    }


    return 0;
}