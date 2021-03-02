// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000387174

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int K; cin >> K;
        vector<int> A(K); for (int i = 0; i < K; ++i) cin >> A[i];

        // idx : [0, K)
        // note : {0, 1, 2, 3}
        // {idx, note} : A[0] -> 0
        // break : {i-1, 0} & A[i-1] > A[i]
        // break : {i-1, 3} & A[i-1] < A[i]

        int ans = 0;
        int note = 0; 
        int i = 1;
        while (i < K) {
            if (A[i - 1] == A[i]) continue;

        }

        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}