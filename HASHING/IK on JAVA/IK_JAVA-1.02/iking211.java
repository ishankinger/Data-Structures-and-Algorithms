// CHECK IF AN ARRAY IS SORTED(STRICTLY INCREASING)
/**
 * iking211
 */
public class iking211 {
                                                             // WAY TO WRITE ARRAY AS VARIABLE--> int arr[]
    public static boolean isSorted(int arr[], int idx ){     // BOOLEAN TYPE FUNCTION TRUE OR FALSE
        if(idx==arr.length-1)
        return true;                                      // IF WE REACH BASE CASE MEANS ALL ELEMENTS SATISFY CONDITION THUS SORTED
        
        if(arr[idx]<arr[idx+1]){
            return isSorted(arr,idx+1);                   // NUMBERS SATISFYING CONDITION SO WE MOVED FORWARD
        }else{
            return false;                                 // IF ANY ONE IS NOTED GETTING THIS RESULT THEN NOT SORTED FALSE
        }
    }
    public static void main(String args[]){
        int arr[]={1,3,5,6,7};
        System.out.println(isSorted( arr,0));
        }
    
}