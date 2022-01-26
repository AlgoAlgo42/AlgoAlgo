class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
        int m = 0;
        while (dp[m][K] < N) {
            m++;
            for (int k = 1; k <= K; ++k)
                dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
            // std::cout << m << " , " << k << std::endl;
            // std::cout << dp[m][k]<< std::endl;}
            // std::cout << " =========== "<< std::endl;
            // std::cout << dp[m][K]<< std::endl;
        }
        return m;
    }
};
// 2 6
        // 0 0 0
        // 0 1 1
        // 0 2 3    
        // 0 3 6
        // 0 0 0
        // 0 0 0
        // 0 0 0    
// 2 7
        // 0 0 0
        // 0 1 1
        // 0 2 3    
        // 0 3 6
        // 0 4 10
        // 0 0 0
        // 0 0 0    
        