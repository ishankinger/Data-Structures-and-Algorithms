// FIBONNACI SERIES FROM RECURSION
/**
 * iking205
 */
public class iking205 {

    public static void printFib(int a, int b, int n){          // VOID TYPE AS SYSO IS USED
        if(n==0){
            return;                                            // ALSO HERE ONLY RETURN WRITTEN AS NOTHING TO BE RETURNED
        }
        int c=a+b;                                              // NOT DEFINE IN MAIN SO WRITTEN IN THIS NOT IN BRACKETSS
        System.out.println(c);
        printFib(b,c,n-1);                                      // FOR FURTHER SERIES A AND B BECOMES B AND C
    }
    public static void main(String args[]){
        int a=0, b=1;
        System.out.println(a);
        System.out.println(b);
        int n=10;
        printFib(a,b,n-2);                                   // N-2 AS TWO TERMS A AND B ARE WRITTEN ALREADY SO WE NEED N TERMS
    }
}