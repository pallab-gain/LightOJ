/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package _java;

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
                solve1136(i);
            }
            out.flush();
        } catch (Exception e) {
            System.exit(1);
        }
    }

    public void solve1136(int kaseno) throws Exception {

//        ArrayList<BigInteger> arr = new ArrayList<BigInteger>();
//        StringBuilder num = new StringBuilder();
//        for (int i = 1, k = 1; k <= 20; ++i, ++k) {
//            num.append(i);
//            arr.add(new BigInteger(num.toString()));
//        }
//        debug(arr);
//        boolean[] mark = new boolean[arr.size()];
//        for (int i = 0; i < arr.size(); ++i) {
//            boolean flag = arr.get(i).mod(BigInteger.valueOf(3L)).equals(BigInteger.valueOf(0));
//            mark[i] = flag;
//        }
//        debug(mark);

        long lo = lread();
        long hi = lread();
        long cnt=Calculate(lo,hi);
        
        out.write("Case "+kaseno+": "+( (hi-lo+1)-cnt )+"\n");
    }

    public long Calculate(long lo, long hi) {
        long mn = (long) ( Math.ceil( ((double) lo - 1) / 3D) );
        mn = 3L*mn +1;
        long Mn = (long) ( Math.floor( ((double) hi - 1) / 3D) );
        Mn = 3L*Mn +1;
        //debug(mn+"_"+Mn);
        if(mn>Mn)return 0;
        return ( (Mn-mn)/3 )+1 ;
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
//1 4 7 10 13
