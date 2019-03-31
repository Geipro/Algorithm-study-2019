#include <iostream>
#include<vector>
using namespace std;

vector<int> cost_day; //일별 대여 금액
double get_avg(int start_idx, int count); //평균 값 구하기

int main()
{
	int count; //총 반복 회수
	cin >> count;
	int max_day, min_day; //최대 일수, 최소 참가 일수

	vector<int> min_avg;
	double avg;
	double MIN = 0.0f; //리턴 할 최소 평균 값

	if (count > 100)
	{
		cout << "입력범위 초과(100이하)";
		return 0;
	}

	for (int i = 0; i < count; i++)
	{
		int nTmp; //일별 가격 임시 저장 변수
		int sum = 0;//요일별 합을 구하기 위한 임시 변수
		cin >> max_day >> min_day;
		if (max_day < 1 || max_day>1000)
		{
			cout << "최대 대여 일수가 이상합니다(1~1000)";
			return 0;
		}
		else if (min_day<1 || min_day>max_day)
		{
			cout << "최소 참가 일수가 이상합니다(1~MAX_DAY)";
			return 0;
		}
		vector< vector<double> > arr(max_day - min_day + 1, vector<double>(max_day - min_day + 1, 0)); //평균값들 넣어 놓는 배열

		for (int i = 0; i < max_day; i++)
		{
			cin >> nTmp;
			cost_day.push_back(nTmp); //일별 대여료 입력받기
		}

		for (int i = 0; i < max_day - min_day + 1; i++)
		{
			for (int j = 0; j < max_day - min_day + 1 - i; j++)
			{
				arr[i][j] = get_avg(j, min_day + i); // 최소 대여 일수 만큼 묶어서 배열에 삽입
			}

		}
		MIN = arr[0][0]; //최소값 초기 설정

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

