// FIBBONACI SERIES(0 1 1 2 3 5 8 13 21...........)
/**
 * iking139
 */
import java.util.*;
public class iking139{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n= sc.nextInt();

        int a=0;                                               // INITIALISERS OF THE FIBBONACI SERIES
        int b=1;

        System.out.println(a);                                 // FIRST PRINT INITIALISERS
        System.out.println(b);

        int i=0;                                               // INITIALISATION
        while(i!=n){                                           // i NOT EQUAL TO N MEANS TILL THE USER WANT THE SERIES TO BE PRINTED
            int c=a+b;                                         // NEW VARIABLE HAVING PROPERTY OF THE FIBBONACCI SERIES
            System.out.println(c);                             // FIRST PRINT IT
            a=b;                                               // NOW VALUE OF A IS ASSIGNED TO BE B
            b=c;                                               // SAME FOR B MEANS WE MOVE FURTHER IN THE SERIES 
            i++;                                               // FOR UPDATION TO COUNT THE NUMBERS
        }                                                      // THE PROCESS WILL REPEAT AND LOOP MOVE AGAIN TILL CONDITION REACH AND 
                                                               // SERIES WILL BE PRINTED

    }
}

