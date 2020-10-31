// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d8565

#include <iostream>
#include <vector>

using namespace std;

double wandering(int W, int H, int L, int U, int R, int D) {
    // P(w, 1) = 0.5 ^ (w - 1), w = [1, W]
    // P(1, h) = 0.5 ^ (h - 1), h = [1, H]
    // P(w, h) = P(w - 1, h) * 0.5 + P(w, h - 1) * 0.5

    vector<double> dp(W + 1, 0);
    dp[1] = 1;
    for (int h = 1; h <= H; ++h) {
        for (int w = 1; w <= W; ++w) {
            if (h == 1 && w == 1) continue;

            if (U <= h && h <= D && L <= w && w <= R) dp[w] = 0;
            else {
                double fromLeft = h == H ? 1 : 0.5;
                double fromUp = w == W ? 1 : 0.5;
                dp[w] = dp[w - 1] * fromLeft + dp[w] * fromUp;
            }
            // printf("%1.4f ", dp[w]);
        }    
        // cout << endl;
    }
    return dp[W];
}

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; ++i) {
        int W, H, L, U, R, D;
        cin >> W >> H >> L >> U >> R >> D;
        
        cout << "Case #" << i << ": " << wandering(W, H, L, U, R, D) << endl;
    }
    return 0;
}