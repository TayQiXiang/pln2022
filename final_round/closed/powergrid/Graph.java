import java.util.*;
//O (E log V)
//using Kruskal's minimum spanning Tree Algorithm
public class Graph {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Number of vertices in graph
        int E = scanner.nextInt(); // Number of edges in graph
        Graph graph = new Graph(N, E);
        
        int oldweight = 0;
        
        for(int i = 0; i < E; i++){
            graph.edge[i].src = scanner.nextInt();
            graph.edge[i].dest = scanner.nextInt();
            graph.edge[i].weight = scanner.nextInt();
            oldweight += graph.edge[i].weight;
        }

        // Function call
        System.out.println(oldweight - graph.KruskalMST());
    }
    
    class Edge implements Comparable<Edge>{
        int src, dest, weight;
        
        //sort edges based on their weight
        public int compareTo(Edge compareEdge){
            return this.weight - compareEdge.weight;
        }
    };
    
    class subset{
        int parent, rank;
    };
    
    int N, E;
    Edge edge[];
    
    //create graph with N vertices and E edges
    Graph(int n, int e){
        N = n;
        E = e;
        edge = new Edge[E];
        for (int i = 0; i < e; i++)
            edge[i] = new Edge();
    }
    
    //to find set of an element i (uses path compression technique)
    int find(subset subsets[], int i){
        if (subsets[i].parent != i)
            subsets[i].parent = find(subsets, subsets[i].parent);
        
        return subsets[i].parent;
    }
    
    void Union(subset subsets[], int x, int y)
    {
        int xroot = find(subsets, x);
        int yroot = find(subsets, y);
 
        // Attach smaller rank tree under root of high rank tree (Union by Rank)
        if (subsets[xroot].rank < subsets[yroot].rank)
            subsets[xroot].parent = yroot;
        else if (subsets[xroot].rank > subsets[yroot].rank)
            subsets[yroot].parent = xroot;
        // If ranks are same, then make one as root and increment its rank by one
        else {
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }
    }
    
    int KruskalMST(){
        Edge result[] = new Edge[N];
        int e = 0;
        int i = 0;
        for (i = 0; i < N; ++i)
            result[i] = new Edge();
        
        Arrays.sort(edge);
        subset subsets[]= new subset[N];
        for (i = 0; i < N; ++i){
            subsets[i] = new subset();
        }
        
        for (int v = 0; v < N; ++v){
            subsets[v].parent = v;
            subsets[v].rank = 0;
        }
        
        i = 0;
        
        while (e < N - 1){
            Edge next_edge = edge[i++];
            
            int x = find(subsets, next_edge.src);
            int y = find(subsets, next_edge.dest);
            
            if(x != y){
                result[e++] = next_edge;
                Union(subsets, x, y);
            }
        }
        
        int minimumCost = 0;
        
        for(i = 0; i < e; ++i){
            minimumCost += result[i].weight;
        }
        
        return minimumCost;
    }
}
