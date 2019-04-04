#include <iostream>
#include <string>

using namespace std;

bool search_Next(char BOGGLE[][5], string voca, int now, int a, int b) {		//인자로 2차원배열판, 주어진 단어, 현재 어디까지 찾았는지와, 배열 위치를 넘겨받음.
	while (voca.at(now + 1) != NULL) {									//단어의 다음 알파벳이 NULL이 아닐 때까지
		if (b - 1 > 0) {
			if (BOGGLE[a][b - 1] == voca.at(now + 1))
				search_Next(BOGGLE, voca, now + 2, a, b);
		}
		if (b + 1 < 5) {
			if (BOGGLE[a][b + 1] == voca.at(now + 1))
				search_Next(BOGGLE, voca, now + 2, a, b);
		}
		if (a - 1 > 0 || b - 1 > 0) {
			if (BOGGLE[a - 1][b - 1] == voca.at(now + 1))
				search_Next(BOGGLE, voca, now + 2, a, b);
		}
		if (a - 1 > 0) {
			if (BOGGLE[a - 1][b] == voca.at(now + 1))
				search_Next(BOGGLE, voca, now + 2, a, b);
		}
		if (a - 1 > 0 || b + 1 < 5 ) {
			if (BOGGLE[a - 1][b + 1] == voca.at(now + 1))
				search_Next(BOGGLE, voca, now + 2, a, b);
		}
		if (a + 1 < 5 || b - 1 > 0) {
			if (BOGGLE[a + 1][b - 1] == voca.at(now + 1))
				search_Next(BOGGLE, voca, now + 2, a, b);
		}
		if (a + 1 < 5) {
			if (BOGGLE[a + 1][b] == voca.at(now + 1))
				search_Next(BOGGLE, voca, now + 2, a, b);
		}
		if (a + 1 < 5 || b + 1 < 0) {
			if (BOGGLE[a + 1][b + 1] == voca.at(now + 1))
				search_Next(BOGGLE, voca, now + 2, a, b);
		}

	}
	if (voca.at(now + 1) == NULL)
		return true;
	return false;
}

int main() {
	int C, N;
	char word;
	string voca[10];
	cin >> C;
	char BOGGLE[5][5] = { NULL };

	for (int i = 0; i < C; i++) {
		for (int a = 0; a < 5; a++) {									//2차원 배열에 입력
			for (int b = 0; b < 5; b++) {
				cin >> word;											
				BOGGLE[a][b] = word;
			}
		}

		cin >> N;

		for (int j = 0; j < N; j++) {										//단어들 입력
			cin >> voca[j];

			for (int a = 0; a < 5; a++) {									//첫 글자 위치찾기.
				for (int b = 0; b < 5; b++) {
					if (BOGGLE[a][b] == voca[j].at(0)) {						//첫 글자가 배열에 있다면
						if (search_Next(BOGGLE, voca[j], 0, a, b))				//현재 위치와 함께 함수 호출 결과가 false가 아니라면
							cout << voca[j] << "  YES" << endl;
						else
							cout << voca[j] << "  NO" << endl;
					}
					else
						cout << voca[j] << "  NO" << endl;
				}
			}
		}
	}
	return 0;
}