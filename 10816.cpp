#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<functional>
#include<vector>
using namespace std;

struct Answer {
	int first;
	int second;
	int value = 0;

	inline bool operator==(const int& item) {
		return first == item;
	}
	inline bool operator>(const int& item) {
		return first > item;
	}
	inline bool operator<(const int& item) {
		return first < item;
	}
};

struct CMP_1 {
	inline bool operator()(const Answer& a1, const Answer& a2) {
		return a1.first < a2.first;
	}
};

struct CMP_2 {
	inline bool operator()(const Answer& a1, const Answer& a2) {
		return a1.second < a2.second;
	}
};

template<typename T1, typename T2>
void quick_sort(T1 arr[], int start, int end) {
	static T2 cmp;
	int i = start;
	int j = end;
	T1 mid = arr[(start + end) / 2];
	T1 tmp;
	while (i <= j) {
		while (cmp(arr[i], mid))
			i++;
		while (cmp(mid, arr[j]))
			j--;
		if (i<=j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
	if (start < j)
		quick_sort<T1,T2>(arr, start, j);
	if (end > i)
		quick_sort<T1, T2>(arr, i, end);
}
int arr[500001];
Answer arr2[500001];
Answer* v[500001];
int index = 0;
int main() {	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N; cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> arr2[i].first;
		arr2[i].second = i;
	}

	quick_sort<Answer, CMP_1>(arr2, 0, M - 1);

	for (int i = 0; i < N; i++) {
		int item = arr[i];
		int left = 0;
		int right = M - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (arr2[mid] == item) {
				arr2[mid].value++;
				break;
			}
			else if (arr2[mid] > item)
				right = mid - 1;
			else
				left = mid + 1;
		}
	}
	int prev = -1;
	int sum = 0;
	for (int i = 0; i < M; i++) {
		if (prev != arr2[i].first) {
			for (int j = 0; j < index; j++)
				v[j]->value = sum;
			index = 0;
			prev = arr2[i].first;
			sum = arr2[i].value;
			v[index++] = &arr2[i];
		}
		else {
			sum += arr2[i].value;
			v[index++] = &arr2[i];
		}
	}
	for (int j = 0; j < index; j++)
		v[j]->value = sum;
	
	quick_sort<Answer, CMP_2>(arr2, 0, M - 1);
	for (int i = 0; i < M; i++)
		cout << arr2[i].value << ' ';

	return 0;
}
