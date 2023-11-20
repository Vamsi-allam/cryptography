/* 5. Kohli have plain text “wewishtoreplaceplayer”. Can you build encryption process and find out what is the cipher text he needs send to BCCI. 
Help him out by using monoalphabatic cipher. Hint: use any one-to-one mapping between  alphabets.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string encr_text = "WEWISHTOREPLACEPLAYER";
    vector<pair<char,char>>mapp;
    mapp.push_back({'A','A'});
    mapp.push_back({'B','N'});
    mapp.push_back({'C','D'});
    mapp.push_back({'D','R'});
    mapp.push_back({'E','E'});
    mapp.push_back({'F','W'});
    mapp.push_back({'G','I'});
    mapp.push_back({'H','C'});
    mapp.push_back({'I','K'});
    mapp.push_back({'J','S'});
    mapp.push_back({'K','O'});
    mapp.push_back({'L','H'});
    mapp.push_back({'M','T'});
    mapp.push_back({'N','B'});
    mapp.push_back({'O','F'});
    mapp.push_back({'P','G'});
    mapp.push_back({'Q','J'});
    mapp.push_back({'R','L'});
    mapp.push_back({'S','M'});
    mapp.push_back({'T','P'});
    mapp.push_back({'U','Q'});
    mapp.push_back({'V','U'});
    mapp.push_back({'W','V'});
    mapp.push_back({'X','X'});
    mapp.push_back({'Y','Y'});
    mapp.push_back({'Z','Z'});
    string msg = "";
    for(int i=0;i<encr_text.size();i++)
    {
        for(const auto& p:mapp)
        {
            if(p.first == encr_text[i])
            {
                msg+=p.second;
                break;
            }
        }
    }
    cout<<"The message is : "<<msg;
    return 0;
}
