#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

/**
 * @file binary_search.h
 * @brief ���ֲ����㷨�ӿڶ���
 */

/**
 * @brief ���ֲ����㷨
 * 
 * ���ֲ�����һ�������������в����ض�Ԫ�صĸ�Ч�㷨��
 * ��ͨ���������������仮��Ϊһ��������������Χ��
 * ʱ�临�Ӷ�ΪO(log n)���ռ临�Ӷ�ΪO(1)��
 * 
 * @param arr �����������飨�������У�
 * @param n ���鳤��
 * @param target Ҫ���ҵ�Ŀ��ֵ
 * @return int ����ҵ�Ŀ��ֵ�����������������򷵻�-1
 * 
 * @note ����������������е�
 */
int binary_search(int arr[], int n, int target);

// ��������δʵ�ֵ������㷨�ӿڶ���
// �������Ը�����Ҫʵ����Щ����

/**
 * @brief ���Բ����㷨
 * 
 * @param arr ��������
 * @param n ���鳤��
 * @param target Ҫ���ҵ�Ŀ��ֵ
 * @return int ����ҵ�Ŀ��ֵ���������״γ��ֵ����������򷵻�-1
 */
// int linear_search(int arr[], int n, int target);

/**
 * @brief ��ֵ�����㷨
 * 
 * @param arr �����������飨�������У�
 * @param n ���鳤��
 * @param target Ҫ���ҵ�Ŀ��ֵ
 * @return int ����ҵ�Ŀ��ֵ�����������������򷵻�-1
 */
// int interpolation_search(int arr[], int n, int target);

/**
 * @brief 쳲����������㷨
 * 
 * @param arr �����������飨�������У�
 * @param n ���鳤��
 * @param target Ҫ���ҵ�Ŀ��ֵ
 * @return int ����ҵ�Ŀ��ֵ�����������������򷵻�-1
 */
// int fibonacci_search(int arr[], int n, int target);

/**
 * @brief ��Ծ�����㷨
 * 
 * @param arr �����������飨�������У�
 * @param n ���鳤��
 * @param target Ҫ���ҵ�Ŀ��ֵ
 * @return int ����ҵ�Ŀ��ֵ�����������������򷵻�-1
 */
// int jump_search(int arr[], int n, int target);

/**
 * @brief ָ�������㷨
 * 
 * @param arr �����������飨�������У�
 * @param n ���鳤��
 * @param target Ҫ���ҵ�Ŀ��ֵ
 * @return int ����ҵ�Ŀ��ֵ�����������������򷵻�-1
 */
// int exponential_search(int arr[], int n, int target);

#endif // BINARY_SEARCH_H