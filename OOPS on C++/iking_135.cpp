// EXAMPLE ON VIRTUAL FUNCTIONS

#include<iostream>
#include<cstring>
using namespace std;

class CWH{
    protected:
        string title;
        float rating;
    public:
        CWH(string s, float r){
            title=s;
            rating= r;
        }
        virtual void display(){};
};

class CWHVideo : public CWH{
        int videolength;
    public: 
        CWHVideo(string s, float r, int vl) : CWH(s,r){
            videolength=vl;
        }
        void display(){
            cout<<"This is an amazing video with title "<<title<<endl;
            cout<<"Ratings "<<rating<<" out of 5 stars "<<endl;
            cout<<"length of the video is : "<<videolength<<" minutes"<<endl;
        }
};

class CWHText : public CWH{
        int words;
    public: 
        CWHText(string s, float r, int wc) : CWH(s,r){
            words=wc;
        }
        void display(){
            cout<<"This is an amazing title with title "<<title<<endl;
            cout<<"Ratings "<<rating<<" out of 5 stars "<<endl;
            cout<<"words of this text tutorial is : "<<words<<endl;
        }
};

int main(){
    string title;
    float rating,vl;
    int words;

    title="Django tutorial";
    vl=4,56;
    rating=4.87;
    
    CWHVideo djVideo(title,rating,vl);
    // djVideo.display();

    title="Django tutorial text";
    words=433;
    rating=4.34;
    
    CWHText djText(title,rating,words);
    //djText.display();

    CWH *tuts[2];
    tuts[0]= &djVideo;
    tuts[1]= &djText;

    tuts[0]-> display();
    cout<<endl;
    tuts[1]-> display();

    return 0;
}