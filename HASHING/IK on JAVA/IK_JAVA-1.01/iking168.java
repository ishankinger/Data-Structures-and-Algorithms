// BUBBLE SORTING 
/**
 * iking168
 */
public class iking168 {

    public static void returnArray(int arr[]){        // FUNCTION TO PRINT ARRAY
        for(int i=0;i<arr.length;i++){      
            System.out.print(arr[i]+" ");
        }
      
    }
    public static void main(String args[]){          //TIME COMPLEXITY O(N2)
        int arr[]={7,8,3,2,1,-1};
        for(int i=0;i<arr.length-1;i++){             //OUTER LOOP(SO N-1 TIMES LOOP WILL TRAVERSE IN THE WHOLE ARRAY) 
            for(int j=0;j<arr.length-i-1;j++){       //INNER LOOP(SO FOR I=0 IT WILL TRAVERSE FOR J=0 TO LENGTH -1)
                
                if(arr[j]>arr[j+1]){                 // IMPORTANT TYPE FOR SWAPPING IN ARRAYS
                    int temp=arr[j];                 // DEFINING ELEMENT AT J POSITION
                    arr[j]=arr[j+1];                 // J TO GIVE TO J+1
                    arr[j+1]=temp;                   // J+1 TO J
                }
            }
        }
        returnArray(arr);                             // CALLING FUNCTION
                                                      // HERE CAN ALSO SIMPLY WRITE FOR LOOPS ALSO INSTEAD OF MAKING OTHER FUNCTION
    }
}