ll kd[30][L] , a[L] , pos[L] , Real[L];
 
void init(ll d,ll b,ll e){
    if(b == e){
        kd[d][b] = pos[b];
        return;
    }
    ll m = (b + e) >> 1;
    init(d + 1,b,m);
    init(d + 1,m+1,e);
    ll i = b , j = m + 1;
    ll ptr = 0;
    while(i <= m && j <= e){
        if(kd[d + 1][i] < kd[d + 1][j]){
            kd[d][b + (ptr++)] = kd[d + 1][i++];
        }else{
            kd[d][b + (ptr++)] = kd[d + 1][j++];
        }
    }
    while(i <= m) kd[d][b + (ptr++)] = kd[d + 1][i++];
    while(j <= e) kd[d][b + (ptr++)] = kd[d + 1][j++];
}
 
inline ll find(ll d,ll b,ll e,ll x1,ll x2){
    return upper_bound(kd[d] + b,kd[d] + e + 1,x2) - lower_bound(kd[d] + b,kd[d] + e + 1,x1);
}
 
ll get(ll n,ll x1,ll x2,ll k){
    ll d = 0 , b = 1 , e = n;
    while(b != e){
        ll ll = find(d + 1,b,(b+e)/2,x1,x2);
        ll m = (b + e) >> 1;
        if(ll >= k){
            e = m;
        }else{
            b = m + 1;
            k -= ll;
        }
        ++d;
    }
    return b;
}