// ROWS WITH MAxIMUM NO. OF 1'S PROBLEM 
// A 2D VECTOR IS GIVEN COSISTING OF ONLY 0'S AND 1'S IN SORTED WAY
// IN THE GIVEN DATA IT IS SORTED SO IT GIVES A CLUE TO OTHER METHOD THAN BRUTE FORCE METHOD OF GOING IN EACH ROW AND COUNT ONE
// AS VECTORS ARE SORTED SO WHEN WE FIND FIRST ONE AFTER THAT ALL WILL BE 1

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
    vector<vector<int>> V(3,vector<int>(4));                   // VECTOR PROTOTYPE
    V={{0,0,0,1},{0,1,1,1},{0,0,1,1}};                         // OUTPUT OF THE VECTOR
    int maxOnes=INT_MIN;                                       // VARIABLE TO COUNT THE TOTAL ONES IN THE ROWS
    int maxOnesRow=-1;                                         // ROW IN WHICH MAX ONES OCCUR AND WHICH IS TO PRINTED AT END FOR OUT ANSWER
    int columnNumber=V[0].size();                              // VARIABLE JUST TO COUNT TOTAL NUMBER OF COLUMNS AS THIS GIVE FIRST ROW SIZE
    int numberOfOnes;                                          // DEFINING A VARIABLE TO BE USED FURTHER

    for(int i=0;i<V.size();i++){                               // TRAVERSING IN LOOP V.SIZE()--> WILL GIVE TOTAL NUMBER OF ROWS IN THE VECTOR
        for(int j=0;j<V[i].size();j++){                        // V[I].SIZE--> WILL GIVE TOTAL NUMBER OF COLUMNS OR TOTAL ELEMENTS IN GIVEN ROW
            if(V[i][j]==1){                                    // IF ELEMENT OF VECTOR IS EQUAL TO 1
                numberOfOnes= columnNumber-j;                  // WAY TO CALCULATE NO. OF ONES IN THE ROW
                if(numberOfOnes>maxOnes){                      // CONDITION WAY TO CHECK MAX NUMBER OF ONES VARIABLE
                    maxOnes=numberOfOnes;                      // WE CAN ALSO USE MAX(  ) OPERATION TO GET MAXIMUM ONE
                    maxOnesRow=i;
                }
                break;                                         // IF WE DONOT USE BREAK THEN IT WILL TRAVERSE ON WHOLE OF THE ROW
            }                                                  // THIS BREAK WILL MAKE IT TO JUMP TO NEXT ROW
            
        }
    }
    
    cout<<maxOnesRow<<endl;                                    // AT END OUR ANSWER WILL BE PRINTED

    // ALTERNATE APPROACH FOR ABOVE QUESTION
    // ROW IN WHICH 1 IS APPEARED AT THE FIRST OF ALL WILL BE THE ROW WHICH CONTAINS MAXIMUM NUMBER OF 1'S
    // WE WILL TRAVERSE FROM THE BACK OF THE VECTORS AND MAKE A VARIABLE OF LEFT MOST ONE SO THAT AFTER THAT WE WILL CHECK OTHERS VECTORS BY THIS ONLY
    
    int leftMostOne=-1;                              // VARIABLE TO CHECK POSITION OF THE FIRST 1 COMING FROM THE END
    int maxOneRow=-1;                                // VARIABLE IN WHICH MAXIMUM ROW WILL COME
    int j=V[0].size()-1;                             // TO JUSTIFY POSITION FROM THE END
    for(int j=V[0].size()-1;j>=0;j--){               // TRAVERSING FROM THE END
        if(V[0][j]==1){                              // CHECKING THE FIRST 1 COMING FROM THE LEFT
            leftMostOne=j;                           // THIS LOOP IS ONLY TO CHECK FOR FIRST ROW POSITION OF 1
        }else{
            break;                                   // IF NOT 1 THEN GET OUT OF THE LOOP
        }
    }
    for(int i=1;i<V.size();i++){                     // NOW FIRST LOOP TO TRAVERSE IN DIFFERENT ROWS
        while(j>=0 && V[i][j]==1){                   // TILL HERE VALUE OF J IS LEFTMOST ONE AND IF WE GET ONE
            leftMostOne=j;                           // THEN LEFT MOST ONE WILL BE CHANGED
            j--;                                     // AND J WILL BE DECREMENTED
            maxOneRow= i;                            // MAXROW WILL BE STORED
        }
    }
    cout<<maxOneRow;








    return 0;
    
}