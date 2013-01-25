/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mypkg;

import java.io.*;
import java.math.*;
import java.util.*;

public class Main {

    BufferedReader reader;
    StringTokenizer token;
    

    
    public static void main(String[] args) throws IOException {
        Main ob = new Main();
        ob.run();
        System.exit(0);
    }

    public void run() throws IOException {
        reader = new BufferedReader(new InputStreamReader(System.in));
        token = new StringTokenizer("");

        int kase=nextInt();
        for(int i=1;i<=kase;++i){
            BigInteger a= new BigInteger(nextToken());
            BigInteger b= new BigInteger(nextToken());
            a=a.abs();
            b=b.abs();
            System.out.print("Case "+i+": ");
            System.out.println(a.mod(b).compareTo(BigInteger.ZERO)==0 ? "divisible" : "not divisible");
        }
    
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    String nextToken() throws IOException {
        while (token == null || !token.hasMoreTokens()) {
            String line = reader.readLine();
            token = new StringTokenizer(line);
        }
        return token.nextToken();
    }
}
