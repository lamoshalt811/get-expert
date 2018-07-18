
public class Dijkstra {

    static final int NODE = 5;
    static final int VERTEX = 8;

    static int [] DIST  = new int[NODE];        //DIST 넣을 배열
    static int [][] V   = new int[NODE][NODE];  //간선의 가중치를 담을 배열
    static int [] Vf    = new int[NODE];        //경로를 담을 배열
    static boolean [] check = new boolean[NODE];//방문 여부 true/false

    public static void main(String[] args){
        // t값을 0으로 초기화 DIST(V1)=0이기 때문
        int i, j, k, t=0;   

        // 초기화
        for(i=0; i<NODE; i++){
            for(j=0; j<NODE; j++){
                // 자신 to 자신은 0
                // 자신 to 나머지 MAX_VALUE(무한대)
                V[i][j] = (i==j) ? 0 : 9999;
            }
        }        

        DIST[0] = 0;
        for(i=1; i<NODE; i++) {
            DIST[i] = 9999;
        }
        
        //시작 노드 방문 표시
        check[0]=true; 
        //시작점
        Vf[0]=0; 

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
            for(k=1; k<NODE; k++) {
                //만약 방문하지 않는 노드라면
                if(check[k]==false){   
                   //t를 거쳐가는게 나은지 MINIMUM함수를 호출하여 검사
                    DIST[k]=Math.min(DIST[k],DIST[t]+V[t][k]);
                }                
            }

            // 일단 t에 i를 넣어주고
            t = i;
    
            // t를 업데이트 해주는 과정
            for(j=1; j<NODE; j++){

                //아직 방문하지 않은 노드중에 (아직 Vf에 업데이트 되지 않는 노드중에)
                if(check[j]==false) {
                    //만약 Vf에 업데이트되는 마지막 노드이거나, 남아 있는 값 중 가장 작은 값을 t로 지정
                    if(i==NODE-1 || DIST[t]>=DIST[j]) {
                        t=j;
                    }
                }
            }
            check[t]=true;
            Vf[i]=t;
        }
        
        System.out.println("********ROUTE**********");
        for(i=0; i<NODE; i++) {
            System.out.print("->"+Vf[i]);
        }
        System.out.println();

        System.out.println("********DIST***********");
        for(i=0; i<NODE; i++) {
            System.out.print(DIST[i]+" ");
        }

    }

}