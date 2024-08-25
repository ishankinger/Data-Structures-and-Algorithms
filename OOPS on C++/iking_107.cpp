// MAKING ARRAY DATATYPES IN THE CLASS 

#include<iostream>
using namespace std;

class Shop{
    int itemId[100];                           // THESE THINGS DEFAULT ARE PRIVATE
    int itemPrice[100];                        // SO WE CAN ALSO USE ARRAY AS DATATYPE
    int counter;                               // THIS VARIABLE THAT WILL HELP IN TRAVERSING THE ARRAY
    public:                                    // NOW PUBLIC THINGS
        void initCounter(void){                // FUNCTION TO GIVE INITIAL VALUE TO THE COUNTER
            counter=0;                         // THIS COUNTER IS PRIVATE VARIABLE SO IT WILL ONLY BE USED IN THE FUNCTIONS OF THE CLASS
        }
        void getPrice(void);                   // F UNCTION PROTOTYPES
        void setPrice(void);
};

void Shop :: setPrice(void){                   // FUNCTION TO SET PRICE OF THE ARRAY ITEMS
    cout<<"Enter Id of your item"<<endl;       
    cin>>itemId[counter];                      // TAKE INPUT LIKE THIS
    cout<<"Enter Price of your item"<<endl;
    cin>>itemPrice[counter];
    counter++;
};

void Shop :: getPrice(void){                   // PRINT THE PRICE WITH GIVEN ID OF THE ITEMS ARRAY
    for(int i=0;i<counter;i++){
        cout<<"The price of item with Id "<< itemId[i]<<" is "<<itemPrice[i]<<endl;
    }
}

int main(){
    Shop dukaan;                                // AN OBJECT IS MADE FROM CLASS
    dukaan.initCounter();                       
    dukaan.setPrice();                          // THIS WILL MAKE ONLY ONE ITEM TO SET PRICE
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.getPrice();                          // THEN ATLAST PRINT ALL THE ITEMS WITH ID'S AND PRICES
}
// SO IN ABOVE EXAMPLE WE SEE HOW TO USE ARRAY DATATYPE IN CLASSES AND HOW TO TAKE COUNTER, INPUT AND OUTPUT

// MEMORY ALLOCATIONS FOR OBJECTS
// MEMORY SPACE FOR THE OBJECTS IS ALLOCATED WHEN THEY ARE DECALARED
// THIS IS NOT COMPLETELY TURE AS-
// BUT THE MEMBER FUNCTIONS OF CLASS GET MEMORY ONLY ONCE WHEN THEY ARE DEFINED AS A PART OF CLASS SPECIFICATION
// SINCE ALL THE OBJECTS OF THE CLASS USES SAME MEMBER FUNCTIONS
// WHILE THE VARIABLES OF THE OBJECTS ARE ALLOCATED ONLY WHEN THEY ARE DECLARED AS VARIABLE WILL CONTAIN DIFFERENT DATA OF PARTICULAR OBJECTS