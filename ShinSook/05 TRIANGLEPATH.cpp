#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
int n;
int tri[100][100];
int dp[100][100];

int triangle(int h, int w) {
	if (h == n - 1)											//마지막 줄 일때(높이 최댓값) 더 이상 더하지 않으므로
		return tri[h][w];
	int& ret = dp[h][w];									//메모이제이션을 쓰기 위한 dp의 주소값을 ret에 넣음

	if (ret != -1)											//이미 사용한 적 있으면 ret 반환.
		return ret;

	return ret = max(triangle(h+1, w), triangle(h+1, w+1)) + tri[h][w];		//ret에 함수를 바로 사용. max함수를 이용함으로써 아래쪽과 오른쪽아래로 가는 것 비교 + 배열의 값
}

int main() {
	int C;
	cin >> C;
	for (int i = 0; i < C; i++) {
		memset(dp, -1, sizeof(dp));
		cin >> n;
		for (int h = 0; h < n; h++) {						//삼각형이므로 h는 n보다, w는 최대가 h와 값이 같아야함.
			for(int w = 0; w < h+1; w++)
				cin >> tri[h][w];
		}
		cout << triangle(0, 0) << endl;						//triangle의 결과값이 삼각형 경로의 최대값인 ret의 반환값이므로 바로 출력.
	}

	return 0;
}