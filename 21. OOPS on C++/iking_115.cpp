// EXAMPLE BASED ON THE CONSTRUCTORS
// DISTANCE BETWEEN TWO POINTS USING DISTANCE FORMULA WITH THE HELP OF OOP'S 

#include<iostream>
#include<cmath>
using namespace std;

class Point{
    int x,y;
    friend int calDist(Point o1,Point o2){
        int m= (o1.x-o2.x)*(o1.x-o2.x);
        int n= (o1.y-o2.y)*(o1.y-o2.y);
        int k=m+n;
        return sqrt(k);
    }

public:
    Point(int a,int b){                                        // HERE ARGUMENTS ARE PASSED IN THE CONSTRUCTOR SO IT IS PARAMETERISED CONSTRUCTOR
        x=a;                                                   // ASSIGNING VALUES OF X AND Y AS A AND B
        y=b;
    }
    
    void displayPoint(){
        cout<<"The point is "<<"("<<x<<","<<y<<")"<<endl;
    }
};

int main(){
    Point a(3,4);
    a.displayPoint();

    Point b(6,8);
    b.displayPoint();

    cout<<"Distance between the two given points is ";
    cout<<calDist(a,b);

    return 0;
}