// X RAISE TO POWER N FROM FIBONNACI SERIES WITH STACK HEIGHT 'LOG(N)'
/**
 * iking207
 */
public class iking207 {

    public static int calcPower(int n, int x){             
        if(n==0){                                           
            return 1;
        }
        if(x==0){
            return 0;
        }
        if(n % 2==0){ //EVEN NUMBER
            
            return calcPower(n/2,x)*calcPower(n/2,x);               // IN THIS WE ARE NOT MAKING IT A SEPARATE VARIBLE AND JUST 
                                                                    // WRITING STRAIGHT FORWARD AS IN PREVIOUS WE DEFINE INT K
        }else{      //ODD NUMBER                                    // BUT HERE DOING STRAIGHT
           
            return calcPower(n/2,x)*calcPower(n/2,x)*x;
        }
    }
    public static void main(String args[]){
        System.out.println(calcPower(5,2));
    }
}