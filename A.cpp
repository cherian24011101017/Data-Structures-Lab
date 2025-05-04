#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int ans = solve();
        cout << ans << "\n";
    }
    cout << "\n";
}

int solve()
{
    int n;
    cin >> n;
    vector <int> numbers(n);
    for(int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    int moves;
    vector <bool> count(n+1,false);
    for(int i=n;i>=0;i--)
    {
        if(count[numbers[i]])
        {
            moves=i+1;
            return moves;
        }
        count[numbers[i]]=true;
    }
    return 0;
}