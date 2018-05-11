#pragma once

/*
データの座標と場所を表す構造体
変数の型自体はClusterと同じだけど
表す内容が違うので別の構造体に
position: 座標　実数のベクトルで表す
cluster_number:クラスタの番号、初期化した時点では-1を入れる
*/
typedef struct Data{
    double *position; 
    int8_t cluster;    
}