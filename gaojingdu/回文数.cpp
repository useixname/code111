#include <bits/stdc++.h>
using namespace std;
const int maxN = 105;
char sixt[20] = "0123456789ABCDEF";
int n;
string m;
bool hw(string a) { //�жϻ���
	string s = a; //�� a ��ֵ�� s
	reverse(s.begin(), s.end()); //��ת�ַ��� s
	return s == a; //�ж� a �� s �Ƿ����
}
string add(int k, string b) { //�߾��ȼӷ����̣��ƹ㵽 k ����
	string a = b;
	reverse(a.begin(), a.end());
	int numa[maxN], numb[maxN], numc[maxN];
	int len = a.length(), lenc = 1;
	string ans;
	for (int i=0; i<len; i++) {
		if (isdigit(a[i])) numa[len-i] = a[i] - '0'; //����ʮ�����Ƶ����У���������ּ�ȥ 0 ����ͬ
		else numa[len-i] = a[i] - 'A' + 10; //����������ּ�ȥ A �ټ��� 10
		if (isdigit(b[i])) numb[len-i] = b[i] - '0';
		else numb[len-i] = b[i] - 'A' + 10;
	}
	int x = 0;
	while (lenc <= len) {
		numc[lenc] = numa[lenc] + numb[lenc] + x;
		x = numc[lenc] / k; //�ѳ��� 10 �޸�Ϊ���� k
		numc[lenc] %= k; //����Ѷ� 10 ȡģ�޸�Ϊ�� k ȡģ
		lenc++;
	}
	numc[lenc] = x;
	while (numc[lenc] == 0) lenc--; 
	for (int i=lenc; i>=1; i--) ans += sixt[numc[i]];
	return ans;
}
int main() {
	cin >> n >> m;
	for (int i=0; i<=30; i++){ //ģ�����
		if(hw(m)) { //����ǻ����������������
			printf("STEP=%d", i);
			return 0;
		}
		else m = add(n, m);
	}
	printf("Impossible!"); //������� 30 ������� Impossible!
	return 0;
}