//package mypkg;

import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

    final String filename = "in";

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
            int kase = iread();
            for (int i = 1; i <= kase; ++i) {
                solve1317(i);
            }
            out.flush();
        } catch (Exception e) {
            System.exit(1);
        }
    }

    public void solve1317(int kaseno) throws Exception {
        int N = iread();  //number of people
        int M = iread();  //number of busket
        int K = iread();  //number of turns to play
        double P = dread(); //probability of a success

        double ret = 0.0;
        for (int people = 1; people <= N; ++people) {
            double tmp = Get(M, K, P);
            ret += tmp;
        }
        Format df = new DecimalFormat("0.000000");
        String res = df.format(ret);
        out.write("Case " + kaseno + ": " + res + "\n");
    }

    public double Get(int M, int K, double P) {
//        double ret=0;
//        for(int i=1;i<=K;++i){
//            ret+= P;
//        }
//        return ret;
        return P * K;
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

