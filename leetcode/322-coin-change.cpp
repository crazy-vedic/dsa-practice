/*
 * Coin Change
 * Difficulty: Medium
 * 
 * You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 
Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1


Example 2:

Input: coins = [2], amount = 3
Output: -1


Example 3:

Input: coins = [1], amount = 0
Output: 0


 
Constraints:


	1 <= coins.length <= 12
	1 <= coins[i] <= 231 - 1
	0 <= amount <= 104


 */


class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            vector<int> dp = vector<int>(amount+1,-2);
            sort(coins.rbegin(),coins.rend());
            dp[0]=0;
            for (int curr=1;curr<amount+1;curr++){
                bool impossible=true;
                vector<int> possible_sol = vector<int>();
                for (int currCoin=0;currCoin<coins.size();currCoin++){
                    if (curr-coins[currCoin]<0){
                        continue;
                    }
                    else if (curr-coins[currCoin]==0){
                        dp[curr] = (1);
                        impossible=false;
                        break;
                    }
                    else{
                        if (dp[curr-coins[currCoin]] == -1){
                            continue;
                        }
                        possible_sol.push_back(currCoin);
                        // dp[curr] = (1+dp[curr-coins[currCoin]]);
                        impossible=false;
                        // break;
                    }
                }
                if (impossible){
                    dp[curr]=-1;
                }
                else if (dp[curr]==-2) {
                    int minShit  = dp[curr - coins[possible_sol[0]]];
                    for (int i=1;i<possible_sol.size();i++){
                        minShit = min(minShit,dp[curr - coins[possible_sol[i]]]);
                    }
                    dp[curr] = minShit +1 ;
                }
            }
            return dp[amount];
        }
    };
