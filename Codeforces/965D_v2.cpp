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

ll a[L];
ll reach[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll w, l;
    cin >> w >> l;

    for(ll i=1; i<w; i++)
    {
        cin >> a[i];

        if(i<=l)
        {
            reach[i] = a[i];
        }

        // cout << reach[i] << endl;
    }

    a[w] = 1e15;

    ll left = 0;
    ll right = l+1;

    reach[0] = 1e15;

    while(1)
    {
        // if(right==w+1)
        // {
        //     // for(ll i=0; i<=w; i++)
        //     // {
        //     //     cout << i << " " << reach[i] << endl;
        //     // }

        //     cout << reach[w] << endl;
        //     return 0;
        // }

        while(left<right-l)
        {
            left++;
        }

        while(a[right]>=reach[left])
        {
            if(left==right)
            {
                break;
            }

            reach[right]+=reach[left];
            a[right]-=reach[left];
            reach[left] = 0;
            left++;
        }

        if(right==w)
        {
            // for(ll i=0; i<=w; i++)
            // {
            //     cout << i << " " << reach[i] << endl;
            // }

            cout << reach[w] << endl;
            return 0;
        }

        // cout << left << " " << right << endl;
        // a[right]-=reach[left];
        if(left!=right)
        {
            reach[right]+=a[right];
            reach[left]-=a[right];
        }
        // left++;
        right++;
    }


    return 0;
}