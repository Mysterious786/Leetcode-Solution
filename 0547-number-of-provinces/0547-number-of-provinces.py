class Solution:
    def __init__(self):
        self.adj = []
        self.vis = [0] * 201
        
    def dfs(self, node: int) -> None:
        self.vis[node] = 1
        for i in self.adj[node]:
            if self.vis[i] == 0:
                self.dfs(i)
        
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        self.adj = [[] for _ in range(n)]  # Initialize adjacency list for each node
        self.vis = [0] * n  # Adjust visited array to correct size
        
        # Build the adjacency list from the isConnected matrix
        for i in range(n):
            for j in range(n):
                if isConnected[i][j] == 1 and i != j:
                    self.adj[i].append(j)
                    self.adj[j].append(i)
                    
        count = 0
        # Perform DFS for each unvisited node
        for i in range(n):
            if self.vis[i] == 0:  # If node `i` is unvisited
                self.dfs(i)
                count += 1  # Increment province count
        
        return count

        
        