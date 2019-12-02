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
     
    ll A, B, K;
    cin >> A >> B >> K;

    ll cnt = 0;
    for(ll i=min(A, B); i>0; i--)
    {
        if(A%i==0 && B%i==0)
        {
            cnt++;

            if(cnt==K)
            {
                cout << i << endl;
                return 0;
            }
        }
    }

    return 0;
}