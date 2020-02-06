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
* #### 새로운 것을 제외한   
- - -
