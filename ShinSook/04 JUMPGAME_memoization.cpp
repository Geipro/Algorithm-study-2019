nclude <iostream>
#include <cstring>

using namespace std;
int n, board[100][100], cache[100][100];										//�Լ��� main���� ����ϴ� �� �������� ����

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

		for (int h = 0; h < n; h++) {						//�����ǿ� �����Է�.
			for (int w = 0; w < n; w++) {
				cin >> numb;
				board[h][w] = numb;
			}
		}
		memset(cache, -1, sizeof(cache));					//�迭�ʱ�ȭ
		int test = jumpgame(0, 0);
		if (test)							//���ȣ��
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}