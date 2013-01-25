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
                solve1331(i);
            }
            out.flush();
        } catch (Exception e) {
            System.exit(1);
        }
    }
    
    public void solve1331(int kaseno) throws Exception {
        double r1=dread();
        double r2=dread();
        double r3=dread();
        double a = r1+r2;
        double b = r2+r3;
        double c = r3+r1;


        double tmp1 = (b*b+c*c-a*a)/(b*c*2);
        double tmp2 = (c*c+a*a-b*b)/(c*a*2);
        double tmp3 = (a*a+b*b-c*c)/(a*b*2);
        double A = Math.acos( tmp1 );
        double B = Math.acos( tmp2 );
        double C = Math.acos( tmp3 );

        double s = (a+b+c)/2;
        double Area = Math.sqrt( s*(s-a)*(s-b)*(s-c) );

        
        double p1 = (A*r3*r3)/2;
        double p2 = (B*r2*r2)/2;
        double p3 = (C*r3*r3)/2;
        //debug(r1+" "+r2+" "+r3);
        //debug(a+" "+b+" "+c);
        //debug(A+" "+B+" "+C);

        double area1 = (r3*r3*A)/2.;
        double area2 = (r1*r1*B)/2;
        double area3 = (r2*r2*C)/2.;
        //debug(area1+" "+area2+" "+area3);
        DecimalFormat df = new DecimalFormat("0.00000000000000");
        String ret = df.format( Area-(area1+area2+area3) );
        out.write("Case "+kaseno+": "+ret+"\n");

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
