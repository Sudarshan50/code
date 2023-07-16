#include <iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int fact(int a)
{
    int ui = 1;
    if (a == 0)
    {
        ui = 1;
    }
    else
    {
        for (int i = 1; i <= a; i++)
        {
            ui = ui * i;
        }
    }
    return ui;
}
int commut(int b, int c)
{
    int ans = 1;
    if (c == 0)
    {
        ans = 1;
    }
    else if (b == c)
    {
        ans = 1;
    }

    else
    {
        ans = fact(b) / (fact(c) * fact(b - c));
    }
    return ans;
}

int main()
{
    int p;
    cin >> p;
    int n = abs(p);
    vector<pair<int,string> > sh;

    for (int i = 0; i < n + 2; i++)
    {
        int fuck = commut(n, i);
        string ab = "a";
        string cd = "b";
        string gd = "+";
        string pd = "^";
        string temp1 = to_string(n - i);
        string temp2 = to_string(i);
        if (temp1[0] == '1' && temp2[0] == '0')
        {
            ab.append(gd);
            sh.push_back(make_pair(fuck, ab));
        }
        else if ((temp1[0] == '0') && (temp2[0] == '1') && (stoi(temp2) != n))
        {
            cd.append(gd);
            sh.push_back(make_pair(fuck, cd));
        }
        else if ((temp1[0] == '0') && (temp2[0] == '1') && (stoi(temp2) == n))
        {
            sh.push_back(make_pair(fuck, cd));
        }

        else if (temp1[0] == '1' && temp2[0] == '1')
        {
            ab.append(cd);
            ab.append(gd);
            sh.push_back(make_pair(fuck, ab));
        }
        else if (temp1[0] == '1')
        {
            ab.append(cd);
            ab.append(pd);
            ab.append(temp2);
            ab.append(gd);
            sh.push_back(make_pair(fuck, ab));
        }
        else if ((temp1[0] == '0') && (stoi(temp2) != n))
        {
            cd.append(pd);
            cd.append(temp2);
            cd.append(gd);
            sh.push_back(make_pair(fuck, cd));
        }
        else if (temp2[0] == '1' && stoi(temp2) != n)
        {
            ab.append(pd);
            ab.append(temp1);
            ab.append(cd);
            ab.append(gd);
            sh.push_back(make_pair(fuck, ab));
        }
        else if (temp2[0] == '0')
        {
            ab.append(pd);
            ab.append(temp1);
            ab.append(gd);
            sh.push_back(make_pair(fuck, ab));
        }
        else if (temp1[0] == '0' && stoi(temp2) == n)
        {
            cd.append(pd);
            cd.append(temp2);
            sh.push_back(make_pair(fuck, cd));
        }
        else
        {
            ab.append(pd);
            ab.append(temp1);
            ab.append(cd);
            ab.append(pd);
            ab.append(temp2);
            ab.append(gd);
            sh.push_back(make_pair(fuck, ab));
        }
    }
    sh.pop_back();

    if (p > 0)
    {
        for (int i = 0; i < sh.size(); i++)
        {
            if (sh[i].first == 1)
            {
                cout << sh[i].second;
            }
            else
            {
                cout << sh[i].first << sh[i].second;
            }
        }
        cout << endl;
    }
    else if (p==0)
    {
        cout<<"1"<<endl;
    }
    
    else
    {
        cout << "1/";
        for (int i = 0; i < sh.size(); i++)
        {
            if (sh[i].first == 1)
            {
                cout << sh[i].second;
            }
            else
            {
                cout << sh[i].first << sh[i].second;
            }
        }
        cout << endl;
    }
    return (0);
}