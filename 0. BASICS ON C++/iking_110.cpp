// FOR LOOPS

#include<iostream>
using namespace std;

int main(){
    
    for(int i=1; i<11; i++){                          // IN THIRD SPACE WE CAN WRITE ANY OPERATION TO BE EXCUTED
        cout<<i<<" ";
    }
    cout<<"\n";
    int k=1;                                          // INITIALISER CAN BE WRITTEN LIKE THIS
    for( ; k<11; k++){                                // HERE SEMICOLON MUST BE WRITTEN
        cout<<k<<" ";
    }

    // SIMILARLY WE CAN ALSO OMMIT UPDATION AND CONDITION ANY OTHER PLACE WHICH WE WILL SEE FURTHER
   
    for(int i=0,j=4; i<5,j>0; i++,j--){                // ONE OR MORE VARIABLES CAN BE DEFINED IN THE FOR LOOP USING COMMAS
        cout<<i<<" "<<j<<endl;
    }
    
    return 0;
}