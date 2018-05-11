#pragma once


/*
旧クラスタと新クラスタの中心地およびその差の量
differenceの値は二乗誤差
*/
typedef struct DiffOldAndNew{
    double* old_pos;
    double* new_pos;
    double difference;
    int8_t cluster_number;
}DiffOldAndNew;