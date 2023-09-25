// REVERSE STRINGS
/**
 * iking156
 */
import java.util.*;

public class iking156 {
   
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        String name= sc.next();
        String name1=sc.next();
       
        String newString = "";

        for(int i=name.length()-1;i>=0;i--){
            newString += name.charAt(i);
        }
        System.out.println(newString);

        // USING STRING BUILDER CONCEPT
        
        StringBuilder sb= new StringBuilder(name1);
        for(int i=0;i<sb.length()/2;i++){
            
            int front= i;
            int back= sb.length()-1-i;

            char frontChar= sb.charAt(front);
            char backChar= sb.charAt(back);
             
            sb.setCharAt(front,backChar);
            sb.setCharAt(back,frontChar);
        }
        System.out.println(sb);
    }
    
}
