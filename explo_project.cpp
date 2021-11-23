#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int32_t main()
{
    // time_t start = time(&start);
    // freopen("inp.txt","r", stdin);
    // freopen("outp.txt", "w", stdout);

    cout << "\nEnter no. of 1st semester subjects: ";
    int n1;
    cin >> n1;
    cout << "Enter subject codes:" << endl;
    string arr1[n1];
    for (int i = 0; i < n1; i++)
        cin >> arr1[i];
    cout << endl;

    cout << "Enter no. of 3rd semester subjects including the 1st sem overload subjects:  ";
    int n2;
    cin >> n2;
    cout << "Enter subject codes:" << endl;
    string arr2[n2];
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];
    cout << endl;

    cout << "Enter no. of 5th sem subjects including the 1st sem and 2nd sem overloads: ";
    int n3;
    cin >> n3;
    string arr3[n3];
    cout << "Enter subject codes:" << endl;
    for (int i = 0; i < n3; i++)
        cin >> arr3[i];
    cout << endl;

    cout << "Enter no. of 7th sem subjects including the overloads: ";
    int n4;
    cin >> n4;
    string arr4[n4];
    cout << "Enter subject codes:" << endl;
    for (int i = 0; i < n4; i++)
        cin >> arr4[i];
    cout << endl;

    cout << "Enter no. of 9th sem subjects including overloads: ";
    int n5;
    cin >> n5;
    string arr5[n5];
    cout << "Enter subject codes:" << endl;
    for (int i = 0; i < n5; i++)
        cin >> arr5[i];
    cout << endl;

    map<string, vector<string>> adj;
    map<string, int> color;

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            if (i != j)
                adj[arr1[i]].push_back(arr1[j]);
        }
    }
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (i != j)
                adj[arr2[i]].push_back(arr2[j]);
        }
    }
    for (int i = 0; i < n3; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            if (i != j)
                adj[arr3[i]].push_back(arr3[j]);
        }
    }
    for (int i = 0; i < n4; i++)
    {
        for (int j = 0; j < n4; j++)
        {
            if (i != j)
                adj[arr4[i]].push_back(arr4[j]);
        }
    }
    for (int i = 0; i < n5; i++)
    {
        for (int j = 0; j < n5; j++)
        {
            if (i != j)
                adj[arr5[i]].push_back(arr5[j]);
        }
    }

    for (auto x : adj) //Initialize the color of each node to -1
        color[x.first] = -1;

    color[adj.begin()->first] = 1;
    vector<bool> alreadyAssigned(n1 + n2 + n3);

    auto it = adj.begin();
    it++;
    map<string, vector<string>>::iterator i;
    for (i = it; i != adj.end(); i++)
    {
        fill(alreadyAssigned.begin(), alreadyAssigned.end(), false);

        for (auto av : adj[i->first])
            if (color[av] != -1)
                alreadyAssigned[color[av]] = true;

        int c;
        for (c = 1; c <= n1 + n2 + n3; c++)
            if (alreadyAssigned[c] == false)
                break;

        color[i->first] = c;
    }

    for (auto ele : adj)
        cout << "Vertex  " << ele.first << " ---> Color " << color[ele.first] << endl;

    int mx = INT_MIN;
    for (auto ele : color)
    {
        mx = max(mx, ele.second);
    }

    cout << "\nNumber of colors required: " << mx << endl
         << endl;

    for (int i = 1; i <= mx; i++)
    {
        cout << "DAY : " << i << endl;
        for (auto ele : adj)
        {
            if (color[ele.first] == i)
                cout << ele.first << " ";
        }
        cout << endl
             << endl;
    }

    // time_t end = time(&end);
    // cout<<end-start<<" seconds"<<endl;

    return 0;
}

// 5
// phy102 ma101 cy101 cso101 me104
// 8
// cso211 ma102 me102 cso204 phy101 ma101 me104 phy102
// 7
// ma301 cso301 ma302 ma101 ma102 me102 me104
// 7
// ma401 cso411 cso301 ma302 me102 ma101 ma302
// 7
// ma502 cso522 cso501 ma401 cso411 ma101 ma102