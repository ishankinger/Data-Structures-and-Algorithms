// PALLINDRONMIC NUMBER PYRAMID
/**
 * iking128
 */
import java.util.*;

public class iking128 {

    public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();

    for(int i=1;i<=n;i++){                                  //OUTER LOOP

        for(int j=1;j<=n-i;j++){                            // FIRST INNER LOOP
            System.out.print("  ");
        }
        for(int j=i;j>=1;j--){                              //SECOND INNER LOOP
            System.out.print(j+" ");                        //STARTING FROM I ROW NO. AND DECREASING TILL 1
        }
        for(int j=2;j<=i;j++){                             // THIRD INNER LOOP
            System.out.print(j+" ");                       // STARTING FROM SECOND COL AND INCREASING J
        }
        System.out.println();
    }
      // ?????????????????????????????????????????/PASCALS TRIANGLE                            
       
    }
}

