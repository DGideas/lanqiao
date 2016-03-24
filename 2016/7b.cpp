#include <stdio.h>
#include <string.h>
int mpt[3][4];
int mpt_visit[3][4];
int num[6]; 
int have[13];
int visit[13];
int ans = 0;
int Count = 0;

void init()
{
	int k = 1;
	for(int i = 0 ; i < 3 ; i ++)
		for(int j = 0 ; j < 4 ; j ++)
		{
			mpt[i][j] = k;
			k ++;
		}
}
int dir[4][2] = {0,1,0,-1,-1,0,1,0};
//判断五个数是否能连在一起
void dfs_find(int x,int y)
{
	for(int i = 0 ; i < 4 ; i++)
	{
		int tx,ty;
		tx = x + dir[i][0];
		ty = y + dir[i][1];
		if(tx < 0 || tx >= 3 || ty < 0 || ty >= 4) continue;
		if(have[mpt[tx][ty]] == 0 || mpt_visit[tx][ty])continue;
		mpt_visit[tx][ty] = 1;
		Count ++;
		dfs_find(tx,ty);
	}
}

void Solve()
{
	int i;
	memset(have,0,sizeof(have));
	memset(mpt_visit,0,sizeof(mpt_visit));
	for(i = 1; i < 6 ; i ++) have[num[i]] = 1;
	for(i = 0 ; i < 12 ; i ++)
	{
		int x,y;
		x = i / 4;
		y = i % 4;
		if(have[mpt[x][y]])
		{
			Count = 1;
			mpt_visit[x][y] =1;
			dfs_find(x,y);
			break;
		}
	}
	if(Count == 5)
	{
		ans ++;
	}
}

//创建5个数的组合
void dfs_creat(int index)
{
	if(index == 6)
	{
		Solve();
		return;
	}
	for(int i = num[index-1] + 1; i < 13 ; i ++)
	{
		if(!visit[i])
		{
			visit[i] = true;
			num[index] = i;
			dfs_creat(index+1);
			visit[i] = false;
		}
	}
}

int main()
{
	init();
	dfs_creat(1);
	printf("%d\n",ans);
	return 0;
}
