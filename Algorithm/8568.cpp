#define _CRT_SECURE_NO_WARNINGS

/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = &apos;b&apos;;
// char var[256] = &quot;ABCDEFG&quot;;
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << &quot; &quot; << c;               // float ���� 2�� ����ϴ� ����
// cout << d << &quot; &quot; << e << &quot; &quot; << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
/////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	freopen("C:\\TMP\\input.txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N; cin >> N;
		int swapCount = 0;
		int arr[5000];
		bool pos_cor[5000];
		register int i, j, startInd;
		memset(pos_cor, 0, sizeof(pos_cor));
		for (i = 1; i <= N; i++) {
			cin >> arr[i];
			arr[i] %= 3;
			if (arr[i] == i % 3) {
				pos_cor[i] = true;
			}
		}
		startInd = 1;
		while (startInd <= N) {
			while (pos_cor[startInd])
				startInd++;
			
			for (i = startInd; i <= N; i++) {
				if (pos_cor[i] == true)
					continue;
				for (j = i + 1; j <= N; j++) {
					if (i % 3 == arr[j] && j % 3 == arr[i] && !pos_cor[j]) {
						swap(arr[i], arr[j]);
						pos_cor[i] = true;
						pos_cor[j] = true;
						swapCount++;
						break;
					}
				}
			}

			while (pos_cor[startInd])
				startInd++;

			for (j = startInd + 1; j <= N; j++) {
				if (startInd % 3 == arr[j] && !pos_cor[j]) {
					swap(arr[startInd], arr[j]);
					pos_cor[startInd] = true;
					swapCount++;
					break;
				}
			}
			
		}
		cout << "#" << test_case << " " << swapCount << endl;
	}
	fclose(stdin);

	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}