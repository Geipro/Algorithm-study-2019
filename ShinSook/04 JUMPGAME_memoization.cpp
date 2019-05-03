nclude <iostream>
#include <cstring>

using namespace std;
int n, board[100][100], cache[100][100];										//함수와 main에서 사용하는 것 전역으로 선언

int jumpgame(int h, int w) {
	if (h >= n || w >= n) return 0;
	if (h == n - 1 && w == n - 1) return 1;
	int& ret = cache[h][w];
	if (ret != -1) return ret;

	return ret = (jumpgame(h + board[h][w], w) || jumpgame(h, w + board[h][w]));
}

int main() {
	int C, numb;
	cin >> C;

	for (int i = 0; i < C; i++) {
		cin >> n;

		for (int h = 0; h < n; h++) {						//게임판에 숫자입력.
			for (int w = 0; w < n; w++) {
				cin >> numb;
				board[h][w] = numb;
			}
		}
		memset(cache, -1, sizeof(cache));					//배열초기화
		int test = jumpgame(0, 0);
		if (test)							//재귀호출
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}