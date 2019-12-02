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
    
    ll N;
    cin >> N;

    ll T, A;
    cin >> T >> A;

    ll ans = 1;
    float mini = 1e6;
    for(ll i=0; i<N; i++)
    {
        ll h;
        cin >> h;

        if(abs(abs(T-(float)(h*0.006)-A)) < mini)
        {
            mini = abs(abs(T-(float)(h*0.006)-A));
            ans = i+1;
        }
    }

    cout << ans << endl;

    return 0;
}