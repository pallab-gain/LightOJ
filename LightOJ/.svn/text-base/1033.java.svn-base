/**
 *
 * @author xerxes
 */

import java.util.*;
import java.text.*;
import java.math.*;
import java.lang.*;
import java.io.*;

class Main {

    /**
     * @param args the command line arguments
     */
    BufferedReader reader;
    StringTokenizer token;
    int[][] dp;
    String line;
    public static void main(String[] args) throws IOException{
        Main ob = new Main();
        ob.Run();
        System.exit(0);
    }
    public void Run()throws IOException{
        reader = new BufferedReader( new InputStreamReader(System.in) ) ;
        //reader = new BufferedReader( new FileReader("in") ) ;
        token = new StringTokenizer("");

        int n = nextInt();
        for( int i=1; i<=n; ++i ){
            line = nextToken();
            int var = dpit();
            System.out.println("Case "+i+": "+var);
        }

    }
    public int dpit(){
        int len = line.length();
        dp = new int[ len ][ len ];
        for(int i=0;i<len;++i ){
            for(int j=0;j<len;++j ){
                dp[i][j] = -1;
            }
        }

        int retval = go(0,len-1);
        return retval;
    }

    public int go( int st, int ed ){
        if( st>ed ){
            return 0;
        }
        if( dp[st][ed]!=-1 ){
            return dp[st][ed];
        }
        int best = (int)1e6;
            int v1 = 1+go(st+1,ed);
            best = Math.min(best, v1);
            int v2 = 1+go(st,ed-1);
            best = Math.min(best, v2);
            if( line.charAt(st)== line.charAt(ed) ){
                int v3 = go(st+1,ed-1);
                best = Math.min(best, v3);
            }

        dp[st][ed]=best;
        return best;
    }

    String nextToken()throws IOException{
        while( token==null || !token.hasMoreTokens() ){
            token = new StringTokenizer( reader.readLine() );
        }
        return token.nextToken();
    }
    int nextInt()throws IOException{
        return Integer.parseInt( nextToken() );
    }

}

