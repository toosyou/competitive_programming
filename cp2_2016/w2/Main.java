import java.io.*;
import java.util.*;

class QuickScan{
	BufferedReader buffer;
	StringTokenizer tok;

	QuickScan(){
		buffer = new BufferedReader(new InputStreamReader(System.in));
	}

	Boolean hasNext(){
		while( tok == null || !tok.hasMoreElements() ){
			try{
				tok = new StringTokenizer(buffer.readLine());
			}catch(Exception e){
				return false;
			}
		}
		return true;
	}

	String next(){
		if(hasNext())
			return tok.nextToken();
		return null;
	}

	int nextInt(){
		return Integer.parseInt(next());
	}

}

public class Main{

	int[] radius ;

	public static void main(String[] args){

		QuickScan input = new QuickScan();
		PrintWriter output = new PrintWriter(System.out, false);

		this.radius = new int[10001];

		int n = input.nextInt();
		while(n != 0){
			for(int i=0;i<n;++i){
				this.radius[i] = input.nextInt();
			}

			n = input.nextInt();
		}
	}

	static Boolean isOK(){
		
	}
}