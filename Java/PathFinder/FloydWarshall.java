package PathFinder;

public class FloydWarshall {

    public static void main(String[] args) {
        int graph[][] = { { 0, 3, INF, INF, 1 }, { INF, 0, INF, 4, INF }, { 9, INF, 0, 2, INF }, { 3, INF, INF, 0, 5 },
                { INF, INF, 6, INF, 0 } };
        print(floydMarshall(graph));
    }

    final static int INF = Integer.MAX_VALUE / 10;

    public static int[][] floydMarshall(int[][] graph) {

        final int V = graph.length;

        int[][] dist = new int[V][V];

        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                dist[i][j] = graph[i][j];

        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                for (int k = 0; k < V; k++)
                    if (dist[j][i] + dist[i][k] < dist[j][k])
                        dist[j][k] = dist[j][i] + dist[i][k];

        return dist;
    }

    static void print(int[][] graph) {

        int V = graph.length;

        for (int i = 0; i < V; i++) {

            for (int j = 0; j < V; j++) {
                if (graph[i][j] == INF)
                    System.out.printf("%4s", "INF");
                else
                    System.out.printf("%4d", graph[i][j]);
            }
            System.out.println();

        }
    }

}
