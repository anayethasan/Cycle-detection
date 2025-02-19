#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[105];
bool vis[105];
bool pathvis[105];
bool flag;

void dfs(int src)
{
    vis[src] = true;
    pathvis[src] = true;
    for (int child : adj_list[src])
    {
        if(vis[child] && pathvis[child])
            flag = true;
        if(!vis[child])
        {
            dfs(child);
        }
    }
    pathvis[src] = false;
}

int main()
{
    int n,e;
    cin >> n >> e;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }
    memset(vis, false, sizeof(vis));
    memset(pathvis, false, sizeof(pathvis));

    flag = false;

    for (int i = 0; i < n; i++)
    {
        if(!vis[i])
            dfs(i);
    }
    
    if(flag)
        cout << "Cycle Detecitet" << endl;
    else
        cout << "No Cycle Detectet" << endl;    
 
    return 0;
}