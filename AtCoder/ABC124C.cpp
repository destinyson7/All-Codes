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

const ll L = 1e5+5;

vector <ll> a(L);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string S;
    cin >> S;

    for(ll i=0; i<(ll)S.size(); i++)
    {
        a[i] = S[i] - 48;
    }

    ll ans = 0;
    for(ll i=1; i<(ll)S.size(); i++)
    {
        if(a[i]==a[i-1])
        {
            ans++;
            a[i]^=1;
        }
    }

    cout << ans << endl;

    return 0;
}