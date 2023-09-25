// RETURN GREATEST OF TWO NUMBERS
/**
 * iking133
 */
import java.util.*;

 
public class iking133 {

   public static void greatestOfNumbers(int a, int b){                 // WHEN WE USE VOID FUNCTION ALWAYS THERE WILL BE SYSO
    if(a==b){
        System.out.println("both are equal");                        // AND THE RETURN ONLY WRITTEN NOTHING WITH IT
    }else if(a>b){
        System.out.println("first number is greater");
    } else{
        System.out.println("second number is greater");
    }
    // return;                                                           // ALSO FOR VOID FUNCTION IT IS NOT COMPULSORY TO WRITE RETURN
   }                                                                  // WITHOUT WRITTING IT CAN ALSO WORKS
   
   public static int greatest(int a, int b){
    if(a==b){                                                         // SO HERE WITH END OF CONDITION WE CAN WRITE RETURN
        return 1 ;                                                    // SOMETHING TO WRITE WITH WRITTEN IS COMPULSORY
    }else if(a>b){                                                    // AND RETURNING THING SHOULD BE OF DATATYPES DEFINED IN FUNCTION
        return a;
    }else{
        return b;
    }    
    
    }

   public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    int a= sc.nextInt();
    int b= sc.nextInt();
     
    greatestOfNumbers(a,b);                                                     // SO A LOT FUNCTIONS CAN BE MADE BUT CAN BE USED ONLY
    System.out.println(greatest(a,b)+"  if 1 comes means both are equal");      // ONLY IN THE MAIN FUNCTION

   }
   

   }


   


   

