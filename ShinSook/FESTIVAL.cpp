#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>

using namespace std;

int festival(vector<int> Cost, int n, int m) {
	float cheapest_cost = 100;								//�˻���� float�� ���е��� 6~9�ڸ�, double�� 15~18�ڸ�.
	float compare = 0;										//�񱳰�
	vector<int> avg;
	for (int i = m; i <= n; i++) {																	//���� ����
		for (int j = 0; j < (n - i + 1); j++) {														//������ ���Ұ��� ���Ϳ� ����. 
			for (int k = 0; k < i; k++) {
				avg.push_back(Cost.at(j));
			}
			
			/*for (int k = 0; k < ; k++) {															//���Ϳ� �־ ��հ� ����
				
			}
			*/
		}
		compare = accumulate(avg.begin(), avg.end(), 0.0) / avg.size();
		if (cheapest_cost > compare)					//��
			cheapest_cost = compare;
		avg.clear();
	}
}

int main() {
	int C, n, m, cost;
	float cheapest_cost = 100;								//�˻���� float�� ���е��� 6~9�ڸ�, double�� 15~18�ڸ�.
	float compare = 0;										//�񱳰�
	cout << std::setprecision(8);							//������ ���ڵ鿡 �ε��Ҽ��� ����
	vector<int> Cost;										//�뿩 ����� ���� ����

	cin >> C; 

	for (int i = 0; i < C; i++) {
		cin >> n; cin >> m;
		for (int j = 0; j < n; j++) {
			cin >> cost;
			Cost.push_back(cost);							//���Ϳ� ��밪�� ����
			compare = festival(Cost, n, m);					//�Լ� ����� ���� ��հ��� ����
			if (cheapest_cost > compare)					//��
				cheapest_cost = compare;
		}
	}
	cout << cheapest_cost << endl;

	return 0;
}