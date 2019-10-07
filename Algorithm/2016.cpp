#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int man_pre[5][5];
int wom_pre[5][5];
int m_couple[5];
int w_couple[5];
int w_start_man[5];
void round(){
    for(int i=0; i<5; i++){
        if(w_couple[i] == -1){
            int j = w_start_man[i]; w_start_man[i]++;
            int pre_man = wom_pre[i][j];
            int pre_wom = m_couple[pre_man];
            if(pre_wom != -1){
                for(int k=0; k<5; k++){
                    if(man_pre[pre_man][k] == pre_wom){
                        break;  
                    }
                    if(man_pre[pre_man][k] == i){                            
                        w_couple[pre_wom] = -1;
                        m_couple[pre_man] = i;
                        w_couple[i] = pre_man;
                        break;
                    }
                }
            }
            else{
                m_couple[pre_man] = i;
                w_couple[i] = pre_man;
            }
        }
    }
}

bool endRound(){
    for(int i=0; i<5; i++){
        if(w_couple[i] == -1)
            return false;
    }
    return true;
}

int calc_cur_rank(){
    int cur_couple = m_couple[0];
    for(int i=0; i<5; i++){
        if(cur_couple == i){
            return i;
        }
    }
}

void init(){
    for(int i=0; i<5; i++){
        m_couple[i] = -1;
        w_couple[i] = -1;
        w_start_man[i] = 0;
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T; cin >> T;
	while(T--){
        for(int i=0; i<5; i++){
            man_pre[0][i] = i;
        }
        for(int i=1; i<5; i++){
            for(int j=0; j<5; j++){
                cin>>man_pre[i][j];
                man_pre[i][j]-=6;
            }
        }
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                cin>>wom_pre[i][j];
                wom_pre[i][j]-=1;
            }
        }
        
        init();
        while(!endRound()){
            round();
        }
        //for(int i=0; i<5; i++){
        //    cout<<i<<" couple "<<m_couple[i]<<endl;;
        //    cout<<m_couple[i]<<" couple "<<w_couple[m_couple[i]]<<endl;
        //}
        
        int pre_rank = calc_cur_rank();
        if(pre_rank == 0){
            cout<<"NO"<<endl;
            continue;
        }

        while(next_permutation(man_pre[0], man_pre[0]+5)){
            init();
            while(!endRound()){
                round();
            }
            int new_rank = calc_cur_rank();
            if(new_rank < pre_rank){
                cout<<"YES"<<endl;
                goto ESCAPE_TO_NEXT_CASE;
            }
        }
        cout<<"NO"<<endl;
        ESCAPE_TO_NEXT_CASE:;
	}
	return 0;
}