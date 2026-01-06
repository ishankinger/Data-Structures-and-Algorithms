// ARRAYS AS POINTERS

#include<iostream>
using namespace std;

void process(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<*(arr+i)<<" ";
    }
    *(arr+1)=33;
}

int main(){
    int arr[3]={15,12,6};
    int n=3;
    int *ptr=&arr[0];

    cout<<ptr<<endl;
    cout<<arr<<endl;                            // SO NAME 'ARRAY' IS ACTUALLY GIVING US THE BASE ADDRESS OF THE WHOLE ARRAY
    
    cout<<*ptr<<endl;                           // SO WITH THE NAME OF THE ARRAY WE CAN ALSO DEREFERENCE THIS
    cout<<*arr<<endl;                           // BOTH WILL GIVE SAME OUTPUT

    cout<<*(ptr+1)<<endl;                       // *(arr+i)--> WILL GIVE US I+1 ELEMENT OF THE ARRAY
    cout<<*(arr+1)<<endl;
    cout<<*ptr+1<<endl;                         // *ARR+1 WILL JUST PRINT ELEMENT VALUE ADDED BY 1
    cout<<*arr+1<<endl;                         // BUT IF WE USE *ARR++ THEN ELEMENT VALUE WILL BE PRINTED AND POINTER WILL SHIFT TO NEXT POSITION

    for(int i=0;i<3;i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
    process(arr,n);
    cout<<"\n";
    
    int *array = new int[3];                     // SYNTAX TO BE USED FOR DECLARATION OF ARRAY THROUGH POINTERS
    array[0]=10;                                 // THIS TYPEE OF SIMILAR SYNTAX IS USED IN OOP'S CLASSES FOR OBJECTS
    array[1]=20;
    array[2]=30;
    process(array,3);
    return 0;
}