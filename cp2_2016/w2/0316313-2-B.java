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

	public static void main(String[] args){

		QuickScan input = new QuickScan();
		PrintWriter output = new PrintWriter(System.out, false);

		int []radius = new int[10001];
		int []sofar = new int[10002];

		int n = input.nextInt();
		while(n != 0){
			for(int i=0;i<n;++i){
				radius[i] = input.nextInt();
			}

			Arrays.sort(radius, 0, n);

			sofar[0] = 0;
			for(int i=0;i<n;++i){
				sofar[i+1] = sofar[i] + radius[i];
			}

			Boolean finded = false;
			for(int i=n-1;i>=0;--i){
				if( radius[i] <= sofar[i] ){
					output.printf("%d%n", i+1);
					finded = true;
					break;
				}
			}
			if(!finded)
				output.printf("0%n");

			n = input.nextInt();
		}
		
		output.flush();
	}

}