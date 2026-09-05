class Solution {
private:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& isVisited) {
        isVisited[node] = 1;

        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[node][i] == 1 && !isVisited[i]) {
                dfs(i, isConnected, isVisited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> isVisited(V, 0);
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!isVisited[i]) {
                count++;
                dfs(i, isConnected, isVisited);
            }
        }
        return count;
    }
};