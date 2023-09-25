// LINEAR SEARCH
/**
 * iking143
 */
import java.util.*;

public class iking143 {

    public static void main(String args[]){
        Scanner sc= new Scanner(System.in);
         int size= sc.nextInt();

      int numbers[]= new int[size];
     
      for(int i=0; i<size;i++){                               // EVERYTHING SAME BUT ONLY DIFFERENCE IS THAT IN THIS THE OUTPUT LOOP
        numbers[i]=sc.nextInt();                              // WE ARE USING IF ELSE CONDITION 
    }
      int x= sc.nextInt();

      for(int i=0; i<numbers.length;i++){                               //NUMBER.LENGTH==SIZE
       if(numbers[i]==x){                                               //THERE IS NO ()AFTER WRITTING LENGTH KEEP IN MIND
        System.out.println("index where x occurs :"+ i);
      }


    }
}
}
