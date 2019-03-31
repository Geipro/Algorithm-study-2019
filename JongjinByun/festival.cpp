#include <iostream>
#include<vector>
using namespace std;

vector<int> cost_day; //�Ϻ� �뿩 �ݾ�
double get_avg(int start_idx, int count); //��� �� ���ϱ�

int main()
{
	int count; //�� �ݺ� ȸ��
	cin >> count;
	int max_day, min_day; //�ִ� �ϼ�, �ּ� ���� �ϼ�

	vector<int> min_avg;
	double avg;
	double MIN = 0.0f; //���� �� �ּ� ��� ��

	if (count > 100)
	{
		cout << "�Է¹��� �ʰ�(100����)";
		return 0;
	}

	for (int i = 0; i < count; i++)
	{
		int nTmp; //�Ϻ� ���� �ӽ� ���� ����
		int sum = 0;//���Ϻ� ���� ���ϱ� ���� �ӽ� ����
		cin >> max_day >> min_day;
		if (max_day < 1 || max_day>1000)
		{
			cout << "�ִ� �뿩 �ϼ��� �̻��մϴ�(1~1000)";
			return 0;
		}
		else if (min_day<1 || min_day>max_day)
		{
			cout << "�ּ� ���� �ϼ��� �̻��մϴ�(1~MAX_DAY)";
			return 0;
		}
		vector< vector<double> > arr(max_day - min_day + 1, vector<double>(max_day - min_day + 1, 0)); //��հ��� �־� ���� �迭

		for (int i = 0; i < max_day; i++)
		{
			cin >> nTmp;
			cost_day.push_back(nTmp); //�Ϻ� �뿩�� �Է¹ޱ�
		}

		for (int i = 0; i < max_day - min_day + 1; i++)
		{
			for (int j = 0; j < max_day - min_day + 1 - i; j++)
			{
				arr[i][j] = get_avg(j, min_day + i); // �ּ� �뿩 �ϼ� ��ŭ ��� �迭�� ����
			}

		}
		MIN = arr[0][0]; //�ּҰ� �ʱ� ����

		for (int i = 0; i < max_day - min_day + 1; i++)
		{
			for (int j = 0; j < max_day - min_day + 1 - i; j++)
			{
				if (arr[i][j] < MIN)
					MIN = arr[i][j];
			}
		}
		printf("%.12f", MIN);
		cout << endl;

	}
}

double get_avg(int start_idx, int count)
{
	double sum = 0.0;
	double result = 0.0;
	for (int i = 0; i < count; i++)
	{
		sum += cost_day[start_idx + i];
	}
	result = sum / count;
	return result;
}

