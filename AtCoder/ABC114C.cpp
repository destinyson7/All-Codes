#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

vector <ll> v;

void generateAll(ll n, ll cur)
{
    if(n<15)
    {
        v.pb(cur);

        generateAll(n+1, cur*10+3);
        generateAll(n+1, cur*10+5);
        generateAll(n+1, cur*10+7);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N;
    cin >> N;

    generateAll(1, 3);
    generateAll(1, 5);
    generateAll(1, 7);

    ll ans = 0;

    for(ll i=0; i<sz(v); i++)
    {
        if(v[i] <= N)
        {
            ll c = v[i];

            ll flag[15];
            for(ll j=0; j<15; j++)
            {
                flag[j] = 0;
            }

            while(c)
            {
                flag[c%10]=1;
                c/=10;
            }

            if(flag[3] && flag[5] && flag[7])
            {
                ans++;
            }
        }
    }

    cout << ans << endl;    

    return 0;
}