// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d83bf

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T, N;
    int64_t D;
    cin >> T;

    for (int i = 1; i <= T; ++i) {
        cin >> N >> D;

        vector<int64_t> X(N);
        for (int j = 0; j < N; ++j) {
            cin >> X[j];
        }

        int64_t d = D;
        for (int j = N - 1; j >= 0; --j) {
            // d = (d / X[j]) * X[j];
            d = d - d % X[j];
        }
        
        cout << "Case #" << i << ": " << d << endl;
    }
    return 0;
}