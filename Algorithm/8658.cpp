#include<iostream>
#include<string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	getchar();
	for (int i = 1; i <= T; ++i)
	{
		int max = -1;
		int min = 999999999;
		
		for (int j = 0; j < 10; j++) {
			int count = 0;
			int num; cin >> num;
			while (num != 0) {
				count += num % 10;
				num /= 10;
			}
			if (max < count)
				max = count;
			if (min > count)
				min = count;
		}
		
		cout << '#' << i << ' ' << max << ' ' << min << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}