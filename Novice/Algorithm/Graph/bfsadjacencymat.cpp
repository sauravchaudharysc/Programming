void BFS(int G[][7],int start,int n)
{
 int i=start,j;
 //Visited vertex array
 int visited[7]={0};
 //Source Vertex
 printf("%d ",i);
 //Mark visited
 visited[i]=1;
 //Push the element in Queue
  enqueue(i);
  while(!isEmpty()){
     //Pop An ELement
       i=dequeue();
       //Check for the adjacent vertex of the poped element.
       //If present and not visited then push it.
        for(j=1;j<n;j++){
            if(G[i][j]==1 && visited[j]==0){
                printf("%d ",j);
                visited[j]=1;
                enqueue(j);
            }
        }
    }
    //If the queue becomes empty then BFS is over.
}