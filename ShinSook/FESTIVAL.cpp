#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>

using namespace std;

int festival(vector<int> Cost, int n, int m) {
	float cheapest_cost = 100;								//검색결과 float의 정밀도는 6~9자리, double은 15~18자리.
	float compare = 0;										//비교값
	vector<int> avg;
	for (int i = m; i <= n; i++) {																	//더할 개수
		for (int j = 0; j < (n - i + 1); j++) {														//어디부터 더할건지 벡터에 삽입. 
			for (int k = 0; k < i; k++) {
				avg.push_back(Cost.at(j));
			}
			
			/*for (int k = 0; k < ; k++) {															//벡터에 넣어서 평균값 내기
				
			}
			*/
		}
		compare = accumulate(avg.begin(), avg.end(), 0.0) / avg.size();
		if (cheapest_cost > compare)					//비교
			cheapest_cost = compare;
		avg.clear();
	}
}

int main() {
	int C, n, m, cost;
	float cheapest_cost = 100;								//검색결과 float의 정밀도는 6~9자리, double은 15~18자리.
	float compare = 0;										//비교값
	cout << std::setprecision(8);							//나오는 숫자들에 부동소수점 설정
	vector<int> Cost;										//대여 비용을 넣을 벡터

	cin >> C; 

	for (int i = 0; i < C; i++) {
		cin >> n; cin >> m;
		for (int j = 0; j < n; j++) {
			cin >> cost;
			Cost.push_back(cost);							//벡터에 비용값을 넣음
			compare = festival(Cost, n, m);					//함수 결과로 나온 평균값을 넣음
			if (cheapest_cost > compare)					//비교
				cheapest_cost = compare;
		}
	}
	cout << cheapest_cost << endl;

	return 0;
}