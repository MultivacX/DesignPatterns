// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043b0c6

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

// [1, maxNum]
bool countBoring(uint64_t maxNum, const string& str, int idx, uint64_t curNum, vector<uint64_t>& digits) {
    const int n = str.length();
    if (idx >= n) return maxNum >= curNum;
    if (maxNum < curNum) return false;

    int v = str[idx] - '0';
    if (((idx + 1) & 1) != (v & 1)) v -= 1;
    if (v < 0) v += 10;
    if (v == 0 && idx == 0) return false;

    for (int d = v; d >= 0; d -= 2) {
        digits.push_back(d);
        if (countBoring(maxNum, str, idx + 1, curNum * 10 + d, digits)) return true;
        digits.pop_back();
    }
    
    return false;
}

// [1, 9...9]
uint64_t countBoring(uint64_t len) {
    return len == 0 ? 0 : (pow(5, len + 1) - 1) / (5 - 1) - 1;
}

uint64_t countDigits(const vector<uint64_t>& digits) {
    static const vector<uint64_t> counts{1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    const int n = digits.size();
    uint64_t cnt = counts[digits[n - 1]];
    for (int i = n - 2, c = 5; i >= 0; --i, c *= 5) {
        int d = digits[i] - 2;
        if (i == 0 && d == 0) break;
        if (d < 0) continue;
        cnt += counts[d] * c;
    }
    return cnt;
}

uint64_t countBoring(uint64_t maxNum, const string& str) {
    uint64_t cnt = countBoring(str.length() - 1);
    vector<uint64_t> digits;
    if (countBoring(maxNum, str, 0, 0, digits))
        cnt += countDigits(digits);
    return cnt;
}

bool isBoring(const string& str) {
    const int n = str.length();
    for (int i = 1; i <= n; ++i) {
        int v = str[i - 1] - '0';
        if ((i & 1) != (v & 1))
            return false;
    }
    return true;
}

int main() {
#define TEST_2021
#ifdef TEST_2021
    vector<vector<uint64_t>> testcases{
        {5, 15},
        {120, 125},
        {779, 783}
    };
    int T = testcases.size();
#else
    int T;
    cin >> T;
#endif

    for (int t = 1; t <= T; ++t) {
#ifdef TEST_2021
        uint64_t L = testcases[t - 1][0], R = testcases[t - 1][1];
#else
        uint64_t L, R; cin >> L >> R;
#endif

        string ls(to_string(L)); vector<uint64_t> ld;
        string rs(to_string(R)); vector<uint64_t> rd;

        uint64_t ans = countBoring(R, rs) - countBoring(L, ls) + isBoring(ls);

        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
