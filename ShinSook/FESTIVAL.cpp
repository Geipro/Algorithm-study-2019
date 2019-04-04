#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>

using namespace std;

double festival(vector<int> Cost, int n, int m) {
	float cheapest_cost = 100.0000000;								//�˻���� float�� ���е��� 6~9�ڸ�, double�� 15~18�ڸ�.
	float compare = 100.0000000;									//�񱳰�cout << std::setprecision(8);
	for (int i = m; i <= n; i++) {						//���� ����
		for (int j = 0; j < (n - i + 1); j++) {			//������ ���Ұ��� ���Ϳ� ����. (ex 0��° ����, 6���� 4��°����)
			int x = j;									//�Ʒ� �������� j���� �־���ϴµ�, ������ �ȿ� �־ j���� �߰����� �����Ƿ� ���ο��� ���Ҽ� �ֵ��� ��������
			vector<int> avg;
			for (int k = 0; k < i; k++) {				//0��°���� 3���� �ִ´ٸ� 0~2������ ���Ϳ� ����.    
				avg.push_back(Cost.at(x));
				x++;
			}
			compare = accumulate(avg.begin(), avg.end(), 0.0000000) / avg.size();
			if (compare < cheapest_cost)					//��
				cheapest_cost = compare;
			avg.clear();
		}
	}
	return cheapest_cost;
}

int main() {
	int C, n, m, cost;
	double cheapest = 0;									//�Լ����� �޾ƿ� �����
	cout << fixed;
	cout << std::setprecision(11);						//������ ���ڵ鿡 �ε��Ҽ��� ����(7�ڸ� ������ ��, 7���ϸ� ������ ��ٰ� ��.)

	cin >> C;

	vector<int> Cost;								//�뿩 ����� ���� ����

	for (int i = 0; i < C; i++) {
		cin >> n; cin >> m;

		for (int j = 0; j < n; j++) {
			cin >> cost;
			Cost.push_back(cost);						//���Ϳ� ��밪�� ����
		}
		cheapest = festival(Cost, n, m);				//�Լ� ����� ���� ��հ��� ����
		cout << cheapest << endl;
		Cost.clear();
	}

	return 0;
}