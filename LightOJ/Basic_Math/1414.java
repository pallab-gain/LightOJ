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
                solve1414(i);
            }
            out.flush();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public void solve1414(int kaseno) throws Exception {
        String line1 = in.readLine();
        String line2 = in.readLine();
//        line1=line1.replaceAll("[,]", "");
//        line2=line2.replaceAll("[,]", "");
//
//        debug(line1);
//        debug(line2);
        String[] bucket1 = line1.replaceAll("[,]", "").split("[ ]");
        String[] bucket2 = line2.replaceAll("[,]", "").split("[ ]");

        long year1 = FormatYear1(bucket1);
        long year2 = FormatYear2(bucket2);
        long divBy400 = Calculate(year1, year2, 400);
        long divBy100 = Calculate(year1, year2, 100);
        long divBy4 = Calculate(year1, year2, 4);

        long ret = divBy400 - divBy100 + divBy4;
        out.write("Case " + kaseno + ": " + ret + "\n");
    }

    public long Calculate(long yeara, long yearb, int div) {
        long a = (long) Math.ceil(((double) yeara) / div) * div;
        long b = (long) Math.floor(((double) yearb) / div) * div;
        //debug(yeara+"_"+yearb+"_"+div);
        if (a > b) {
            return 0;
        }
        return ((b - a) / div) + 1;
    }

    public long FormatYear1(String[] str) {
        if (str[0].equals("January")) {
            return Long.parseLong(str[2]);
        } else if (str[0].equals("February")) {
            int dat = Integer.parseInt(str[1]);
            if (dat <= 29) {
                return Long.parseLong(str[2]);
            } else {
                return Long.parseLong(str[2]) + 1;
            }
        } else {
            return Long.parseLong(str[2]) + 1;
        }
    }

    public long FormatYear2(String[] str) {
        if (str[0].equals("January")) {
            return Long.parseLong(str[2]) - 1;
        } else if (str[0].equals("February")) {
            int dat = Integer.parseInt(str[1]);
            if (dat < 29) {
                return Long.parseLong(str[2]) - 1;
            } else {
                return Long.parseLong(str[2]);
            }
        } else {
            return Long.parseLong(str[2]);
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

