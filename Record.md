> * #### Vector에 원소를 추가하면서 기존 것만 탐색
```cpp
vector<int> v;
v.push_back(0); visited[0] = true; ans++;
for (int i = 0; i < N; i++) {
	int v_siz = v.size();
	for (int j = 0; j < v_siz; j++) {
		int ele = v[j];
		if (visited[ele + arr[i]] == false) {
			visited[ele + arr[i]] = true;
			v.push_back(ele + arr[i]);
			ans++;
		}
	}
}
```
- - - -
> * #### 배열 공백 제거
for (int i = 0; i < N; i++) {
```cpp
	int arrInd = 0;
	memset(tmpArr, 0, N*sizeof(int));
	for (int j = 0; j < N; j++) {
		if (board[i][j] != 0) {
			int blockIndex = j + 1;
			while (board[i][blockIndex] == 0 && blockIndex < N)
				blockIndex++;

			if (board[i][j] == board[i][blockIndex] && blockIndex != N) {
				board[i][j] *= 2;
				board[i][blockIndex] = 0;
				maxAns = board[i][j] > maxAns ? board[i][j] : maxAns;
			}
		}
		if (board[i][j] != 0)
			tmpArr[arrInd++] = board[i][j];
	}
	memcpy(board[i], tmpArr, N * sizeof(int));
}
```
- - - -
> * #### stringstream에서 input 후의 getc 결과는 공백이 나온다 그리고 ungetc 또한 사용 가능하다
> * #### mingw 에서는 getchar를 이용한 버퍼 관리가 안됨
- - - -
> * #### Flag 비트마스킹 : 순서를 보지 않아도 알 수 있다.... -> DP with bitmask
- - - -
> * #### 특정 구간이 겹치는지 확인
```cpp
!(nBus.sx > bus.ex || nBus.ex < bus.sx)
```
- - -
> * #### 레퍼런스 배열을 선언할 수 없다
- - -
> * #### 2차원 선 교차 확인(대각선이 존재하지 않을 때)
```cpp
!(s.x>r.e.x || s.y>r.e.y || r.s.x>e.x || r.s.y>e.y)
```
- - -
> * #### 다익스트라 with adjust matrix : edge 모델링이 필요 없다.
- - -
```cpp
Trie* & t //포인터 레퍼런스 선언
bool operator<(const Matrix& m) const{
	if (hei * wid != m.hei * m.wid)
		return hei * wid < m.hei * m.wid;
	return hei < m.hei;
}// operator에 const 속성을 붙혀 주지 않으면 에러가 날 수도 있다.
```
- - -
