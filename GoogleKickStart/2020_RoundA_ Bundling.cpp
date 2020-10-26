// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3ff3

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Trie {
public:
    Trie(char val_ = '\0', int len_ = 0, int cnt_ = 0)
    : val(val_), len(len_), cnt(cnt_) {}
    char val;
    int len;
    int cnt;
    unordered_map<char, Trie*> children;
};

class Solution {
    Trie root;
    int K;
    int ans = 0;

    void buildTrie(const string& str, int i, Trie* node) {
        if (!node->children.count(str[i]))
            node->children.emplace(str[i], new Trie(str[i], i + 1));
        auto child = node->children[str[i]];
        ++child->cnt;
        if (i + 1 < str.length())
            buildTrie(str, i + 1, child);
    }

    int visit(Trie* node) {
        int used = 0;
        for (auto it : node->children)
            used += visit(it.second);
        node->children.clear();
        if (node->cnt - used >= K) {
            int t = (node->cnt - used) / K;
            used += t * K;
            ans += t * node->len;
        }
        node->cnt -= used;
        return used;
    }

public:
    int bundling(int N, int K_, vector<string>& strs) {
        for (const auto& str : strs)
            buildTrie(str, 0, &root);
        K = K_;
        visit(&root);
        return ans;
    }
};

int main() {
    int T, N, K;
    cin >> T;

    for (int i = 1; i <= T; ++i) {
        cin >> N >> K;

        vector<string> strs(N);
        for (int j = 0; j < N; ++j) {
            cin >> strs[j];
        }
        
        cout << "Case #" << i << ": " << Solution().bundling(N, K, strs) << endl;
    }
    return 0;
}