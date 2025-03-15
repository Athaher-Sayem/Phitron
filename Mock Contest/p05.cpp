#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;  // number of test cases
    
    while (T--) {
        int N;
        cin >> N;  // number of coins
        
        vector<int> coins(N);
        int total_sum = 0;
        
        for (int i = 0; i < N; i++) {
            cin >> coins[i];
            total_sum += coins[i];  // calculate the total sum of coins
        }
        
        int target = total_sum / 2;
        
        // Create a dp array to track possible sums
        vector<bool> dp(target + 1, false);
        dp[0] = true;  // sum 0 is always achievable
        
        for (int i = 0; i < N; i++) {
            for (int j = target; j >= coins[i]; j--) {
                dp[j] = dp[j] || dp[j - coins[i]];  // update dp array
            }
        }
        
        // Find the largest sum that can be achieved <= target
        int closest_sum = 0;
        for (int i = target; i >= 0; i--) {
            if (dp[i]) {
                closest_sum = i;
                break;
            }
        }
        
        // The minimal difference will be total_sum - 2 * closest_sum
        cout << total_sum - 2 * closest_sum << endl;
    }
    
    return 0;
}
