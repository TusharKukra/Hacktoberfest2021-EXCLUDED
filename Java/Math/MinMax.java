package Math;

import java.util.Arrays;

import Utils.ArrayGen;

public class MinMax {

    public static void main(String[] args) {
        int[] graph = ArrayGen.generateArray(10, 30);
        System.out.println(Arrays.toString(graph));
        System.out.println(getMin(graph));
        System.out.println(getMax(graph));
    }

    public static int[] getMinMax(int[] graph) {
        return new int[] { getMin(graph), getMax(graph) };
    }

    public static int[] getSimpleMinMax(int[] graph) {

        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;

        for (int i = 0; i < graph.length; i++) {
            int x = graph[i];

            if (x > max)
                max = x;

            if (x < min)
                min = x;
        }

        return new int[] { min, max };

    }

    public static int getMin(int[] graph) {
        return min(graph, 0, graph.length - 1);
    }

    static int min(int[] graph, int start, int end) {
        int mid = (start + end) / 2;

        if (start > end) {
            System.out.println("Bruh");
            return Integer.MAX_VALUE;
        }
        if (start == end) {
            return graph[start];
        }
        if (start + 1 == end) {
            return graph[start] < graph[end] ? graph[start] : graph[end];
        }

        return Math.min(min(graph, start, mid), min(graph, mid + 1, end));

    }

    public static int getMax(int[] graph) {
        return max(graph, 0, graph.length - 1);
    }

    static int max(int[] graph, int start, int end) {
        int mid = (start + end) / 2;

        if (start > end) {
            return Integer.MAX_VALUE;
        }
        if (start == end) {
            return graph[start];
        }
        if (start + 1 == end) {
            return graph[start] > graph[end] ? graph[start] : graph[end];
        }

        return Math.max(max(graph, start, mid), max(graph, mid + 1, end));

    }

}
