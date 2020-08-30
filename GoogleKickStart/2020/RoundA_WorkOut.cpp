#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Test set 1 passed
// Test set 2 wrong answer
int main() {
    int t, n, k, p;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cin >> n >> k;

        priority_queue<int> q;
        int a;
        cin >> a;
        for (int j = 1; j < n; ++j) {
            int b;
            cin >> b;
            q.push(b - a);
            a = b; 
        }

        while (k-- > 0) {
            int v = q.top();
            q.pop();
            int a = v / 2;
            q.push(a);
            q.push(v - a);
        }
        cout << "Case #" << i << ": " << q.top() << endl;
    }
    return 0;
}