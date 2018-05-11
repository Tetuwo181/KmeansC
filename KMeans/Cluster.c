#include "Cluster"
#include<stdio.h>
#include<stdlib.h>

/*
クラスタを表す構造体のベクトルのメモリ確保
base_cluster: メモリ確保前のクラスタ
dimention
*/
void allocate_cluster_pos(Cluster base_cluster, int8_t dimension){
    base_cluster->position = (*double)malloc(dimention * sizeof(double))
}

/*
クラスタの初期の場所を設定する
現状クラスタの取りうる値は0<x<1
C++11じゃないからメルセンヌツイスタを標準で使えないのが…
dimention: ベクトルの次元
class: クラスの番号
*/
Cluster init_cluster(int8_t dimention, int8_t cluster_class){
    Cluster init_cluster
    init_cluster.cluster_class =  cluster_class
    allocate_cluster_pos(init_cluster, dimention)
    for(index = 0; index < dimention; index++){
        init_cluster.position[index] = ((double)rand() / ((double)RAND_MAX + 1))
    }
    return init_cluster
}

/*
クラスタを複数初期化する
dimention: ベクトルの次元
cluster_num: クラスタの数
*/
Cluster* init_cluster_set(int8_t dimention, int8_t cluster_num){
    Cluster* cluster_set;
    cluster_set = (*Cluster)malloc(cluster_num*sizeof(Cluster))
    for(index = 0; index < cluster_num; index++){
        cluster_set = init_cluster(dimention, index)
    }
    return cluster_set
}

/*
ベクトルのメモリを開放する
*/
void free_cluster_pos(Cluster base_cluster){
    free(base_cluster.position)
}