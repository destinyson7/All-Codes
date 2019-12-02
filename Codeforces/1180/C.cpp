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

const ll L = 1e5+5;
const ll M = 3e5+5;

ll a[L];
ll after[L];

deque <ll> dq;
deque <ll> dq2;

vector <pll> ans(M);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, q;
    cin >> n >> q;

    ll maxx = -1e12;

    for(ll i=0; i<n; i++)
    {
        cin >> a[i];

        maxx = max(a[i], maxx);

        dq.pb(a[i]);
        dq2.pb(a[i]);
    }

    ll cnt = 1;

    while(true)
    {
        if(dq.front()!=maxx)
        {
            ll A = dq.front();
            dq.pop_front();

            ll B = dq.front();
            dq.pop_front();

            if(A > B)
            {
                dq.push_front(A);
                dq.pb(B);
            }

            else
            {
                dq.push_front(B);
                dq.pb(A);
            }

            ans[cnt++] = mp(A, B);
        }

        else
        {
            break;
        }
    }

    cnt--;

    for(ll i=0; i<n; i++)
    {
        after[i] = dq.front();
        dq.pop_front();
    }

    while(q--)
    {
        ll m;
        cin >> m;

        if(m<=cnt)
        {
            cout << ans[m].ff << " " << ans[m].ss << endl;
        }

        else
        {
            m-=cnt;
            m%=(n-1);

            if(m==0)
            {
                m=n-1;
            }

            cout << maxx << " " << after[m] << endl;
        }
    }


    return 0;
}