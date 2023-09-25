// FIRST AND LAST OCCURENCE OF AN ELEMENT IN THE STRING
/**
 * iking210
 */
public class iking210 {
    
    public static int first=-1;    // INITIALISED VALUE AND WE DONOT WANT TO CHANGE THEM IN THE WHOLE PROCESS
    public static int last=-1;     //ACTUALLY INDEX IS STARTING FROM 0 SO 

   public static void findOccurrence(String str, int idx, char element){         // FOR a,b,c WE USE DATATYPE --> CHAR
   if(idx==str.length()){
    System.out.println(first);
    System.out.println(last);
    return;
   }
    char currChar= str.charAt(idx);                     // IMPORTANT PHRASE
        if(currChar==element){
            if(first==-1){
                first=idx;
            }else{
                last=idx;
            }
        }
        findOccurrence(str,idx+1,element);
    }
    public static void main(String args[]){
        findOccurrence("bcdiandan",0,'a');
    }
   }
