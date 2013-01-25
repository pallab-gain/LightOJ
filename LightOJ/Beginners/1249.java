/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mypkg;

/**
 * @author xerxes
 * May 14, 2012
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
                solve1249(i);
            }
            out.flush();
        } catch (Exception e) {
            System.exit(1);
        }
    }

    public void solve1249(int kaseno) throws Exception {
        int npeople = iread();
        Student[] Students = new Student[npeople];
        String name;
        int x, y, z;
        for (int i = 0; i < npeople; ++i) {
            name = readword();
            x = iread();
            y = iread();
            z = iread();
            Students[i] = new Student(name, x * y * z);
        }
      //  debug(Students);
        Arrays.sort(Students);
//        debug(Students);
        out.write("Case "+kaseno+": ");
        if (Students[npeople - 1].area == Students[npeople - 2].area) {
            out.write("no thief\n");
        } else {
            String a = Students[npeople-1].Name;
            String b = Students[0].Name;
            out.write(a+" took chocolate from "+b+"\n");
        }
    }

    public class Student implements Comparable<Student> {

        String Name;
        int area;

        Student(String name, int area) {
            this.Name = name;
            this.area = area;
        }

        public int compareTo(Student o) {
            int get = area - o.area;
            if (get < 0) {
                return -1;
            }
            if (get > 0) {
                return 1;
            }
            return 0;
        }

        public String toString() {
            return Name + " " + area;
        }
    };

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
