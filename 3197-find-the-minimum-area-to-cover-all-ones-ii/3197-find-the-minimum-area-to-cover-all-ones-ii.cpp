#define pii pair<int, int>
#define F first
#define S second

class Solution {
    
    vector<vector<int>> grid;
    
    pair<pii, pii> MinRectangle(pii x, pii y) {
        int lft = x.S, rgt = y.S;
        for (; lft <= y.S; lft ++) {
            int one = 0;
            for (int i = x.F; i <= y.F; i ++) one += grid[i][lft];
            if (one > 0) break;
        }
        for (; rgt >= x.S; rgt --) {
            int one = 0;
            for (int i = x.F; i <= y.F; i ++) one += grid[i][rgt];
            if (one > 0) break;
        }
        
        int top = x.F, dwn = y.F;
        for (; top <= y.F; top ++) {
            int one = 0;
            for (int i = x.S; i <= y.S; i ++) one += grid[top][i];
            if (one > 0) break;
        }
        for (; dwn >= x.F; dwn --) {
            int one = 0;
            for (int i = x.S; i <= y.S; i ++) one += grid[dwn][i];
            if (one > 0) break;
        }
        
        if (lft > rgt) return {{x.F, x.S}, {x.F, x.S}}; // rectangle with area 1
        return {{top, lft}, {dwn, rgt}};
    }
    
    int Area (pair<pii, pii> r) {
        return (r.S.F - r.F.F + 1) * (r.S.S - r.F.S + 1);
    }
    
    int Min2Rectangle (pii x, pii y) {
        int ans = Area({x, y});
        
        for (int col = x.S; col < y.S; col ++) {
            auto lft = MinRectangle ({x.F, x.S}, {y.F, col});
            auto rgt = MinRectangle ({x.F, col+1}, {y.F, y.S});
            
            ans = min (ans, Area(lft) + Area(rgt));    
        }
        for (int row = x.F; row < y.F; row ++) {
            auto lft = MinRectangle ({x.F, x.S}, {row, y.S});
            auto rgt = MinRectangle ({row+1, x.S}, {y.F, y.S});
            
            ans = min (ans, Area(lft) + Area(rgt));    
        }
        return ans;
    }
    
    int Min3Rectangle (pii x, pii y) {
        int ans = Area({x, y});
        
        for (int col = x.S; col < y.S; col ++) {
            auto lft1 = MinRectangle ({x.F, x.S}, {y.F, col});
            auto rgt1 = Min2Rectangle ({x.F, col+1}, {y.F, y.S});
            
            auto lft2 = Min2Rectangle ({x.F, x.S}, {y.F, col});
            auto rgt2 = MinRectangle ({x.F, col+1}, {y.F, y.S});
            
            ans = min (ans, Area(lft1) + rgt1); 
            ans = min (ans, lft2 + Area(rgt2)); 
        }
        for (int row = x.F; row < y.F; row ++) {
            auto lft1 = MinRectangle ({x.F, x.S}, {row, y.S});
            auto rgt1 = Min2Rectangle ({row+1, x.S}, {y.F, y.S});
            
            auto lft2 = Min2Rectangle ({x.F, x.S}, {row, y.S});
            auto rgt2 = MinRectangle ({row+1, x.S}, {y.F, y.S});
            
            ans = min (ans, Area(lft1) + rgt1);  
            ans = min (ans, lft2 + Area(rgt2)); 
        }
        return ans;
    }
    
public:
    int minimumSum(vector<vector<int>>& _grid) {
        grid = _grid;
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        return Min3Rectangle({0, 0}, {rows-1, cols-1});
    }
};