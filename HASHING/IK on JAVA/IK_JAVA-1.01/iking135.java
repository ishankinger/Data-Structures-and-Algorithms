// POSITIVE NEGATIVE AND ZERO ENTERED
 /**
 * iking135
 */
import java.util.*;

public class iking135{
    public static void main(String args[]){
    Scanner sc= new Scanner(System.in);
    System.out.println("write set of numbers you want to enter");
    int size= sc.nextInt();
    System.out.println("write the series of numbers whatever you want");
    System.out.println("and please click enter after each number filled");
    int numbers[]= new int[size];

    for(int i=0;i<size;i++){
        numbers[i]=sc.nextInt();
    }
    int a=0;
    int b=0;
    int c=0;
    int i=0;
    while(i!=size){                                                   //for(int i=0;i<size;i++){  CAN ALSO BE USED HERE
     if(numbers[i]<0){
        a++;
        i++;
    }else if(numbers[i]>0){
        b++;
        i++;
    }else{
        c++;
        i++;
    }
}
    System.out.println("total number of positive numbers : "+ b);
    System.out.println("total number of negative numbers : "+ a);
    System.out.println("total number of zeroes entered : "+ c);
    }
}