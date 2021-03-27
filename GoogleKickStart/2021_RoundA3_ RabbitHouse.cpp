// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000436140/000000000068cb14
// Rabbit House

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

/*int diff(const vector<vector<int>>& cells, int i, int j) {
    const int R = cells.size();
    const int C = cells[0].size();

    int d = 0;
    if (i > 0) d = max(d, cells[i - 1][j] - cells[i][j]);
    if (j > 0) d = max(d, cells[i][j - 1] - cells[i][j]);
    if (i + 1 < R) d = max(d, cells[i + 1][j] - cells[i][j]);
    if (j + 1 < C) d = max(d, cells[i][j + 1] - cells[i][j]);
    return d;
}*/

// WA
/*int using_priority_queue(vector<vector<int>>& cells) {
    const int R = cells.size();
    const int C = cells[0].size();

    auto cmp = [&cells](const array<int, 2>& l, const array<int, 2>& r){
        return diff(cells, l[0], l[1]) < diff(cells, r[0], r[1]);
    };
    priority_queue<array<int, 2>, vector<array<int, 2>>, decltype(cmp)> q(cmp);

    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (diff(cells, i, j) > 1)
                q.push({i, j});

    int ans = 0;
    while (!q.empty()) {
        int i = q.top()[0], j = q.top()[1]; q.pop();
        int d = diff(cells, i, j);
        if (d > 1) cells[i][j] += d - 1, ans += d - 1;

        static const array<int, 5> directions = {0, 1, 0, -1, 0};
        for (int k = 0; k < 4; ++k) {
            int ni = i + directions[k], nj = j + directions[k + 1];
            if (ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
            if (diff(cells, ni, nj) > 1) q.push({ni, nj});
        }
    }
    return ans;
}*/

// MLE
/*int bfs(vector<vector<int>>& cells) {
    const int R = cells.size();
    const int C = cells[0].size();

    queue<int> q;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (diff(cells, i, j) > 1)
                q.push(i * C + j);

    int ans = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size-- > 0) {
            int i = q.front() / C, j = q.front() % C; q.pop();
            int d = diff(cells, i, j);
            if (d > 1) cells[i][j] += d - 1, ans += d - 1;

            static const vector<int> directions{0, 1, 0, -1, 0};
            for (int k = 0; k < 4; ++k) {
                int ni = i + directions[k], nj = j + directions[k + 1];
                if (ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
                if (diff(cells, ni, nj) > 1) q.push(ni * C + nj);
            }
        }
    }
    return ans;
}*/

int64_t using_priority_queue(const vector<vector<int>>& cells) {
    const int R = cells.size();
    const int C = cells[0].size();

    priority_queue<tuple<int, int, int>> q;

    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
                q.push({cells[i][j], i, j});

    vector<vector<int>> tmp(cells);
    while (!q.empty()) {
        auto [h, i, j] = q.top(); q.pop();
        if (h < tmp[i][j]) continue;
        
        static const array<int, 5> directions = {0, 1, 0, -1, 0};
        for (int k = 0; k < 4; ++k) {
            int ni = i + directions[k], nj = j + directions[k + 1];
            if (ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
            if (h - 1 > tmp[ni][nj]) {
                q.push({h - 1, ni, nj});
                tmp[ni][nj] = h - 1;
            }
        }
    }

    int64_t ans = 0;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            ans += tmp[i][j] - cells[i][j];
    return ans;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int R, C; cin >> R >> C;
        
        vector<vector<int>> cells(R, vector<int>(C));
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                cin >> cells[i][j];

        int64_t ans = using_priority_queue(cells);
    
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}