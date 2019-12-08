#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node *next;
    bool is_blue;
    Node *blueNext;
    Node() : val{0}, next{NULL}, is_blue{false}, blueNext{NULL}{};
    Node(int val, Node *next, bool is_blue = false, Node *blueNext = NULL) :
     val{val}, next{next}, is_blue{is_blue}, blueNext{blueNext} {}
};

Node *piece[4];
Node narr[50];
int query[10];
int maxSum = 0;
void dfs(int depth, int sum)
{
    if(depth == 10){
        if(sum > maxSum)
            maxSum = sum;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        Node * tmpNode = piece[i];
        if(piece[i]->is_blue){
            piece[i] = piece[i]->blueNext;
        }
        else{
            if (piece[i]->next != NULL)
                piece[i] = piece[i]->next;
        }
        for (int j = 1; j < query[depth]; j++)
        {
            if (piece[i]->next != NULL)
                piece[i] = piece[i]->next;
        }
        for(int j=0; j<4; j++)
            if(piece[i] == piece[j] && i != j && piece[i]->next !=NULL)
                goto DO_NOT_DFS;
        
        dfs(depth + 1, sum + piece[i]->val);
        DO_NOT_DFS:
        piece[i] = tmpNode;
    }
}
int main()
{
    for (int i = 0; i < 10; i++)
        cin >> query[i];
    for (int i = 0; i < 4; i++)
        piece[i] = narr + 21;
    narr[0] = (Node(0, NULL)); //end
    narr[1] = (Node(40, narr));
    narr[2] = (Node(38, narr + 1));
    narr[3] = (Node(36, narr + 2));
    narr[4] = (Node(34, narr + 3));
    narr[5] = (Node(32, narr + 4));
    narr[6] = (Node(30, narr + 5, true, narr + 33));
    narr[7] = (Node(28, narr + 6));
    narr[8] = (Node(26, narr + 7));
    narr[9] = (Node(24, narr + 8));
    narr[10] = (Node(22, narr + 9));
    narr[11] = (Node(20, narr + 10, true, narr + 30));
    narr[12] = (Node(18, narr + 11));
    narr[13] = (Node(16, narr + 12));
    narr[14] = (Node(14, narr + 13));
    narr[15] = (Node(12, narr + 14));
    narr[16] = (Node(10, narr + 15, true, narr + 28));
    narr[17] = (Node(8, narr + 16));
    narr[18] = (Node(6, narr + 17));
    narr[19] = (Node(4, narr + 18));
    narr[20] = (Node(2, narr + 19));
    narr[21] = (Node(0, narr + 20));

    narr[23] = (Node(35, narr + 1));
    narr[24] = (Node(30, narr + 23));
    narr[25] = (Node(25, narr + 24));

    narr[26] = (Node(19, narr + 25));
    narr[27] = (Node(16, narr + 26));
    narr[28] = (Node(13, narr + 27));

    narr[29] = (Node(24, narr + 25));
    narr[30] = (Node(22, narr + 29));

    narr[31] = (Node(26, narr + 25));
    narr[32] = (Node(27, narr + 31));
    narr[33] = (Node(28, narr + 32));
    
    dfs(0,0);
    cout<<maxSum<<endl;
    return 0;
}