#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>

using namespace std;

float festival(vector<int> Cost, int n, int m) {
	float cheapest_cost = 100;								//�˻���� float�� ���е��� 6~9�ڸ�, double�� 15~18�ڸ�.
	float compare = 100;									//�񱳰�
	cout << std::setprecision(8);							//������ ���ڵ鿡 �ε��Ҽ��� ����(7�ڸ� ������ ��, 7���ϸ� ������ ��ٰ� ��.)

	vector<int> avg;
	for (int i = m; i <= n; i++) {																//���� ����
		for (int j = 0; j < (n - i + 1); j++) {													//������ ���Ұ��� ���Ϳ� ����. (ex 0��° ����, 6���� 4��°����)
			for (int k = 0; k < i; k++) {														//0��°���� 3���� �ִ´ٸ� 0~2������ ���Ϳ� ����.    
				avg.push_back(Cost.at(j));														// <- ����ƴϸ�
			}
			compare = accumulate(avg.begin(), avg.end(), 0.0000000) / avg.size();               // <-���Ⱑ ����
			if (compare < cheapest_cost)					//��
				cheapest_cost = compare;
			avg.clear();
		}
	}

	return cheapest_cost;
}

int main() {
	int C, n, m, cost;
	float cheapest = 0;									//�Լ����� �޾ƿ� �����
	cout << std::setprecision(8);						//������ ���ڵ鿡 �ε��Ҽ��� ����(7�ڸ� ������ ��, 7���ϸ� ������ ��ٰ� ��.)
	vector<int> Cost;								    //�뿩 ����� ���� ����

	cin >> C;

	for (int i = 0; i < C; i++) {
		cin >> n; cin >> m;
		for (int j = 0; j < n; j++) {
			cin >> cost;
			Cost.push_back(cost);						//���Ϳ� ��밪�� ����
		}
		cheapest = festival(Cost, n, m);				//�Լ� ����� ���� ��հ��� ����
		cout << cheapest << endl;
	}

	return 0;
}