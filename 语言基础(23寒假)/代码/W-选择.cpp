//W
#include<iostream>
#include<algorithm>
using namespace std;
int a[100] = { 0 };
int n, k;
int sum = 0;
int ans = 0;
bool f(int sum)//�ж�����
{
	
	if (sum == 2)
		return true;
	for (int i = 2; i < sum; i++)
	{
		if (sum%i == 0)
		{
			
			return false;
		}
	}
	
	
		return true;
	
 
}
void dfs(int m,int sum ,int z)//����һ�������±꣬��ѡk������m�Ǽ�¼ѡ�˼�����
{
	
	if (m == k)//һ���Ѿ�ѡ�����������ͱ������
	{
		
		if (f(sum))
		{
			ans++;
		}
		return;//�����������ط����ݵĻ����������ִ����������m��ֵ�ͻ���� return�������ĸ��ط�����
	}
	//û����ݹ�֮ǰ���ǰ�ѡ�ĵ�һ������ѭ��һ�飬Ҳ�ǵݹ���ֹ������
	for (int i = z; i <= n; i++)//����ڶ����ݹ����൱�ڰ�Ҫѡ�ĵڶ�����ȫ����ѭ����
	{
		
		
		dfs(m + 1, sum + a[i], i + 1);
	}
	
	return;
}
int main()
{
	
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];//Ҫ��֤�������ŷ���������
	}
	sort(a,a + n+1);
	dfs(0,0,1);
	cout << ans;
	return 0;
}
