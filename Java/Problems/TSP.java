package Problems;

import java.util.ArrayList;
import java.util.List;

public class TSP {

    public static void main(String[] args) {

        int[][] graph = { { 0, 10, 15, 20 }, { 5, 0, 9, 10 }, { 6, 13, 0, 12 }, { 8, 8, 9, 0 } };

        getShortestPath(graph);

    }

    public static int getShortestPath(int[][] graph) {

        int[] nodes = new int[graph.length];

        for (int i = 0; i < nodes.length; i++)
            nodes[i] = i;

        Route r = getShortestPath(graph, 0, nodes);

        System.out.println(r);

        return r.getDistance();
    }

    static Route getShortestPath(int[][] graph, int src, int nodes[]) {

        if (nodes.length == 1) {
            ArrayList<Integer> temp = new ArrayList<>();
            temp.add(nodes[0]);
            return new Route(graph[src][nodes[0]], temp);
        }

        Route temp = new Route(Integer.MAX_VALUE, null);

        for (int i = 0; i < nodes.length; i++) {
            if (nodes[i] == src)
                continue;

            Route temp1 = getShortestPath(graph, nodes[i], getRemovedArray(nodes, nodes[i]));
            temp1.addNode(graph[src][nodes[i]], nodes[i]);

            if (temp.getDistance() > temp1.getDistance())
                temp = temp1;
        }

        return temp;

    }

    private static int[] getRemovedArray(int[] arr, int x) {

        int[] newArr = new int[arr.length - 1];
        int j = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != x) {
                newArr[j] = arr[i];
                j++;
            }
        }

        return newArr;

    }

}

class Route {

    private int distance;
    private List<Integer> path;

    public Route() {
        this(0, new ArrayList<>());
    }

    public Route(int dist, List<Integer> path) {
        this.distance = dist;
        this.path = path;
    }

    public int getDistance() {
        return distance;
    }

    public void setDistance(int distance) {
        this.distance = distance;
    }

    public List<Integer> getPath() {
        return path;
    }

    public void setPath(List<Integer> path) {
        this.path = path;
    }

    public void addNode(int dist, int node) {
        this.distance += dist;
        this.path.add(0, node);
    }

    @Override
    public String toString() {
        return this.distance + " through " + path.toString();
    }
}
