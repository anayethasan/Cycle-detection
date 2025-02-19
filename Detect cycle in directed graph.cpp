#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool vis[1005];
int parent[1005];
bool flag;

void dfs(int src)
{
    vis[src] = true;
    for(int child : adj_list[src])
    {
        if(vis[child] && parent[src] != child)
            flag = true;
        if(!vis[child])
        {
            parent[child] = src;
            dfs(child);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    flag = false;

    for (int i = 0; i < n; i++)
    {
        if(!vis[i])
            dfs(i);
    }
    
    if(flag)
        cout << "Cycle" << endl;
    else
        cout << "NO Cycle" << endl;    
 
    return 0;
}