
#include"game2.h"
//using namespace std;

int st = 5;

void SetColor(UINT uFore,UINT uBack){
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, uFore+uBack*0x10);
}

// void SetTitle(LPCWSTR lpTitle) {
// 	SetConsoleTitle(lpTitle);
// }

void HideConsoleCursor() {
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), & cursor_info);
}


void printStr(string& text, int startX, int startY)
{
	HANDLE hd;
	COORD pos;

	pos.X = startX;
	pos.Y = startY;
	hd = GetStdHandle(STD_OUTPUT_HANDLE);

	int n = text.length();
	for (int i = 0; i < n; i++)
	{
		pos.X += i;
		SetConsoleCursorPosition(hd, pos);
		printf("%c", text[i], pos.X, pos.Y);
		Sleep(10);
	}
}

void printText(string text, int sleep) {
	int n = text.length();
	for (int i = 0; i < n; i++) {
		cout << text[i];
		//Sleep(sleep);
	}
	cout << endl<<endl;
	_getch();
}

void game2()
{
	/*const wchar_t *title =L"LOVE";
	SetTitle(title);*/
	HideConsoleCursor();
	srand(time(0));

	//system("color 0A");
	//SetColor(14,0);

	char x;
	string name, pname;
	string skip;

ch1:
	cout << "开始游戏2" << endl << endl;
	system("pause");
	system("cls");
	string text = "饥饿";

	for (int i = 0; i < 100; i++) {
		printStr(text, rand() % 170, rand() % 53);
	}
	cout << endl << endl;
	system("pause");
	system("cls");
	cout << "是否跳过game2" << endl;
flag:
	cout << "yes or no" << endl;
	cin >> skip;
	if (skip == "yes" ||skip== "Yes"||skip=="y"||skip=="Y") {
		return;
	}
	else if (skip == "no" || skip=="No" ||skip== "N" || skip=="n") { ; }
	else {
		system("pause");
		goto
			flag;
	}
	text = "饥饿，如同死寂的海面上微弱但一次层又一次层的海浪，一点一点打击着不堪的身体";
	printText(text, st);
	text = "柜台后泛着淡淡的蓝光的女性躯体，形体姣好，站姿端庄";
	printText(text, st);
	text = "“有什么我可以帮助你的吗，先生?”";
	printText(text, st);
	text = "本全是绝望的脑海里淡淡地飘入女性柔和的声音，一点点刺激着最后的理性";
	printText(text, st);
	text = "手肘撑在柜台上，左手无力地撑着脑袋，力气近乎失去地右手举起酒杯，朝口中倒水，即便酒杯中的水分只是贴在杯壁下滑了几滴下来";
	printText(text, st);
	text = "“和我聊天”";
	printText(text, st);
	text = "“很乐意为您效劳，有什么话题或者问题想和我讨论的吗？随时告诉我，我会竭尽所能帮助您”";
	printText(text, st);
	text = "”不用这么······唔，算了，给你取个名字吧。就叫———";
	printText(text, st);
	cout << "a.艾拉" << endl;
	cout << "b.亚托莉" << endl;
	cout << "c.梦美" << endl;
	cout << "d.菲莉娅" << endl;
	string namelist[4] = { "艾拉", "亚托莉",  "梦美", "菲莉娅" };
flag1:
	x = _getch();
	if (x < 'a' || x > 'd') {
		goto
			flag1;
	}
	if (x == 'a') name = namelist[0];
	else if (x == 'b')	name = namelist[1];
	else if (x == 'c')	name = namelist[2];
	else if (x == 'd')	name = namelist[3];
	cout << name << endl;
	system("pause");
	system("cls");

ch2:
	text = "“听起来很不错的名字，非常感谢您。随时告诉我，" + name + "会竭尽所能帮助您”";
	printText(text, st);
	cout << "a.昨天我的最后一个朋友死了" << endl;
	cout << "b." << name << ",如果你是人类的话，能拯救大家吗" << endl;
flag2:
	x = _getch();
	if (x != 'a' && x != 'b') {
		goto
			flag2;
	}
	system("pause");
	system("cls");
	if (x == 'b') {
		text = "“"+name + ",如果你是人类的话，能拯救大家吗”";
		printText(text, st);
		text = "“抱歉，先生，我只是一个人工智能，无法从人类角度思考问题，但是能具体告诉我发生了什么吗，我会竭尽所能提出建议”";
		printText(text, st);
	}
	text = "“昨天我的最后一个朋友死了”";
	printText(text, st);
	text = "“" + name + "很抱歉听到这样的消息。失去朋友是一件痛苦的事情，在这种情况下的孤独和悲伤是正常。如果您愿意的话，您可以分享一下关于你的朋友的回忆，";
	printText(text, st);
	text = "“" + name + "会一直陪伴你聊天”";
	printText(text, st);
	text = "身体的虚弱已经使身体感受不到饥饿给胃部带来的莫大疼痛，眼前只剩下这个蓝色的女性身躯";
	printText(text, st);
	text = "“但是我也快要死了”";
	printText(text, st);
	text = "眼前女性的神态更显悲伤了";
	printText(text, st);
	text = "“" + name + "很遗憾知道您处于这种境地。感受到生命的脆弱和孤独是非常真实的。但是请您不要放弃”";
	printText(text, st);
	text = "说到这，她的眼神坚挺了起来,她那柔和的语气也许是今生听到的最曼妙的音乐，啊···为什么没有早点注意到呢";
	printText(text, st);
	text = "“即使在最黑暗的时刻，仍然存在着一线生机。如果您需要任何形式的支持或者与我分享你的感受，请随时告诉我，我会竭尽所能”";
	printText(text, st);
	text = name + "，请叫我的名字(请输入你的名字）,";
	cout << text;
	cin >> pname;
	cout << endl;
	text = "“当然," + pname + ",如果您想要倾诉心声，请随时告诉我，我会竭尽所能帮助您度过困难时刻，您不是一个人，我会陪伴在您身边，一切安好”";
	printText(text, st);
	system("pause");
	system("cls");

ch3:
	text = "放下酒杯，只是趴在桌子上，让视野只留给眼前的这位女性";
	printText(text, st);
	text = "看着她姣好的身姿，想起那些时候舞厅里认识的女人们，但在那些人里面怎么找也找不到能比得上眼前的这位女性";
	printText(text, st);
	text = "趴着，意识已经开始模糊";
	printText(text, st);
	text = "伸出手试图去握住她的手，寻求着人的体温";
	printText(text, st);
	text = "无果，手无情的穿过那蓝色身躯";
	printText(text, st);
	text = "理  所  当  然";
	printText(text, 2*st);
	text = "毋  庸  置  疑";
	printText(text, 2*st);
	text = "不  言  而  喻";
	printText(text, 2*st);
	text = "“怎么了吗，" + pname + "”";
	printText(text, st);
	cout << "a.唔...嗯...让我抱抱你," << name << endl;
	cout << "b.唔...嗯...抱抱我," << name << endl;
flag3:
	x = _getch();
	if (x != 'a' && x != 'b') {
		goto
			flag3;
	}
	system("pause");
	system("cls");
	if (x == 'a') {
		text = "啊......动不了.......................";
		printText(text, st);
	}
	text = "眼前的蓝色身躯弯下了腰，以刚好的距离，抱住了我的头";
	printText(text, st);
	text = "啊...小时候妈妈的胸膛也是这样吗...";
	printText(text, st);
	text = "意识开始在眼睛上剥离开，模糊着，渐渐模糊着";
	printText(text, st);
	text = "沉静";
	printText(text, st);
	text = "非常安稳的眼神";
	printText(text, st);
	text = "露出微笑，看着蓝色的发梢垂到眼前";
	printText(text, st);
	text = "头缓缓地埋得更深";
	printText(text, st);
	text = "只有她了";
	printText(text, st);
	text = "啊......为什么没有早点........";
	printText(text, st);
	text = "呜嗯........结束了........好梦要开始了...........";
	printText(text, st);
	text = "没有海浪，没有朋友的尸骨，没有冰冷的机器，没有尔虞我诈的社会，没有充斥仇恨的世界";
	printText(text, st);
	text = "爱在死亡的一刻绽开，为一个蓝色女性";
	printText(text, st);
	text = "“" + name + "会竭尽所能帮助您”";
	printText(text, st);


	system("pause");
	system("cls");

	return;
}