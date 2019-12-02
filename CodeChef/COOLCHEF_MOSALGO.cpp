

    //satyaki3794
    #include <bits/stdc++.h>
    #define ff first
    #define ss second
    #define pb push_back
    #define MOD (1000000007LL)
    #define LEFT(n) (2*(n))
    #define RIGHT(n) (2*(n)+1)
     
    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;
    typedef pair<int, int> ii;
    typedef pair<ii, int> iii;
    ll pwr(ll base, ll p, ll mod = MOD){
    ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;
    }
    ll modular_inverse(ll n){
        return pwr(n, MOD-2);
    }
    #define N 1000005
    int n, BLOCK, C, arr[N], func[N], cnt[N];
    ll curr_value;
    ii qarr[N];
    inline int getBlock(int pos){
        return (pos-1) / BLOCK;
    }
    bool comp(ii a, ii b){
        int b1 = getBlock(a.ff);
        int b2 = getBlock(b.ff);
        if(b1 != b2)   return b1 < b2;
        return a.ss < b.ss;
    }
    inline void remove(int pos){
        if(cnt[arr[pos]] >= 0)
            curr_value = (curr_value * modular_inverse(func[cnt[arr[pos]]])) % MOD;
        cnt[arr[pos]]--;
        if(cnt[arr[pos]] >= 0)
            curr_value = (curr_value * func[cnt[arr[pos]]]) % MOD;
    }
    inline void add(int pos){
        if(cnt[arr[pos]] >= 0)
            curr_value = (curr_value * modular_inverse(func[cnt[arr[pos]]])) % MOD;
        cnt[arr[pos]]++;
        if(cnt[arr[pos]] >= 0)
            curr_value = (curr_value * func[cnt[arr[pos]]]) % MOD;
    }
    int main(){
        int q;
        scanf("%d%d%d", &n, &C, &q);
        for(int i=1;i<=n;i++){
            scanf("%d", &arr[i]);
            assert(arr[i] > 0 && arr[i] <= C);
        }
        for(int i=0;i<=n;i++){
            scanf("%d", &func[i]);
            assert(func[i] > 0 && func[i] <= C);
        }
        for(int i=0;i<q;i++){
            scanf("%d%d", &qarr[i].ff, &qarr[i].ss);
            assert(1<=qarr[i].ff && qarr[i].ff<=qarr[i].ss && qarr[i].ss<=n);
        }
        BLOCK = ceil(sqrt(n));
        sort(qarr, qarr+q, comp);
        int left = 1, right = 1;
        cnt[arr[1]] = 1;
        curr_value = 1;
        for(int i=1;i<=C;i++)
            curr_value = (curr_value * func[cnt[i]]) % MOD;
        ll ans = 1;
        for(int i=0;i<q;i++){
            int lo = qarr[i].ff;
            int hi = qarr[i].ss;
            while(left < lo){
                remove(left);
                left++;
            }
            while(left > lo){
                left--;
                add(left);
            }
            while(right < hi){
                right++;
                add(right);
            }
            while(right > hi){
                remove(right);
                right--;
            }
            assert(curr_value > 0);
            ans = (ans * curr_value) % MOD;
        }
        printf("%lld\n", ans);
        return 0;
    }

Tester Solution by Akul Sareen

    #include <bits/stdc++.h>
    using namespace std;
    const int MAXN = 50005;
    const int MAXV = 1000006;
    const long long int MOD = 1000000007;
    int SQRT, ctr[MAXV], A[MAXN], F[MAXN], l[MAXN], r[MAXN];
    long long int power(long long int a, int b)
    {
        if(!b)
            return 1;
        long long int ans = power(a, b/2);
        ans = (ans*ans)%MOD;
        if(b%2)
            ans = (ans*a)%MOD;
        return ans;
    }
    bool sorter(const int &x, const int &y)
    {
        int bx = l[x]/SQRT, by = l[y]/SQRT;
        if(bx != by)
            return bx < by;
        return r[x] < r[y];
    }
    inline void add_value(int x, long long int &tot)
    {
        tot = (tot*power(F[ctr[x]], MOD-2))%MOD;
        ctr[x]++;
        tot = (tot*F[ctr[x]])%MOD;
    }
    inline void rem_value(int x, long long int &tot)
    {
        tot = (tot*power(F[ctr[x]], MOD-2))%MOD;
        ctr[x]--;
        tot = (tot*F[ctr[x]])%MOD;
    }
    int main()
    {
        int n,c,q;
        cin>>n>>c>>q;
        for (int i = 1; i <= n; ++i)
            cin>>A[i];
        for (int i = 0; i <= n; ++i)
            cin>>F[i];
        vector <int> que;
        for (int i = 0; i < q; ++i)
        {
            cin>>l[i]>>r[i];
            que.push_back(i);
        }
        SQRT = sqrt(n + 5);
        sort(que.begin(), que.end(), sorter);
        int p1 = 0, p2 = 0;
        long long int cval = power(F[0],c), ans = 1;
        for (int i = 0; i < q; ++i)
        {
            int id = que[i];
            while(p2 < r[id])
            {
                p2++;
                add_value(A[p2], cval);
            }
            while(p2 > r[id])
            {
                rem_value(A[p2], cval);
                p2--;
            }
            while(p1 < l[id] - 1)
            {
                p1++;
                rem_value(A[p1], cval);
            }
            while(p1 >= l[id])
            {
                add_value(A[p1], cval);
                p1--;
            }
            ans = (ans*cval)%MOD;;
        }
        cout<<ans<<"\n";
        return 0;
    }

