#include <iostream>
#include <string>

using namespace std;

bool search_Next(char BOGGLE[][5], string voca, int now, int a, int b) {		//���ڷ� 2�����迭��, �־��� �ܾ�, ���� ������ ã�Ҵ�����, �迭 ��ġ�� �Ѱܹ���.
	while (voca.at(now + 1) != NULL) {									//�ܾ��� ���� ���ĺ��� NULL�� �ƴ� ������
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
		for (int a = 0; a < 5; a++) {									//2���� �迭�� �Է�
			for (int b = 0; b < 5; b++) {
				cin >> word;											
				BOGGLE[a][b] = word;
			}
		}

		cin >> N;

		for (int j = 0; j < N; j++) {										//�ܾ�� �Է�
			cin >> voca[j];

			for (int a = 0; a < 5; a++) {									//ù ���� ��ġã��.
				for (int b = 0; b < 5; b++) {
					if (BOGGLE[a][b] == voca[j].at(0)) {						//ù ���ڰ� �迭�� �ִٸ�
						if (search_Next(BOGGLE, voca[j], 0, a, b))				//���� ��ġ�� �Բ� �Լ� ȣ�� ����� false�� �ƴ϶��
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