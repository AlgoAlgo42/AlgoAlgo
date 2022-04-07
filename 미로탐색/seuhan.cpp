#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int arr[101][101] = {
    0,
};
bool visit[101][101] = {
    false,
};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(int x, int y, int cnt) {
    queue<pair<pair<int, int>, int> > que;
    que.push(make_pair(make_pair(x, y), cnt));

    while (!que.empty()) {
        x = que.front().first.first;
        y = que.front().first.second;
        cnt = que.front().second;
        que.pop();

        if (x == N - 1 && y == M - 1)
            return cnt;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (arr[nx][ny] == 1 && !visit[nx][ny]) {
                visit[nx][ny] = true;
                que.push(make_pair(make_pair(nx, ny), cnt + 1));
            }
        }
    }
    return 0;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++)
            arr[i][j] = temp[j] - '0';
    }
    visit[0][0] = true;
    cout << bfs(0, 0, 1) << endl;
    return 0;
}