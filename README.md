# Cycle-detection
🚀 Cycle Detection in Graphs
Today, I explored Cycle Detection in both undirected and directed graphs using BFS and DFS.

📌 Topics Covered:
1️⃣ Introduction to Cycle Detection
2️⃣ Detecting Cycles in Undirected Graphs

Using DFS
Using BFS (Graph Coloring Approach)
3️⃣ Detecting Cycles in Directed Graphs
Using DFS (Recursion Stack Approach)
🔥 Approach & Algorithm:
✅ Cycle Detection in Undirected Graph (DFS)
Use DFS with a parent tracking mechanism.
If a visited node is found and it’s not the parent, a cycle exists.
✅ Cycle Detection in Undirected Graph (BFS)
Use BFS with a queue.
Track parent nodes and check if a visited neighbor is not the parent.
✅ Cycle Detection in Directed Graph (DFS)
Maintain a visited array and a recursion stack.
If a node is visited again in the current recursion stack, a cycle exists

```cpp
#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool vis[1005];
int parent[1005];
bool cycle;

void dfs(int src)
{
    vis[src] = true;
    for(int child : adj_list[src])
    {
        if(vis[child] && parent[src] != child)
            cycle = true;
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
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    
    cycle = false;

    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
            dfs(i);
    }


    if(cycle)
        cout << "Cycle" << endl;
    else
        cout << "No Cycle" << endl;    
 
    return 0;
}
```

🚀 Graph Cycle Detection – BFS & DFS Approach!

Today, I deep-dived into Cycle Detection in both undirected and directed graphs using BFS and DFS.

🔹 Undirected Graph: Cycle detection using DFS (parent tracking) and BFS (graph coloring approach).
🔹 Directed Graph: Cycle detection using DFS (recursion stack method).

Understanding these techniques is crucial for graph-based problem-solving, and I’m excited to apply them in competitive programming! 💡