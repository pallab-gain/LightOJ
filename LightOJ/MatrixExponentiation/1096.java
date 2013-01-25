/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pkg1096;

/**
 * 1096
 *
 * @author xerxes
 * 11:15:33 PM  May 25, 2012
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
                solve(i);
            }
            out.flush();
        } catch (Exception e) {
            System.exit(1);
        }
    }

    public void solve(int kaseno) throws Exception {
        out.write("Case " + kaseno + ": ");
        int n = iread();
        int a = iread();
        int b = iread();
        int c = iread();
        if (n <= 2) {
            out.write("0\n");
            return;
        }
        Matrix A = new Matrix(4, 4);
        A.data[0][0] = a;
        A.data[0][2] = b;
        A.data[0][3] = 1;
        A.data[1][0] = 1;
        A.data[2][1] = 1;
        A.data[3][3] = 1;
        //3 = 0
        Matrix B = A.Pow(A, n - 3);
        Matrix C = new Matrix(4, 1);
        C.data[3][0] = c;
        Matrix D = C.Multiply(B, C);
//        B.Print();
//        D.Print();
        out.write(D.data[0][0] + "\n");
    }

    public class Matrix {

        int[][] data;
        int row;
        int col;

        public Matrix(int rowCount, int colCount) {
            this.row = rowCount;
            this.col = colCount;
            this.data = new int[rowCount][colCount];
        }

        public Matrix Multiply(Matrix A, Matrix B) {
            Matrix result = new Matrix(A.row, B.col);
            for (int i = 0; i < A.row; ++i) {
                for (int j = 0; j < B.row; ++j) {
                    for (int k = 0; k < B.col; ++k) {
                        int var = domod(A.data[i][j] * B.data[j][k]);
                        result.data[i][k] = domod(result.data[i][k] + var);
                    }
                }
            }
            return result;
        }

        public Matrix Pow(Matrix A, int pow) {
            Matrix res = A;
            while (pow > 0) {
                if ((pow & 1) != 0) {
                    res = Multiply(res, A);
                }
                A = Multiply(A, A);
                pow >>= 1;
            }
            return res;
        }

        public void Print() {
            for (int i = 0; i < row; ++i) {
                debug(data[i]);
            }
        }
    }
    final int mod = 10007;

    public int domod(int var) {
        if (var < 0) {
            var += mod;
        }
        return var % mod;
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
