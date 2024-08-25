// NESTING OF MEMBER FUNCTIONS
// FUNCTIONS WHICH ARE USED IN A PARTICULAR CLASS ARE CALLED MEMBER FUNCTIONS
// NESTING MEANS IN ANY MEMBER FUNCTIONS WE CAN USE THAT FUNCTION IN OTHER FUNCTION
// EVEN PRIVATE MEMBER FUNCTIONS CAN BE USED IN OTHER MEMBER FUNCTIONS WHILE OBJECT CAN'T USE THE PRIVATE FUNCTIONS USING DOT OPERATOR

#include<iostream>
#include<string>
using namespace std;

class Binary{                                              // A BINARY CLASS IS MADE
    private:
        void ones(void);                                   // A PRIVATE FUNCTION IS CREATED
        string s= "101010";                                // DEFINING A STRING
    public :                                               // IN PUBLIC SOME FUNCTIONS ARE DEFINED
        void read(void);                                   // FUNCTIONS PROTOTYPES ARE WRITTEN HERE SO THAT WE CAN USE THEM OUT OF THE CLASS ALSO
        void chk_bin(void);                                // ALSO ONE MORE POINT THAT THESE FUNCTIONS SHOULD BE WRITTEN AFTER THE CLASS
        void display(void);                                // WRITTEN ABOVE CLASS WILL SHOW ERROR AS SIMILAR TO DIFFERENT FUNCTIONS ARE WRITTEN
};                                                         // ABOVE THE MAIN FUNCTION


void Binary :: read(void){                                 // THIS IS SIMPLE SYNTAX TO TAKE INPUT OF STRING S FROM THE USER
    cout<<"Enter a Binary Number "<<endl;
    cin>>s;
}

void Binary :: chk_bin(void){                              // FUNCTION TO CHECK WHETHER THE STRING CONTAINS OF ONLY BINARY NO. THAT IS ONLY
    int k=0;                                               // 0'S AND 1'S OR NOT
    for(int i=0;i<s.length();i++){
        if(s.at(i)!='0' && s.at(i)!='1'){                  // IF ANY OTHER ELEMENT NOT PRESENT THEN FALSE CONDITION WILL OCCUR AND K++
            
        }else{
            k++;
        }
    }
    if(k==s.length()){                                    // SO IF FOR WHOLE TRAVERSAL IT IS FINE THEN IT IS A BINARY NUMBER
        cout<<"it is a binary number"<<endl;
    }else{                                                // OTHERWISE NOT A BINARY NUMBER
        cout<<"it is not a binary number"<<endl;
    }
}

void Binary :: ones(void){                                 // FUNCTION TO NOT THE GIVEN BINARY NUMBER 
    int k=0;
    cout<<"our modified string is -"<<endl;                          
    for(int i=0;i<s.length();i++){                          // MEANS IF IT IS 1 MAKE IT 0 AND VICE VERSA
        if(s.at(i)=='0'){
            cout<<'1';
        }else if(s.at(i)=='1'){
             cout<<'0';
        }else{
           k++;
        }
    }
    if(k>0){
         cout<<"it is not a binary number thus cannot get it's not "<<endl;
    }
    cout<<endl;
};

void Binary :: display(void){                               // PRINTING OF THE CHARACTERS OF THE GIVEN STRING
    cout<<"our given string is "<<endl;                     // FUCNTION FOR NESTING OF THE LOOP
    for(int i=0;i<s.length();i++){
        cout<<s.at(i);
    }
    cout<<endl;
    chk_bin();                                             // THIS IS WHAT NESTING OF MEMBER FUNCTIONS MEANT
    ones();                                                // JUST WRITE THE NAME OF THE MEMBER FUNCTION NOTHING ELSE TO DO IN ANOTHER MEMBER
    cout<<endl;
};

int main(){
    Binary b;                                               // NOW MAKING AN OBJECT OF BINARY CLASS
    b.read();                                               // CALLING APPROPIATE FUNCTIONS TO BE USED
    b.display();                                            // IN THIS FIRST CHK_BIN WILL BE USED AND THEN ONES AND THEN ITS MAIN CODE 
   // b.ones();                                             // IN THIS ITS MAIN CODE WILL BE USED
}

// IF ANY MEMBER FUNCTIONS ARE MADE PRIVATE THEN WE CANNOT USE THAT DIRECTLY IN MAIN FUNCTION AS DONE ABOVE
// BUT NESTING OF THAT PRIVATE FUNCTION CAN BE DONE
// IN ABOVE WE MAKE ONES FUNCTION AS PRIVATE SO IT IS USED IN NESTED FUNCTIONS BUT WHEN WE USE IT DIRECTLY USING OBJECT.ONES() THEN IT WILL 
// SHOW AN EROR