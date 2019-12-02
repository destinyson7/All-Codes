#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector<long long int> vl;
#define pb push_back
#define mp make_pair

int n;
bool g[5200][5200], c[5200][5200];

bool check(int sz){
	bool f = 1;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(g[i][j]!=g[i/sz*sz][j/sz*sz])
				return false;
	
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	
	cin >> n;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j+=4){
			char c;
			cin >> c;
			
			int a;
			if(c >=48 && c<=57)
				a = c-'0';
			else
				a = c-'A'+10;
			
			for(int k=0;k<4;k++)
				g[i][j+3-k] = a%2, a/=2;
		}
	}
	
	set<int> fact;
	for(int i=1;i*i<=n;i++){
		if(n%i==0)
			fact.insert(i), fact.insert(n/i);
	}
	vl v;

	for(auto it:fact)
		v.pb(it);
	
	int l = 0, r = v.size();
	int mid= (l+r)/2, mo=-1;
	while(mid!=mo){
		mo = mid;
		if(check(v[mid])) l = mid;
		else r = mid;
		mid = (l+r)/2;
	}
	
	cout << v[mid] << endl;
	return 0;
}