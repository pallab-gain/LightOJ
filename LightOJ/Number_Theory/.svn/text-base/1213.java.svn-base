 /*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
//package mypkg;

/**
 * @author xerxes
 * May 11, 2012
 * I have not failed, I have just found 10000 ways that won't work.
 */
import java.io.*;
import java.awt.*;
import java.text.*;
import java.math.*;
import java.util.*;
import java.lang.*;

public class Main implements Runnable {

    final String filename = "in";
    long mod;
    public static void main(String[] args) {
        // new Thread(new Main()).start();
        new Thread(null, new Main(), "1", 1 << 25).start();
    }

    public void run() {
        try {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new BufferedWriter(new OutputStreamWriter(System.out));
//            in = new BufferedReader(new FileReader(filename + ".in"));
            // out = new BufferedWriter(new FileWriter(filename+".out"));
            int kase = iread();
            for (int i = 1; i <= kase; ++i) {
                solve1213(i);
            }
            out.flush();
        } catch (Exception e) {
            System.exit(1);
        }
    }

    public void solve1213(int kaseno) throws Exception {
        int n = iread();
        int k = iread();
        mod = iread();
        long w = domod( k*fastPow(n,k-1) );
        long ret=0;
        int value;
        for(int i=0;i<n;++i){
            value=iread();
            ret = domod(ret+ domod(value*w) );
        }
        out.write("Case "+kaseno+": "+ret+"\n");
    }

    public long domod(long x) {
        if (x < 0) {
            x += mod;
        }
        return x % mod;
    }

    public long fastPow(long a, long b) {
        long x = 1L;
        long y = domod(a);

        while (b > 0) {
            if ((b & 1) != 0) {
                x = domod(x * y);
            }
            y = domod(y * y);
            b >>= 1;
        }
        return domod(x);
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

