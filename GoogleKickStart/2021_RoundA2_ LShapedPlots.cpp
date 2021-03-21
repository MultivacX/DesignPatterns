// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000436140/000000000068c509
// L Shaped Plots

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findLShapes(int x, int y) {
    if (x < 2 || y < 2) return 0;

    auto count = [](int a, int b) -> int {
        if (a < 4) return 0;
        return min(a / 2, b) - 1;
    };
    
    return count(x, y) + count(y, x);
    
    /*int ans = 0;
    int i = 2;
    while (i <= x && i * 2 <= y) {
        ++ans;
        ++i;
    }
    i = 2;
    while (i * 2 <= x && i <= y) {
        ++ans;
        ++i;
    }
    return ans;*/
}

int main() {
    int T;
    cin >> T;

    for (int c = 1; c <= T; ++c) {
        int R, C; cin >> R >> C;
        vector<vector<uint8_t>> matrix(R, vector<uint8_t>(C));

        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                cin >> matrix[i][j];

        vector<vector<uint16_t>> l(R, vector<uint16_t>(C));
        vector<vector<uint16_t>> t(R, vector<uint16_t>(C));
        vector<vector<uint16_t>> r(R, vector<uint16_t>(C));
        vector<vector<uint16_t>> b(R, vector<uint16_t>(C));

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (matrix[i][j] == '0') continue;
                l[i][j] = 1 + (j > 0 ? l[i][j - 1] : 0);
                t[i][j] = 1 + (i > 0 ? t[i - 1][j] : 0);
            }
        }

        for (int i = R - 1; i >= 0; --i) {
            for (int j = C - 1; j >= 0; --j) {
                if (matrix[i][j] == '0') continue;
                r[i][j] = 1 + (j + 1 < C ? r[i][j + 1] : 0);
                b[i][j] = 1 + (i + 1 < R ? b[i + 1][j] : 0);
            }
        }

        int ans = 0;
        for (int i = 0; i < R; ++i) 
            for (int j = 0; j < C; ++j) 
                ans += findLShapes(l[i][j], t[i][j]) + 
                       findLShapes(t[i][j], r[i][j]) + 
                       findLShapes(r[i][j], b[i][j]) + 
                       findLShapes(b[i][j], l[i][j]);
        
        cout << "Case #" << c << ": " << ans << endl;
    }
    return 0;
}
