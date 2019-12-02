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

const ll L = 55;

ll arr1[L][L];
ll arr2[L][L];

bool check(ll i, ll j)
{
    if(arr1[i][j] < arr1[i+1][j])
    {
        if(arr1[i][j] < arr1[i][j+1])
        {
            if(arr2[i][j] < arr2[i+1][j])
            {
                if(arr2[i][j] < arr2[i][j+1])
                {
                    return true;
                }

                else
                {
                    // cout << "1" << endl;
                    return false;
                }
            }

            else
            {
                return false;
            }
        }

        else
        {
            return false;
        }
    }

    else
    {
        return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m;
    cin >> n >> m;

    for(ll i=1; i<=m; i++)
    {
        arr1[n+1][i] = 1e15;
        arr2[n+1][i] = 1e15;
    }

    for(ll i=1; i<=n; i++)
    {
        arr1[i][m+1] = 1e15;
        arr2[i][m+1] = 1e15;
    }

    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=m; j++)
        {
            cin >> arr1[i][j];
        }
    }   

    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=m; j++)
        {
            cin >> arr2[i][j];
        }
    }  

    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=m; j++)
        {
            if(!check(i, j))
            {
                swap(arr1[i][j], arr2[i][j]);

                if(!check(i, j))
                {
                    cout << "Impossible" << endl;
                    return 0;
                }
            }

            else
            {
                if((max(arr1[i+1][j], arr1[i][j+1]) > max(arr2[i+1][j], arr2[i][j+1]) && arr2[i][j] > arr1[i][j]) || (max(arr1[i+1][j], arr1[i][j+1]) < max(arr2[i+1][j], arr2[i][j+1]) && arr2[i][j] < arr1[i][j]))
                {
                    swap(arr1[j][j], arr2[i][j]);

                    if(!check(i, j))
                    {
                        swap(arr1[j][j], arr2[i][j]);
                    }
                }
            }
        }
    }    

    // for(ll i=1; i<=n; i++)
    // {
    //     for(ll j=1; j<=m; j++)
    //     {
    //         if(arr1[i][j] <= arr1[i-1][j] || arr2[i][j] <= arr2[i-1][j])
    //         {
    //             cout << "Impossible" << endl;
    //             return 0;
    //         }
    //     }
    // }

    // for(ll i=1; i<=m; i++)
    // {
    //     for(ll j=1; j<=n; j++)
    //     {
    //         if(arr1[j][i] <= arr1[j][i-1] || arr2[j][i] <= arr2[j][i-1])
    //         {
    //             cout << "Impossible" << endl;
    //             return 0;
    //         }
    //     }
    // }

    cout << "Possible" << endl;

    return 0;
}