#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair <int, int>
#define pll pair <ll, ll>
#define gcd __gcd
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

const ll L = 1e4+5;

ll a[L];
ll ch[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T;
    cin >> T;

    while(T--)
    {
        ll N;
        cin >> N;

        ll pref = 0;
        ll cnt = 0;

        for(ll i=0; i<N; i++)
        {
            cin >> a[i];
            pref+=a[i];
        }

        ll K, X;
        cin >> K;
        cin >> X;

        ll ma = 0;
        ll mi = 0;
        ll maxx = 1e15;
        ll minn = -1e15;
        ll gr = 0;
        ll le = 0;

        for(ll i=0; i<N; i++)
        {
            ch[i] = (a[i]^X) - a[i];

            if(!ch[i])
            {
                cnt++;
            }

            else if(ch[i] > 0)
            {
                gr++;
                pref+=ch[i];
                ma+=ch[i];
                maxx = min(maxx, ch[i]);
            }

            else
            {
                le++;
                mi+=ch[i];
                minn = max(minn, ch[i]);
            }
        }

        if(K&1)
        {
            cout << (N==K ? max(pref-ma, pref+mi):pref) << endl;
        }

        else
        {
            if(N-K)
            {
                if(cnt || gr%2==0)
                {
                    cout << pref << endl;
                    continue;
                }

                if(!le)
                {
                    pref-=maxx;
                }

                else if(maxx+minn >= 0)
                {
                    pref+=minn;
                }

                else
                {
                    pref-=maxx;
                }

                cout << pref << endl;                
            }

            else
            {
                cout << max(pref+mi, pref-ma) << endl;
            }
        }
    }

    return 0;
}