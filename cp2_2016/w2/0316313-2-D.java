import java.io.*;
import java.math.BigInteger;
import java.util.*;

class QuickScanner{

	BufferedReader buffer;
	StringTokenizer tok;

	QuickScanner(){
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
		QuickScanner input = new QuickScanner();
		PrintWriter output = new PrintWriter(System.out, false);

		BigInteger[] result = new BigInteger[1000];
		while( input.hasNext() ){
			int sizeResult = 0;
			int n = input.nextInt();
			int r = input.nextInt();
			String inputNumberString = input.next();
			int originalSum = getNumberSum(inputNumberString);

			String lastConcatString = "0";
			for(int i=0;i<10;++i){
				if( getNumberSum( originalSum+i ) == r ){
					for(int j=0;j<inputNumberString.length()+1;++j){
						String concatString = inputNumberString.substring(0,j) + String.valueOf(i) + inputNumberString.substring(j);
						if( !lastConcatString.equals(concatString) ){
							result[sizeResult++] = new BigInteger(concatString);
							lastConcatString = concatString;
						}
					}
				}
			}
			Comparator<BigInteger> c = new Comparator<BigInteger>(){
				public int compare(BigInteger a, BigInteger b){
					return a.compareTo(b);
				}
			};
			Arrays.sort( result, 0, sizeResult, c);
			for(int i=1;i<sizeResult-1;++i){
				String resultString = result[i].toString();
				for(int j=0;j< n-resultString.length(); ++j){
					output.printf("0");
				}
				output.printf("%s%n", resultString);
			}
		}

		output.flush();
	}

	private static int getNumberSum(String input){
		int sum = 0;
		for(int i=0;i<input.length();++i){
			sum += input.charAt(i) - (int)'0';
		}
		return sum;
	}

	private static int getNumberSum(int input){
		while(input >= 10){
			int sum = 0;
			while(input > 0){
				sum += input%10;
				input /= 10;
			}
			input = sum;
		}
		return input;
	}
}
