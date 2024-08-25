// ARRAY OF OBJECTS FROM CONCEPT OF POINTERS AND ARROW OPERATORS
// SYNTAX TO DEFINE ARRAY FROM POINTERS
// {DATATYPE}__*{NAME OF ARRAY} = new {DATATYPE}[{SIZE OF ARRAY}]
// SO HERE FOR DATATYPE WE WILL BE USING OUR CLASS NAME AS WE ALSO MAKING NEW DATATYPES WITH THE HELP OF OUR CLASS

#include<iostream>
using namespace std;

class shop{                                                       // SIMPLE CLASS TO TELL ID AND PRICE OF ITEMS IN SHOP
    int id;
    float price;
    public:
        void setData(int a, float b){
            id=a;
            price=b;
        }
        void getData(void){
            cout<<"Id of this item is "<< id<<endl;
            cout<<"Price of this item is "<< price<<endl;
        }
};

int main(){
    int size=3;
    int p;
    float q;
    
    shop *ptr= new shop[size];                                 // USING THIS SYNTAX WE CAN GET ARRAY DERIVED FROM POINTERS
    
    shop *ptrTemp=ptr;                                         // ONE MORE POINTER POINTING TO FIRST ELEMENT WHICH WE WILL BE USING FURTHER
    
    for(int i=0;i<size;i++){                                   // LOOP FOR TAKING INPUT OF ID AND PRICE
        cout<<"Id and price of item "<<i+1<<endl;
        cin>>p>>q;
        ptr->setData(p,q);                                     // TAKE DATA FOR FIRST ELEMENT
        ptr++;                                                 // THEN JUMP TO NEXT ONE
    }
    
    for(int i=0;i<size;i++){                                   // TO PRINT ALL ITEM'S ID AND PRICE
        cout<<"Item number : "<<i+1<<endl;
        ptrTemp->getData();                                    // AS PTR IS ALREADY AT LAST POSITION SO WE USE ANOTHER POINTER VARIABLE TO 
        ptrTemp++;                                             // TRAVERSE IN THE ITEMS
    }

    return 0;
}