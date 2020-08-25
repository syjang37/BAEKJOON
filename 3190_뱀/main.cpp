#include <iostream>
#include <string.h>		// memset
#include <map>
#include <deque>

using namespace std;

struct Point
{
	int iX;
	int iY;
};

int **board;

// Function.
int gameStart(const map<int, char>& p_mapDir, const int& p_iSize);
void getDirection(const map<int, char>& p_mapDir, const int& p_iTime, int& pr_iX, int& pr_iY);
int main()
{
	// Get Size Info
	int iSize = 0;
	scanf("%d", &iSize);

	// Init Board
	board = new int*[iSize];
	for (int i = 0; i < iSize; i++) {
		board[i] = new int[iSize];
		memset(board[i], 0, sizeof(int)*iSize);
	}

	// Get Apple info
	int iCount = 0;
	scanf("%d", &iCount);

	// Init Location of Apple 
	for (int i = 0; i < iCount; i++) {
		int iX = 0;
		int iY = 0;
		scanf("%d %d", &iX, &iY);
		board[iX-1][iY-1] = 1;
	}

	// Get Direction Info
	scanf("%d", &iCount);

	map<int, char> mapDirInfo;
	for (int i = 0; i < iCount; i++) {
		int iTime = 0;
		char cDir;
		scanf("%d %c", &iTime, &cDir);
		mapDirInfo.insert(make_pair(iTime, cDir));
	}

	// Game Start
	printf("%d\n", gameStart(mapDirInfo, iSize));
	return 0;
}

int gameStart(const map<int, char>& p_mapDir, const int& p_iSize)
{
	int iTime = 0;
	int iDirX = 0;
	int iDirY = 1;

	deque<Point> dequeSnake;
	Point point;
	point.iX = 0;
	point.iY = 0;
	dequeSnake.push_back(point);
	board[point.iX][point.iY] = 2;

	while (true) {
		iTime++;
		int iX = dequeSnake.back().iX;
		int iY = dequeSnake.back().iY;

		Point nextPoint;
		nextPoint.iX = iX + iDirX;
		nextPoint.iY = iY + iDirY;

		// Check Escape
		if (nextPoint.iX < 0 || nextPoint.iX >= p_iSize ||
			nextPoint.iY < 0 || nextPoint.iY >= p_iSize ) {
			break;
		}

		// Check Hit
		if (board[nextPoint.iX][nextPoint.iY] == 2) {
			break;
		}

		if (board[nextPoint.iX][nextPoint.iY] != 1) {
			board[dequeSnake.at(0).iX][dequeSnake.at(0).iY] = 0;
			dequeSnake.pop_front();
		}

		board[nextPoint.iX][nextPoint.iY] = 2;
		dequeSnake.push_back(nextPoint);

		getDirection(p_mapDir, iTime, iDirX, iDirY);
	}
	return iTime;
}

void getDirection(const map<int, char>& p_mapDir, const int& p_iTime, int& pr_iX, int& pr_iY)
{
	auto iter = p_mapDir.find(p_iTime);
	if (iter == p_mapDir.end()) {
		return;
	}

	char cDir = iter->second;
	int temp = 0;
	switch (cDir) {
	case 'L':
		temp = pr_iY != 0 ? -pr_iY : pr_iY;
		pr_iY = pr_iX;
		pr_iX = temp;
		break;

	case 'D':
		temp = pr_iX != 0 ? -pr_iX : pr_iX;
		pr_iX = pr_iY;
		pr_iY = temp;
		break;
	}
}