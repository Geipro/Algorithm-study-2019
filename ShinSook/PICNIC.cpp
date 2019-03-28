#include <iostream>

using namespace std;

int C, n, m, f1, f2;
bool fr[10][10];							//ģ�� ���踦 ��Ÿ���� 2���� �迭

int count(bool student[10]) {
	int countN = 0, flag = -1;
	for (int i = 0; i < n; i++) {
		if (!student[i]) {					//¦�̾��ٸ�
			flag = i;
			break;
		}
	}
	if (flag == -1)							//¦�� �ִٸ�
		return 1;
	for (int i = flag + 1; i < n; i++) {
		if (!student[i] && fr[flag][i]) {	//¦�̾��� & ģ���� ���
			student[flag] = true;
			student[i] = true;
			countN += count(student);		//���
			student[flag] = false;
			student[i] = false;
		}
	}
	return countN;
}

int main()
{
	int countN = 0;
	bool flag = true;
	bool stu[10];								//¦�� �Ǿ����� ��Ÿ���� �迭
	cin >> C;									//��� �׽�Ʈ���̽����� C

	for (int i = 0; i < C; i++) {				//���� i��°
		cin >> n >> m;							//�л� �� n�� ģ���ǰ�� m�� C for����ŭ

		for (int h = 0; h < 10; h++) {			//2���� �迭 �ʱ�ȭ
			for (int j = 0; j < 10; j++)
				fr[h][j] = false;
			stu[h] = false;						//stu �迭 �ʱ�ȭ
		}

		for (int j = 0; j < m; j++) {			//2���� �迭 �� ����
			cin >> f1 >> f2;
			fr[f1][f2] = true;					//2���� �迭�� ģ�� �� �ֱ���� m for�� ��ŭ
			fr[f2][f1] = true;
		}
		countN = count(stu);
		cout << countN << endl;

	}


	return 0;
}