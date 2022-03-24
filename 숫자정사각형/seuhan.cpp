#include <iostream>
#include <string>
#define MAX 50
using namespace std;

int main() {
    int N, M, res = 1;
    cin >> N >> M;

    int square[MAX][MAX];

    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < M; j++) {
            square[i][j] = (tmp[j] - '0');
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = M - 1; j >= 0; j--) {
            for (int width = 1; width <= min(M, N); width++) {
                if ((i + width < N) && (j + width < M) &&
                    (square[i][j] == square[i][j + width]) &&
                    (square[i][j] == square[i + width][j]) &&
                    (square[i][j] == square[i + width][j + width])) {
                    if (res <= ((width + 1) * (width + 1))) {
                        res = (width + 1) * (width + 1);
                    }
                }
            }
        }
    }
    cout << res;
}