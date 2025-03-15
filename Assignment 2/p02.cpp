#include <iostream>
#include <vector>
using namespace std;

void con(long long n, vector<long long>& h) {
    long long maxheight = 0;
    long long l = 0, r = n - 1;
    long long bestl = 0, bestr = 0;  
    while (l < r) {
        long long height = min(h[l], h[r]);
        if (height > maxheight) {
            maxheight = height;
            bestl = l;  
            bestr = r;  
        }

        if (h[l] < h[r]) {
            l++;
        } else {
            r--;
        }
    }

    cout << bestl << " " << bestr << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        vector<long long> h(n);

        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }

        con(n, h);
    }

    return 0;
}
