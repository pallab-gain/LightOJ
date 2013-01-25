/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mypkg;

/**
 * @author xerxes
 * May 15, 2012
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
            //in = new BufferedReader(new InputStreamReader(System.in));
            out = new BufferedWriter(new OutputStreamWriter(System.out));
            in = new BufferedReader(new FileReader(filename + ".in"));
            // out = new BufferedWriter(new FileWriter(filename+".out"));
            int kase = iread();
            for (int i = 1; i <= kase; ++i) {
                //TODO CODE HERE
                solve1216(i);
            }
            out.flush();
        } catch (Exception e) {
            System.exit(1);
        }
    }
    final double pii = ((double)(2.))*Math.acos(0) ;
    public void solve1216(int kaseno) throws Exception {
        int r1=iread(),r2=iread(),h=iread(),p=iread();

        double R1 = (double)r2;
        double R2 = ((double)((r1-r2)*p ))/h ;
        R2+=r2;
        double H = (double)p;

        double ret = pii*(R1*R1 + R2*R2 + R1*R2)*H;
        ret/=3.;
        Format df = new DecimalFormat("0.0000000000");
        String res = df.format(ret);
        out.write("Case "+kaseno+": "+res+"\n");
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
