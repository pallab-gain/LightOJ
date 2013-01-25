/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


/**
 *
 * @author xerxes
 */
import java.io.*;
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
            //in = new BufferedReader(new FileReader(filename));
            // out = new BufferedWriter(new FileWriter(filename+".out"));
            int kase = iread();
            for (int i = 1; i <= kase; ++i) {
                solve(i);
            }
            out.flush();
        } catch (Exception e) {
            System.exit(1);
        }
    }

    public void solve(int kaseno) throws Exception {
        Point A = readPoint();
        Point B = readPoint();
        long res = laticPoint(A.x,A.y,B.x,B.y);
        out.write( "Case "+kaseno+": "+(res)+"\n" );
    }
    public long laticPoint(long x1, long y1, long x2, long y2){
        long dx = Math.abs(x1-x2);
        long dy = Math.abs(y1-y2);
        if(dx==0)return dy+1;
        if(dy==0)return dx+1;
        return gcd(dx,dy)+1;
    }
    public long gcd(long a, long b){
        while(b!=0){
            long temp = a%b;
            a=b;
            b=temp;
        }
        return a;
    }

    public Point readPoint() throws Exception {
        long x = lread();
        long y = lread();
        return new Point(x,y);
    }
    public class Point{
        long x;
        long y;
        Point(long x,long y){
            this.x=x;
            this.y=y;
        }
        void Translate(long dx, long dy){
            x=x+dx;
            y=y+dy;
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
