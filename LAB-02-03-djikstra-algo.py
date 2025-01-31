def dijkstras(graph,start,num_nodes):
    #initializing distances , prointer for processed and unprocessed nodes , and previous node in path
    distances=[float('inf')]*num_nodes
    visited=[False]*num_nodes
    previous=[-1]*num_nodes
    #distance to itself is zero
    distances[start]=0
    #algorithm loop
    for _ in range(num_nodes):
        
        min_distance=float('inf')
        current_node=-1
        #finding closest neighbour
        for i in range(num_nodes):

            if not visited[i] and distances[i]<min_distance:

                min_distance=distances[i]
                current_node=i
        #if all nodes are prosessed or distances is optimised stop the algorithm
        if current_node == -1 :
                
            break

        visited[current_node]=True

        #relaxtation loop 
        for neighbour in range(num_nodes) :
            #checking if d(u)+c(u,v)<d(v)
            #then d(v)=d(u)+c(u,v)
            if graph[current_node][neighbour] != 0 and not visited[neighbour] :

                new_distance= distances[current_node] + graph[current_node][neighbour]

                if new_distance<distances[neighbour] :
                    #updating distances and previous node list
                    distances[neighbour]=new_distance
                    previous[neighbour]=current_node

    #returning the result
    return distances,previous


#function to get the path from source to target node 
def reconstruct_path(previous,start,target) :
    #initializing containers
    path=[]
    current=target
    #main loop for add previous nodes one by one
    while current != -1 :
        path.append(current)
        current=previous[current]
    #reversing order to get the path 
    path.reverse()
    #if starting from root then return path
    if path[0] == start :
        return path
    #else return no path
    return None


num_nodes=int(input("enter number of nodes : "))
graph=[[0]*num_nodes for _ in range(num_nodes)]

num_edges=int(input("enter number of edges : "))
print("enter edges in start node , end node , weight")

for _ in range(num_edges):
    u,v,weight=map(int,input().split())
    graph[u][v]=weight
    graph[v][u]=weight

start_node=int(input("enter start node : "))

shortest_paths,previous_nodes=dijkstras(graph,start_node,num_nodes)


print(f"\nstarting from node : {start_node}")
print("target  |  distance  | path  \n")

for target_node in range(num_nodes) :
    
    path=reconstruct_path(previous_nodes,start_node,target_node)

    if path :
        print(f"{target_node}       |     {shortest_paths[target_node]}      |    {' -> '.join(map(str,path))}\n")
    else :
        print(f"{target_node}       |     {shortest_paths[target_node]}      |  ------\n")




































