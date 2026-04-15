class Solution {
public:
bool isReachable(vector<int> G[],vector<bool> &visited , int source , int destination){
    visited[source] = true;
    if(source==destination) return true;
    for(auto des:G[source])
    {
        if(visited[des]==false) 
        {
            bool resp = isReachable(G,visited,des,destination);
            if(resp==true) return true;
            else continue;
        }
    }
    return false;
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination) return true;

        vector<int> G[n];
        for(int r=0;r<edges.size();r++)
        {
            int row = edges[r][0];
            int col = edges[r][1];
            G[row].push_back(col);
            G[col].push_back(row);
        }
        vector<bool> visited(n,false);
        bool resp = isReachable(G,visited,source,destination);
        return resp;
    }
        
};