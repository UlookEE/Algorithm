#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
 
vector<int> xPosV;
vector<int> massV;
vector<double> ansV;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T; cin >> T;
    for (int test = 1; test <= T; test++) {
        xPosV.clear();
        massV.clear();
        ansV.clear();
        int N; cin >> N;
        for (int i = 0; i < N; i++) {
            int tmp; cin >> tmp;
            xPosV.push_back(tmp);
        }
        for (int i = 0; i < N; i++) {
            int tmp; cin >> tmp;
            massV.push_back(tmp);
        }
 
        for (int i = 0; i < N - 1; i++) {
            double start = xPosV[i];
            double end = xPosV[i + 1];
            while (start < end) {
                double mid = (start + end) / 2;
                double leftPow = 0;
                double rightPow = 0;
                for (int j = 0; j < N; j++) {
                    if (xPosV[j] < mid)
                        leftPow += massV[j] / (mid - xPosV[j]) / (mid - xPosV[j]);
                    else if(xPosV[j] > mid)
                        rightPow += massV[j] / (mid - xPosV[j]) / (mid - xPosV[j]);
                }
                if (leftPow == rightPow || abs(mid - start) < 0.000000000001) {
                    ansV.push_back(mid);
                    break;
                }
                else if (leftPow < rightPow)
                    end = mid;
                else if (leftPow > rightPow)
                    start = mid;
            }
        }
        cout << fixed;
        cout.precision(10);
        cout << '#' << test << ' ';
        for (int i = 0; i < ansV.size(); i++)
            cout << ansV[i] << ' ';
        cout << '\n';
    }
    return 0;
}
