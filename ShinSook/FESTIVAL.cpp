#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>

using namespace std;

float festival(vector<int> Cost, int n, int m) {
	float cheapest_cost = 100;								//검색결과 float의 정밀도는 6~9자리, double은 15~18자리.
	float compare = 100;									//비교값
	cout << std::setprecision(8);							//나오는 숫자들에 부동소수점 설정(7자리 이하일 시, 7로하면 에러가 뜬다고 함.)

	vector<int> avg;
	for (int i = m; i <= n; i++) {																//더할 개수
		for (int j = 0; j < (n - i + 1); j++) {													//어디부터 더할건지 벡터에 삽입. (ex 0번째 부터, 6개중 4번째부터)
			for (int k = 0; k < i; k++) {														//0번째부터 3개만 넣는다면 0~2번까지 벡터에 넣음.    
				avg.push_back(Cost.at(j));														// <- 여기아니면
			}
			compare = accumulate(avg.begin(), avg.end(), 0.0000000) / avg.size();               // <-여기가 문제
			if (compare < cheapest_cost)					//비교
				cheapest_cost = compare;
			avg.clear();
		}
	}

	return cheapest_cost;
}

int main() {
	int C, n, m, cost;
	float cheapest = 0;									//함수에서 받아올 결과값
	cout << std::setprecision(8);						//나오는 숫자들에 부동소수점 설정(7자리 이하일 시, 7로하면 에러가 뜬다고 함.)
	vector<int> Cost;								    //대여 비용을 넣을 벡터

	cin >> C;

	for (int i = 0; i < C; i++) {
		cin >> n; cin >> m;
		for (int j = 0; j < n; j++) {
			cin >> cost;
			Cost.push_back(cost);						//벡터에 비용값을 넣음
		}
		cheapest = festival(Cost, n, m);				//함수 결과로 나온 평균값을 넣음
		cout << cheapest << endl;
	}

	return 0;
}