import java.util.Queue;

public class Dijkstra {

    static final int NODE = 5;
    static final int VERTEX = 8;

    static int [] DIST  = new int[NODE];        //DIST 넣을 배열
    static int [][] V   = new int[NODE][NODE];  //간선의 가중치를 담을 배열
    static boolean [] check = new boolean[NODE];//방문 여부 true/false

    public static void main(String[] args){
        // t값을 0으로 초기화 DIST(V1)=0이기 때문
        int i, j, k, t;   

        // 초기화
        for(i=0; i<NODE; i++){
            for(j=0; j<NODE; j++){
                V[i][j] = (i==j) ? 0 : 9999;
            }
        }        

        t=0;
        DIST[0] = 0;
        for(i=1; i<NODE; i++) {
            DIST[i] = 9999;
        }
        check[0] = true;

        // input data
        int [][] data = { {1, 2, 1}, {1, 3, 7}, {2, 3, 5}, {2, 4, 4}, {2, 5, 3}, {3, 4, 1}, {5, 3, 1}, {5, 4, 2} };        
        for(i=0; i<VERTEX; i++) {
            int node1 = data[i][0]-1;
            int node2 = data[i][1]-1;
            int weight = data[i][2];

            V[node1][node2] = weight;
        }

        // Dijkstra algorithm        
        for(i=1; i<NODE; i++) {

            // 미방문 노드를 방문하여 최단거리를 업데이트 한다.
            for(k=1; k<NODE; k++) {
                if(!check[k]){    
                    DIST[k]=MINIMUM(DIST[k],DIST[t]+V[t][k]);
                } 
            }

            // 미방문 노드 중 가장 거리가 짧은 노드를 찾는다.
            t=i;           
            for(j=1; j<NODE; j++){
                if(!check[j]) {                   
                    if(i==NODE-1 || DIST[t]>=DIST[j]) {
                        t=j;
                    }
                }
            }
            check[t]=true;
        }
        
        System.out.println("********DIST***********");
        for(i=0; i<NODE; i++) {
            System.out.print(DIST[i]+" ");
        }

    }

}