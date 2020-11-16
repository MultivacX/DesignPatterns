// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/0000000000337b4d

#include <iostream>
#include <vector>

using namespace std;

template<class T>
class segment_tree {
    const T n;
    vector<T> tree;

public:
    segment_tree(vector<T>& nums) : n(nums.size()), tree(nums.size() << 1, 0) {
        for (T i = 0; i < n; ++i)
            tree[n + i] = nums[i];
        for (T i = n - 1; i > 0; --i)
            tree[i] = tree[i << 1] + tree[i << 1 ^ 1];
    }

    void update(T i, T val) {
        for (T j = n + i, diff = val - tree[n + i]; j > 0; j >>= 1)
            tree[j] += diff;
    }

    T query(T l, T r) {
        T sum = 0;
        // [l, r)
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) sum += tree[l++];
            if (r & 1) sum += tree[--r];
        }
        return sum;
    }
};

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int64_t N, Q;
        cin >> N >> Q;

        // vector<int64_t> nums(N);
        vector<int64_t> nums1(N);
        vector<int64_t> nums2(N);
        for (int64_t i = 0; i < N; ++i) { 
            // cin >> nums[i];
            int64_t num; cin >> num;
            int64_t x = (i & 1) ? -1 : 1;
            nums1[i] = x * num;
            nums2[i] = x * num * (i + 1);
            // printf("(%d,%d), ", nums1[i], nums2[i]);
        }
        // cout << endl;

        segment_tree<int64_t> st1(nums1);
        segment_tree<int64_t> st2(nums2);

        int64_t ans = 0;
        // vector<vector<int64_t>> ops(Q, vector<int64_t>(3));
        for (int i = 0; i < Q; ++i) {
            // cin >> ops[i][0] >> ops[i][1] >> ops[i][2];
            char op; cin >> op;
            if (op == 'Q') {
                int l, r; cin >> l >> r;
                l -= 1;
                int64_t sum1 = st1.query(l, r);
                int64_t sum2 = st2.query(l, r);
                if (l & 1) ans += sum1 * l - sum2;
                else ans += sum2 - sum1 * l;
                // cout << sum1 << "," << sum2 << endl;
            } else {
                int idx, num; cin >> idx >> num;
                idx -= 1;
                int64_t x = (idx & 1) ? -1 : 1;
                int64_t num1 = x * num;
                int64_t num2 = x * num * (idx + 1);
                st1.update(idx, num1);
                st2.update(idx, num2);
            }
        }
        
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}