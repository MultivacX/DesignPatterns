#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int t, n, b;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cin >> n >> b;
        vector<int> a(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }
        
        sort(begin(a), end(a));
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            if (b >= a[j]) {
                b -= a[j];
                ++ans;
            } else {
                break;
            }
        }
        
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}