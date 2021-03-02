// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043adc7

#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N, K, S; cin >> N >> K >> S;

        int64_t opt1 = K - 1;
        opt1 += 1; // restart
        opt1 += N; // finish game

        int64_t opt2 = K - 1;
        opt2 += K - S; // back to S
        opt2 += N - S + 1; // finish game

        cout << "Case #" << t << ": " << min(opt1, opt2) << endl;
    }
    return 0;
}