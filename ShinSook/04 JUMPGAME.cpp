#include <iostream>

using namespace std;
int n, board[100][100];										//�Լ��� main���� ����ϴ� �� �������� ����
bool func_flag;

bool jumpgame(int h, int w) {
	if (h >= n || w >= n) return false;
	if (func_flag == true) return true;
	if (h == n - 1 && w == n - 1) {
		func_flag = true;
		return true;
	}
	return jumpgame(h + board[h][w], w) || jumpgame(h, w + board[h][w]);
}

int main() {
	int C, numb;
	bool flag = false;
	cin >> C;

	for (int i = 0; i < C; i++) {
		cin >> n;

		for (int h = 0; h < n; h++) {						//�����ǿ� �����Է�.
			for (int w = 0; w < n; w++) {
				cin >> numb;
				board[h][w] = numb;
			}
		}
		func_flag = false;									//�������� ������ func_flag �ʱ�ȭ
		flag = jumpgame(0, 0);								//����Լ� ȣ��

		if (flag == true)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		flag = false;										//�ֱ⸶�� flag�� flase�� �ʱ�ȭ
	}
	return 0;
}