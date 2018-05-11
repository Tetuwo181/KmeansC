#include<math.h>

/*
入力したデータとクラスタの距離を測定する
*/
double calc_distance(Data data, Cluster cluster){
    int8_t dimention = malloc_usable_size(data.position)
    double distance = 0
    for(index = 0, index < dimention; index++){
        double diff = data.position[index] - cluster.position[index]
        distance = distance + diff*diff
    }
    return distance
}

/*
データがどのクラスに属するか判定する
*/
void set_cluster_to_data(Data data, Cluster* cluster_set){
    int8_t cluster_num = malloc_usable_size(cluster_set)
    double shortest_distance = calc_distance(data, cluster_set[0])
    data.cluster = cluster_set[0].cluster_class
    for(index = 1; index < cluster_num; index++){
        double now_distance = calc_distance(data, cluster_set[index])
        if(now_distance < shortest_distance){
            data.cluster = cluster_set[index].cluster_class
            shortest_distance = now_distance
        }
    }
}

/*
古いクラスタの中心地と新しいクラスタの中心地の差を
*/
void 