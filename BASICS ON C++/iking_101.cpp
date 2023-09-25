// OUTPUT, VARIABLES AND DATATYPE

#include<iostream>                                                 // ANOTHER HEADER FILE IS IOSTREAM FOR INPUT AND OUTPUT PURPOSE
#include<sumByIshan.h>                                             // USING ONE OF THE HEADER FILES FROM INCLUDE FOLDER
using namespace std;                                               // IF NOT WRITTEN IN THE SYNTAX THEN TO PRINT ANYTHING WE WILL WRITE LIKE --> std :: cout<<"________";

int main(){                                                        // MAIN FUNCTION HAVING RETURN TYPE INTEGER

    cout<<"hello world of c++, ishan here"<<endl;                  // WILL PRINT ANYTHING WRINTTEN IN "  "
    cout<<"hello\n"<<endl<<"world"<<endl;                          // TO DO NEXT LINE WE USE 'endl' OR "/N"
    int a=3;                                                       // DEFINING A VARIABLE A OF INT TYPE AS 3
    a=5;                                                           // THIS WILL AUTOMATICALLY CHANGE VALUE TO 5
    cout<<a<<endl;                                                 // WILL PRINT VALUE OF VARIABLE NOT PRINT A
    int b;                                                         // ANOTHER WAY TO DEFINE A VARIABLE
    b=3;                                                           // THEN DEFINING ITS VALUE
    cout<<b<<endl;            

    cout<<sumOfTwoNumbers(5,3)<<"\n";                              // THIS SUM FUNCTION IS DECLARED IN SUMBYISHAN.H FILE                            

    // DIFFERENT DATATYPES

    char name= 'a';                                                // char DEFINED AS ' '
    bool flag= true;
    float apple= 5.3456875;
    double banana= 4.449586384673849479;
    int number=248535839;
    long long int number2=2938583866985934545;
    unsigned int a1=pow(2,32)-1;
    unsigned long long int c = pow(2,64)-1;
    string names= "ishan";                                         // string DEFINED AS "  "

    // USE OF PRINTF FUNCTION TO OUTPUT

    printf("%c\n",name);                                          // CHARACTER DATATYPE 
    printf("%f\n",apple);                                         // FLOAT DATATYPE (PRECISTION GENERALY TILL 6)
    printf("%0.4f\n",apple);                                      // FLOAT WITH PRECISION TILL 4 DECIMALS
    printf("%lf\n",banana);                                       // DOUBLE DATATYPE (ROUND TO 6)
    printf("%0.15lf\n",banana);                                   // VERY HIGH PRECISION
    printf("%d\n",number);                                        // INTEGER DATATYPE
    printf("%lli\n",number2);                                     // LONG LONG INTEGER DATATYPE
    printf("%u\n",a1);                                            // USIGNED INTEGER DATATYPE
    printf("%llu\n",c);                                           // UNSIGNED LONG LONG INTEGER DATATYPE                                             
    
    return 0;
}



