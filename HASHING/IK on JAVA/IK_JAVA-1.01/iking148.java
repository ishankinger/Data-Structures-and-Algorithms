// ??????????????????? SPIRAL ORDER MATRIX FROM A GIVEN MATRIX FROM USER
/**
 * iking148
 */
import java.util.*;

public class iking148 {

    public static void main(String args[]){
        Scanner sc= new Scanner(System.in);
        int rows= sc.nextInt();
        int cols= sc.nextInt();
       
        int numbers[][]=new int[rows][cols];
        
        for(int i=0;i<rows;i++){                              // INPUT OF MATRIX FROM THE USER
            for(int j=0;j<cols;j++){
                numbers[i][j]=sc.nextInt();
            }
        }
        

    }
}