// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d40bb

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Test sets passe
// TLE
/*void pick(int n, int k, int p, vector<vector<int>>& stacks, int start, int val, int& ans) {
    if (p == 0) {
        ans = max(ans, val);
        return;
    }

    for (int i = start; i < n; ++i) {
        for (int k_ = 0; k_ < k && p - k_ - 1 >= 0; ++k_) {
            pick(n, k, p - k_ - 1, stacks, i + 1, val + stacks[i][k_], ans);
        }
    }
}*/

int pick(int n, int k, int p, vector<vector<int>>& stacks, int start, vector<vector<int>>& memo) {
    if (n <= start || p == 0) return 0;
    if (memo[start][p] != 0) return memo[start][p];

    int ans = pick(n, k, p, stacks, start + 1, memo);
    for (int k_ = 0; k_ < k && p - k_ - 1 >= 0; ++k_) {
        ans = max(ans, stacks[start][k_] + pick(n, k, p - k_ - 1, stacks, start + 1, memo));
    }
    memo[start][p] = ans;
    return memo[start][p];
}

int main() {
    int t, n, k, p;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cin >> n >> k >> p;

        vector<vector<int>> stacks(n, vector<int>(k));
        for (int j = 0; j < n; ++j) {
            for (int k_ = 0; k_ < k; ++k_) {
                cin >> stacks[j][k_];
            }
            for (int k_ = 1; k_ < k; ++k_) {
                stacks[j][k_] += stacks[j][k_ - 1];;
            }
        }

        // int ans = 0;
        // pick(n, k, p, stacks, 0, 0, ans);
        // cout << "Case #" << i << ": " << ans << endl;

        vector<vector<int>> memo(n, vector<int>(p + 1, 0));
        pick(n, k, p, stacks, 0, memo);
        cout << "Case #" << i << ": " << memo[0][p] << endl;        
    }
    return 0;
}