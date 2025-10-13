#ifndef MEAN_FILTER_H
#define MEAN_FILTER_H

/**
 * @file mean_filter.h
 * @brief ��ֵ�˲��㷨�ӿڶ���
 */

/**
 * @brief һά�źŵľ�ֵ�˲�
 * 
 * ��ֵ�˲���һ�ּ򵥵������˲��㷨������ÿ���������ֵ�滻Ϊ����Χ
 * ���ڲ������ƽ��ֵ����������������
 * 
 * @param input �����ź�����
 * @param output ����ź�����
 * @param length �źų���
 * @param window_size �˲����ڴ�С��������
 * 
 * @note �����������������ͬһ�����飬�����ʹ�ò�ͬ�������Ա������ݸ���
 * @warning ȷ��window_sizeΪ������������ܵ���������Ϊ
 */
void mean_filter_1d(double input[], double output[], int length, int window_size);

// ��������δʵ�ֵ��˲��㷨�ӿڶ���
// �������Ը�����Ҫʵ����Щ����

/**
 * @brief ��ֵ�˲��㷨
 * 
 * @param input �����ź�����
 * @param output ����ź�����
 * @param length �źų���
 * @param window_size �˲����ڴ�С��������
 */
// void median_filter_1d(double input[], double output[], int length, int window_size);

/**
 * @brief ��˹�˲��㷨
 * 
 * @param input �����ź�����
 * @param output ����ź�����
 * @param length �źų���
 * @param kernel_size ��˹�˴�С��������
 * @param sigma ��˹�ֲ��ı�׼��
 */
// void gaussian_filter_1d(double input[], double output[], int length, int kernel_size, double sigma);

/**
 * @brief ��ͨ�˲���
 * 
 * @param input �����ź�����
 * @param output ����ź�����
 * @param length �źų���
 * @param cutoff_frequency ��ֹƵ�ʣ�0-1��
 */
// void low_pass_filter(double input[], double output[], int length, double cutoff_frequency);

/**
 * @brief ��ͨ�˲���
 * 
 * @param input �����ź�����
 * @param output ����ź�����
 * @param length �źų���
 * @param cutoff_frequency ��ֹƵ�ʣ�0-1��
 */
// void high_pass_filter(double input[], double output[], int length, double cutoff_frequency);

/**
 * @brief ��ͨ�˲���
 * 
 * @param input �����ź�����
 * @param output ����ź�����
 * @param length �źų���
 * @param low_cutoff �ͽ�ֹƵ�ʣ�0-1��
 * @param high_cutoff �߽�ֹƵ�ʣ�0-1��
 */
// void band_pass_filter(double input[], double output[], int length, double low_cutoff, double high_cutoff);

/**
 * @brief ������˹��ͨ�˲���
 * 
 * @param input �����ź�����
 * @param output ����ź�����
 * @param length �źų���
 * @param order �˲�������
 * @param cutoff_frequency ��ֹƵ�ʣ�0-1��
 */
// void butterworth_low_pass(double input[], double output[], int length, int order, double cutoff_frequency);

#endif // MEAN_FILTER_H