// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/00000000003379bb

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int R, C;
        cin >> R >> C;

        vector<vector<char>> wall(R, vector<char>(C));
        vector<bool> types(26, false);
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                cin >> wall[i][j];
                types[wall[i][j] - 'A'] = true;
            }
        }

        vector<unordered_set<int>> predecessors(26);
        vector<unordered_set<int>> successors(26);
        for (int i = 0; i + 1 < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (wall[i][j] != wall[i + 1][j]) {
                    predecessors[wall[i][j] - 'A'].insert(wall[i + 1][j] - 'A');
                    successors[wall[i + 1][j] - 'A'].insert(wall[i][j] - 'A');
                }
            }
        }
                
        string ans;
        int cnt = 0;
        queue<int> q;
        for (int i = 0; i < 26; ++i) {
            if (!types[i]) continue;
            ++cnt;
            if (predecessors[i].empty()) q.push(i);
        }
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int pre = q.front(); q.pop();
                ans += (pre + 'A');
                
                for (int suc : successors[pre]) {
                    predecessors[suc].erase(pre);
                    if (predecessors[suc].empty())
                        q.push(suc);
                }
                successors[pre].clear();
            }
        }
        
        cout << "Case #" << t << ": " << (cnt == ans.length() ? ans : "-1") << endl;
    }
    return 0;
}