#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack <string> B,F;
string now;
int main()
{
    string opt;
    now = "http://www.acm.org/";
    while(cin >> opt)
    {
        if(opt == "QUIT")
            break;
        if(opt == "VISIT")
        {
            cin >> opt;
            cout << opt << endl;
            B.push(now);
            now = opt;
            while(!F.empty())
                F.pop();
        }
        else if(opt == "BACK")
        {
            if(!B.empty())
            {
                F.push(now);
                now = B.top();
            }
            else
            {
                cout << "Ignored" << endl;
                continue;
            }
            cout << now << endl;
            B.pop();
        }
        else if(opt == "FORWARD")
        {
            if(!F.empty())
            {
                B.push(now);
                now = F.top();
            }
            else
            {
                cout << "Ignored" << endl;
                continue;
            }
            cout << now << endl;
            F.pop();
        }
    }
}
