// 0-1 TRIANGLE
/**
 * iking124
 */
public class iking124 {

    public static void main(String args[]){
        for(int i=1;i<=7;i++){                           // PATTERN OF HALF TRIANGLE SAME
                                                         // SO USING SAME CODE FOR INNER AND OUTER LOOP
            for(int j=1;j<=i;j++){
              
                int sum=i+j;                              // BUT PATTERN NOTICED 
               
               if(sum%2==0){                              // SO WE ARE USING IF ELSE STATEMENT IN FOR LOOP 
                    System.out.print(" 1 ");
                } else{
                    System.out.print(" 0 ");
                }
            }
            System.out.println();
        }
    }
}
