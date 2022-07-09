class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int totalSum = accumulate(stones.begin(), stones.end(), 0);        
        bool dp[n + 1][totalSum + 1];
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n+1; i++)
        {
            dp[i][0] = true;
        }
        for(int j=1; j<totalSum+1; j++)
        {
            dp[0][j] = false;
        }
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<totalSum+1; j++)
            {
                if(stones[i-1] <= j)
                {
                    dp[i][j] = ((dp[i-1][j - stones[i-1]]) || dp[i-1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        int minWeight = INT_MAX;
        
	    for(int i=totalSum/2; i>=0; i--)
	    {
	        if(dp[n][i] == true) 
	        {
	            minWeight = totalSum - (2*i);
	            break;
	        }
	    }
	    return minWeight;       
   }
};