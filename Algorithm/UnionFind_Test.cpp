#include<iostream>
#include"UnionFind.h"

using namespace std;

int main() {
	UnionFind * UF = new UnionFind(8);
	UF->unionSet(0, 1);
	UF->unionSet(2, 3);
	UF->unionSet(4, 5);
	UF->unionSet(6, 7);

	UF->unionSet(0, 2);
	UF->unionSet(4, 6);

	UF->unionSet(0, 4);

	for (int i = 0; i < 8; i++) {
		cout << "i : " << i << " , " << UF->sizeOfSet(i) <<" rank : "<< UF->rank[i] << endl;
	}
	cout << "numDisjointSets : " << UF->numDisjointSets() << endl;
	
	delete UF;

	return 0;
}