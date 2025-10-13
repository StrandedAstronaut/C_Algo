/**
 * ��ֵ�˲��㷨ʵ��
 * ��ֵ�˲���һ�ּ򵥵������˲�����������ƽ���źź�ȥ������
 * ��ʵ��֧��һά�źŵľ�ֵ�˲�����
 */
#include "../../include/filter/mean_filter.h"

/**
 * @brief һά�źŵľ�ֵ�˲�
 * 
 * @param input �����ź�����
 * @param output ����ź�����
 * @param length �źų���
 * @param window_size �˲����ڴ�С��������
 */
void mean_filter_1d(double input[], double output[], int length, int window_size) {
    int half_window = window_size / 2;
    int i, j;
    
    // �����źŵ�ÿһ����
    for (i = 0; i < length; i++) {
        double sum = 0.0;
        int count = 0;
        
        // ���㴰����������Ч���ƽ��ֵ
        for (j = -half_window; j <= half_window; j++) {
            int index = i + j;
            
            // ��������Ƿ�����Ч��Χ��
            if (index >= 0 && index < length) {
                sum += input[index];
                count++;
            }
        }
        
        // ����ƽ��ֵ
        if (count > 0) {
            output[i] = sum / count;
        } else {
            output[i] = input[i];  // �Է���һ����������²��ᷢ����
        }
    }
}