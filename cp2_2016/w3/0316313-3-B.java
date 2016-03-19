import java.io.*;
import java.util.*;

class QuickScanner{
    BufferedReader buffer;
    StringTokenizer tok;

    QuickScanner(){
        buffer = new BufferedReader(new InputStreamReader(System.in));
    }
    QuickScanner(String input){
        buffer = new BufferedReader(new StringReader(input) );
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

    String nextLine(){
        if(hasNext())
            return tok.nextToken("\n");
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

        int[] inputNumber = new int[100];
        int[] values = new int[100];
        int[] number = new int[100];

        while( input.hasNext() ){
            QuickScanner lineScanner = new QuickScanner( input.nextLine() );

            int t = lineScanner.nextInt();
            int n = lineScanner.nextInt();
            int sizeValue = 1;

            if( t == 0 && n == 0 )
                break;

            for(int i=0;i<n;++i){
                inputNumber[i] = lineScanner.nextInt();
            }

            values[0] = inputNumber[0];
            number[0] = 1;
            for(int i=1;i<n;++i){
                if( values[sizeValue-1] == inputNumber[i] ){
                    number[sizeValue-1] += 1;
                }
                else{
                    values[sizeValue] = inputNumber[i];
                    number[sizeValue] = 1;
                    sizeValue += 1;
                }
            }

            output.printf("Sums of %d:%n", t);
            ArrayList<Integer> result = new ArrayList<Integer>();
            if( backTracking( t, 0, values, number, sizeValue, result, output ) == false )
                output.printf("NONE%n");
        }

        output.flush();
    }

    private static Boolean backTracking(int remain, int depth, int[] values, int[] number, int size, ArrayList<Integer> result, PrintWriter output){

        if(remain == 0){
            output.printf("%d", result.get(0) );
            for(int i=1;i<result.size();++i){
                output.printf("+%d", result.get(i));
            }
            output.printf("%n");
            return true;
        }
        else if(remain < 0 || depth >= size)
            return false;

        Boolean findResult = false;
        for(int i=0;i<number[depth];++i){
            result.add( values[depth] );
        }
        for(int i=number[depth];i>=0;--i){
            findResult = findResult | backTracking( remain - values[depth]*i, depth+1, values, number, size, result, output);
            if( i != 0)
                result.remove( result.size()-1 );
        }


        return findResult;
    }

}
