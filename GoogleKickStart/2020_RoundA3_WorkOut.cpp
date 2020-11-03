// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f5b

#include <iostream>
#include <vector>
// #include <queue>
#include <algorithm>
using namespace std;

// Test set 1 passed
// Test set 2 TLE
/*iint addSessions(const vector<int>& d, int k, int idx, vector<vector<int>>& memo) {
    if (d.size() <= idx) return 1;
    if (memo[idx][k] != 0) return memo[idx][k];

    int ans = d[idx];
    for (int i = 1; i <= k && i <= d[idx] - 1; ++i) {
        int a = d[idx] / (i + 1);
        a = max(a, d[idx] - a * i);
        a = max(a, addSessions(d, k - i, idx + 1, memo));
        ans = min(ans, a);
    }
    memo[idx][k] = ans;
    return ans;
}

int main() {
    int t, n, k, p;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cin >> n >> k;

        vector<int> d;
        int a;
        cin >> a;
        for (int j = 1; j < n; ++j) {
            int b;
            cin >> b;
            if (b - a > 1) d.push_back(b - a);
            a = b; 
        }
        sort(rbegin(d), rend(d));

        vector<vector<int>> memo(n, vector<int>(k + 1));
        int ans = addSessions(d, k, 0, memo);

        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}*/

// M : sessions
// K : additional training sessions
// D : target difficulty
bool check(vector<int>& M, int K, int D) {
    int m = M[0];
    int used = 0;
    for (int i = 1; i < M.size(); ++i) {
        int d = M[i] - m;
        if (d > D) {
            // try to add sessions betweent [m, M[i]]
            used += (d - 1) / D;
            // can not add more
            // need a greater D
            if (used > K) return false;
        }
        m = M[i];
    }
    // found D or need a less D
    return true;
}

int find(vector<int>& v, int k, int l, int r) {
    while (l < r) {
        int m = l + (r - l) / 2;
        if (check(v, k, m)) r = m;
        else l = m + 1;
    }
    return l;
}

int main() {
    int t, n, k, p;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cin >> n >> k;

        int max_d = 0;
        vector<int> v(n);
        for (int j = 0; j < n; ++j) {
            cin >> v[j];
            if (j > 0) max_d = max(max_d, v[j] - v[j - 1]);
        }
        
        cout << "Case #" << i << ": " << find(v, k, 1, max_d + 1) << endl;
    }
    return 0;
}