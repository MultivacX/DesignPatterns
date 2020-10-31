// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/00000000003380d2

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N);
        for (int i = 0; i < N; ++i) 
            cin >> A[i];

        int cnt = 0;
        int len = 0;
        for (int i = N - 1; i >= 0; --i) {
            if (A[i] == 1) {
                len = 1;
            } else if (len > 0 && A[i] == A[i + 1] + 1) {
                if (++len >= K) {
                    ++cnt;
                    len = 0;
                }
            } else {
                len = 0;
            }
        }
        
        cout << "Case #" << t << ": " << cnt << endl;
    }
    return 0;
}