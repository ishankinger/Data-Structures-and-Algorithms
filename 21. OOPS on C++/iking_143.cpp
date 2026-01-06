 // ONE CLASS TO ANOTHER CLASS TYPE

// OBJ X = OBJ Y --> CLASS Y IS KNOWN AS SOURCE CLASS WHILE CLASS X IS KNOWN AS DESTINATION CLASS
// SUCH CONVERSIONS CAN BE CARRIED OUT BY EITHER CONSTRUCTOR OR A CONVERSION FUNCTION
// WE HAVE TO USE ONE OF THEM OTHERWISE COMPILER WILL SHOW AMBUIGUITY ERRORS

#include<iostream>
using namespace std;

class invent2;          

class invent1{
    int code;
    int items;
    float price;
public:

    invent1(int a, int b, float c){
        code = a;
        items = b;
        price = c;
    }

    void putdata(){
        cout << "Code : " << code << "\n";
        cout << "Items : " << items << "\n";
        cout << "Price : " << price << "\n";
    }

    int getcode(){return code;}

    int getItems(){return items;}

    float getPrice(){return price;}

    operator float(){
        return (items*price);
    }

    // USING CONVERSION FUNCTION WHICH MUST BE DEFINED IN THE SOURCE CLASS
    // THE TYPE NAME IN THIS FUNCTION CAN BE BUILT IN TYPE OR USER DEFINED TYPE
    // operator invent2(){
    //     invent2 temp;
    //     temp.code = code;
    //     temp.value = price * items;
    //     return temp;
    // }
};

class invent2{
    int code;
    float value;
public:
    invent2(){
        code = 0, value = 0;
    }

    invent2(int x, float y){
        code = x;
        value = y;
    }

    void putdata(){
        cout << "Code : " << code << "\n";
        cout << "Value : " << value << "\n\n";
    }

    // CONVERSION CONVERTER CONSTRUCTOR MUST BE DEFINED IN THE DESTINATION CLASS
    // OBJECT IN THE CONSTRUCTOR BELONGS TO THE SOURCE CLASS WHICH IS TO CONVERTED TO THE DESTINATION CLASS
    invent2(invent1 p){
        code = p.getcode();
        value = p.getItems() * p.getPrice();
    }

};

int main(){
    invent1 s1(100,5,140.0);
    invent2 d1;

    float total_value;
    total_value = s1;

    d1 = s1;

    s1.putdata();
    cout << total_value << "\n";
    d1.putdata();

    return 0;
}