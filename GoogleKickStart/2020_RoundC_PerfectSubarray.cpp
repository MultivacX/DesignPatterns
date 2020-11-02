// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/00000000003381cb

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;

        // {prefixSum, count}
        unordered_map<int, int64_t> M; M[0] = 1;
        
        int64_t cnt = 0;
        for (int i = 0, min_prefix = 0, prefix = 0; i < N; ++i) {
            int a; cin >> a;
            prefix += a;

            for (int j = 0; j * j <= prefix - min_prefix; ++j) 
                if (M.count(prefix - j * j)) cnt += M[prefix - j * j];
            
            min_prefix = min(min_prefix, prefix);
            ++M[prefix];
        }
        
        cout << "Case #" << t << ": " << cnt << endl;
    }
    return 0;
}