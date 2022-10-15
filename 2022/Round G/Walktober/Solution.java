import java.util.*;

class Main{
    public static long check(int[][] inpArr,int N,int M,int P){
        long ans=0;
        for(int j=0;j<N;j++){
            int maximum=Integer.MIN_VALUE;
            for(int i=0;i<M;i++){
                if(inpArr[i][j]>maximum)
                    maximum=inpArr[i][j];
            }
            ans+=(maximum-inpArr[P-1][j]);
        }
        return ans;
    }
    public static void main(String[] agrs){
        Scanner sc=new Scanner(System.in);
        int testCase=sc.nextInt();
        for(int test=1;test<=testCase;test++){
            int M=sc.nextInt();
            int N=sc.nextInt();
            int P=sc.nextInt();
            int[][] inpArr=new int[M][N];
            for(int i=0;i<M;i++){
                for(int j=0;j<N;j++){
                    inpArr[i][j]=sc.nextInt();
                }
            }
            long ans=check(inpArr,N,M,P);
            System.out.println("Case #"+test+": "+ans);
        }
    }
}