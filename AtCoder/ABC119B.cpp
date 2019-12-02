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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    float ans = (float)0;

    ll N;
    cin >> N;

    for(ll i=0; i<N; i++)
    {
        string u;
        float x;

        cin >> x >> u;

        if(u=="JPY")
        {
            ans+=x;
        }

        else
        {
            ans+=x*380000;
        }
    }

    cout << fixed << setprecision(8) << ans << endl;

    return 0;
}