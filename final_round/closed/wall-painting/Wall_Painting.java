import java.util.Arrays;
import java.util.Scanner;

public class Wall_Painting {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        for(int i = 0; i < t; i++){
            int m = scan.nextInt();
            int n = scan.nextInt();
            int x = scan.nextInt();
            int y = scan.nextInt();
            int newColour = scan.nextInt();

            int[][] wall = new int[m][n];

            for(int j = 0; j < m; j++){
                for(int k = 0; k < n; k++){
                    wall[j][k] = scan.nextInt();
                }
            }
            paint(wall, x, y, newColour);
            for(int j = 0; j < m; j++){
                for(int k = 0; k < n; k++){
                    System.out.print(wall[j][k] + " ");
                }
                System.out.println();
            }
        }
    }
    public static void paint(int[][] wall, int x, int y, int newColour){
        int colour = wall[x][y];
        if(colour != newColour) dfs(wall, x, y, colour, newColour);

    }
    public static void dfs(int[][] wall, int r, int c, int colour, int newColour){
        if(wall[r][c] == colour){
            wall[r][c] = newColour;
            if(r >= 1) dfs(wall, r - 1, c, colour, newColour);
            if(c >= 1) dfs(wall, r, c - 1, colour, newColour);
            if(r + 1 < wall.length) dfs(wall, r + 1, c, colour, newColour);
            if(c + 1 < wall[0].length) dfs(wall, r, c + 1, colour, newColour);
        }
    }
}
