/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


/**
 * @author xerxes
 * May 16, 2012
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
                solve1211(i);
            }
            out.flush();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public void solve1211(int kaseno) throws Exception {
        int n = iread();
        Cube ret = new Cube();
        for (int i = 0; i < n; ++i) {
            Cube tmp = new Cube();
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 3; ++k) {
                    tmp.cor[k][j] = iread();
                }
            }
            if (i == 0) {
                ret = tmp;
            } else {
                for (int j = 0; j < 3; ++j) {
                    int Mn = Math.max(ret.cor[j][0], tmp.cor[j][0]);
                    int mn = Math.min(ret.cor[j][1], tmp.cor[j][1]);
                    if (Mn >= mn) {
                        ret = new Cube();
                    } else {
                        ret.cor[j][0]=Mn;
                        ret.cor[j][1]=mn;
                    }
                }

            }
            
        }

        out.write("Case " + kaseno + ": " + ret.Area() + "\n");

    }

    class Cube {

        int[][] cor;

        Cube() {
            this.cor = new int[3][2];
        }

        public int Area() {
            int ret = 1;
            for (int i = 0; i < 3; ++i) {
                ret *= (cor[i][1] - cor[i][0]);
            }
            return ret;
        }

        @Override
        public String toString() {
            String ret = "[ ";
            for (int i = 0; i < 3; ++i) {
                ret += " " + cor[i][1] + " " + cor[i][0] + " _ ";
            }
            ret += " ] ";
            return ret;
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

