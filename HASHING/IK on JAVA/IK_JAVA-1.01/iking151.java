//CONCEPT OF STRINGS
/**
 * iking151
 */
import java.util.*;


public class iking151 {

    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        String name=sc.next();
        String sentence=sc.nextLine();

        // METHODS OF STRINGS

        System.out.println("your name is : " + name);
        System.out.println(name.toLowerCase());
        System.out.println(name.toUpperCase());
        System.out.println(sentence.trim());
        System.out.println(name.replace('i','j'));
        System.out.println(name.startsWith("is"));
        System.out.println(name.endsWith("er"));
        System.out.println(name.equals("ishaan"));
        System.out.println(name.equalsIgnoreCase("Ishan)"));

        // OTHER WAY OF .REPLACE WITH THE HELP OF FOR LOOP AND IF CONDITION

        String result= "";                           // FIRST TAKEN EMPTY 
        for(int i=0;i<name.length();i++){
            if(name.charAt(i)=='i'){
                result += 'e';                       // IF I COMES THEN ADD E OTHERWISE ADD THAT CHARACTER ITSELF
            }else{
                result += name.charAt(i);
            }
        }
        System.out.println(result);

    }
}
