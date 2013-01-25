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
                solve1297(i);
            }
            out.flush();
        } catch (Exception e) {
            System.exit(1);
        }
    }
    final double eps = 1e-9;
    public void solve1297(int kaseno) throws Exception {
        double w=dread();
        double l=dread();
        out.write("Case "+kaseno+": ");
        double x = ( l + w - Math.sqrt(l * l - l * w + w * w ) )/ 6.0 + eps;
        w-= (x*2.);
        l-= (x*2.);
        double ret=w*l*x;
        Format fd = new DecimalFormat("0.0000000");
        String res = fd.format(ret);
        out.write(res+"\n");

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
