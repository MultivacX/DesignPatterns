// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000387171

#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;

        int cur;
        cin >> cur;
        if (N == 1) {
            cout << "Case #" << t << ": " << 1 << endl;
            continue;
        }

        int cnt = 0;
        int maxv = cur;
        for (int i = 0; i < N; ++i) {
            int nxt;
            if (i == 0) {
                cin >> nxt;
                if (cur > nxt) ++cnt;
            } else if (i + 1 == N) {
                if (cur > maxv) ++cnt;
            } else {
                cin >> nxt;
                if (cur > maxv && cur > nxt) ++cnt;
                maxv = max(maxv, cur);
            }
            cur = nxt;
        }

        cout << "Case #" << t << ": " << cnt << endl;
    }

    return 0;
}