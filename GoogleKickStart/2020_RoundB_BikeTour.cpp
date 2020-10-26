// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d82e6

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T, N;
    cin >> T;

    for (int i = 1; i <= T; ++i) {
        cin >> N;

        vector<int> H(N);
        for (int j = 0; j < N; ++j) {
            cin >> H[j];
        }

        int ans = 0;
        for (int j = 1; j < N - 1; ++j) {
            if (H[j - 1] < H[j] && H[j] > H[j + 1]) {
                ++ans;
            }
        }
        
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}