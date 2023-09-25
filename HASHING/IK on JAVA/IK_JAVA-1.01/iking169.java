// SELECTION SORTING (REVERSE TYPE OF BUBBLE SORTING) 
/**
 * iking169
 */
public class iking169 {
   
    public static void returnArray(int arr[]){        // FUNCTION TO PRINT ARRAY
        for(int i=0;i<arr.length;i++){      
            System.out.print(arr[i]+" ");
        }
        }
    public static void main(String args[]){
        int arr[]={7,8,3,1,2};                        // ARRAY TO BE SORTED
        for(int i=0;i<arr.length-1;i++){              // OUTER LOOP(TRAVERSING IN THE WHOLE LOOP)
            int smallest= i;                          // CHOOSE FIRST SMALLEST ELEMENT TO COMPARE WITH OTHERS
            for(int j=i+1;j<arr.length;j++){          // INNER LOOP(TRAVERSE AFTER THE ELEMENT CHOSEN AS SMALLEST)
                if(arr[smallest]>arr[j]){             // IF ANY OTHER SMALLER ELEMENT THAN SMALLEST IS THERE THEN 
                    smallest=j;                       // SMALLEST WILL BECOME J
                }
            }
            int temp=arr[smallest];                    // NOW FROM I=0 IN FIRST TRAVERESE WE WILL GET THE SMALLEST NUMBER
            arr[smallest]=arr[i];                      // SO WE WILL DO SWAPPING WITH RESPECTIVE I
            arr[i]= temp;
        }
        returnArray(arr);
    }

}