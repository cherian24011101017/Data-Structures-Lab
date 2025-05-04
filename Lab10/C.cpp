#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    unordered_map <string,int> freq;
    vector<vector<string>> word (3,vector<string>(n));
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> word[i][j];
            freq[word[i][j]]++;
        }
    }
    vector <int> point {0,0,0};
    for(int player=0; player<3; player++)
    {
        for(int i=0;i<n;i++)
        {
            if(freq[word[player][i]]==1)
            {
                point[player]+=3;
            }
            else if(freq[word[player][i]]==2)
            {
                point[player]++;
            }
        }
    }
    cout << point[0] << " " << point[1] << " " << point[2] << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    cout << "\n";
    return 0;
}