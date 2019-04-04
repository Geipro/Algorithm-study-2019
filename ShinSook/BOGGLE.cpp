//���� while �� ���� �߸���. ������ ������ ����.
//+ 1�� ���� ��. ��Ͱ� ���� return �� �ϸ鼭 ������ �ȴ�.�� ���� loop�� ���� �͵鵵 �ִ� ��. ��... while���� �ʿ���� �� ������?
//+ 2�� ���� ��, ���ο��� ���� loop�� ���� ���� ���������, ����� �ټ� ������ ���� ����� �ȶ�. if�� ���ο��� now�� ���ϴ� ���� 2�� �ƴ϶� 1�̾ƴұ�?
//��... ���������� ���� ����� ���� �ʴ´�...... ��� �� ��, a,b�� �ٲپ���� ���� �ʴ�?  ->  �� ����� ������ �߳�?
//�� �Լ��� ��������� �Ǵ��ϴ� ���� �ƴ϶� flag�� ��������? ������ ����� ���� ��.  -> ���ڿ��� ���� �˾Ƴ��� ������ ������ ����ٸ�? ���� NULL�� �ƴ� ���ΰ�?
//���ڿ� ���� �Ǻ��ϴ� �� �κ��� �¾ҳ�����. YES��� ������ �߱� ������, ������ ������ ������� ������. �� ������ �Ʒ� IF���鿡�� ���� ��ȯ�� ����ϱ� �����ΰ�. ������?
//�ϴ� 5�� ���� ��, ������ ������ ���� ���� ��µǴ� ��Ȳ. �Ƹ��� ���� ��͸��� ���ϵǴ� ��Ȳ�� �޶��ΰ�? 
//���� �Ŀ� ���� ���� ���ڰ� �����ϴ����� ã�� ������ if������ �ʿ��Ѱ�? -> �ƴ� �̰� MAIN�� ������. 25�� �˻縦 �ϳ� ������ ���� �����Ͽ� ù ��ġ�� ������ �ξ �Լ��� �ۿ��� ��������.
//������ �������� ������ �����ϳ� ���� �ù�. ����. �������� for�� �ȿ��� ���� �߸��޳� ����
//�ذ��....�� �ε� ������, ���� ��� �̻��ϰ� �߳�;
//D�� ������ PANDORA�� �Ǵ� ������ ���� ���� ���� �̽��ε�?
//MAIN���� ���������� ã�� ù ������ ���ĺ����� ������ �ϴ� ���� �ƴϸ� �������� ��.  => �ذ�
//PANDORA�� ��� �� �����ε�...

#include <iostream>
#include <string>

using namespace std;
bool flag = false;																//search_NEXT �� ������� ������ FLAG

bool search_Next(char BOGGLE[][5], string voca, int now, int a, int b) {		//���ڷ� 2�����迭��, �־��� �ܾ�, ���� ������ ã�Ҵ�����, �迭 ��ġ�� �Ѱܹ���.
	if (a > 5 || a < 0 || b < 0 || b > 5)
		return false;

	if (voca.at(now) == voca[voca.size() - 1]) {								//���������� ã���� ��, true�� ������ ���ε�... �� PANDORA�� �߳İ� ����
		flag = true;
		return true;
	}

	if (BOGGLE[a][b - 1] == voca.at(now + 1))
		search_Next(BOGGLE, voca, now + 1, a, b - 1);
	else if (BOGGLE[a][b + 1] == voca.at(now + 1))
		search_Next(BOGGLE, voca, now + 1, a, b + 1);
	else if (BOGGLE[a - 1][b - 1] == voca.at(now + 1))
		search_Next(BOGGLE, voca, now + 1, a - 1, b - 1);
	else if (BOGGLE[a - 1][b] == voca.at(now + 1))
		search_Next(BOGGLE, voca, now + 1, a - 1, b);
	else if (BOGGLE[a - 1][b + 1] == voca.at(now + 1))
		search_Next(BOGGLE, voca, now + 1, a - 1, b + 1);
	else if (BOGGLE[a + 1][b - 1] == voca.at(now + 1))
		search_Next(BOGGLE, voca, now + 1, a + 1, b - 1);
	else if (BOGGLE[a + 1][b] == voca.at(now + 1))
		search_Next(BOGGLE, voca, now + 1, a + 1, b);
	else if (BOGGLE[a + 1][b + 1] == voca.at(now + 1))
		search_Next(BOGGLE, voca, now + 1, a + 1, b + 1);
	else
		return false;
	return false;
}

int main() {
	int C, N;
	int x, y;															//���� ��ġ�� ������ ����
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
					if (BOGGLE[a][b] == voca[j].at(0)) {					//ù ���ڰ� �迭�� �ִٸ�
						x = a, y = b;
						search_Next(BOGGLE, voca[j], 0, x, y);
					}
				}
			}
			if (flag)				//���� ��ġ�� �Բ� �Լ� ȣ�� ����� false�� �ƴ϶��
				cout << voca[j] << "  YES" << endl;
			else
				cout << voca[j] << "  NO" << endl;
			flag = false;			//flag �ʱ�ȭ
		}
	}
	return 0;
}