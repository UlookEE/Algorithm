#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;


#define MAX_N 500

int front;
int rear;
int queue[MAX_N];

void queueInit(void)
{
	front = 0;
	rear = 0;
}

int queueIsEmpty(void)
{
	return (front == rear);
}

int queueIsFull(void)
{
	if ((rear + 1) % MAX_N == front)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int queueEnqueue(int value)
{
	if (queueIsFull())
	{
		printf("queue is full!");
		return 0;
	}
	queue[rear] = value;
	rear++;
	if (rear == MAX_N)
	{
		rear = 0;
	}

	return 1;
}

int queueDequeue(int *value)
{
	if (queueIsEmpty())
	{
		printf("queue is empty!");
		return 0;
	}
	*value = queue[front];
	front++;
	if (front == MAX_N)
	{
		front = 0;
	}
	return 1;
}

int N;
char arr[25][25];
bool visited[25][25];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int resArr[1000];
int resIndex = 0;

void quick_sort(int left, int right) {
	int pivot = resArr[(left + right) / 2];
	int i = left; int j = right;
	int tmp = resArr[i];

	do {
		while (resArr[i] < pivot) i++;
		while (resArr[j] > pivot) j--;
		
		if (i <= j) {
			tmp = resArr[i];
			resArr[i] = resArr[j];
			resArr[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j)
		quick_sort(left, j);
	if (right > i)
		quick_sort(i, right);
}
inline bool in_range(int x, int y) {
	return x >= N || y >= N || x < 0 || y < 0 ? false : true;
}

int countBFS = 0;
void bfs() {
	while (!queueIsEmpty()) {
		int n; queueDequeue(&n);
		int x = n / N, y = n % N;
		countBFS++;
		for (int i = 0; i < 4; i++) {
			if (in_range(x + dx[i], y + dy[i]) && !visited[x + dx[i]][y + dy[i]] && arr[x + dx[i]][y + dy[i]]) {
				queueEnqueue((x+dx[i])*N + y + dy[i]);
				visited[x + dx[i]][y + dy[i]] = true;
			}
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			arr[i][j] -= '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			
			if (visited[i][j] == false && arr[i][j]) {
				countBFS = 0;
				queueEnqueue(i*N + j);
				visited[i][j] = true;
				bfs();
				resArr[resIndex++] = countBFS;
			}
		}
	}

	cout << resIndex << endl;
	quick_sort(0, resIndex - 1);
	for (int i = 0; i < resIndex; i++) {
		cout << resArr[i] << endl;
	}

	return 0;
}
