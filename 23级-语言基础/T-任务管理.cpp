//T
//#include <iostream>
//#include <map>
//#include <vector>
//#include <set>
//using namespace std;
//
//set<int> ans;
//map<int, vector<int> > in;
//
//void find(int i)
//{
//	int len = in[i].size();
//	ans.insert(i);
//	for (int j = len - 1; j >= 0; --j)
//    	find(in[i][j]);
//}
//
//int main()
//{
//	int N;
//	cin >> N;
//	for (int i = 1; i <= N; ++i)
//	{
//		int Ci;
//		cin >> Ci;
// 		in[i].resize(Ci);
//		while (Ci--)
//		{
// 			cin >> in[i][Ci];
//		}
//	}	
//	find(1);
//	cout << ans.size();
//}

//�Ż���Ĵ���ʹ����һ�� visited ��������¼�ڵ�
//�Ƿ��Ѿ������ʹ���ͬʱ��ʹ��һ�� stack ��ģ��
//�ݹ�Ĺ��̣�ʵ���������������ÿ�δ�ջ��ȡ��һ
//���ڵ���д���������Ϊ�ѷ��ʣ��������ӽڵ�
//��ջ���������Ա��⺯�����ô����Ŀ�����
#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAXN = 1000005;

vector<int> in[MAXN];
bool visited[MAXN];

int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int Ci;
        cin >> Ci;
        in[i].resize(Ci);
        for (int j = 0; j < Ci; ++j)
        {
            cin >> in[i][j];
        }
    }

    set<int> ans;
    vector<int> stack;
    stack.push_back(1);
    while (!stack.empty())
    {
        int node = stack.back();
        stack.pop_back();
        if (!visited[node])
        {
            visited[node] = true;
            ans.insert(node);
            for (int i = in[node].size() - 1; i >= 0; --i)
            {
                stack.push_back(in[node][i]);
            }
        }
    }

    cout << ans.size();

    return 0;
}
