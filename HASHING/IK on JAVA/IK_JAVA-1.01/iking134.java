//CIRCUMFERENCE OF CIRCLE
/**
 * iking134
 */
import java.util.*;

public class iking134 {

    public static double circumference(double rad){              // JUST TO SHOW EXAMPLE OF FUNCTON WITH OTHER DATATYPES
        double circm= 2*(3.14)*rad;
        return circm;
    }   
    public static void main(String args[]){
        Scanner sc= new Scanner(System.in);
        double rad= sc.nextDouble();
        double circm= circumference(rad);

        System.out.println("circumference of radius : "+ circm);

    }
}
