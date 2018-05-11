#include"dataset"
#include<stdio.h>
#include<stdlib.h>

/*
データを表す構造体のベクトルのメモリ確保
base_data: メモリ確保前のデータ
dimention
*/
void allocate_data_pos(Data base_data, int8_t dimension){
    base_cluster->position = (*double)malloc(dimention * sizeof(double));
}

/*
データの値を初期化
現状データの取りうる値は0<x<1
raw_data 生のデータ
*/
Cluster init_cluster(double* raw_data){
    Cluster init_cluster;
    init_cluster.cluster =  -1;
    int8_t dimention = malloc_usable_size(raw_data);
    allocate_cluster_pos(init_cluster, dimention);
    for(index = 0; index < dimention; index++){
        init_cluster.position[index] = raw_data[index];
    }
    return init_cluster
}

/*
データセットの中から該当する番号クラスタに属する
データを抜き出す
dataset 抽出する元のデータ数
cluster_number: クラスタの番号
*/
DataSet* extract_cluster(DataSet* dataset, int8_t cluster_number){
    int32_t data_num = malloc_usable_size(dataset);
    int32_t cluster_num = 0;
    DataSet* extracted;
    for(index = 0; index < data_num; index++){
        if(dataset[index].cluster == cluster_number){
            cluster_num++;
            extraceted = realloc(extraceted, cluster_num*sizeof(dataset));
            extracted[cluster_num-1] = dataset[index];
        }
    }
    return extracted
}


/*
データ内のベクトルのメモリを開放する
*/
void free_cluster_pos(Cluster base_cluster){
    free(base_cluster.position);
}