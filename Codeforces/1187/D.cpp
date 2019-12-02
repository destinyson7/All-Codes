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
 
const ll L = 3e5+5;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll t;
    cin >> t;
 
    while(t--)
    {
        ll n;
        cin >> n;
 
        vector <ll> a;
        vector <ll> b;
        // vector <ll> cnt(n+5, 0);
        vector <ll> check(n+5, 0);
        vector <ll> occur[n+5];
        vector <ll> siz(n+5, 0);
 
        for(ll i=1; i<=n; i++)
        {
            ll q;
            cin >> q;
 
            a.pb(q);
 
            occur[q].pb(i);
            // occur[i].pb(-1);
        }
 
        for(ll i=0; i<n; i++)
        {
            ll q;
            cin >> q;
 
            b.pb(q);
 
            // cnt[q]++;
 
        }
 
        for(ll i=0; i<=n; i++)
        {
            siz[i] = sz(occur[i]);
        }
 
        bool next = false;
 
        ll end = 0;
 
        for(ll i=0; i<n; i++)
        {
            if(a[i] == b[i])
            {
                check[b[i]]++;
                // cnt[a[i]]--;
                continue;
            }
 
            if(siz[b[i]] < check[b[i]]+1)
            {
                // cout << "here2" << endl;
                cout << "NO" << endl;
                next = true;
                break;
            }
 
            ll r = occur[b[i]][check[b[i]]];
            check[b[i]]++;
 
            // for(ll j=i; j<=r; j++)
            // {
            //     check[b[j]]++;
            // }
 
            if(r<i)
            {
                // cout << "here1" << endl;
                cout << "NO" << endl;
                next = true;
                break;
            }
 
            // if(end < r)
            // {
                // sort(a.begin()+i, a.begin()+r+1);
            swap(a[i], a[r]);
                // for(; i<=r; i--)
                // {
                    // if(a[i]!=b[i])
                    // {
                    //     cout << "NO" << endl;
                    //     next = true;
                    //     break;
                    // }   
                // }

                // if(next)
                // {
                //     break;
                // }
                
                // i = r;
            //     end = r;
            // }
        }
 
        if(next)
        {
            continue;
        }
 
        for(ll i=0; i<n; i++)
        {
            if(a[i]!=b[i])
            {
                cout << "NO" << endl;
                next = true;
                break;                
            }
        }
 
        if(next)
        {
            continue;
        }
 
        cout << "YES" << endl;
    }
 
 
    return 0;
}