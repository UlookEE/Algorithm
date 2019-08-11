int grid[1000][1000];
int row, int col;

const int dr[] = { 1,1,0,-1,-1,-1,0,1 };
const int dc[] = { 0,1,1,1,0,-1,-1,-1 };

int floodfill(int r, int c, char c1, char c2) {
	if (r < 0 || r >= row || c < 0 || c >= col)
		return 0;

	if (grid[r][c] != c1) 
		return 0;

	int ans = 1;
	grid[r][c] = c2;
	for (int d = 0; d < 8; d++)
		ans += floodfill(r + dr[d], c + dc[d], c1, c2);
	return ans;
}