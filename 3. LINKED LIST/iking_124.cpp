// LIST DATASTRUCTURE

#include<bits/stdc++.h>
using namespace std;

int main(){
    list<int>l;
    for(int i=4;i<=8;i++) l.push_back(i);
    for(int i=3;i>=1;i--) l.push_front(i);

    for(auto it=l.begin();it!=l.end();it++){    // FOR PRINTING WE USE ITERATOR
        cout<<(*it)<<" ";
    }
    cout<<"\n";

    l.pop_back();

    for(auto it=l.begin();it!=l.end();it++){    // FOR PRINTING WE USE ITERATOR
        cout<<(*it)<<" ";
    }
    cout<<"\n";

    l.pop_front();

    for(auto it=l.begin();it!=l.end();it++){    // FOR PRINTING WE USE ITERATOR
        cout<<(*it)<<" ";
    }
    cout<<"\n";

    //cout<<l[0];     DOESNOT WORK FOR THIS

    cout<<l.empty()<<"\n";
    cout<<l.front()<<"\n";
    cout<<l.back()<<"\n";
    return 0;
}