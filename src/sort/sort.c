/*
 * �����㷨�⺯��ʵ��
 * ����ʵ�������������
 */
#include "../../include/sort/sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief ��������������λ��
 * 
 * @param a ָ���һ��������ָ��
 * @param b ָ��ڶ���������ָ��
 */
static void swap(int* a, int* b) {
    // TODO: ʵ�ֽ������������Ĺ���
}

/**
 * @brief ð������������
 * 
 * @param arr ���������������
 * @param n ���鳤��
 */
void bubble_sort(int arr[], int n) {
    // TODO: ʵ��ð�������㷨
}

/**
 * @brief ��������ķ�������
 * 
 * ѡ�����ұߵ�Ԫ����Ϊ��׼(pivot)��
 * ��С�ڵ��ڻ�׼��Ԫ�ط��ڻ�׼����࣬
 * �����ڻ�׼��Ԫ�ط��ڻ�׼���Ҳࡣ
 * 
 * @param arr ������������
 * @param low ��������ʼ����
 * @param high �����Ľ�������
 * @return int ��׼Ԫ�ص�����λ��
 */
static int partition(int arr[], int low, int high) {
    // TODO: ʵ�ֿ�������ķ�������
    return 0; // ��ʱ����ֵ
}

/**
 * @brief ��������������
 * 
 * ʹ�÷��η��ݹ�ض������������
 * 
 * @param arr �����������
 * @param low �������ʼ����
 * @param high ����Ľ�������
 */
void quick_sort(int arr[], int low, int high) {
    // TODO: ʵ�ֿ��������㷨
}

/**
 * @brief ѡ�������㷨ʵ��
 * 
 * ѡ������ÿ�δ�δ���򲿷�ѡ����СԪ�طŵ������򲿷ֵ�ĩβ
 */
void selection_sort(int arr[], int n) {
    // TODO: ʵ��ѡ�������㷨
}

/**
 * @brief ���������㷨ʵ��
 * 
 * �������򣺶���δ�������ݣ����������������ҵ���Ӧλ�ò�����
 */
void insertion_sort(int arr[], int n) {
    // TODO: ʵ�ֲ��������㷨
}

/**
 * @brief �ϲ�������������
 * 
 * �������������ڹ鲢�����еĺϲ�����
 */
static void merge(int arr[], int left, int mid, int right) {
    // TODO: ʵ�ֹ鲢����ĺϲ�����
}

/**
 * @brief �鲢�����㷨ʵ��
 * 
 * �鲢���򣺷����㷨���ݹ�����򲢺ϲ�
 */
void merge_sort(int arr[], int left, int right) {
    // TODO: ʵ�ֹ鲢�����㷨
}

/**
 * @brief ά����������
 * 
 * �������������ڶ�����
 */
static void heapify(int arr[], int n, int i) {
    // TODO: ʵ�ֶ�����Ķѻ�����
}

/**
 * @brief �������㷨ʵ��
 * 
 * �����򣺹������ѣ�Ȼ�󷴸���ȡ���Ԫ��
 */
void heap_sort(int arr[], int n) {
    // TODO: ʵ�ֶ������㷨
}

/**
 * @brief ϣ�������㷨ʵ��
 * 
 * ϣ������ʹ���������н��в�������
 */
void shell_sort(int arr[], int n) {
    // TODO: ʵ��ϣ�������㷨
}

/**
 * @brief ���������㷨ʵ��
 * 
 * ��������ͳ��ÿ��Ԫ�س��ֵĴ�����Ȼ���ؽ�����
 */
void counting_sort(int arr[], int n, int output[], int max) {
    // TODO: ʵ�ּ��������㷨
}

/**
 * @brief ��Ͱ�е�Ԫ�ؽ��в�������
 * 
 * ��������������Ͱ����
 */
static void insertion_sort_double(double arr[], int n) {
    // TODO: ʵ�ֶ�˫���ȸ������Ĳ�������
}

/**
 * @brief Ͱ�����㷨ʵ��
 * 
 * Ͱ���򣺽�Ԫ�ط��䵽��ͬ��Ͱ�У���ÿ��Ͱ����Ȼ��ϲ�
 */
void bucket_sort(double arr[], int n) {
    // TODO: ʵ��Ͱ�����㷨
}

/**
 * @brief ��ȡ�����е����ֵ
 * 
 * �������������ڻ�������
 */
static int get_max(int arr[], int n) {
    // TODO: ʵ�ֻ�ȡ�������ֵ�ĺ���
    return 0; // ��ʱ����ֵ
}

/**
 * @brief ����ָ��λ�����м�������
 * 
 * �������������ڻ�������
 */
static void counting_sort_radix(int arr[], int n, int exp) {
    // TODO: ʵ�ֻ��������еļ�������������
}

/**
 * @brief ���������㷨ʵ��
 * 
 * �������򣺰�λ�ӵ͵��߽�������
 */
void radix_sort(int arr[], int n) {
    // TODO: ʵ�ֻ��������㷨
}