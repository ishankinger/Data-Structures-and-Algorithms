// X RAISE TO THE POWER N FROM RECURSION WITH STACK HEIGHT 'N'
/**
 * iking206
 */
public class iking206 {

    public static int calcPower(int x, int n){                           // TWO BASE CONDITIONS
        if(n==0){                                                  
            return 1;                                                    // FIRST BASE CONDITION
        }
        if(x==0){                                                        // SECOND BASE CONDITION
            return 0;                                                        
        }
        int k= calcPower(x, n-1);
                                                                       // SIMILAR TO FACTORIAL OF NUMBERS
        int i= k*x;                                                    // OTHER WAY TO WRITE-->> return calcPower(x,n-1)*x
         return i;                                                     // BASICALLY THIS WRITTEN IN RETURN TYPE FUNCTIONS
    }
    public static void main(String args[]){
        System.out.println(calcPower(2,5));
    }
}