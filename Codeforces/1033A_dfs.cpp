using namespace std;

#include <iostream>

typedef long long int ll;

ll visited[1005][1005];
ll flag[1005][1005];

ll n, cx, cy;

ll dfs(ll x, ll y)
{
	if(x==cx && y==cy)
	{
		return 1;
	}

	if(x>n || x<=0 || y>n || y<=0)
	{
		return 0;
	}

	if(visited[x][y]==1)
	{
		return 0;
	}

	if(flag[x][y]==1)
	{
		return 0;
	}

	visited[x][y]=1;

	if(dfs(x+1, y+1))
	{
		return 1;
	}

	if(dfs(x+1, y))
	{
		return 1;
	}

	if(dfs(x+1, y-1))
	{
		return 1;
	}

	if(dfs(x, y-1))
	{
		return 1;
	}

	if(dfs(x-1, y-1))
	{
		return 1;
	}

	if(dfs(x-1, y))
	{
		return 1;
	}

	if(dfs(x-1, y+1))
	{
		return 1;
	}

	if(dfs(x, y+1))
	{
		return 1;
	}

	return 0;
}

int main()
{
	cin >> n;

	ll ax, ay, bx, by;
	cin >> ax >> ay;
	cin >> bx >> by;
	cin >> cx >> cy;

	ll x, y;

	x=ax;
	y=ay;
	while(x<=n && y<=n)
	{
		flag[x][y]=1;
		x++;
		y++;
	}

	x=ax;
	y=ay;
	while(x && y)
	{
		flag[x][y]=1;
		x--;
		y--;
	}

	x=ax;
	y=ay;
	while(x<=n && y)
	{
		flag[x][y]=1;
		x++;
		y--;
	}

	x=ax;
	y=ay;
	while(x && y<=n)
	{
		flag[x][y]=1;
		x--;
		y++;
	}

	x=ax;
	y=ay;
	while(x<=n)
	{
		flag[x][y]=1;
		x++;
	}

	x=ax;
	y=ay;
	while(y<=n)
	{
		flag[x][y]=1;
		y++;
	}

	x=ax;
	y=ay;
	while(x)
	{
		flag[x][y]=1;
		x--;
	}

	x=ax;
	y=ay;
	while(y)
	{
		flag[x][y]=1;
		y--;
	}

	if(dfs(bx, by)==1)
	{
		cout << "YES" << endl;
	}

	else
	{
		cout << "NO" << endl;
	}

	return 0;
}