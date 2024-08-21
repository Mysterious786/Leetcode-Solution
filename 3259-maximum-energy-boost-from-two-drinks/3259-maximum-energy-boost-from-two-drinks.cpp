class Solution {
public:
    int n;
    long long dp[100000][2];// (i, j) ith hour drinking j=(dinking==B)
    long long f(int i, int j, vector<int>& A, vector<int>& B){
        if (i>=n) return 0;
        if (dp[i][j]!=-1) return dp[i][j];
        long long energy=(j==0)?A[i]: B[i];
        energy+=max(f(i+1, j, A, B), f(i+2, 1-j, A, B));
        return dp[i][j]=energy;
    }
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        n=energyDrinkA.size();
        memset(dp, -1, sizeof(dp));
        return max(f(0, 0, energyDrinkA, energyDrinkB), f(0, 1, energyDrinkA,energyDrinkB));
        
    }
};

// int main() {
//     int n;
//     cin >> n;
//     vector<ll> a(n), b(n);
//     Solution ol;
//     for (auto& it : a) cin >> it;
//     for (auto& it : b) cin >> it;
//     cout << ol.maxEnergyBoost(a, b) << endl;
// }
