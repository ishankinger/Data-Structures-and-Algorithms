// PRIME NUMBER OR NOT
/**
 * iking140
 */
import java.util.*;

public class iking140 {

    public static void primeNumber(int n){
        int temp=0; 
         
        for(int i=2;i<=n-1;i++){                  // NUMBER DIVISIBILITY SHOULD BE CHECKED WITH NUMBERS B/W 1 AND N SO THIS LOOP
            
              if(n % i==0){                       // AS IF THIS OKAY THEN IT WILL NOT BE A PRIME 
                temp++;                           // IF WE WRIRE SYSO HERE THEN LOOP WILL GO ON AN IT WILL BE PRINTED AS MUCH TIME                    
            }                                     // AS ANY NUMBER GET DIVISIBLE WITH IT BUT WE DONOT WANT THAT THING SO WE DEFINE TEMP
        }
       
        if(n==1){                                                   // 1 IS NEITHER A PRIME NOR A COMPOSITE NO.
            System.out.println("this is not a prime number");
        
        }else{ if(temp>0){                                          // IF THIS THEN THERE ARE NUMBER WHICH ARE DIVINDING N SO NOT PRIME
            System.out.println("this is not a prime number");
        
        }else{
            System.out.println("this is a prime number");         // OTHER WISE IF NOT DIVIDED THEN NO OTHER NUMBER CAN ALSO DIVIDE
        }                                                           // THIS IF WE THOUGHT MATHEMATICALLY
    }
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.println("enter the number");
        int n= sc.nextInt();
       
        primeNumber(n);
    }
}