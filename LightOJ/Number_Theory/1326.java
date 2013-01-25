/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
//package mypkg;

/**
 *
 * @author xerxes
 */
import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

    final String filename = "in";
    long[] memo = new long[1005];
    long[] res = new long[1005];
    public static void main(String[] args) {
        // new Thread(new Main()).start();
        new Thread(null, new Main(), "1", 1 << 25).start();
    }

    public void run() {
        try {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new BufferedWriter(new OutputStreamWriter(System.out));
            //in = new BufferedReader(new FileReader(filename + ".in"));
            // out = new BufferedWriter(new FileWriter(filename+".out"));
            precal();
            int kase = iread();
            for (int i = 1; i <= kase; ++i) {
                solve1326(i);
            }
            out.flush();
        } catch (Exception e) {
            System.exit(1);
        }
    }

    public void solve1326(int kaseno) throws Exception {
        int ith = iread();
        out.write("Case " + kaseno + ": " + res[ith] + "\n");
    }

    public void precal() {
        Arrays.fill(memo, 1);
        Arrays.fill(res, 0);
        memo[0]=1;
        memo[1]=memo[3]=4;
        memo[2]=6;
        res[0]=1;
        res[1]=1;
        res[2]=3;
        res[3]=13;
        for (int i = 4; i <= 1000; ++i) {
             for(int u=i-1;u>=0;--u){
               res[i]= (res[i]+(res[u]*memo[u])%10056)%10056;
           }

           for(int u=i;u>0;--u){
               memo[u]=(memo[u]+memo[u-1])%10056;
           }
        }
    }

    public void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    public int iread() throws Exception {
        return Integer.parseInt(readword());
    }

    public double dread() throws Exception {
        return Double.parseDouble(readword());
    }

    public long lread() throws Exception {
        return Long.parseLong(readword());
    }
    BufferedReader in;
    BufferedWriter out;

    public String readword() throws IOException {
        StringBuilder b = new StringBuilder();
        int c;
        c = in.read();
        while (c >= 0 && c <= ' ') {
            c = in.read();
        }
        if (c < 0) {
            return "";
        }
        while (c > ' ') {
            b.append((char) c);
            c = in.read();
        }
        return b.toString();
    }
}

