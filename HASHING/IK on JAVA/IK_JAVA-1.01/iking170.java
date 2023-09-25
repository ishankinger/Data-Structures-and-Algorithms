// ????????????????????????????????? INSERTION SORTING
/**
 * iking170
 */
public class iking170 {
    public static void returnArray(int arr[]){        // FUNCTION TO PRINT ARRAY
        for(int i=0;i<arr.length;i++){      
            System.out.print(arr[i]+" ");
        }
    }
    public static void main(String args[]){
        int arr[]={7,8,3,1,2};                        // ARRAY TO BE SORTED
        for(int i=1;i<arr.length;i++){                // OUTER LOOP TRAVERSE FULLY
            int current=arr[i];                       // VARIABLE ON Ith ELEMENT OF THE ARRAY
            int j=i-1;                                // TAKE J AS I-1
            while(j>=0 && current<arr[j]){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=current;
        }
        returnArray(arr);
    }
}