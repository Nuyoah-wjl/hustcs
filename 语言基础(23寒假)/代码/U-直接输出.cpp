//U
#include <iostream>
using namespace std;
void f(int m, int n){//mΪ���ֽ������nΪλ����rΪ��ֵ 
    int r;
    if (m == 0) return;//m���ֽ��� 
    r=m%2;
    m=m/2;
    f(m, n+1);
    if (m!=0 && r!=0){//���ǵ�һ���������+ 
        cout<<"+";
    }
    if (r == 1){
        if (n == 0) cout<<"2(0)";
        else if (n == 1) cout<<"2";
        else if (n == 2) cout<<"2(2)";
        else{//2��ָ������2�����ֽ�
            cout<<"2(";
            f(n, 0);
            cout<<")";
        }
    }
}
int main(){
    int num;
	cin>>num;
    f(num, 0);
    return 0;
}
