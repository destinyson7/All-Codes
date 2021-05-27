#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 1013;

ll arr[N], dp[N][N], prefs[N], n, k, m;

ll solve(ll start, ll no)
{
    if(no == k)
    {
        return 0;
    }

    if(start + m - 1 == n + 1)
    {
        return -1e16;
    }

    if(dp[start][no] == -1)
    {
        dp[start][no] = max(prefs[start + m - 1] - prefs[start - 1] + solve(start + m, no + 1), solve(start + 1, no));
    }

    return dp[start][no];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;

    for(int a = 1; a <= n; a++)
    {
        cin >> arr[a];
    }

    for(int a = 1; a <= n; a++)
    {
        prefs[a] = prefs[a-1] + arr[a];
    }

    for(int a =0; a<=n; a++)
    {
        for(int b=0; b<=n+5; b++)
        {
            dp[a][b] = -1;
        }
    }

    cout << solve(1, 0) << endl;

    return 0;
}
