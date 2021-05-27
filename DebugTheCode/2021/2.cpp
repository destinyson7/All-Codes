#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1013;

void solve()
{
    int n;
    cin >> n;

    vi marks(n);
    for(auto &x: marks)
    {
        cin >> x;
    }

    vi app(n);
    for(auto &x: app)
    {
        cin >> x;
    }

    vector <pii> a(n);

    for(int i=0; i<n; i++)
    {
        a[i] = {marks[i], i};
    }

    sort(a.begin(), a.end());

    vi ans(n);

    set <int, greater<>> apps;

    for(int i=0; i<n; i++)
    {
        int cc = app[a[i].second];

        int size = 0, sum = 0;

        for(auto x: apps)
        {
            sum += x;
            size++;
            if(sum > cc)
            {
                break;
            }
        }

        apps.insert(cc);
        ans[a[i].second] = sum > cc ? size : -1;
    }

    for(auto x: ans) cout << x << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    solve();

    return 0;
}
