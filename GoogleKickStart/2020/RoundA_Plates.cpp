#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Test sets passe
// TLE
void pick(int n, int k, int p, vector<vector<int>>& stacks, int start, int val, int& ans) {
    if (p == 0) {
        ans = max(ans, val);
        return;
    }

    for (int i = start; i < n; ++i) {
        for (int k_ = 0; k_ < k && p - k_ - 1 >= 0; ++k_) {
            pick(n, k, p - k_ - 1, stacks, i + 1, val + stacks[i][k_], ans);
        }
    }
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

        int ans = 0;
        pick(n, k, p, stacks, 0, 0, ans);

        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}