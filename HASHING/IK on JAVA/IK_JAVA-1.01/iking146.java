// MAXIMUM AND MINIMUM NUMBER IN AN ARRAY OF INTEGERS
/**
 * iking146
 */
import java.util.*;

public class iking146 {

    public static void main(String args[]){

        Scanner sc=new Scanner(System.in);
        int size =sc.nextInt();
        int numbers[]=new int[size];

        for(int i=0;i<size;i++){                        // INPUTS FOR ARRAY
            numbers[i]=sc.nextInt();
        }
        
        int max = numbers[0];                          // DEFINING TWO VARIABLE WITH SOME NUMBER OF THE ARRAY SUPPOSE
        int min = numbers[0];                          // 0 INDEX NUMBER
        

        for(int i=0;i<numbers.length;i++){             // NOW WE START A LOOP IN THE ARRAY

           if(numbers[i]> max){                        // IF FROM GOING THROUGH THE NUMBER WE GET ANY NUMBER GREATER THAN IT THEN
                max=numbers[i];                        // WE WILL ASSIGN MAX TO BE EQUAL TO THAT NUMBER
            }
           
            if(numbers[i]<min){                        // SIMILARLY FOR MINIMUM
                min= numbers[i];
            }
         }
         System.out.println("largest number is : "+  max);
         System.out.println("smallest number is : "+ min) ;
         
}
}