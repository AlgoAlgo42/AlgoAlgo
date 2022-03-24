#include <iostream>

using namespace std;

int N, r, c;
int ans;

void Z(int size, int x, int y) {
    if (y == r && x == c) {
        cout << ans << '\n';
        return;
    }

    if (r < y + size && r >= y && c < x + size && c >= x) {
        Z(size / 2, x, y);
        Z(size / 2, x + size / 2, y);
        Z(size / 2, x, y + size / 2);
        Z(size / 2, x + size / 2, y + size / 2);
    } else {
        ans += size * size;
    }
}
int main() {
    cin >> N >> r >> c;
    Z((1 << N), 0, 0);
    return 0;
}