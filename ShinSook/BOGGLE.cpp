//薄仙 while 庚 鎧採 設公喫. 骨是研 鉱生稽 皐切.
//+ 1託 呪舛 板. 仙瑛亜 唖唖 return 聖 馬檎辞 庚薦亜 吉陥.暁 巷廃 loop拭 匙遭 依級亀 赤澗 牛. 製... while庚戚 琶推蒸聖 依 旭精汽?
//+ 2託 呪舛 板, 鎧採拭辞 巷廃 loop拭 匙遭 依精 紫虞然生蟹, 窒径戚 陥呪 蟹神悟 岩戚 薦企稽 照銀. if庚 鎧採拭辞 now拭 希馬澗 呪亜 2亜 焼艦虞 1戚焼諌猿?
//緋... 原濁亜走稽 岩戚 薦企稽 襟走 省澗陥...... 仙瑛 拝 凶, a,b研 郊荷嬢操醤 馬走 省艦?  ->  緋 巨獄焔 神嫌亜 襟革? (3託 呪舛)
//戚 敗呪税 衣引葵生稽 毒舘馬澗 依戚 焼艦虞 flag研 室趨瑳猿? 焼送亀 巨獄焔 神嫌 掻.  -> 庚切伸税 魁聖 硝焼鎧澗 汽拭辞 庚薦亜 持医陥檎? 魁戚 NULL戚 焼観 依昔亜?(4託呪舛)
//庚切伸 魁聖 毒紺馬澗 益 採歳戚 限紹蟹左陥. YES虞澗 舛岩戚 襟延 馬走幻, 食穿備 呪弦精 舛岩級戚 蟹伸喫. 益 戚政澗 焼掘 IF庚級拭辞 唖唖 鋼発聖 域紗馬奄 凶庚昔亜. 訊戚走?
//+ 5託 呪舛 板, 舛岩精 襟走幻 食君 鯵亜 窒径鞠澗 雌伐. 焼原亀 唖唖 仙瑛原陥 軒渡鞠澗 雌伐戚 含虞辞昔亜? 
//呪舛 板拭 瓜戚 陥製 越切亜 糎仙馬澗走研 達澗 引舛戚 if庚拭辞 琶推廃亜? -> 焼艦 戚闇 MAIN税 庚薦革. 25腰 伊紫研 馬革 痕呪研 魚稽 竺舛馬食 湛 是帖研 煽舌背 砧嬢辞 敗呪研 鉱拭辞 叔楳馬切.(6託)
//鉱生稽 晒製拭亀 食君腰 叔楳馬革 更醤 獣降. 佐重. せせせせ for庚 照拭辞 拭君 設公媒革 せせ + 7託 呪舛
//背衣刃....戟 昔牛 梅生蟹, 岩戚 護鯵亜 戚雌馬惟 襟樫;
//D亜 蒸生蟹 PANDORA亜 鞠澗 依生稽 左焼 鎧採 姥薄 耕什昔牛?
//MAIN拭辞 原走厳生稽 達精 湛 越切税 硝督昏採斗 獣拙聖 馬澗 依戚 焼艦檎 神岩生稽 銀.  => 背衣 8託呪舛
//PANDORA税 井酔 亜 庚薦昔汽... 戚闇 嬢追 背衣馬劃... KARA税 井酔 湛 越切採斗 蒸奄 凶庚拭 敗呪 叔楳聖 馬走 省焼辞 NO亜 襟澗汽, PANDORA坦軍 掻娃戚 蒸澗 井酔亜 庚薦革?
//掻娃拭 if税 魁引 搾嘘馬澗 依拭辞 PANDORA税 2腰属 A人 原走厳越切昔 A人 旭焼辞 舛岩坦軒 鞠澗 依戚醸揮 暗績. 鯵 冊企亜軒. 遭拙拭 窒径獣佃辞 溌昔背瑳杏 ご
//せせせせせ衣厩 IF庚生稽 昔背辞 爽痕戚 畳短蟹惟 旭精惟 弦焼霜 井酔 希 照達焼獄顕. 馬走幻 else if研 if稽 郊蝦井酔 獣娃段引 銀. 緋.... 衣厩 五乞戚薦戚芝聖 潤醤廃陥澗闇亜?

#include <iostream>
#include <string>

using namespace std;
bool flag = false;																//search_Next 税 衣引葵聖 煽舌拝 flag

bool search_Next(char BOGGLE[][5], string voca, int now, int a, int b) {		//昔切稽 2託据壕伸毒, 爽嬢遭 舘嬢, 薄仙 嬢巨猿走 達紹澗走人, 壕伸 是帖研 角移閤製.
	if (a > 5 || a < 0 || b < 0 || b > 5)
		return false;

	if ((voca.at(now) == voca[voca.size() - 1]) && (now == voca.size() - 1)) {	//原走厳猿走 達紹聖 凶, true亜 蟹神澗 依昔汽... 訊 PANDORA亜 襟劃壱.. 益軍 原走厳昔走 溌昔馬澗惟 拭君昔闇汽.
		flag = true;
		return true;
	}

	if (BOGGLE[a][b - 1] == voca.at(now + 1) && !flag)									//薄仙 是帖拭辞 昔羨廃 疎妊拭 陥製越切亜 赤聖 井酔 益 楕生稽 仙瑛敗呪 硲窒.
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
	int C, N;															//脊径 閤聖 痕呪
	char word;															//疎妊毒拭 脊径拝 痕呪
	string voca[10];													//赤澗走 溌昔 拝 庚切伸級聖 煽舌拝 庚切伸 壕伸

	cin >> C;															//護 亜走 井酔研 溌昔拝 依昔走 脊径
	for (int i = 0; i < C; i++) {										//C腰 幻鏑 鋼差
		char BOGGLE[5][5] = { NULL };									//2託据 壕伸毒 持失
		for (int a = 0; a < 5; a++) {									//2託据 壕伸拭 脊径
			for (int b = 0; b < 5; b++) {
				cin >> word;
				BOGGLE[a][b] = word;
			}
		}

		cin >> N;														//N幻鏑 庚切伸級聖 隔製
		for (int j = 0; j < N; j++) {									//舘嬢級 脊径
			cin >> voca[j];
			for (int a = 0; a < 5; a++) {								//湛 越切 是帖達奄.
				for (int b = 0; b < 5; b++) {
					if (BOGGLE[a][b] == voca[j].at(0))				//湛 越切亜 壕伸拭 赤陥檎
						search_Next(BOGGLE, voca[j], 0, a, b);			//
				}
			}
			if (flag)				//薄仙 是帖人 敗臆 敗呪 硲窒 衣引亜 false亜 焼艦虞檎
				cout << voca[j] << "  YES" << endl;
			else
				cout << voca[j] << "  NO" << endl;
			flag = false;			//flag 段奄鉢
		}
	}
	return 0;
}