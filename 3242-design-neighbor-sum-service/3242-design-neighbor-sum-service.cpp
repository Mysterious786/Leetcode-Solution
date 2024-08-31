#include <vector>
#include <map>

using namespace std;

class NeighborSum {
    int mp[101][101] = {0}; // Map from {diagonal, value} to sum
public:
    NeighborSum(vector<vector<int>>& grid) {
        int n = grid.size();
        //mp.resize(n+1,0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int currentValue = grid[i][j];
                
                // ----------------Adjacent
                if (i - 1 >= 0) {
                    mp[0][currentValue] += grid[i - 1][j];
                }
                if (i + 1 < n) {
                    mp[0][currentValue] += grid[i + 1][j];
                }
                if (j - 1 >= 0) {
                    mp[0][currentValue] += grid[i][j - 1];
                }
                if (j + 1 < n) {
                    mp[0][currentValue] += grid[i][j + 1];
                }
                
                // ----------------Diagonal
                if (i - 1 >= 0 && j + 1 < n) {
                    mp[1][currentValue] += grid[i - 1][j + 1];
                }
                if (i + 1 < n && j + 1 < n) {
                   mp[1][currentValue] += grid[i + 1][j + 1];
                }
                if (i + 1 < n && j - 1 >= 0) {
                   mp[1][currentValue] += grid[i + 1][j - 1];
                }
                if (i - 1 >= 0 && j - 1 >= 0) {
                    mp[1][currentValue] += grid[i - 1][j - 1];
                }
            }
        }
    }
    
    int adjacentSum(int value) {
        return mp[0][value];
    }
    
    int diagonalSum(int value) {
        return mp[1][value];
    }
};



/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */