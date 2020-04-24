    #include <bits/stdc++.h>
     
    #ifdef ONLINE_JUDGE
    #define endl "\n"
    #endif
    using namespace std;
    typedef vector<int> v;
    typedef vector<v> vv;
    typedef vector<bool> vb;
    typedef vector<string> vs;
    typedef pair<int, int> pii;
    const int MOD = 1e9 + 7;
    const v dx = {1, -1, 0, 0};
    const v dy = {0, 0, 1, -1};
    #define yes cout << "YES\n";
    #define no cout << "NO\n";
    #define yesno(f) \
        if (f)       \
            yes else no;
    #define noo \
        { no return; }
    #define amax(x, y) \
        if (y > x)     \
            x = y;
    #define amin(x, y) \
        if (y < x)     \
            x = y;
    #define sz(x) (int)x.size()
    #define sq(x) ((x) * (x))
     
    #define all(x) x.begin(), x.end()
    #define rall(x) x.rbegin(), x.rend()
     
    template<typename T = int>
    vector<T> ga(int n, bool oneIndexed = false) {
        vector<T> a = vector<T>(n + oneIndexed);
     
        for (int i = 0; i < n; i++) {
            T p;
            cin >> p;
            a[i + oneIndexed] = p;
        }
     
        return move(a);
    }
     
    template<typename T, typename A>
    void pa(vector<T, A> const &a, int begin = 0, int end = -1) {
        if (end == -1)
            end = sz(a) - 1;
        for (int i = begin; i <= end; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
     
    void solve() {
        int n;
        cin >> n;
     
        vector<long long> a(n), b(n);
     
        for (int i = 0; i < n; i++)cin >> a[i] >> b[i];
     
        vector<long long> excess(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                excess[i] = max(a[i] - b[n - 1], 0ll);
            } else {
                excess[i] = max(a[i] - b[i - 1], 0ll);
            }
        }
     
        long long req = 0;
        for (auto e : excess) req += e;
        long long m = 1e15;
        for(auto idx = 0; idx < n; idx++)
            amin(m, a[idx] - excess[idx]);
        cout << req + m << endl;
    }
     
    int main(void) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int t;
        cin >> t;
        while (t--)
            solve();
        return 0;
    }