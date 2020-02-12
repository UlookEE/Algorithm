#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int M, N, K;

struct Bus {
	int num;
	int sx, sy, ex, ey;
	int visitOrd;
};
vector<int> xb[100001];
vector<int> yb[100001];

Bus b[5001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> K;

	for (int i = 0; i < K; i++) {
		int num;
		cin >> num;
		cin >> b[num].sx >> b[num].sy >> b[num].ex >> b[num].ey;
		b[num].visitOrd = 0;
		if (b[num].sx > b[num].ex)
			swap(b[num].sx, b[num].ex);
		if(b[num].sy == b[num].ey)
			xb[b[num].sy].push_back(num);
		if (b[num].sy > b[num].ey)
			swap(b[num].sy, b[num].ey);
		if (b[num].sx == b[num].ex)
			yb[b[num].sx].push_back(num);	
	}
	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	queue<int> bq;
	for (auto busNum : yb[sx]) {
		Bus& bus = b[busNum];
		if (bus.sy <= sy && bus.ey >= sy) {
			bq.push(busNum);
			bus.visitOrd++;
		}
	}

	for (auto busNum : xb[sy]) {
		Bus& bus = b[busNum];
		if (bus.sx <= sx && bus.ex >= sx) {
			bq.push(busNum);
			bus.visitOrd++;
		}
	}
	int ans = 0;
	while (!bq.empty()) {
		Bus& bus = b[bq.front()];
		bq.pop();
		if (ex >= bus.sx && ex <= bus.ex && ey >= bus.sy && ey <= bus.ey) {
			ans = bus.visitOrd;
			break;
		}
		if (bus.sx == bus.ex) {
			for (int i = bus.sy; i <= bus.ey; i++) {
				for (auto busNum : xb[i]) {
					Bus& nBus = b[busNum];
					if (!nBus.visitOrd && nBus.sx <= bus.sx && nBus.ex >= bus.sx) {
						nBus.visitOrd = bus.visitOrd + 1;
						bq.push(busNum);
					}
				}
			}
			for (auto busNum : yb[bus.sx]) {
				Bus& nBus = b[busNum];
				if (!nBus.visitOrd && !(nBus.sy > bus.ey || nBus.ey < bus.sy)) {
					nBus.visitOrd = bus.visitOrd + 1;
					bq.push(busNum);
				}
			}
		}
		else if (bus.sy == bus.ey) {
			for (int i = bus.sx; i <= bus.ex; i++) {
				for (auto busNum : yb[i]) {
					Bus& nBus = b[busNum];
					if (!nBus.visitOrd && nBus.sy <= bus.sy && nBus.ey >= bus.sy) {
						nBus.visitOrd = bus.visitOrd + 1;
						bq.push(busNum);
					}
				}
			}
			for (auto busNum : xb[bus.sy]) {
				Bus& nBus = b[busNum];
				if (!nBus.visitOrd && !(nBus.sx > bus.ex || nBus.ex < bus.sx)) {
					nBus.visitOrd = bus.visitOrd+1;
					bq.push(busNum);
				}
			}
		}
	}
	cout << ans << endl;
}
