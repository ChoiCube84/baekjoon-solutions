#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#include <unordered_map>

#include<ext/pb_ds/assoc_container.hpp>

using namespace std;

struct time_based_hash {
	[[gnu::const]] static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	[[gnu::const]] size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x ^ FIXED_RANDOM);
	}
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> A(n), B(n), C(n), D(n);
    
    for (int i=0; i<n; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    
    __gnu_pbds::gp_hash_table<int, int, time_based_hash> sumCounts;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int sum = A[i] + B[j];
            
            if (sumCounts.find(sum) == sumCounts.end()) {
                sumCounts[sum] = 0;
            }
            
            sumCounts[sum]++;
        }
    }
    
    long long int result = 0;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int sum = C[i] + D[j];
            
            if (sumCounts.find(0 - sum) != sumCounts.end()) {
                result += sumCounts[0 - sum];
            }
        }
    }
    
    cout << result;
    
    return 0;
}
