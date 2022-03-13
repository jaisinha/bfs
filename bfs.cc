int *bfs(struct graph *g, int n, int m) {
    vector<int> bfs;
    vector<int> vis(n+1,0);
    for(int i=1;i<=vis.size();i++) //ensures even the disconnected graph elements are traversed
    {
        if(!vis[i])
        {
            queue<int> q;
            q.push(i); // it will help to begin the searching in adjacent C node
            vis[i]=1;
            while(!q.empty()) // it will break only when all the elements of the disconnected graph is reached
            {
                int node=q.front(); // before searching the adjacent C node push the parent element
                q.pop(); 
                bfs.push_back(node); 
                for(auto it:g[node]) // searching in adjacent c node
                {
                    if(!vis[it])
                    {
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
        }
    }
    return bfs;
}
