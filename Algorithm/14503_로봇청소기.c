#define _CRT_SECURE_NO_WARNINGS


/*�ð���ǥ*/
#if 0
#include <stdio.h>
#define MAX 60
int n, m;
int cnt;
int map[MAX][MAX];
int visited[MAX][MAX];
int dirx[4] = { 0,-1,0,1 };	//�� �� �� ��
int diry[4] = { -1,0,1,0 };	//�� �� �� ��
int dir;
typedef struct st
{
	int x;
	int y;
}st;
st start;
void dfs(int x, int y, int dir)
{
	visited[x][y] = 1;

	int nextx = x;
	int nexty = y;
	int nextd = dir;
	int i;
	for (i = 0; i < 4; i++)
	{
		//dir : �� �� �� ��
		//�� �Ʒ� �� �� (0 3 2 1 )������ ���ƾ��Ѵ�.
		int nextd = dir - i;
		if (nextd < 0) nextd += 4;
		nextx = dirx[nextd] + x;
		nexty = diry[nextd] + y;
		if (nextd % 2 && (nextx < 0 || nextx >= n)) continue;
		else if (!(nextd % 2) && (nexty < 0 || nexty >= m)) continue;
		if (!visited[nextx][nexty] && !map[nextx][nexty])
		{
			if (nextd == 0) dfs(nextx, nexty, 3);
			else dfs(nextx, nexty, nextd - 1);
			break;
		}
	}

	if (i == 4)
	{
		//dir : �� �� �� ��
		nextd = dir - 1;
		if (nextd == -1) nextd = 3;
		nextx = x + dirx[nextd];
		nexty = y + diry[nextd];
		if (dir % 2 && (nexty < 0 || nexty >= m || map[nextx][nexty])) return;
		if (!(dir % 2) && (nextx < 0 || nextx >= n || map[nextx][nexty])) return;
		dfs(nextx, nexty, dir);
	}
}
int main()
{
	scanf("%d %d", &n, &m);

	scanf("%d %d %d", &start.x, &start.y, &dir);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	dfs(start.x, start.y, dir);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j]) cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}
#endif



/*�ݽð���ǥ*/
#if 0
#include <stdio.h>
#define MAX 60
int n, m;
int cnt;
int map[MAX][MAX];
int visited[MAX][MAX];
int dirx[4] = { 0,1,0,-1 };	//�� �� �� ��
int diry[4] = { -1,0,1,0 };	//�� �� �� ��
int dir;

typedef struct st
{
	int x;
	int y;
}st;
st start;

void dfs(int x, int y, int dir)
{
	visited[x][y] = 1;
	
	int nextx, nexty, nextd;
	int i;
	for (i = 0; i < 4; i++)
	{
		//dir : �� �� �� ��
		//�� �Ʒ� �� �� (0 1 2 3)������ ���ƾ��Ѵ�.
		nextd = (dir + i) % 4;
		nextx = dirx[nextd] + x;	nexty = diry[nextd] + y;
		if (nextd % 2 && (nextx < 0 || nextx >= n)) continue;
		else if (!(nextd % 2) && (nexty < 0 || nexty >= m)) continue;
		if (!visited[nextx][nexty] && !map[nextx][nexty])
		{
			dfs(nextx, nexty, (nextd + 1) % 4);
			break;
		}
	}

	if (i == 4)
	{
		//dir : �� �� �� ��
		int nextd = (dir + 1) % 4;
		int nextx = x + dirx[nextd];
		int nexty = y + diry[nextd];
		if (dir % 2 && (nexty < 0 || nexty >= m || map[nextx][nexty])) return;
		else if (!(dir % 2) && (nextx < 0 || nextx >= n || map[nextx][nexty])) return;
		else dfs(nextx, nexty, dir);
	}
}
int main()
{
	scanf("%d %d", &n, &m);

	scanf("%d %d %d", &start.x, &start.y, &dir);
	if (dir == 3) dir = 1;
	else if (dir == 1) dir = 3;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	dfs(start.x, start.y, dir);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j]) cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}
#endif