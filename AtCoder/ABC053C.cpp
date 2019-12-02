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

    ll x;
    cin >> x;

    ll ans = 0;
    ans+=2*(x/11);
    x%=11;

    if(x<=6 && x)
    {
        cout << ans+1 << endl;
    }    

    else if(x>6)
    {
        cout << ans+2 << endl;
    }

    else
    {
        cout << ans << endl;
    }
    

    return 0;
}