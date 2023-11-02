//#define PRINT printf
#define PRINT
#define Alloc_Player (&player_pool[++Pidx])
#define ABS(x) ((x) >= 0 ? (x) : (-(x)))
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

const int dy[5] = {-1,0,1,0};
const int dx[5] = {0,1,0,-1};

int n, m, k, x, y, d, s, Ginput;
int playerNum, playerY, playerX, playerD, playerS, playerG;
int SideplayerNum, SideplayerY, SideplayerX, SideplayerD, SideplayerS, SideplayerG;
int WinPlayerNum, LosePlayerNum;

int PArr[25][25];

struct PLAYER {
	int y;
	int x; 
	int dir;
	int stats;
	int gun;
};
PLAYER player_pool[1000];
int player_point[1000];
int Pidx;

priority_queue<int> GUNArr[25][25];


/////////

void MapCheck() {
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			PRINT("%d ", PArr[i][j]);
		}
		PRINT("\n");
	}
}

void PlayerCheck() {
	for (int i = 1; i <= m; ++i) {
		PRINT("\nPlayer[%d] ||  y,x: (%d,%d) | dir: %d | gun: %d | stats: %d\n", i, player_pool[i].y, player_pool[i].x, player_pool[i].dir, player_pool[i].gun, player_pool[i].stats);
	}
}


void ChangeGun(int Y, int X, int playerNum) {
	if (!GUNArr[Y][X].empty()) {
		if (player_pool[playerNum].gun > 0) {
			GUNArr[Y][X].push(player_pool[playerNum].gun);
		}
		player_pool[playerNum].gun = GUNArr[Y][X].top();
		GUNArr[Y][X].pop();
	}
}




int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &Ginput);
			GUNArr[i][j].push(Ginput);
		}
	}

	for (int i = 1; i <= m; ++i) {
		scanf("%d %d %d %d", &y, &x, &d, &s);
		PLAYER* player = Alloc_Player;
		player->y = y, player->x = x;
		player->dir = d;
		player->stats = s;
		PArr[y][x] = i;
	}


	int currentRound = 0;
	bool UserExist = 0;
	int ExistUserNum = 0;
	while (currentRound < k) {
		currentRound++;
		MapCheck();
		PlayerCheck();
		for (int i = 1; i <= m; ++i) {
			playerNum = i;
			playerY = player_pool[i].y;
			playerX = player_pool[i].x;
			playerD = player_pool[i].dir;
			playerS = player_pool[i].stats;
			playerG = player_pool[i].gun;

			// �̵������� Ÿ �÷��̾ �����ϴ��� Ȯ���ϰ� �̵� 
			if (!(1 <= playerY + dy[playerD] && playerY + dy[playerD] <= n && 1 <= playerX + dx[playerD] && playerX + dx[playerD] <= n)) {
				playerD = (playerD + 2) % 4;
			}
			int nextY = playerY + dy[playerD];
			int nextX = playerX + dx[playerD];

			if (PArr[nextY][nextX] != 0) {
				UserExist = 1;
				ExistUserNum = PArr[nextY][nextX];
			}
			else {
				UserExist = 0;
			}
			player_pool[i].dir = playerD;
			player_pool[i].y = nextY;
			player_pool[i].x = nextX;
			PArr[playerY][playerX] = 0;

			//�÷��̾� ������ ���� �ൿ ����
			if (!UserExist) {
				//�÷��̾� ����
				//�� �ִ��� Ȯ���ؼ� ������ �ٲ�ġ���ϱ� 
				PArr[nextY][nextX] = playerNum;
				ChangeGun(nextY, nextX, playerNum);
			}
			else {
				//�÷��̾� ����
				PRINT("//User Exists// %d \n", playerNum);
				SideplayerNum = PArr[nextY][nextX];
				SideplayerD = player_pool[SideplayerNum].dir;
				SideplayerS = player_pool[SideplayerNum].stats;
				SideplayerG = player_pool[SideplayerNum].gun;
				
				//�÷��̾� ����
				//���� �Ǵ� (�ɷ�ġ + �� ���ݷ�) �� 
				int CalScore = (SideplayerS + SideplayerG) - (playerS + playerG);
				if (CalScore > 0) {
					WinPlayerNum = SideplayerNum;
					LosePlayerNum = playerNum;
				}
				else if (CalScore < 0) {
					WinPlayerNum = playerNum;
					LosePlayerNum = SideplayerNum;
				}
				else if (CalScore == 0) {
					if (SideplayerS > playerS) {
						WinPlayerNum = SideplayerNum;
						LosePlayerNum = playerNum;
					}
					if (SideplayerS < playerS) {
						WinPlayerNum = playerNum;
						LosePlayerNum = SideplayerNum;
					}
				}
				
				PRINT("Win:%d, Lose:%d\n", WinPlayerNum, LosePlayerNum);
				//�̱� �÷��̾�� ���� �ο� , Array�� ��ȣ ���
				player_point[WinPlayerNum] += ABS(CalScore);
				PArr[nextY][nextX] = WinPlayerNum;

				//�� �÷��̾� 
				//1.�ش� ��ġ�� �� ����
				GUNArr[nextY][nextX].push(player_pool[LosePlayerNum].gun);
				player_pool[LosePlayerNum].gun = 0;
				//2.�̵�
					// �̵� �� �ٸ� �÷��̾ ���� ��� �� ĭ�� ���϶����� 90�� ȸ���ؼ� �̵� 
					// �̵� �� ���� �� �� ȹ�� 
				while(1){
					int tempD = player_pool[LosePlayerNum].dir;
					if (1 <= nextY + dy[tempD] && nextY + dy[tempD] <= n && 1 <= nextX + dx[tempD] && nextX + dx[tempD] <= n) {
						if (PArr[nextY + dy[tempD]][nextX + dx[tempD]] == 0) {
							player_pool[LosePlayerNum].y = nextY + dy[tempD];
							player_pool[LosePlayerNum].x = nextX + dx[tempD];
							PArr[player_pool[LosePlayerNum].y][player_pool[LosePlayerNum].x] = LosePlayerNum;
							break;
						}
						else {
							PRINT("///here\n");
							player_pool[LosePlayerNum].dir = (tempD + 1) % 4;
						}
					}
					else {
						PRINT("///%d , there\n", tempD);
						player_pool[LosePlayerNum].dir = (tempD + 1) % 4;
					}
				}
				ChangeGun(player_pool[LosePlayerNum].y, player_pool[LosePlayerNum].x, LosePlayerNum);			

				//�̱� �÷��̾�
				//���� �ڸ����� ���� ���� �� ������ ��ü�ϰ� �ڱⲨ �������� 
				ChangeGun(nextY, nextX, WinPlayerNum);

			}

		}

		PRINT("Round: %d\n", currentRound);
		MapCheck();
		PlayerCheck();
		PRINT("---------------\n");
	}


	//print_answer
	for (int i = 1; i <= m; ++i) {
		printf("%d ", player_point[i]);
	}
	
	return 0;
}
