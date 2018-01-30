import java.lang.*;
import java.util.*;
import java.math.*;

public class Main {
	static long[][] ans = new long[10001][100];
	public static void main(String[] args) {
		for(int i=0;i<100;++i)ans[0][i]=1;
		for(int N=1;N<10001;++N){
			for(int k=1;k<100;++k){
				ans[N][k]=ans[N][k-1];
				if(k*k*k<=N)ans[N][k]+=ans[N-k*k*k][k];
			}
		}
		Scanner cin = new Scanner(System.in);
		while(cin.hasNextInt()){
			System.out.println(ans[cin.nextInt()][99]);
			//System.out.println(has[cin.nextInt()]);
		}
	}
}
