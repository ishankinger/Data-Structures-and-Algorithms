// TRANSPOSE OF 2D ARRAY(ROWS BECOMES COLUMNS AND VICE VERSA)
/**
 * iking149
 */
import java.util.*;

public class iking149 {

    public static void main(String args[]){
    Scanner sc= new Scanner(System.in);
    int rows= sc.nextInt();
    int cols= sc.nextInt();

    int [][]numbers= new int[rows][cols];

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++)
        numbers[i][j]=sc.nextInt();
    }
    for(int i=0;i<cols;i++){                              // I AND J LIMITING VALUES ARE CHANGED
        for(int j=0;j<rows;j++){
        System.out.print(numbers[j][i]+" ");             // HERE NUMBERS[J][I] ROWS BECOME COLS AND VICE VERSA
        }  
        System.out.println();  
    }
    }
}