/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
//package pkg1065;

/**
 * 1065
 *
 * @author xerxes
 * 1:16:39 PM  May 25, 2012
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
                solve(i);
            }
            out.flush();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
    int mod;

    public void solve(int kaseno) throws Exception {
        out.write("Case " + kaseno + ": ");
        int a = iread();
        int b = iread();
        int n = iread();
        int m = iread();
        int ret = Fib(a, b, n, m);
        out.write(ret + "\n");
    }

    public int Fib(int a, int b, int n, int m) {
        mod = 1;
        for (int i = 1; i <= m; ++i) {
            mod *= 10;
        };

        if (n == 0) {
            return domod(a);
        }
        if (n == 1) {
            return domod(b);
        }

        Matrix mat = new Matrix(2, 2);
        mat.data[0][0] = 1;
        mat.data[0][1] = 1;
        mat.data[1][0] = 1;
        mat.data[1][1] = 0;

        Matrix get = mat.Pow(mat, n - 1);

        Matrix tmp = new Matrix(2, 1);
        tmp.data[0][0] = b;
        tmp.data[1][0] = a;

        Matrix ret = tmp.Multiply(get, tmp);

//        tmp.Print();
//        get.Print();
//        ret.Print();
        return ret.data[1][0];
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

