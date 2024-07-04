from typing import List

class Solution:
    def dfs(self,i:int,j:int,adj:List[List[int]],hasApple:List[bool]):
        count =0
        for it in adj[i]:
            if it!=j:
                num = self.dfs(it,i,adj,hasApple)
                if hasApple[it]:
                    num = num+2
                    count = count+num
                    hasApple[i] =True
        return count
        
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        adj = [[] for _ in range(n+1)]
        for edge in edges:
            adj[edge[0]].append(edge[1])
            adj[edge[1]].append(edge[0])
        return self.dfs(0,0,adj,hasApple)
    