import java.util.*;
import java.math.*;

public class Main {
	static BigInteger[] has = new BigInteger[2001],ans = new BigInteger[2001],exac = new BigInteger[2001];
	public static void main(String[] args) {
		for(int i=0;i<2001;++i)has[i]=ans[i]=exac[i]=BigInteger.ZERO;
		has[3]=has[4]=has[2]=BigInteger.valueOf(1);
		has[6]=has[5]=BigInteger.valueOf(3);;
		has[7]=BigInteger.valueOf(1);
		for(int i=1;i<2001;++i){
			ans[i]=exac[i]=BigInteger.ZERO;
			if(i<=7)exac[i]=exac[i].add(has[i]);
			if(i==6)exac[i]=exac[i].subtract(BigInteger.ONE);
			for(int k=2;k<=7 && i-k>=0;++k){
				exac[i]=exac[i].add(exac[i-k].multiply(has[k]));
			}
		}
		exac[6]=exac[6].add(BigInteger.ONE);
		for(int i=1;i<=2000;++i)ans[i]=ans[i].add(ans[i-1].add(exac[i]));
		Scanner cin =new Scanner(System.in);
		while(cin.hasNextInt()){
			System.out.println(ans[cin.nextInt()].toString());
			//System.out.println(has[cin.nextInt()]);
		}
	}
}
