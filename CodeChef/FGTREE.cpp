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

const ll L = 1e2+5;

vector <ll> done(L);
vector <ll> res(L);
vector <ll> r(L);
vector <ll> l(L);
vector <ll> orig(L);

bool check(ll N)
{
    if(N!=2)
    {
        return true;
    }

    printf("Q 1 1 1\n");
    fflush(stdout);

    char s[10];
    scanf("%s", s);

    if(s[0] == 'N')
    {
        printf("A -1 1\n");
        fflush(stdout);
        
        return false;
    }

    printf("A 2 -1\n");
    fflush(stdout);

    return false;
}

void solve(ll N, ll &ans, ll &cur, map <ll, ll> &mnormal, map<pll, ll> &mpair)
{
    ll fin = 0;
    while(ans > 1)
    {
        // cout << ans << endl;
        for(ll i=0; i<cur; i++)
        {
            if(mnormal.find(orig[i]) == mnormal.end())
            {
                while(true)
                {
                    ll check = 1;
                    
                    mnormal[orig[i]] = 1;

                    if(l[i] > 1)
                    {
                        printf("Q %lld %lld %lld\n", l[i]-1, l[i]-1, r[i]);
                        fflush(stdout);

                        char s[10];
                        scanf("%s", s);

                        if(s[0] != 'N')
                        {
                            check = 0;
                            l[i]--;
                            ans--;
                            res[orig[i]] = l[i];
                            done[orig[i]] = 0;
                            orig[i] = l[i];
                        }
                    }

                    if(check && r[i] < N)
                    {
                        printf("Q %lld %lld %lld\n", r[i]+1, l[i], r[i]+1);
                        fflush(stdout);

                        char s[10];
                        scanf("%s", s);

                        if(s[0] != 'N')
                        {
                            check = 10;
                            r[i]++;
                            ans--;
                            res[orig[i]] = r[i];
                            done[orig[i]] = 0;
                            orig[i] = r[i];
                        }
                    }

                    if(check == 1)
                    {
                        break;
                    }
                }

                // assert(false);
            }
        }

        // assert(false);

        for(ll i=1; i<cur; i++)
        {
            if(mpair.find(mp(orig[i-1], orig[i]))!=mpair.end())
            {
                continue;
            }

            if(!done[orig[i]] || !done[orig[i-1]])
            {
                continue;
            }

            if(l[i]-2 != r[i-1])
            {
                continue;
            }

            mpair[mp(orig[i-1], orig[i])] = 1;

            printf("Q %lld %lld %lld\n", r[i-1]+1, l[i-1], r[i]);
            fflush(stdout);

            char s[10];
            scanf("%s", s);

            if(s[0] != 'N')
            {
                r[i-1]++;
                ans-=2;
                done[orig[i]] = 0;
                done[orig[i-1]] = 0;
                res[orig[i]] = r[i-1];
                res[orig[i-1]] = r[i-1];
                l[i] = l[i-1];
                orig[i] = r[i-1];
                orig[i-1] = -1;
                i++;
                r[i-1]--;
            }
        }

        // assert(false);

        ll ok = 0;

        for(ll i=0; i<cur; i++)
        {
            if(orig[i] == -1)
            {
                continue;
            }

            ok++;

            r[ok-1] = r[i];
            l[ok-1] = l[i];
            orig[ok-1] = orig[i];
        }

        cur = ok;

        fin++;

        // cout << ans << endl;
        // if(fin > 10000)
        // {
        //     assert(false);
        // }
    }

    // assert(false);
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    
    ll T;
    scanf("%lld", &T);

    while(T--)
    {
        map <pll, ll> mpair;
        map <ll, ll> mnormal;

        ll N;
        scanf("%lld", &N);

        bool flag = false;
        ll cur = 0;
        ll ans = N;

        for(ll i=1; i<=N; i++)
        {
            if(!check(N))
            {
                flag = true;
                break;
            }

            printf("Q %lld %lld %lld\n", i, i, i);
            fflush(stdout);

            char s[10];
            scanf("%s", s);

            if(s[0] != 'N')
            {   
                r[cur] = i;
                orig[cur] = i;
                l[cur++] = i;
            }

            done[i] = 1;
            res[i] = -1;
        }

        if(!flag)
        {
            solve(N, ans, cur, mnormal, mpair);

            printf("A ");

            // cout << ans << endl;

            for(ll i=1; i<=N; i++)
            {
                printf("%lld ", res[i]);
            }
            printf("\n");
            fflush(stdout);
        }

    }

    return 0;
}