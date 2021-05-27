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
#define all(a) a.begin(), a.end()

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
// int adj[101][101];
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(NULL));
    int N = max(4, rand() % 10 + 1), S = rand() % 10 + 1;
    S = min(S, N - 1);
    fstream out_stream;
    out_stream.open("in.txt", ios::out);

    out_stream << N << " " << S << "\n";

    vector <int> x;

    for(ll i=0; i<N; i++)
    {
        x.pb((rand() % 100000000 + 1));
        out_stream << x[i] << " ";
    }
    out_stream << "\n";

    // while (M--)
    // {
    //     int ind = rand() % size;
    //     out_stream << edges[ind].first << " " << edges[ind].second.first << " " << edges[ind].second.second << "\n";
    //     edges.erase(edges.begin() + ind);
    //     size--;
    // }
    // int src = rand() % N + 1;
    // out_stream << src << "\n";
}
