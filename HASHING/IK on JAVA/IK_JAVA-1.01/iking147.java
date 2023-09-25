// CHECK ASCENDING ORDER OR NOT
/**
 * iking147
 */
import java.util.*;

public class iking147 {

    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int size = sc.nextInt();

        int numbers[]= new int[size];

        for(int i=0;i<size;i++){                         // INPUT FOR AN ARRAY
            numbers[i]=sc.nextInt();
        }
        int temp=0;                                      // DEFINED FOR THE SAME PURPOSE AS THAT FOR IN PRIME NO.TYPE QUESTION

        for(int i=0;i<size-1;i++){                       // GOING IN ARRAY AS LOOP TILL LAST SECOND AS AFTER THAT NO COMPARISON OF LAST 
            if(numbers[i]<numbers[i+1]){                 // NOW THE PAIRS WHICH SATISFY THIS CONDITION WILL AUTOMATICALLY           
                temp++;                                  // INCREASE TEMP NUMBER
            }
        }
        if(temp==numbers.length-1){                                   // FOR N NUMBERS THERE WILL BE N-1 PAIRS AND IF THAT EQUALS TEMP 
            System.out.println("this is in ascending order");      // THUS IT MEANS THAT ALL ARE SATISFYING THEN ASCENDING ORDER
        }else{
            System.out.println("this is not an ascending order");   // OTHERWISE NOT IN ASCENDING
        }
    }
}
