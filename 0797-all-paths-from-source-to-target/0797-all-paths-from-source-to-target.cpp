class Solution {
public:
void fullpath(vector<int>&vec , vector<vector<int>> &rvector, vector<vector<int>>&graph,int src,int dst)
{
    vec.push_back(src);
    if(src==dst)
    {
        rvector.push_back(vec);
        vec.pop_back();
        return;
    }
    for(int i=0;i<graph[src].size();i++)
    {
        int des = graph[src][i];
        fullpath(vec,rvector,graph,des,dst);
    }
    vec.pop_back();
    return;
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> rvector;
        vector<int> vec;
        fullpath(vec,rvector,graph,0,graph.size()-1);
        return rvector;
    }
};