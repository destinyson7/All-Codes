def mult(path,tree,i,n,visited):
    flag=1
    vis=[False]*n
    vis[path[i]]=True
    for x in tree[path[i]]:
        if visited[x]==False:
            t=count(x,tree,vis)
            flag*=(t+1)
    return flag-1
def count(x,tree,visited):
    flag1=1
    visited[x]=True
    for y in tree[x]:
        if visited[y]==False:
            #print(y)
            visited[y]=True
            flag1+=count(y,tree,visited)
    return flag1
def dfs(a,x,y,visited):
    visited[x]=True
    for t in a[x]:
        if visited[t]==False:
            visited[t]=True
            if t==y:
                return [t]
            else:
                temp=dfs(a,t,y,visited)
                if temp!=None:
                    return [t]+temp
for _ in range(int(input())):
    n,q=map(int,input().split())
    tree=[[] for _ in range(n)]
    for i in range(n-1):
        a,b=map(int,input().split())
        tree[a-1].append(b-1)
        tree[b-1]+=[a-1]
    for _ in range(q): 
        x,y=map(int,input().split())
        path=[x-1]+dfs(tree,x-1,y-1,[False]*n)
        p_len=len(path)
        i=0
        out=0
        visited=[False]*n
        for x in path:
            visited[x]=True
        while i<p_len:
            out+=mult(path,tree,i,n,visited)
            i+=1
        out+=p_len
        print(out)