package PathFinder;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

import Utils.GraphGen;

public class AllPaths {

    List<List<Integer>> allPaths;
    private final int V;

    public final int[][] graph;

    public AllPaths(int[][] graph) {

        this.allPaths = new ArrayList<>();
        this.graph = graph;
        this.V = graph.length;

    }

    public List<List<Integer>> getAllPaths(int s, int d) {

        boolean[] visited = new boolean[V];
        Stack<Integer> temp = new Stack<>();
        temp.push(s);

        paths(s, d, visited, temp);

        return this.allPaths;

    }

    public void paths(int u, int d, boolean[] visited, Stack<Integer> current) {

        if (u == d) {
            this.allPaths.add(new ArrayList<>(current));
            return;
        }

        visited[u] = true;

        for (int i = 0; i < V; i++)
            if (graph[u][i] != 0 && !visited[i]) {

                current.push(i);
                paths(i, d, visited, current);
                current.pop();

            }

        visited[u] = false;

    }

    public static void main(String[] args) {

        int[][] graph = GraphGen.getRandomGraph(6, 10);

        GraphGen.printGraph(graph);

        System.out.println("\n\n\n");

        AllPaths ap = new AllPaths(graph);
        System.out.println(ap.getAllPaths(2, 3));

    }

}