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

const ll L = 505;

vector <ll> t(L);
vector <ll> f[L];
vector <ll> s[L];
bool visited[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll tc = 0;
    
    while(true)
    {
        tc++;

        ll v, e;
        cin >> v >> e;

        ll tot = 0;

        if(!v && !e)
        {
            break;
        }

        for(ll i=0; i<L; i++)
        {
            f[i].clear();
            s[i].clear();
            t[i] = 0;
        }


        for(ll i=1; i<=v; i++)
        {
            cin >> t[i];

            tot+=t[i];
        }

        for(ll i=0; i<e; i++)
        {
            ll a, b;
            cin >> a >> b;

            f[a].pb(b);
            s[b].pb(a);
        }

        ll q;
        cin >> q;

        cout << "Case #" << tc << ":" << endl;

        while(q--)
        {
            ll x;
            cin >> x;

            queue <ll> q1, q2;
            
            for(ll i=0; i<L; i++)
            {
                visited[i] = false;
            }

            q1.push(x);
            q2.push(x);

            ll sum1 = 0, sum2 = 0;

            while(!q1.empty())
            {
                ll top = q1.front();
                q1.pop();

                sum1+=t[top];

                visited[top] = true;

                for(auto i: f[top])
                {
                    if(!visited[i])
                    {
                        q1.push(i);
                    }
                }
            }

            while(!q2.empty())
            {
                ll top = q2.front();
                q2.pop();

                sum2+=t[top];

                visited[top] = true;

                for(auto i: s[top])
                {
                    if(!visited[i])
                    {
                        q2.push(i);
                    }
                }
            }
            
            cout << tot - sum1 - sum2 + t[x] << endl;
        }

        cout << endl;
    }

    return 0;
}