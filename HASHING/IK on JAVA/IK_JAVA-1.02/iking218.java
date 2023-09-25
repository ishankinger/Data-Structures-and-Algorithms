// COUNT TOTAL PATHS IN A MAZE OF N,M 
/**
 * iking218
 */
public class iking218 {

    public static int countPaths(int i, int j,int n, int m) {
        if(i==n-1&&j==m-1){
            return 1;
        }
        if(i==n||j==m){
            return 0;
        }
        int downPaths= countPaths(i+1,j,n,m);
        int rightPaths= countPaths(i,j+1,n,m);
        return rightPaths+downPaths;                   // IT IS NOT PROPER SUM BUT IT IS NET PATH TO BE COVER
    }
    public static void main(String arg[]){
        System.out.println(countPaths(0,0,3,3));
    }
}