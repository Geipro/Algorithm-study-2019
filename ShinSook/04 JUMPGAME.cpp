#include <iostream>

using namespace std;
int n, board[100][100];										//함수와 main에서 사용하는 것 전역으로 선언
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

		for (int h = 0; h < n; h++) {						//게임판에 숫자입력.
			for (int w = 0; w < n; w++) {
				cin >> numb;
				board[h][w] = numb;
			}
		}
		func_flag = false;									//전역으로 선언한 func_flag 초기화
		flag = jumpgame(0, 0);								//재귀함수 호출

		if (flag == true)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		flag = false;										//주기마다 flag는 flase로 초기화
	}
	return 0;
}