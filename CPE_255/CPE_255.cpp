#include<iostream>

using namespace std;

int GCD(int i, int j) {
    if (j%i == 0) return i;
    return GCD(j%i, i);
}

int main() {
    
    int G,N;
    while (cin >> N)
    {
        if (N == 0) return 0;
        G = 0;

        // j must > i
        for(int i=1;i<N;i++) {
            for(int j=i+1;j<=N;j++)
            {
                G += GCD(i,j);
            }
        }
        cout << G << endl;
    }

    return 0;
}