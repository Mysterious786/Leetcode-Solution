from typing import List

class Solution:
    def f(self, ind: int, coins: List[int], amount: int, dp: List[List[int]]) -> int:
        # Base case when we have only one coin type left
        if ind == 0:
            if amount % coins[ind] == 0:
                return amount // coins[ind]  # Return the number of coins needed
            else:
                return float('inf')  # Impossible to form the amount
        
        if dp[ind][amount] != -1:
            return dp[ind][amount]

        # Not taking the current coin
        notTake = self.f(ind - 1, coins, amount, dp)

        # Taking the current coin
        take = float('inf')
        if coins[ind] <= amount:
            take = 1 + self.f(ind, coins, amount - coins[ind], dp)  # Include the coin

        # Store the minimum number of coins required in dp
        dp[ind][amount] = min(take, notTake)
        return dp[ind][amount]

    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)
        dp = [[-1] * (amount + 1) for _ in range(n)]  # Initialize dp array

        coin = self.f(n - 1, coins, amount, dp)
        return -1 if coin == float('inf') else coin  # Return -1 if no combination was found
