// SUM OF N NATURAL NUMBERS FROM RECURSION
/**
 * iking203
 */
public class iking203 {

    public static void printSum(int i, int n, int sum){              // WRITE VARIABLE WHICH WE WILL DEFINE IN MAIN CLASS
        if(i==n){
            sum+=n;                                                  // SECONC THING IS TO WRITE CONDITION BUT HAVE TO WRITE FIRST
            System.out.println(sum);                                 //HERE ONE TIME PRINTED WHEN IT REACHES BASE CASE
            return;                                                  // 'RETURN' TO BE WRITTEN COMPULSORY
        }
        sum +=i;                                                     // FIRST WRITE THIS THING
        printSum(i+1,n,sum);                                         // CALLING FUNCTION FOR MAKING FURTHER STACKS
       
        System.out.println(i);                                       // THIS SYSO TO SHOW STACKS IN RECURSION
        System.out.println(n);
        System.out.println(sum);
        
    }
    public static void main(String args[]){
        printSum(1,5,0);                                     // WAY TO WRITE THIS SO NOT TO DEFINE VALUE SEPARATELY
    }
}