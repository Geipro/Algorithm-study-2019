#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
int n;
int tri[100][100];
int dp[100][100];

int triangle(int h, int w) {
	if (h == n - 1)											//������ �� �϶�(���� �ִ�) �� �̻� ������ �����Ƿ�
		return tri[h][w];
	int& ret = dp[h][w];									//�޸������̼��� ���� ���� dp�� �ּҰ��� ret�� ����

	if (ret != -1)											//�̹� ����� �� ������ ret ��ȯ.
		return ret;

	return ret = max(triangle(h+1, w), triangle(h+1, w+1)) + tri[h][w];		//ret�� �Լ��� �ٷ� ���. max�Լ��� �̿������ν� �Ʒ��ʰ� �����ʾƷ��� ���� �� �� + �迭�� ��
}

int main() {
	int C;
	cin >> C;
	for (int i = 0; i < C; i++) {
		memset(dp, -1, sizeof(dp));
		cin >> n;
		for (int h = 0; h < n; h++) {						//�ﰢ���̹Ƿ� h�� n����, w�� �ִ밡 h�� ���� ���ƾ���.
			for(int w = 0; w < h+1; w++)
				cin >> tri[h][w];
		}
		cout << triangle(0, 0) << endl;						//triangle�� ������� �ﰢ�� ����� �ִ밪�� ret�� ��ȯ���̹Ƿ� �ٷ� ���.
	}

	return 0;
}