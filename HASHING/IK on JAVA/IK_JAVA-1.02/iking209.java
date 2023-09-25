// REVERSING OF STRINGS
/**
 * iking209
 */
public class iking209 {

    public static void printReverse(String str, int idx){
        if(idx==0){
            System.out.println(str.charAt(idx));
            return;
        }
        System.out.println(str.charAt(idx));                     //IMPORTANT PHRASE str.charAt(idx)--> character at i index
        printReverse(str, idx-1);
    }
    public static void main(String args[]){
        String str= "abcdefghijklmnopqrstuvwxyz";
        int idx = 25;
        
        printReverse(str, idx);
    }
}