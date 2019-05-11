import java.util.Scanner;
import java.math.*;
public class Main1065{
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        int n=cin.nextInt();
        for(int i = 1;i<=n;i++){
            BigInteger a,b,c;
            a=cin.nextBigInteger();
            b=cin.nextBigInteger();
            c=cin.nextBigInteger();
            if(a.add(b).compareTo(c)>0){
                System.out.println("Case #"+i+": true");
            }else System.out.println("Case #"+i+": false");
        }
        cin.close();
    }
}