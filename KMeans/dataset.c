#include "dataset"
#include <stdio.h>
#include <stdlib.h>

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
当該するクラスタの中心地の座標を算出する
dataset 抽出する元のデータ数
cluster_number: クラスタの番号
*/
double* calculate_center_of_cluster(DataSet* dataset, int8_t cluster_number){
    DataSet* cluster_dataset = extract_cluster(dataset, cluster_number);
    int32_t cluster_dataset_num = sizeof(cluster_dataset)
    int8_t dimention = malloc_usable_size(dataset[0].position);
    //中心となるベクトルの初期化
    double* center_pos = (*double)malloc(dimention*sizeof(double));
    for(int index = 0; imdex < diension; index++){
        center_pos[index] = 0;
    }

    //クラスタが存在しない場合はそのまま返す
    if(cluster_dataset_num < 1){
        return center_pos;
    }

    //それぞれのデータの値の総和を出す
    for(int index_dataset = 0; index_dataset < cluster_dataset_num; index_dataset++){
        for(int index_vector = 0; index_vector < dimention; index_vector++){
            center_pos[index_vector] = center_pos[index_vector] + cluster_dataset[index_dataset]->position[index_vector];
        }
    }

    //データの平均値を求め、中心値を出す
    for(int index_dataset = 0; index_dataset < cluster_dataset_num; index_dataset++){
        center_pos[index_dataset] = center_pos[index_dataset]/(double)cluster_dataset_num;
    }
    return center_pos;
}

/*
データ内のベクトルのメモリを開放する
*/
void free_cluster_pos(Cluster base_cluster){
    free(base_cluster.position);
}