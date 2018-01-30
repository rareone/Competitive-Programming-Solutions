import java.lang.*;
import java.util.*;
import java.math.*;

public class Main {
	static BigInteger ans;
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while(cin.hasNextInt()){
			int N=cin.nextInt(),A=cin.nextInt();ans=BigInteger.ZERO;
			for(int i=1;i<=N;++i){
				ans = ans.add((BigInteger.valueOf(i)).multiply(BigInteger.valueOf(A).pow(i)));
			}System.out.println(ans.toString());
		}
	}
}
