#pragma once
#include<stdint.h>

/*
クラスタの座標と場所を表す構造体
position: 座標　実数のベクトルで表す
cluster_number:クラスタの中心
*/
typedef struct{
    double *position; 
    int8_t cluster_class;
}  Custer;

