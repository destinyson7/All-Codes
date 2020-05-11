import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class ParenthesisKnapsack_lewin {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        ParenthesisKnapsack solver = new ParenthesisKnapsack();
        solver.solve(1, in, out);
        out.close();
    }

    static class ParenthesisKnapsack {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            ParenthesisKnapsack.Item[] its = new ParenthesisKnapsack.Item[n];
            int sa = 0;
            for (int i = 0; i < n; i++) {
                its[i] = new ParenthesisKnapsack.Item(in.next().toCharArray());
                sa += its[i].value;
            }
            int total = sa;
            Arrays.sort(its);
            int[][] best = new int[2][sa + 1];
            Arrays.fill(best[0], -(1 << 29));
            best[0][0] = 0;
            for (int i = 0; i < n; i++) {
                int cur = i & 1, nxt = 1 ^ cur;
                System.arraycopy(best[cur], 0, best[nxt], 0, best[cur].length);
                for (int j = sa; j >= 0; j--) {
                    if (its[i].a <= j) {
                        int aa = j + its[i].delta;
                        if (aa >= 0 && aa <= sa) {
                            best[nxt][aa] = Math.max(best[nxt][aa], best[cur][j] + its[i].value);
                        }
                    }
                }
            }

            if(total == best[n&1][0])
            {
                out.println("Yes");
            }

            else
            {
                out.println("No");
            }
            // out.println(best[n & 1][0]);
        }

        static class Item implements Comparable<ParenthesisKnapsack.Item> {
            public int delta;
            public int value;
            public int a;
            public int b;

            public Item(char[] s) {
                delta = 0;
                a = 0;
                b = 0;
                value = s.length;
                for (char c : s) {
                    if (c == '(') {
                        delta += 1;
                        b++;
                    } else {
                        if (b > 0) b--;
                        else a++;
                        delta -= 1;
                    }
                }
            }

            public int compareTo(ParenthesisKnapsack.Item other) {
                if ((delta > 0) ^ (other.delta > 0)) {
                    return other.delta - delta;
                }
                if (delta > 0) {
                    if (a == other.a) return other.delta - delta;
                    return a - other.a;
                } else {
                    if (b == other.b) return other.delta - delta;
                    return other.b - b;
                }
            }

        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (this.numChars == -1) {
                throw new InputMismatchException();
            } else {
                if (this.curChar >= this.numChars) {
                    this.curChar = 0;

                    try {
                        this.numChars = this.stream.read(this.buf);
                    } catch (IOException var2) {
                        throw new InputMismatchException();
                    }

                    if (this.numChars <= 0) {
                        return -1;
                    }
                }

                return this.buf[this.curChar++];
            }
        }

        public int nextInt() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            int res = 0;

            while (c >= 48 && c <= 57) {
                res *= 10;
                res += c - 48;
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * sgn;
                }
            }

            throw new InputMismatchException();
        }

        public String next() {
            int c;
            while (isSpaceChar(c = this.read())) {
                ;
            }

            StringBuilder result = new StringBuilder();
            result.appendCodePoint(c);

            while (!isSpaceChar(c = this.read())) {
                result.appendCodePoint(c);
            }

            return result.toString();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }
}
