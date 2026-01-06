// ABSTRACT BASE CLASS & PURE VIRTUAL FUNCTION
// CLASS HAVING ATLEAST ONE PURE VIRTUAL FUNCTION
// AS IN THIS PROBLEM CWH BASE CLASS IS JUST TO GIVE TITLE AND RATINGS TO IT'S DERIVED CLASS AND NOTHING ELSE
// SO THESE TYPES OF CLASSES ARE KNOWN AS ABSTRACT CLASSES
// PURE VIRTUAL FUNCTION ARE ONLY JUST TO TELL THE FUNCTION NAME IN THE

// ABSTRACTION IS A WAY OF HIDING ALL UNNECESSARY DETAILS AND SHOWING ONLY THE IMPORTANT PARTS
// ACCESS MODIFIERS (PRIVATE, PUBLIC, PROTECTED) IS A WAY OF DOING ABSTRACTION
// ANOTHER WAY IS ABSTRACT CLASS
// >> ABSTRACT CLASSES ARE USED TO PROVIDE A BASE CLASS FROM WHICH OTHER CLASSES CAN BE DERIVED
// >> THEY CANNOT BE INSTANTIATED AND CAN'T MAKE OBJECTS AND ARE MEANT TO BE INHERITED
// >> ABSTRACT CLASS ARE LIKE A BLUEPRINT OF OTHER CLASSES AND TYPICALLY USED TO DEFINE AN INTERFACE FOR DERIVED CLASS

#include<bits/stdc++.h>
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
        virtual void display()=0;        // DO NOTHING FUNCTION == PURE VIRTUAL FUNCTION
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

class Shape{                   // AUTOMATICALLY BECOMES AN ABSTRACT CLASS BY USING PURE VIRTUAL FUNCTION 
    virtual void draw() = 0;   // PURE VIRTUAL FUNCTION
};                             // CAN'T MAKE OBJECTS OF THIS CLASS

int main(){
    string title;
    float rating,vl;
    int words;

    // CWH cwh;  --> error

    title="Django tutorial";
    vl=4.56;
    rating=4.87;
    
    CWHVideo djVideo(title,rating,vl);
    djVideo.display();

    title="Django tutorial text";
    words=433;
    rating=4.34;
    
    CWHText djText(title,rating,words);
    djText.display();

    CWH *tuts[2];
    tuts[0]= &djVideo;
    tuts[1]= &djText;

    tuts[0]-> display();
    cout<<endl;
    tuts[1]-> display();

    return 0;
}