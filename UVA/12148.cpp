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

const ll L = 1e5+5;

bool leap(ll y)
{
    if(y%4 == 0 && y%100 != 0)
    {
        return true;
    }

    if(y%400 == 0)
    {
        return true;
    }

    return false;
}

typedef struct date
{
    ll d, m, y;
    ll c;
} date;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while(true)
    {
        ll N;
        cin >> N;

        if(!N)
        {
            break;
        }

        vector <date> v(N+5);

        for(ll i=0; i<N; i++)
        {
            cin >> v[i].d >> v[i].m >> v[i].y >> v[i].c;
            
            // if(v[i].d == 29 && v[i].m == 2)
            // {
            //     v[i].d = 1;
            //     v[i].m = 3;
            // }
        }

        ll cnt = 0;

        ll res = 0;

        for(ll i=1; i<N; i++)
        {
            if(v[i].y - v[i-1].y == 1)
            {
                if(v[i].d == 1 && v[i].m == 1 && v[i-1].d == 31 && v[i-1].m == 12)
                {
                    cnt++;

                    res+=v[i].c;
                    res-=v[i-1].c;
                }
            }

            else if(v[i].y == v[i-1].y)
            {
                if(v[i].m - v[i-1].m == 1)
                {
                    if(v[i].m == 2 && v[i-1].m == 1)
                    {
                        if(v[i].d == 1 && v[i-1].d == 31)
                        {
                            cnt++;

                            res+=v[i].c;
                            res-=v[i-1].c;
                        }
                    }

                    if(v[i].m == 3 && v[i-1].m == 2)
                    {
                        if(v[i].d == 1 && v[i-1].d == 28 && !leap(v[i].y))
                        {
                            cnt++;

                            res+=v[i].c;
                            res-=v[i-1].c;
                        }

                        if(v[i].d == 1 && v[i-1].d == 29 && leap(v[i].y))
                        {
                            cnt++;

                            res+=v[i].c;
                            res-=v[i-1].c;
                        }
                    }

                    if(v[i].m == 4 && v[i-1].m == 3)
                    {
                        if(v[i].d == 1 && v[i-1].d == 31)
                        {
                            cnt++;

                            res+=v[i].c;
                            res-=v[i-1].c;
                        }
                    }

                    if(v[i].m == 5 && v[i-1].m == 4)
                    {
                        if(v[i].d == 1 && v[i-1].d == 30)
                        {
                            cnt++;

                            res+=v[i].c;
                            res-=v[i-1].c;
                        }
                    }

                    if(v[i].m == 6 && v[i-1].m == 5)
                    {
                        if(v[i].d == 1 && v[i-1].d == 31)
                        {
                            cnt++;

                            res+=v[i].c;
                            res-=v[i-1].c;
                        }
                    }

                    if(v[i].m == 7 && v[i-1].m == 6)
                    {
                        if(v[i].d == 1 && v[i-1].d == 30)
                        {
                            cnt++;

                            res+=v[i].c;
                            res-=v[i-1].c;
                        }
                    }

                    if(v[i].m == 8 && v[i-1].m == 7)
                    {
                        if(v[i].d == 1 && v[i-1].d == 31)
                        {
                            cnt++;

                            res+=v[i].c;
                            res-=v[i-1].c;
                        }
                    }

                    if(v[i].m == 9 && v[i-1].m == 8)
                    {
                        if(v[i].d == 1 && v[i-1].d == 31)
                        {
                            cnt++;

                            res+=v[i].c;
                            res-=v[i-1].c;
                        }
                    }

                    if(v[i].m == 10 && v[i-1].m == 9)
                    {
                        if(v[i].d == 1 && v[i-1].d == 30)
                        {
                            cnt++;

                            res+=v[i].c;
                            res-=v[i-1].c;
                        }
                    }

                    if(v[i].m == 11 && v[i-1].m == 10)
                    {
                        if(v[i].d == 1 && v[i-1].d == 31)
                        {
                            cnt++;

                            res+=v[i].c;
                            res-=v[i-1].c;
                        }
                    }

                    if(v[i].m == 12 && v[i-1].m == 11)
                    {
                        if(v[i].d == 1 && v[i-1].d == 30)
                        {
                            cnt++;

                            res+=v[i].c;
                            res-=v[i-1].c;
                        }
                    }
                }

                else if(v[i].m == v[i-1].m)
                {
                    if(v[i].d - v[i-1].d == 1)
                    {
                        cnt++;

                        res+=v[i].c;
                        res-=v[i-1].c;
                    }
                }
            }
        }

        cout << cnt << " " << res << endl;


    }


    return 0;
}