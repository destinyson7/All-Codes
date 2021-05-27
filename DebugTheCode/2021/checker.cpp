#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

using namespace std;
using namespace __gnu_pbds;


#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

typedef tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
// vector<int> adj[101];
// int color[101];

#define maxn 100000
#define minn 2
#define maxv 100000000
#define minv 1
#define maxs 25
#define mins 1

int vacations[maxn];
int n, s;

bool verify(int a) {
    int projects = 0, nextStartDate = 0;
    for (int i = 0; i < n; i++) {
        if (vacations[i] >= nextStartDate) {
            projects++;
            nextStartDate = vacations[i] + a;
        }
    }
    return (projects <= s);
}

int HACK() {
    int low = 1,
        high = 3e8,
        ans = -1;

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (verify(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}


int AC() {
    int low = 1,
        high = 3e8,
        ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (verify(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fstream graph;
    graph.open("in.txt", ios::in);
    int N,S;
    graph >> N >> S;
    // vector<pair<ll,ll>>adj[N+1];
    // vector<pair<ll,pair<ll, ll>>> edges;

    for(int i = 0; i < N; i++) {
        graph >> vacations[i];
    }

    int a = HACK(), b = AC();

    if(a != b)
    {
        fstream out_stream;
        out_stream.open("hack.txt", ios::out);

        out_stream << N << " " << S << "\n";

        for(int i = 0; i < N; i++)
        {
            out_stream << vacations[i] << " ";
        }
        out_stream << "\n\n\n";

        out_stream << a << " " << b << "\n";
    }

    // cout << a << " " << b << "\n";

    assert(a == b);

    cout << "CORRECT" << "\n";

    return 0;
}
