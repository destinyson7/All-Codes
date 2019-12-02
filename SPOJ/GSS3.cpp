#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

ll arr[50005];

typedef struct segTree
{
	ll sum;
	ll pre;
	ll suf;
	ll max;
		
} segTree;

segTree seg[4*50005];

void make(ll i, ll tl, ll tr)
{
    if(tl==tr)
    {	
    	seg[i].sum = arr[tl];
    	seg[i].pre = arr[tl];
    	seg[i].suf = arr[tl];
    	seg[i].max = arr[tl];
    }
    
    else
    {
        ll mid = tl + (tr-tl)/2;
        
        make(2*i, tl, mid);
        make(2*i+1, mid+1, tr);
        
        seg[i].sum = seg[2*i].sum + seg[2*i+1].sum;
        seg[i].pre = max(seg[2*i].pre, seg[2*i].sum+seg[2*i+1].pre);
        seg[i].suf = max(seg[2*i+1].suf, seg[2*i+1].sum+seg[2*i].suf);
        seg[i].max = max(seg[2*i].max, max(seg[2*i+1].max, seg[2*i].suf+seg[2*i+1].pre));
    }
}

segTree query(ll i, ll tl, ll tr, ll l, ll r)
{
    if(r<tl || l>tr)
    {
        return ((segTree){0, -1e17, -1e17, -1e17});
    }
    	
    if(l<=tl && tr<=r)
    {
        return seg[i];
    }
    
    ll mid = tl + (tr-tl)/2;

    segTree left = query(2*i, tl, mid, l, r);
    segTree right = query(2*i+1, mid+1, tr, l, r);

    segTree toRet;

    toRet.sum = left.sum+right.sum;
    toRet.pre = max(left.pre, left.sum+right.pre);
    toRet.suf = max(right.suf, right.sum+left.suf);
    toRet.max = max(left.max, max(right.max, left.suf+right.pre));

   return toRet;
}

void update(ll i, ll tl, ll tr, ll idx, ll val)
{
    if(tl==tr)
    {
        seg[i] = ((segTree){val, val, val, val});
    }
    
    else
    {
        ll mid = tl + (tr-tl)/2;
        
        if(tl<=idx && idx<=mid)
        {
            update(2*i, tl, mid, idx, val);
        }
        
        else
        {
            update(2*i+1, mid+1, tr, idx, val);
        }
        
        seg[i].sum = seg[2*i].sum + seg[2*i+1].sum;
        seg[i].pre = max(seg[2*i].pre, seg[2*i].sum+seg[2*i+1].pre);
        seg[i].suf = max(seg[2*i+1].suf, seg[2*i+1].sum+seg[2*i].suf);
        seg[i].max = max(seg[2*i].max, max(seg[2*i+1].max, seg[2*i].suf+seg[2*i+1].pre));
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll N;
	cin >> N;

	for(ll i=1; i<=N; i++)
	{
		cin >> arr[i];
	}

	make(1, 1, N);

	ll M;
	cin >> M;

	while(M--)
	{
		ll type, x, y;
		cin >> type >> x >> y;

		if(type==0)
		{
			update(1, 1, N, x, y);
		}

		else
		{
			segTree got = query(1, 1, N, x, y);
			// cout << got.sum << " " << got.pre << " " << got.suf << " " << got.max << endl;	
			cout << got.max << endl;
		}
	}


	return 0;
}