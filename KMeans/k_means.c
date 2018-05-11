#include <math.h>

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
    int8_t cluster_num = malloc_usable_size(cluster_set);
    double shortest_distance = calc_distance(data, cluster_set[0]);
    data.cluster = cluster_set[0].cluster_class;
    for(index = 1; index < cluster_num; index++){
        double now_distance = calc_distance(data, cluster_set[index]);
        if(now_distance < shortest_distance){
            data.cluster = cluster_set[index].cluster_class;
            shortest_distance = now_distance;
        }
    }
}

/*
古いクラスタの中心地と新しいクラスタの中心地の差をとる
*/
DiffOldAndNew　calc_new_central(Data* data_set, Cluster base_cluster){
    DiffOldAndNew diff;
    int8_t dimention = sizeof(base_cluster.position);
    //diffのメモリ確保
    diff->old_pos = (*double)malloc(dimention*sizeof(double));
    diff->new_pos = (*double)malloc(dimention*sizeof(double));
    diff.difference = 0;
    diff.cluster_number = base_cluster.cluster_class;
    new_pos = calculate_center_of_cluster(data_set, base_cluster.cluster_class);
    for(int index = 0; index < dimention; index++){
        diff.old_pos[index] = base_cluster.position[index];
        diff.new_pos[index] = new_pos[index];
        diff.difference = diff.difference + powl(diff.old_pos-diff.new_pos, 2.0);
    }
    return diff;
} 

