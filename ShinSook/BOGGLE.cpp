//현재 while 문 내부 잘못됨. 범위를 밖으로 빼자.
//+ 1차 수정 후. 재귀가 각각 return 을 하면서 문제가 된다.또 무한 loop에 빠진 것들도 있는 듯. 음... while문이 필요없을 것 같은데?
//+ 2차 수정 후, 내부에서 무한 loop에 빠진 것은 사라졌으나, 출력이 다수 나오며 답이 제대로 안뜸. if문 내부에서 now에 더하는 수가 2가 아니라 1이아닐까?
//흠... 마찬가지로 답이 제대로 뜨지 않는다...... 재귀 할 때, a,b를 바꾸어줘야 하지 않니?  ->  흠 디버깅 오류가 뜨네?
//이 함수의 결과값으로 판단하는 것이 아니라 flag를 세워볼까? 아직도 디버깅 오류 중.  -> 문자열의 끝을 알아내는 데에서 문제가 생겼다면? 끝이 NULL이 아닌 것인가?
//문자열 끝을 판별하는 그 부분이 맞았나보다. YES라는 정답이 뜨긴 하지만, 여전히 수많은 정답들이 나열됨. 그 이유는 아래 IF문들에서 각각 반환을 계속하기 때문인가. 왜이지?
//일단 5차 수정 후, 정답은 뜨지만 여러 개가 출력되는 상황. 아마도 각각 재귀마다 리턴되는 상황이 달라서인가? 
//수정 후에 굳이 다음 글자가 존재하는지를 찾는 과정이 if문에서 필요한가? -> 아니 이건 MAIN의 문제네. 25번 검사를 하네 변수를 따로 설정하여 첫 위치를 저장해 두어서 함수를 밖에서 실행하자.
//밖으로 뺏음에도 여러번 실행하네 뭐야 시발. 병신. ㅋㅋㅋㅋ for문 안에서 에러 잘못햇네 ㅋㅋ
//해결완....료 인듯 했으나, 답이 몇개가 이상하게 뜨넹;
//D가 없으나 PANDORA가 되는 것으로 보아 내부 구현 미스인듯?
//MAIN에서 마지막으로 찾은 첫 글자의 알파벳부터 시작을 하는 것이 아니면 오답으로 뜸.  => 해결
//PANDORA의 경우 가 문제인데...

#include <iostream>
#include <string>

using namespace std;
bool flag = false;																//search_NEXT 의 결과값을 저장할 FLAG

bool search_Next(char BOGGLE[][5], string voca, int now, int a, int b) {		//인자로 2차원배열판, 주어진 단어, 현재 어디까지 찾았는지와, 배열 위치를 넘겨받음.
	if (a > 5 || a < 0 || b < 0 || b > 5)
		return false;

	if (voca.at(now) == voca[voca.size() - 1]) {								//마지막까지 찾았을 때, true가 나오는 것인데... 왜 PANDORA가 뜨냐고 ㅅㅂ
		flag = true;
		return true;
	}

	if (BOGGLE[a][b - 1] == voca.at(now + 1))
		search_Next(BOGGLE, voca, now + 1, a, b - 1);
	else if (BOGGLE[a][b + 1] == voca.at(now + 1))
		search_Next(BOGGLE, voca, now + 1, a, b + 1);
	else if (BOGGLE[a - 1][b - 1] == voca.at(now + 1))
		search_Next(BOGGLE, voca, now + 1, a - 1, b - 1);
	else if (BOGGLE[a - 1][b] == voca.at(now + 1))
		search_Next(BOGGLE, voca, now + 1, a - 1, b);
	else if (BOGGLE[a - 1][b + 1] == voca.at(now + 1))
		search_Next(BOGGLE, voca, now + 1, a - 1, b + 1);
	else if (BOGGLE[a + 1][b - 1] == voca.at(now + 1))
		search_Next(BOGGLE, voca, now + 1, a + 1, b - 1);
	else if (BOGGLE[a + 1][b] == voca.at(now + 1))
		search_Next(BOGGLE, voca, now + 1, a + 1, b);
	else if (BOGGLE[a + 1][b + 1] == voca.at(now + 1))
		search_Next(BOGGLE, voca, now + 1, a + 1, b + 1);
	else
		return false;
	return false;
}

int main() {
	int C, N;
	int x, y;															//현재 위치를 저장할 변수
	char word;
	string voca[10];
	cin >> C;
	char BOGGLE[5][5] = { NULL };

	for (int i = 0; i < C; i++) {
		for (int a = 0; a < 5; a++) {									//2차원 배열에 입력
			for (int b = 0; b < 5; b++) {
				cin >> word;
				BOGGLE[a][b] = word;
			}
		}

		cin >> N;

		for (int j = 0; j < N; j++) {										//단어들 입력
			cin >> voca[j];

			for (int a = 0; a < 5; a++) {									//첫 글자 위치찾기.
				for (int b = 0; b < 5; b++) {
					if (BOGGLE[a][b] == voca[j].at(0)) {					//첫 글자가 배열에 있다면
						x = a, y = b;
						search_Next(BOGGLE, voca[j], 0, x, y);
					}
				}
			}
			if (flag)				//현재 위치와 함께 함수 호출 결과가 false가 아니라면
				cout << voca[j] << "  YES" << endl;
			else
				cout << voca[j] << "  NO" << endl;
			flag = false;			//flag 초기화
		}
	}
	return 0;
}