import java.io.*;
import java.util.*;
import java.math.*;

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

    String nextLine(){
        if(hasNext())
            return tok.nextToken("\n");
        return null;
    }
}

public class Main{

    private static int[][] mapInput = new int[20][20];

    public static void main(String[] args){
        QuickScanner input = new QuickScanner();
        PrintWriter output = new PrintWriter(System.out, true);

        while( input.hasNext() ){

            String nameTest = input.nextLine();
            if(nameTest.equals("end"))
                break;

            for(int i=1;i<=10;++i){
                String tmpLine = input.nextLine();
                for(int j=1;j<=10;++j){
                    if( tmpLine.charAt(j-1) == '#' )
                        mapInput[i][j] = 0;
                    else
                        mapInput[i][j] = 1;
                }
            }

            output.printf("%s %d%n", nameTest, magicTrick());
        }

        output.flush();
    }

    private static int magicTrick(){

        int resultPressTime = -1;
        for(long i=0 ; i < ((long)1 << 10); ++i){
            int tmpPressTime = 0;
            int[][] mapClone = new int[20][];
            for(int j=0;j<20;++j){
                mapClone[j] = mapInput[j].clone();
            }

            long mask = 1;
            for(int j=0;j<10;++j){
                if( (i & mask) != 0){
                    press( mapClone, 1, j+1 );
                    tmpPressTime++;
                }
                mask <<= 1;
            }

            /*for(int j=1;j<=10;++j){
                if(mapClone[1][j] == 0)
                    System.out.printf("#");
                else
                    System.out.printf("O");
            }
            System.out.printf("%n");*/

            for(int j=2;j<=10;++j){
                for(int k=1;k<=10;++k){
                    if( mapClone[j-1][k] == 1 ){
                        press( mapClone, j, k );
                        tmpPressTime++;
                    }
                }
            }

            Boolean isOK = true;
            for(int j=1;j<=10;++j){
                if( mapClone[10][j] == 1 ){
                    isOK = false;
                    break;
                }
            }

            if(isOK){
                if(resultPressTime == -1)
                    resultPressTime = tmpPressTime;
                else
                    resultPressTime = Math.min( resultPressTime, tmpPressTime );
            }
        }

        return resultPressTime;
    }

    private static void press(int[][] map, int i, int j){
        map[i][j] = map[i][j] == 0 ? 1 : 0;
        map[i-1][j] = map[i-1][j] == 0 ? 1 : 0;
        map[i][j-1] = map[i][j-1] == 0 ? 1 : 0;
        map[i+1][j] = map[i+1][j] == 0 ? 1 : 0;
        map[i][j+1] = map[i][j+1] == 0 ? 1 : 0;
        return;
    }
}
