#pragma once
#define NULL 0

const static int dr[] = { 1,1,0,-1,-1,-1,0,1 };
const static int dc[] = { 0,1,1,1,0,-1,-1,-1 };

class AdjMat {
public:
	int ** graph;
	int row, col;


	AdjMat(int row, int col) {
		this->row = row;
		this->col = col;

		graph = new int *[row + 1];
		for (int i = 0; i < row + 1; i++) {
			graph[i] = new int[col + 1];
			for (int j = 0; j < col + 1; j++)
				graph[i][j] = 0;			//initailize
		}

	}

	~AdjMat() {
		for (int i = 0; i < row; i++) {
			delete[] graph[i];
			graph[i] = NULL;
		}
		delete[] graph;
		graph = NULL;
	}

	
};