#include<iostream>
#include<vector>
#include<cstdio>
static const int MAXN = 101;
using namespace std;
//�ڽӾ���
vector<vector<int>> graph1(MAXN, vector<int>(MAXN));

//�ڽӱ�
//��̬���ӵ�
vector<vector<pair<int,int>>> graph2(MAXN);//��ʾͼ�ϵı���Ȩֵ

//��ʽǰ����
//ֱ��ʹ�þ�̬������ʵ��
static const int MAXM = 201;//��Ϊ��������ͼ��һ����Ҫ�ӵ���������ȥ
int cnt;//��ʾ�����һ������
int head[MAXM];//���ڵ�n�����㣬�������һ�����ֵĶ�Ӧ�ı�
int nxt[MAXM];//��ʾ��i���ߴ���֮��Ҫ����������
int dest[MAXM];//��ʾ������ָ��Ķ������ĸ�
int weight[MAXM];//��ʾ�ߵ�Ȩֵ

inline void addEdge(int u, int v, int w)
{
	nxt[cnt] = head[u];
	dest[cnt] = v;
	weight[cnt] = w;
	head[u] = cnt++;
}

void build(int n)
{
	//�ڽӾ������
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			graph1[i][j] = 0;
		}
	}

	//�ڽӱ����
	graph2.clear();
	for (int i = 0; i <= n; i++)//0�±�׼�����ǲ�ʹ��
	{
		graph2.push_back(vector<pair<int, int>>());
	}

	//��ʽǰ�������
	cnt = 1;
	for (int i = 1; i < MAXM; i++)
	{
		head[i] = 0;//ֻ��Ҫ���head�Ϳ����ˣ������Ļᷢ������
	}
}
void directGraph(vector<vector<int>>& edges)
{
	//�ڽӾ���ͼ
	for (auto& edge : edges)
	{
		graph1[edge[0]][edge[1]] = edge[2];
	}

	//�ڽӱ�ͼ
	for (auto& edge : edges)
	{
		graph2[edge[0]].push_back(pair<int,int> { edge[1],edge[2] });
	}

	//��ʽǰ���ǽ�ͼ
	for (auto& edge : edges)
	{
		addEdge(edge[0], edge[1], edge[2]);
	}
}
void undirectGraph(vector<vector<int>> edges)
{
	//��������������Ϳ����ˣ����������ͬ������չ����

	//��ʽǰ���ǽ�ͼ��ע��Ҫ����������ı�
	for (auto& edge : edges)
	{
		addEdge(edge[0], edge[1], edge[2]);
		addEdge(edge[1], edge[0], edge[2]);
	}
}
void traversal(int n)
{
	//�ڽӾ���
	/*for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << graph1[i][j] << " ";
		}
		cout << endl;
	}*/

	//�ڽӱ�
	//for (int i = 1; i <= n; i++)
	//{
	//	//����ھӺͱߵ�Ȩֵ

	//}

	//��ʽǰ����
	for (int i = 1; i <= n; i++)
	{
		for (int ei = head[i]; ei > 0; ei = nxt[ei])
		{
			printf("��%d��%d��ȨֵΪ%d\n", i, dest[ei], weight[ei]);
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
