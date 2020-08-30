#include <iostream> // includes cin to read from stdin and cout to write to stdout
#include <vector>
#include <algorithm>
using namespace std; // since cin and cout are both in namespace std, this saves some text
int main() {
    int t, n, b;
    cin >> t; // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 1; i <= t; ++i) {
        cin >> n >> b; // read n and then m.
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