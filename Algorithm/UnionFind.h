#pragma once

#include<vector>

typedef std::vector<int> vi;

class UnionFind {
private: 
	vi p, rank;		//p is array of index of parent, rank is height of set
public:
	UnionFind(int N) {
		rank.assign(N, 0);
		p.assign(N, 0);							//assign 0 to 0 ~ (N - 1)th index of array(vector initialize)
		for (int i = 0; i < N; i++) 
			p[i] = i;	//root's parent is itself(vector initialize)
	}

	int findSet(int i) { 
		return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
	} //find root parent reqursive

	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j); 
	}

	void unionSet(int i, int j){
		if (!isSameSet(i, j)) {					
			int x = findSet(i), y = findSet(j);	//find root
			if (rank[x] > rank[y])
				p[y] = x;	//attach small tree to large tree
			else {
				p[x] = y;
				if (rank[x] == rank[y]) 
					rank[y]++;	//if tree's height is equal, combined tree
													//height is increased
			}
		}
	}

	int numDisjointSets() {
		int count = 0;
		for (int i = 0; i < p.size(); i++) 
			if (i = p[i]) 
				count++;
		return count;
	}

	int sizeOfSet(int k) {
		int count = 0;
		for (int i = 0; i < p.size(); i++) 
			if (isSameSet(i, k)) 
				count++;
		return count;	/*make more array, calculation time reduce to O(1)*/
	}											

};
