#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <windows.h>
using namespace std;

typedef pair<int, int> PII;

class game_power {
	public:
		void start() {
			score1 = score2 = score3 = 0;
			the_map(0);
		}
	private:
		bool done_task1 = false;
		bool done_jie = true;
		int sumv = 0, sumw = 0;
		long long score1, score2, score3;
		long long score1a = 0, score1b = 0;
		int p1[20] = {0, 1, 1, 3, 2, 1, 3, 3, 1, 2, 1, 0, 0};
		int p2[5][20] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 1, 1, 1, 1, 2, 1, 0, 0, 0},
			{0, 2, 3, 1, 3, 2, 3, 0, 0, 0},
			{0, 1, 2, 1, 1, 2, 1, 0, 0, 0},
			{0, 1, 1, 1, 1, 1, 3, 0, 0, 0},
		};
		int st1[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,};
		int st2[5][20] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		};
		int l1 = 1, l2 = 3, l3 = 2;
		int ll1 = 4, ll2 = 7, ll3 = 4;
		//
		int q[30] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		int v[30] = {3, 0, 0, 2, 0, 0, 2, 0, 0, 7, 0, 0, 5, 0, 0, 1, 0, 0, 4, 0, 0, 0, 0, 0};
		int w[30] = {7, 0, 0, 5, 0, 0, 3, 0, 0, 14, 0, 0, 7, 0, 0, 1, 0, 0, 7, 0, 0, 0, 0, 0};

		void task1() {
			system("cls");
			show_title();
			cout << "推进舱段——安插电缆" << '\n';
			cout << "现有三种电线：强动力线、弱动力线、辅助线。强动力线会干扰一步以内的弱动力线和"
			     << "两步以内的辅助线，必须接在3级及以上接口。" <<
			     "弱动力线会干扰一步以内的辅助线，必须接在2级以上接口。" << "辅助线不会干扰其他电线，可以接在任意接口。";
			cout << "一步以内的定义是：通过一次上下左右移动能走到的位置\n";
			cout << "现给定接口等级图，请给出接线方式，使得被接入且未被干扰的电线数量尽量多。\n";
			cout << "计分规则：单题得分 = 合理接入电线总数数*20。 共两题，第一题120分达标，第二题240分达标。\n";
			//task1_problem2();

			int upper, lower;
			if (done_task1) {
				cout << "！！您完成本舱段所有任务,输入0进入传送菜单！！\n" << '\n';
			}
			if (score1 < 120) {
				task1_problem1();
				upper = 1;
				lower = 0;
			} else {
				task1_problem2();
				upper = 4;
				lower = 3;
			}
			cout << "输入格式：三个用空格隔开的数，第一个数代表电线种类(3-强，2-弱，1-辅助，4-置空该处),第二、三个代表操作位置的横，纵坐标。";
			cout << "如 3 1 3 代表在第一行第三列放置一条强动力线";
			show_dom();
			int x, y, z;
			while (1) {
				string s;
				cin.sync();
				getline(cin, s);
				//cout << s.size();
				if (s.size() == 1 && s[0] == '0') {
					the_map(1);
					return;
				} else if (s.size() == 5 && s[0] <= '4' && s[0] >= '1' &&
				           s[2] <= '0' + upper && s[2] >= '1' && s[4] <= '9' - lower && s[4] >= '1') {
					x = s[0] - '0';
					y = s[2] - '0';
					z = s[4] - '0';
					break;
				}
				cout << "输入格式不合法，请再次尝试\n";
			}
			//cou t << 'l' << l3;
			if (score1 < 120) {
				solve1(x, y, z);
			} else {
				solve2(x, y, z);
			}
			score1 = score1a + score1b;
			if (score1 == 120 && upper == 1) {
				cout << "恭喜通过题目1，共获120分！！！" << '\n';
				system("pause");
			}
			if (score1 == 360) {
				cout << "恭喜通过题目2，再获240分！！！" << '\n';
				done_task1 = true;
				system("pause");
			}
			task1();
		}
		void solve1(int x, int y, int z) {
			bool done = true;
			if (x == 1) {
				if (l1 >= 1 && st1[z] == 0) {
					st1[z] = 1;
					l1 --;
				} else
					done = false;
			} else if (x == 2) {
				if (l2 >= 1 && st1[z] == 0 && p1[z] >= 2) {
					st1[z] = 2;
					l2 --;
				} else
					done = false;
			} else if (x == 3) {
				if (l3 >= 1 && st1[z] == 0 && p1[z] >= 3) {
					st1[z] = 3;
					l3 --;
				} else
					done = false;
			} else {
				if (st1[z] != 0) {
					if (st1[z] == 1)
						l1 ++;
					else if (st1[z] == 2)
						l2 ++;
					else
						l3 ++;
					st1[z] = 0;
				} else
					done = false;
			}
			if (!done) {
				cout << "操作不合法QAQ\n";
				system("pause");
			} else {
				score1a = 0;
				for (int i = 1 ; i <= 9 ; i ++) {
					bool done = true;
					if (st1[i] == 0)
						continue;
					else if (st1[i] == 1) {

						if ((i - 2 >= 1 && st1[i - 2] >= 3) || (i + 2 <= 9 && st1[i + 2] >= 3))
							done = false;
						if ((i - 1 >= 1 && st1[i - 1] >= 2) || (i + 1 <= 9 && st1[i + 1] >= 2))
							done = false;
					} else if (st1[i] == 2) {
						if ((i - 1 >= 1 && st1[i - 1] >= 3) || (i + 1 <= 9 && st1[i + 1] >= 3))
							done = false;
					}
					if (done)
						score1a += 20;
				}
				system("pause");
			}
		}
		void solve2(int x, int y, int z) {
			bool done = true;
			if (x == 1) {
				if (ll1 >= 1 && st2[y][z] == 0) {
					st2[y][z] = 1;
					ll1 --;
				} else
					done = false;
			} else if (x == 2) {
				if (ll2 >= 1 && st2[y][z] == 0 && p2[y][z] >= 2) {
					st2[y][z] = 2;
					ll2 --;
				} else
					done = false;
			} else if (x == 3) {
				if (ll3 >= 1 && st2[y][z] == 0 && p2[y][z] >= 3) {
					st2[y][z] = 3;
					ll3 --;
				} else
					done = false;
			} else {
				if (st2[y][z] != 0) {
					if (st2[y][z] == 1)
						ll1 ++;
					else if (st2[y][z] == 2)
						ll2 ++;
					else
						ll3 ++;
					st2[y][z] = 0;
				} else
					done = false;
			}
			if (!done) {
				cout << "操作不合法QAQ\n";
				system("pause");
			} else {
				int dx[5] = {0, 0, -1, 1}, dy[5] = {1, -1, 0, 0};
				score1b = 0;
				for (int i = 1; i <= 4 ; i ++)
					for (int j = 1; j <= 6 ; j ++) {
						done = true;
						if (st2[i][j] == 0)
							continue;
						else if (st2[i][j] == 1) {
							int x = i, y = j;
							for (int k = 0 ; k < 4 && done; k ++) {
								x += dx[k], y += dy[k];
								if (x <= 4 && x >= 1 && y <= 6 && y >= 1) {
									if (st2[x][y] >= 2) {
										done = false;
										break;
									}
								}
								for (int kk = 0 ; kk < 4 ; kk ++) {
									x += dx[kk], y += dy[kk];
									if (x <= 4 && x >= 1 && y <= 6 && y >= 1) {
										if (st2[x][y] >= 3) {
											done = false;
											break;
										}
									}
									x -= dx[kk], y -= dy[kk];
								}
								x -= dx[k], y -= dy[k];

							}
						} else if (st2[i][j] == 2) {
							int x, y;
							for (int k = 0 ; k < 4 && done; k ++) {
								x = i + dx[k], y = j + dy[k];
								if (x <= 4 && x >= 1 && y <= 6 && y >= 1) {
									if (st2[x][y] >= 3) {
										done = false;
										break;
									}
								}
							}
						}
						if (done) {
							score1b += 20;
						}
					}
			}
		}

		void task1_problem1() {
			cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
			cout << "第一题（满分通过后解锁第二题）：\n";
			for (int i = 1 ; i <= 9 ; i ++) {
				cout << p1[i] << "  ";
			}
			puts("");
			for (int i = 1 ; i <= 9 ; i ++) {
				if (st1[i] == 0)
					cout << "空" << ' ';
				else if (st1[i] == 1)
					cout << "辅" << ' ';
				else if (st1[i] == 2)
					cout << "弱" << ' ';
				else
					cout << "强" << ' ';
			}
			puts("");
			printf("未使用电线数：强动力线 %d条,弱动力线 %d条，辅助线 %d条\n", l3, l2, l1);
			cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
		}

		void task1_problem2() {
			cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
			cout << "第二题(单题得分：" << score1 - 120 << ")\n";
			for (int i = 1 ; i <= 4 ; i ++) {
				for (int j = 1 ; j <= 6 ; j ++) {
					cout << p2[i][j] << "  ";
				}
				puts("");

				for (int j = 1 ; j <= 6 ; j ++) {
					if (st2[i][j] == 0)
						cout << "空" << ' ';
					else if (st2[i][j] == 1)
						cout << "辅" << ' ';
					else if (st2[i][j] == 2)
						cout << "弱" << ' ';
					else
						cout << "强" << ' ';
				}
				puts("");
			}
			printf("未使用电线数：强动力线 %d条,弱动力线 %d条，辅助线 %d条\n", ll3, ll2, ll1);
			cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
		}

		void task2() {
			system("cls");
			show_title();
			cout << "支援舱段——防线布置\n";
			cout << "现有四种装甲板，其形状分别为a.左凹右凸，b.右凹左凸，c.左凹右凹，d.左凸右凸。\n";
			cout << "为了加固防御，需要将这四种装甲板按从左到右的顺序拼接成一整条长板。要求凹面只能和凸面对接并且一定要用完所有装甲板。\n";
			cout << "现给定四种装甲板的数量，请求出满足要求的拼接方案总共有多少种。特别地，找不到满足要求的方案则回答 -1。\n";
			cout << "共有四题，第一题 20 分，第二题 40 分 ，第三题 200 分 ，第四题 100 分,共计360分\n";
			cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
			if (score2 < 20) {
				printf("第一题：左凹右凸 1 块，右凹左凸 1 块，\n左凹右凹 1 块，左凸右凸 1 块\n");//4
			} else if (score2 < 60) {
				printf("第二题：左凹右凸 4 块，右凹左凸 2 块，\n左凹右凹 3 块，左凸右凸 7 块\n");//0
			} else if (score2 < 260) {
				printf("第三题：左凹右凸 1 块，右凹左凸 2 块，\n左凹右凹 3 块，左凸右凸 3 块\n");//54
			} else if (score2 < 360) {
				printf("第四题：左凹右凸 12 块，右凹左凸 9 块，\n左凹右凹 14 块，左凸右凸 15 块\n");//56008182
			} else
				cout << "所有题目均已解决，共获得360分";
			cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
			show_dom();
			long long num = 0;
			while (1) {
				string s;
				cin.sync();
				getline(cin, s);
				//cout << s.size();
				if (s.size() == 1 && s[0] == '0') {
					the_map(2);
					return;
				} else if (s.size() == 2 && s[0] == '-' && s[1] == '1') {
					break;
				} else if (s.size() >= 9) {
					cout << "输入过长\n";
					continue;
				} else {
					int n = s.size();
					bool done = true;
					for (int i = 0 ; i < n && done; i ++) {
						if (s[i] > '9' || s[i] < '0') {
							done = false;
							continue;
						} else {
							num *= 10;
							num += s[i] - '0';
						}
					}
					if (done)
						break;
				}
				cout << "输入格式不合法，请再次尝试\n";
			}
			if (score2 < 20) {
				if (num == 4) {
					cout << "Accepted,获得分数20分！！";
					score2 += 20;
					system("pause");
				} else {
					cout << "答案错误QAQ";
					system("pause");
				}
			} else if (score2 < 60) {
				if (num == 0) {
					cout << "Accepted,获得分数40分！！";
					score2 += 40;
					system("pause");
				} else {
					cout << "答案错误QAQ";
					system("pause");
				}
			} else if (score2 < 260) {
				if (num == 54) {
					cout << "Accepted,获得分数200分！！";
					score2 += 200;
					system("pause");
				} else {
					cout << "答案错误QAQ";
					system("pause");
				}
			} else if (score2 < 360) {
				if (num == 56008182) {
					cout << "Accepted,获得分数100分！！";
					cout << "恭喜！您已完成所有任务！！";
					score2 += 100;
					system("pause");
				} else {
					cout << "答案错误QAQ";
					system("pause");
				}

			}
			//cout << num << '\n';
			task2();
		}
		void task3() {
			system("cls");
			show_title();
			problem3();
			cout << "现有油箱7种，每种油箱均有六个，箱体体积和燃油量给定。";
			cout << "为了使火箭的飞行稳定，被选油箱的数量必须呈阶梯型。形式化地，设bi为第i种油箱被选择的数量。";
			cout << "则满足 b1 <= b2 <= b3 <= b4 >= b5 >= b6 >= b7。飞船总容量为35，请设计方案，使得箱体总体积不超过35"
			     << "，且燃油总量尽可能多";
			cout << "计分规则:分数 = 总燃油量 * 5,最高得分为360分\n";
			for (int i = 0 ; i <= 18 ; i += 3) {
				printf("%d号燃料：体积 %d 燃油量 %d \n", i / 3 + 1, v[i], w[i]);
			}
			cout << "输入格式：一行一个字符一个整数，用空格隔开。'-'表示删去'+'表示添加，数字代表被选油箱。\n";
			cout << "如：+ 3  代表多选择3号油箱一个\n";
			bool op;
			int x;
			show_dom();
			while (1) {
				string s;
				cin.sync();
				getline(cin, s);
				//cout << s.size();
				if (s.size() == 1 && s[0] == '0') {
					the_map(3);
					return;
				} else if (s.size() == 3 && (s[0] == '+' || s[0] == '-') && s[2] <= '7' && s[2] >= '1') {
					if (s[0] == '+')
						op = 1;
					else
						op = 0;
					x = s[2] - '0';
					break;
				}
				cout << "输入格式不合法，请再次尝试\n";
			}
			solve3(op, x);
			if (sumv <= 35 && done_jie)
				score3 = sumw * 5;
			else
				score3 = 0;
			task3();
		}
		void solve3(bool op, int x) {
			bool done = true;
			int k = 3 * (x - 1);
			if (op == 1) {
				if (q[k] <= 6) {
					q[k] ++;
				} else
					done = false;
			} else if (op == 0) {
				if (q[k] > 0) {
					q[k] --;
				} else
					done = false;
			}
			if (!done) {
				cout << "操作不合法QAQ";
				system("pause");
			} else {
				sumv = 0;
				sumw = 0;
				for (int j = 0 ; j <= 18 ; j += 3) {
					sumv += q[j] * v[j];
					sumw += q[j] * w[j];
				}
				if (q[0] <= q[3] && q[3] <= q[6] && q[6] <= q[9] && q[9] >= q[12]
				        && q[12] >= q[15] && q[15] >= q[18]) {
					done_jie = true;
				} else
					done_jie = false;
			}
		}
		void problem3() {
			cout << "---------------示意图如下---------------\n";
			cout << "单题得分：（" << score3 << "）\n";
			if (done_jie)
				cout << "阶梯型：符合\n";
			else
				cout << "阶梯型: 不符合\n";
			if (sumv <= 35)
				printf("总体积：%d / 35 (符合要求)\n", sumv);
			else
				printf("总体积：%d / 35 (不符合要求)\n", sumv);
			for (int i = 1 ; i <= 6 ; i ++) {
				for (int j = 0 ; j <= 18 ; j ++) {
					if (j % 3 != 0)
						cout << ' ';
					else if (q[j] >= 7 - i)
						cout << '*';
					else
						cout << ' ';
				}
				puts("");
			}
			for (int j = 0 ; j <= 18 ; j ++) {
				if (j % 3 == 0)
					cout << j / 3 + 1;
				else
					cout << " ";
			}
			puts("");
			cout << "------------------------------------------\n";
		}
		void show_title() {
			cout << "##########################################\n"
			     << " 任务四：a.推进舱段-安插电揽(score: " << score1 << "	) \n"
			     << "         b.防御舱段—防线布置(score: " << score2 << "	) \n"
			     << "         c.指挥舱段-燃料规划(score: " << score3 << "	) \n"
			     << "##########################################\n"
			     <<  "总分 " << score1 + score2 + score3 << "（达950分解锁发射火箭选项）\n"
			     << "##########################################\n";
		}
		void show_dom() {
			cout << '\n';
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

			cout << "任意位置输入数字0可打开传送菜单\n";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		}
		bool check_all() {
			long long sum = score1 + score2 + score3;
			if (sum >= 950) {
				return true;
			} else
				return false;
		}
		void the_map(int last) {
			system("cls");
			show_title();
			cout << "请输入您想前往的舱段：\n";
			cout << "1.推进仓段\n";
			cout << "2.防御仓段\n";
			cout << "3.指挥仓段\n";
			if (last != 0)
				cout << "4.放弃传送\n";
			if (check_all()) {
				cout << "X.发射火箭(输入 X 即可)\n";
			} else
				cout << "(未解锁).发射火箭\n";
			int up;
			if (last != 0)
				up = 4;
			else
				up = 3;
			int op;
			while (1) {
				string s;
				cin >> s;
				if (check_all() && s.size() == 1 && s[0] == 'X') {
					op = -1;
					break;
				} else if (s.size() == 1 && s[0] <= '0' + up && s[0] > '0') {
					op = s[0] - '0';
					break;
				} else {
					cout << "操作不合法QAQ" << '\n';
				}
			}
			if (op == 4)
				op = last;
			if (op == -1) {
				task_end();
			} else if (op == 1) {
				task1();
			} else if (op == 2) {
				task2();
			} else if (op == 3) {
				task3();
			}
		}
		void task_end() {
			cout << "原神，启动！\n";
			system("pause");
			return;
		}
};

