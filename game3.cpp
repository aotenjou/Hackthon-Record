#include <iostream>
#include <algorithm>
#include <time.h>
#include <windows.h>
#include <queue>
#include <cmath>

using namespace std;

class robot {
	public:
		bool survive = true;
		int addtion = 0;
		void get_card(int num) {
			this->q.push(num);
			this->sum += num;
			addtion ++;
		}
		void act() {
			bool done = false;

			if (rand() % 4 == 1) {
				cout << "选择抽牌一次" << '\n';
				srand((unsigned int)time(0));
				int num = rand() % 9 + 1;
				this->get_card(num);
				Sleep(400);
			}
			if (sum >= 17 + rand() % 3 || addtion >= 8) {
				cout << "选择放弃抽牌\n";
			} else {
				if (rand() % 3 == 1) {
					cout << "选择抽牌一次" << '\n';
					srand((unsigned int)time(0));
					int num = rand() % 9 + 1;
					this->get_card(num);
					Sleep(400);
					if (rand() % 3  == 2)
						cout << "选择抽牌一次" << '\n';
					srand((unsigned int)time(0));
					num = rand() % 8 + 1;
					this->get_card(num);
					Sleep(400);
				}

				else {
					while (!(sum >= 18 || addtion >= 6)) {
						cout << "选择抽牌一次" << '\n';
						srand((unsigned int)time(0));
						int num = rand() % 9 + 1;
						this->get_card(num);
						Sleep(400);
					}

				}
			}
			cout << "选择结束回合\n";
			system("pause");
		}
		int sum = 0;
		queue<int> q;

};

class point21 {
	public:

		bool game_start() {
			//cout << "游戏即将开始！\n ";
			//Sleep(1500);
			welcome();
			system("pause");
			init();
			cout << "抽牌阶段开始：";
			system("pause");
			return round();
		}
	private:
		bool player_survive = true;
		int remain = 5;
		robot bot[5];
		int sum_bot[6] = {0, 0, 0, 0, 0};
		queue<int> known[6];
		bool p[40] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		int player_card[40] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		int player_sum = 0;
		void welcome() {

			cout << "++++++++++++++++++++++++++++++++++++\n";
			cout << "游戏——21点\n";
			cout << "++++++++++++++++++++++++++++++++++++\n";

			show_rule();
		}
		bool round() {
			show_table();
			for (int i = 0 ; i < 6 ; i ++) {
				if (i == 5) {
					printf("该你行动了！！！\n", i);
					player_act();
				} else if (bot[i].survive) {
					printf("%d号开始摸牌\n", i);
					bot[i].act();
					show_table();
				}
			}
			if (remain == 4 || remain == 2)
				do_harm();
			cout << "处决回合开始！\n";
			system("cls");
			int k = kill();
			if (k != 5) {
				bot[k].survive = false;
				show_table();
				printf("领袖%d号被处决!!!,ta 手中的总点数是 %d ", k, bot[k].sum);
				system("pause");
			} else {
				show_table();
				cout << "抱歉，您被处决了,游戏结束\n";
				cout << "您的点数：" << player_sum << '\n';
				show_result();
				system("pause");
				return false;
			}
			remain --;
			if (remain >= 1) {
				decrease();
				return round();
			} else {
				show_table();
				show_result();
				cout << "恭喜通关！！\n";
				system("pause");
				return true;
			}

		}
		void do_harm() {
			show_table();
			cout << "陷害阶段开始——————\n";
			cout << "你需要抽取一张卡，并决定留下它或者将其“送给”其他人";
			system("pause");
			int num = rand() % 9 + 1;
			printf("这张卡的点数是 %d \n", num);
			cout << "请输入“送给”的对象的号码（单个数字，'5'代表自己留下）\n";
			int op;
			while (1) {
				string s;
				cin >> s;
				if (s.size() == 1 && s[0] <= '5' && s[0] >= '0') {
					op = s[0] - '0';
					if (op == 5) {
						break;
					} else if (bot[op].survive) {
						break;
					} else {
						cout << "不能送给已被处决的对象\n";
					}
				} else
					cout << "输入不合法QAQ\n";
			}
			if (op == 5) {
				player_get(num);
			} else
				bot[op].get_card(num);
			show_table();
			cout << "赠与完成！";
			system("pause");
		}
		void player_act() {
			bool op;
			cout << "请决定你是否抽牌，放弃抽牌请输入no，需要抽牌输入yes\n";
			while (1) {
				string s;
				cin >> s;
				if (s == "yes") {
					op = 1;
					break;
				} else if (s == "no") {
					op = 0;
					break;
				}
				cout << "输入不合法QAQ";
			}
			if (op == 0) {
				cout << "你决定结束回合\n";
				system("pause");
			} else {
				srand((unsigned int)time(0));
				int num = rand() % 6 + 1;
				printf("你得到一张 %d \n");
				system("cls");
				player_get(num);
				show_table();
				player_act();
			}
		}
		int kill() {
			pair<int, int> a[10];
			int q = 0;
			for (int i = 0 ; i < 6 ; i ++) {
				int diff;
				if (i == 5) {
					diff = abs(player_sum - 21);
				} else {
					if (!bot[i].survive)
						continue;
					else {
						diff = abs(bot[i].sum - 21);
					}
				}
				a[q ++] = {diff, i};
			}
			sort(a, a + q);

			return a[q - 1].second;

		}
		void init() {
			srand((unsigned int)time(0));//初始化种子为随机值
			for (int i = 0 ; i < 6; ++i) {
				int num = rand() % 9 + 1;
				if (i == 5) {
					player_get(num);
					continue;
				}
				known[i].push(num);
				bot[i].get_card(num);
			}
			show_table();
		}
		void show_player_card() {
			cout << "你（5号）的手牌：";
			for (int i = 1 ; i <= 21 ; i ++) {
				if (p[i] != 0) {
					cout << player_card[i] << ' ';
				}
			}
			cout << "总点数 " << player_sum << "/21\n";
			puts("");
		}
		void show_rule() {
			cout << "++++++++++++++++++++++++++++++++++++\n";
			cout << "21点游戏流程：\n1.初始布局：每个玩家摸一张牌并公示."
			     << "2.摸牌回合：玩家按照编号从0~5的顺序，依次进入自己的摸牌回合。摸牌回合内，"
			     "可以决定摸一张牌且额外获得一个摸牌回合或者终止摸牌回合。"
			     << "3.陷害回合(仅第二轮、第四轮有）：仅由人类玩家抽取一张牌，得知其点数后决定将其送给谁."
			     << "4.处决回合：处决手中点数离21点最远的玩家，点数相同随机处决。"
			     << " \n";
			cout << "++++++++++++++++++++++++++++++++++++\n";
		}
		void decrease() {
			cout << "盘末流逝：人类玩家获得一张 -2 牌";
			player_get(-2);
			system("pause");
		}
		void player_get(int num) {
			bool done = false;
			for (int i = 1 ; i <= 21 ; i ++) {
				if (p[i] == 0) {
					p[i] = 1;
					player_card[i] = num;
					done = true;
					player_sum += num;
					break;
				}
			}
		}
		void show_result() {
			cout << "——————游戏结果——————\n";
			for (int i = 0 ; i < 5 ; i ++) {
				printf("%d号领袖手牌：", i);
				{
					printf("(%d/21) ", bot[i].sum);
					for ( ; !bot[i].q.empty() ;) {
						int t = bot[i].q.front();
						bot[i].q.pop();
						cout << t << ' ';
					}
					puts("");
				}
			}
			cout << "————————————————————\n";
		}
		void show_table() {
			system("cls");
			show_rule();
			cout << "——————当前手牌情况——————\n";
			for (int i = 0 ; i < 5 ; i ++) {
				printf("%d号领袖手牌：", i);
				if (!bot[i].survive) {
					printf("共 %d 点，已出局...........\n", bot[i].sum);
				} else {
					for (int j = 1 ; j <= known[i].size() ; j ++) {
						queue<int> qq ;
						qq = known[i];
						int t = qq.front();
						qq.pop();
						cout << t << ' ';
					}
					for (int j = known[i].size() + 1 ; j <= bot[i].addtion; j ++) {
						cout << "？" << ' ';
					}
					puts("");
				}
			}
			cout << "————————————————————\n";
			show_player_card();
		}
};

