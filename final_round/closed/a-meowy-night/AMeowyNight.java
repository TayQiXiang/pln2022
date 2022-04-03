import java.util.Arrays;
import java.util.Scanner;

public class AMeowyNight {
    static int[][] stars;
    static boolean[][] roof;
    static Scanner scanner = new Scanner(System.in);
    static int c, r;

    public static void main(String[] args) {
        c = scanner.nextInt();
        r = scanner.nextInt();
        stars = new int[c][r];
        roof = new boolean[c][r];

        for (int i = 0; i < c; i++) {
            Arrays.fill(stars[i], 0);
            Arrays.fill(roof[i], false);
        }

        for (int i = 0; i < roof.length; i++) {
            if( i % 2 == 0)
                for (int j = 0; j < roof[i].length; j += 2) {
                    roof[i][j] = true;
                }
            else
                for (int j = 1; j < roof[i].length; j += 2) {
                    roof[i][j] = true;
                }
        }

        int n = scanner.nextInt();
        String query;
        for (int i = 0; i < n; i++) {
            query = scanner.next();
            switch (query) {
                case "+" :
                    addStars();
                    break;
                case "B" :
                    setBlack();
                    break;
                case "T" :
                    setTransparent();
                    break;
                case "?" :
                    printViewable();
                    break;
            }
        }
    }

    static void addStars() {
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int b = scanner.nextInt();
        stars[y - 1][x - 1] += b;
    }

    static void setBlack() {
        int x1 = scanner.nextInt() - 1;
        int y1 = scanner.nextInt() - 1;
        int x2 = scanner.nextInt() - 1;
        int y2 = scanner.nextInt() - 1;
        if (x1 > x2) {
            int temp = x1;
            x1 = x2;
            x2 = temp;
        }
        if (y1 > y2) {
            int temp = y1;
            y1 = y2;
            y2 = temp;
        }
        for (int i = 0; i < roof.length; i++) {
            if (i >= y1 && i <= y2) {
                Arrays.fill(roof[i], x1, x2 + 1, false);
            }
        }
    }

    static void setTransparent() {
        int x1 = scanner.nextInt() - 1;
        int y1 = scanner.nextInt() - 1;
        int x2 = scanner.nextInt() - 1;
        int y2 = scanner.nextInt() - 1;
        if (x1 > x2) {
            int temp = x1;
            x1 = x2;
            x2 = temp;
        }
        if (y1 > y2) {
            int temp = y1;
            y1 = y2;
            y2 = temp;
        }
        for (int i = 0; i < roof.length; i++) {
            if (i >= y1 && i <= y2) {
                Arrays.fill(roof[i], x1, x2 + 1, true);
            }
        }
    }

    static void printViewable() {
        int totalBrightness = 0;
        for (int i = 0; i < roof.length; i++) {
            for (int j = 0; j < roof[i].length; j++) {
                if (roof[i][j]) totalBrightness += stars[i][j];
            }
        }
        System.out.println(totalBrightness);
    }
}
