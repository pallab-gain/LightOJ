/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
//package mypkg;

/**
 * @author xerxes
 * 
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
                //TODO CODE HERE
                solve1311(i);
            }
            out.flush();
        } catch (Exception e) {
            System.exit(1);
        }
    }

    public void solve1311(int kaseno) throws Exception {
        double v1 = dread();
        double v2 = dread();
        double vb = dread();
        double a1 = dread();
        double a2 = dread();
        Format df = new DecimalFormat("0.00000000");
        double getD = calcDist(v1, v2, a1, a2);
        double getT1 = calcTime(v1, a1);
        double getT2 = calcTime(v2,a2);
        double getDB = vb*Math.max(getT1, getT2);
        String res1 = df.format(getD);
        String res2 = df.format(getDB);
        
        out.write("Case " + kaseno + ": " + res1 + " " + res2 + "\n");
    }

    public double calcDist(double v1, double v2, double a1, double a2) {
        return (((v1 * v1) / a1) + ((v2 * v2) / a2)) * ((double) 0.5);
    }

    public double calcTime(double v1, double a1) {
        return v1 / a1;
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

