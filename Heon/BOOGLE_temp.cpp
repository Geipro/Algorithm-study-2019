#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <numeric>

using namespace std;

//=============================================================================

void Boggle(string word, int index, int apb_count[26], int apb_position[][2][25]);

int main()
{
	int test_count;
	int input_count;

	cin >> test_count;
	input_count = test_count;

	// test
	while (input_count != 0)
	{
		char board[5][5];					// BOGGLE 게임판
		int word_count;						// 입력 받을 단어 개수
		string word;
		vector<string> word_array;			// 입력 받은 단어

		int alphabet_count[26] = { 0, };	// board의 각 알파벳의 개수
		int alphabet_position[26][2][25];	// 각 알파벳의 좌표

		char c;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j <= 5; j++)
			{
				cin >> c;

				board[i][j] = c;
				alphabet_position[c - 65][0][alphabet_count[c - 65]] = i;
				alphabet_position[c - 65][1][alphabet_count[c - 65]] = j;
			}

		cin >> word_count;
		for (int i = 0; i < word_count; i++)
		{
			cin >> word;
			Boggle(word, 0, alphabet_count, alphabet_position);
		}

		input_count--;
	}
	
	return 0;
}

void Boggle(string word, int index, int apb_count[26], int apb_position[][2][25])
{
	char current = word[0];
	char next = word[1];

	bool result = false;

	result = result || Search(word, index, apb_count, apb_position);
}

bool Search(string word, int index, int apb_count[26], int apb_position[][2][25])
{
	if (word.length() == index + 1)
		return true;

	char current = word[index];
	char next = word[index + 1];

	for(int i = 0; i < apb_count[current - 65]; i++)
		for (int j = 0; j < apb_count[next - 65]; j++)
		{

		}
}