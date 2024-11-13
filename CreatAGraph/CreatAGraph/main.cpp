#include<iostream>
#include<vector>
#include<cstdio>
static const int MAXN = 101;
using namespace std;
//邻接矩阵
vector<vector<int>> graph1(MAXN, vector<int>(MAXN));

//邻接表
//动态增加的
vector<vector<pair<int,int>>> graph2(MAXN);//表示图上的边有权值

//链式前向星
//直接使用静态的数组实现
static const int MAXM = 201;//因为对于无向图，一条边要加到两条边上去
int cnt;//表示填到了那一条边了
int head[MAXM];//对于第n个定点，它的最后一个出现的对应的边
int nxt[MAXM];//表示第i条边处理之后要处理哪条边
int dest[MAXM];//表示这条边指向的顶点是哪个
int weight[MAXM];//表示边的权值

inline void addEdge(int u, int v, int w)
{
	nxt[cnt] = head[u];
	dest[cnt] = v;
	weight[cnt] = w;
	head[u] = cnt++;
}

void build(int n)
{
	//邻接矩阵清空
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			graph1[i][j] = 0;
		}
	}

	//邻接表清空
	graph2.clear();
	for (int i = 0; i <= n; i++)//0下标准备但是不使用
	{
		graph2.push_back(vector<pair<int, int>>());
	}

	//链式前向星清空
	cnt = 1;
	for (int i = 1; i < MAXM; i++)
	{
		head[i] = 0;//只需要清空head就可以了，其他的会发生覆盖
	}
}
void directGraph(vector<vector<int>>& edges)
{
	//邻接矩阵建图
	for (auto& edge : edges)
	{
		graph1[edge[0]][edge[1]] = edge[2];
	}

	//邻接表建图
	for (auto& edge : edges)
	{
		graph2[edge[0]].push_back(pair<int,int> { edge[1],edge[2] });
	}

	//链式前向星建图
	for (auto& edge : edges)
	{
		addEdge(edge[0], edge[1], edge[2]);
	}
}
void undirectGraph(vector<vector<int>> edges)
{
	//正反两个都加入就可以了，和上面的相同，不做展开了

	//链式前向星建图，注意要加两个方向的边
	for (auto& edge : edges)
	{
		addEdge(edge[0], edge[1], edge[2]);
		addEdge(edge[1], edge[0], edge[2]);
	}
}
void traversal(int n)
{
	//邻接矩阵
	/*for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << graph1[i][j] << " ";
		}
		cout << endl;
	}*/

	//邻接表
	//for (int i = 1; i <= n; i++)
	//{
	//	//输出邻居和边的权值

	//}

	//链式前向星
	for (int i = 1; i <= n; i++)
	{
		for (int ei = head[i]; ei > 0; ei = nxt[ei])
		{
			printf("从%d到%d，权值为%d\n", i, dest[ei], weight[ei]);
		}
		cout << endl;
	}
}
int main(void)
{
	/*ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);*/
	vector<vector<int>> edges  { { 1, 3, 6 }, { 4, 3, 4 }, { 2, 4, 2 }, { 1, 2, 7 }, { 2, 3, 5 }, { 3, 1, 1 } };
	build(6);
	directGraph(edges);
	traversal(6);
	return 0;
}
