// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000436140/000000000068cca3
// K-Goodness String

#include <iostream>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N, K; string S; cin >> N >> K >> S;

        int i = 0, j = N - 1, k = 0;
        while (i < j) 
            if (S[i++] != S[j--]) 
                ++k;
        
        cout << "Case #" << t << ": " << abs(K - k) << endl;
    }
    return 0;
}