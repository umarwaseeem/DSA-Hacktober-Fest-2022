import java.util.Scanner;

public class bipartite {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int v = sc.nextInt();
        int e = sc.nextInt();
        int graph[][] = new int[v][v];
        for (int i = 0; i < e; i++) {
            int f = sc.nextInt();
            int s = sc.nextInt();
            graph[f][s] = 1;
            graph[s][f] = 1;
        }
        sc.close();
        int colors[] = new int[v];

        for (int i = 0; i < v; i++) {
            colors[i] = -1;
        }

        isBipartite(graph, 0, 1, colors);
        if (isBartite)
            System.out.println("Barpitite");
        else
            System.out.println("Not barpitite");
    }

    public static boolean isBartite = true;

    public static void isBipartite(int graph[][], int cv, int cc, int[] colors) {
        if (colors[cv] != -1) {
            if (colors[cv] != cc) {
                isBartite = false;
            }
            return;
        }

        colors[cv] = cc;

        for (int i = 0; i < graph.length; i++) {
            if (graph[cv][i] == 1) {
                isBipartite(graph, i, Math.abs(1 - cc), colors);
            }
        }
    }
}
