#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int t;
    cout << "\nEnter the number of test cases: ";
    cin >> t;
    while (t--){

        int n;
        cout << "\nEnter the number of towers: ";
        cin >> n;
        vector <int> a(n);
        cout << "\nEnter the number of blocks in each tower: ";
        for (int i = 0; i < n; i++){

            cin >> a[i];
        }
        int x = a[0];
        vector <int> b(a.begin() + 1, a.end());
        sort(b.begin(), b.end());
        for (int y : b){

            if (y > x){

                x += ((y - x) + 1) / 2;
            }
        }
        cout << "\nMaximum number of blocks in tower one: " << x << "\n";
    }
}