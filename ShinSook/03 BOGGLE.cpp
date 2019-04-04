//현재 while 문 내부 잘못됨. 범위를 밖으로 빼자.
//+ 1차 수정 후. 재귀가 각각 return 을 하면서 문제가 된다.또 무한 loop에 빠진 것들도 있는 듯. 음... while문이 필요없을 것 같은데?
//+ 2차 수정 후, 내부에서 무한 loop에 빠진 것은 사라졌으나, 출력이 다수 나오며 답이 제대로 안뜸. if문 내부에서 now에 더하는 수가 2가 아니라 1이아닐까?
//흠... 마찬가지로 답이 제대로 뜨지 않는다...... 재귀 할 때, a,b를 바꾸어줘야 하지 않니?  ->  흠 디버깅 오류가 뜨네? (3차 수정)
//이 함수의 결과값으로 판단하는 것이 아니라 flag를 세워볼까? 아직도 디버깅 오류 중.  -> 문자열의 끝을 알아내는 데에서 문제가 생겼다면? 끝이 NULL이 아닌 것인가?(4차수정)
//문자열 끝을 판별하는 그 부분이 맞았나보다. YES라는 정답이 뜨긴 하지만, 여전히 수많은 정답들이 나열됨. 그 이유는 아래 IF문들에서 각각 반환을 계속하기 때문인가. 왜이지?
//+ 5차 수정 후, 정답은 뜨지만 여러 개가 출력되는 상황. 아마도 각각 재귀마다 리턴되는 상황이 달라서인가? 
//수정 후에 굳이 다음 글자가 존재하는지를 찾는 과정이 if문에서 필요한가? -> 아니 이건 MAIN의 문제네. 25번 검사를 하네 변수를 따로 설정하여 첫 위치를 저장해 두어서 함수를 밖에서 실행하자.(6차)
//밖으로 뺏음에도 여러번 실행하네 뭐야 시발. 병신. ㅋㅋㅋㅋ for문 안에서 에러 잘못햇네 ㅋㅋ + 7차 수정
//해결완....료 인듯 했으나, 답이 몇개가 이상하게 뜨넹;
//D가 없으나 PANDORA가 되는 것으로 보아 내부 구현 미스인듯?
//MAIN에서 마지막으로 찾은 첫 글자의 알파벳부터 시작을 하는 것이 아니면 오답으로 뜸.  => 해결 8차수정
//PANDORA의 경우 가 문제인데... 이건 어케 해결하냐... KARA의 경우 첫 글자부터 없기 때문에 함수 실행을 하지 않아서 NO가 뜨는데, PANDORA처럼 중간이 없는 경우가 문제네?
//중간에 if의 끝과 비교하는 것에서 PANDORA의 2번째 A와 마지막글자인 A와 같아서 정답처리 되는 것이었던 거임. 개 빡대가리. 진작에 출력시켜서 확인해볼걸 ㅄ
//ㅋㅋㅋㅋㅋ결국 IF문으로 인해서 주변이 엄청나게 같은게 많아질 경우 더 안찾아버림. 하지만 else if를 if로 바꿀경우 시간초과 뜸. 흠.... 결국 메모이제이션을 써야한다는건가?

#include <iostream>
#include <string>

using namespace std;
bool flag = false;																//search_Next 의 결과값을 저장할 flag

bool search_Next(char BOGGLE[][5], string voca, int now, int a, int b) {		//인자로 2차원배열판, 주어진 단어, 현재 어디까지 찾았는지와, 배열 위치를 넘겨받음.
	if (a > 5 || a < 0 || b < 0 || b > 5)
		return false;

	if ((voca.at(now) == voca[voca.size() - 1]) && (now == voca.size() - 1)) {	//마지막까지 찾았을 때, true가 나오는 것인데... 왜 PANDORA가 뜨냐고.. 그럼 마지막인지 확인하는게 에러인건데.
		flag = true;
		return true;
	}

	if (BOGGLE[a][b - 1] == voca.at(now + 1) && !flag)									//현재 위치에서 인접한 좌표에 다음글자가 있을 경우 그 쪽으로 재귀함수 호출.
		search_Next(BOGGLE, voca, now + 1, a, b - 1);
	if (BOGGLE[a][b + 1] == voca.at(now + 1) && !flag)
		search_Next(BOGGLE, voca, now + 1, a, b + 1);
	if (BOGGLE[a - 1][b - 1] == voca.at(now + 1) && !flag)
		search_Next(BOGGLE, voca, now + 1, a - 1, b - 1);
	if (BOGGLE[a - 1][b] == voca.at(now + 1) && !flag)
		search_Next(BOGGLE, voca, now + 1, a - 1, b);
	if (BOGGLE[a - 1][b + 1] == voca.at(now + 1) && !flag)
		search_Next(BOGGLE, voca, now + 1, a - 1, b + 1);
	if (BOGGLE[a + 1][b - 1] == voca.at(now + 1) && !flag)
		search_Next(BOGGLE, voca, now + 1, a + 1, b - 1);
	if (BOGGLE[a + 1][b] == voca.at(now + 1) && !flag)
		search_Next(BOGGLE, voca, now + 1, a + 1, b);
	if (BOGGLE[a + 1][b + 1] == voca.at(now + 1) && !flag)
		search_Next(BOGGLE, voca, now + 1, a + 1, b + 1);

	return false;
}

int main() {
	int C, N;															//입력 받을 변수
	char word;															//좌표판에 입력할 변수
	string voca[10];													//있는지 확인 할 문자열들을 저장할 문자열 배열

	cin >> C;															//몇 가지 경우를 확인할 것인지 입력
	for (int i = 0; i < C; i++) {										//C번 만큼 반복
		char BOGGLE[5][5] = { NULL };									//2차원 배열판 생성
		for (int a = 0; a < 5; a++) {									//2차원 배열에 입력
			for (int b = 0; b < 5; b++) {
				cin >> word;
				BOGGLE[a][b] = word;
			}
		}

		cin >> N;														//N만큼 문자열들을 넣음
		for (int j = 0; j < N; j++) {									//단어들 입력
			cin >> voca[j];
			for (int a = 0; a < 5; a++) {								//첫 글자 위치찾기.
				for (int b = 0; b < 5; b++) {
					if (BOGGLE[a][b] == voca[j].at(0))				//첫 글자가 배열에 있다면
						search_Next(BOGGLE, voca[j], 0, a, b);			//
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