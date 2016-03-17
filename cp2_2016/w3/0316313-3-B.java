import java.io.*;
import java.util.*;

class QuickScanner{
	BufferedReader buffer;
	StringTokenizer tok;

	QuickScanner(){
		buffer = new BufferedReader( new InputStreamReader(System.in) );
	}

	Boolean hasNext(){
		while( tok == null || !tok.hasMoreElements() ){
			try{
				tok = new StringTokenizer( buffer.readLine() );
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
		QuickScanner input = new QuickScanner();
		PrintWriter output = new PrintWriter(System.out, false);

		int[] result = new int[3];
		int n = input.nextInt();
		for(int k=0;k<n;++k){
			int inputNumber = input.nextInt();
			if( backTrack(inputNumber, 0, result) == true ){
				for(int i=0;i<3;++i){
					output.printf("%d%s", result[i], ( i==2? "" : " " ) );
				}
				output.printf("%n");
			}
			else
				output.printf("-1%n");
		}
		output.flush();
	}

	private static Boolean backTrack(int remain, int depth, int[] result){
		double sqrtRemain = Math.sqrt((double)remain);

		if(remain < 0){
			return false;
		}

		if(depth == 2 ){
			if( (int)sqrtRemain*(int)sqrtRemain == remain ){
				result[2] = (int)sqrtRemain;
				return true;
			}
			else
				return false;
		}

		for(int i=0;i<=(int)sqrtRemain;++i){
			if( backTrack( remain - i*i, depth+1, result ) == true ){
				result[depth] = i;
				return true;
			}
		}
		return false;
	}
}
