#ifndef MATH_H
#define MATH_H

#define PI 3.14159265358979323846  // �����ֵ
#define EPSILON 1e-10              // ���ȿ���ֵ
/**
 * @file math.h
 * @brief ��ѧ�⺯���ӿڶ���
 */

/**
 * @brief ���������ľ���ֵ
 * 
 * @param x ��������
 * @return int x�ľ���ֵ
 */
int abs_int(int x);

/**
 * @brief ���㸡�����ľ���ֵ
 * 
 * @param x ���븡����
 * @return double x�ľ���ֵ
 */
double abs_double(double x);

/**
 * @brief ���������������ֵ
 * 
 * @param a ��һ����
 * @param b �ڶ�����
 * @return int �ϴ����
 */
int max_int(int a, int b);

/**
 * @brief �������������������ֵ
 * 
 * @param a ��һ��������
 * @param b �ڶ���������
 * @return double �ϴ�ĸ�����
 */
double max_double(double a, double b);

/**
 * @brief ��������������Сֵ
 * 
 * @param a ��һ����
 * @param b �ڶ�����
 * @return int ��С����
 */
int min_int(int a, int b);

/**
 * @brief ������������������Сֵ
 * 
 * @param a ��һ��������
 * @param b �ڶ���������
 * @return double ��С�ĸ�����
 */
double min_double(double a, double b);

/**
 * @brief ����x��n���ݣ������ݣ�
 * 
 * @param x ����
 * @param n ָ��
 * @return double x��n���ݽ��
 * @note ��nΪ����ʱ������1.0 / (x��|n|����)
 */
double power(double x, int n);

/**
 * @brief ����x��ƽ������ʹ��ţ�ٵ�������
 * 
 * @param x �Ǹ���
 * @return double x��ƽ����
 * @warning x����Ϊ�Ǹ��������򷵻�0
 */
double custom_sqrt(double x);

/**
 * @brief ����x��������
 * 
 * @param x ������
 * @return double x��������
 */
double custom_cbrt(double x);

/**
 * @brief �������뵽��ӽ�������
 * 
 * @param x ���븡����
 * @return int ��������������
 */
int custom_round(double x);

/**
 * @brief ����ȡ��
 * 
 * @param x ���븡����
 * @return int ����ȡ���������
 */
int custom_ceil(double x);

/**
 * @brief ����ȡ��
 * 
 * @param x ���븡����
 * @return int ����ȡ���������
 */
int custom_floor(double x);

/**
 * @brief �ж�һ�����Ƿ�Ϊ����
 * 
 * @param n ��������
 * @return int �������������1�����򷵻�0
 */
int is_prime(int n);

/**
 * @brief ���������������Լ����GCD��
 * 
 * @param a ��һ����
 * @param b �ڶ�����
 * @return int ���Լ��
 */
int gcd(int a, int b);

/**
 * @brief ��������������С��������LCM��
 * 
 * @param a ��һ����
 * @param b �ڶ�����
 * @return int ��С������
 */
int lcm(int a, int b);

// =============================================================================
// ��������δʵ�ֵ���ѧ�㷨�ӿڶ���
// �������Ը�����Ҫʵ����Щ����
// =============================================================================

/**
 * @brief ��������ֵ
 * 
 * @param x ����ֵ
 * @return double sin(x)�Ľ���ֵ
 */
double custom_sin(double x);

/**
 * @brief ��������ֵ
 * 
 * @param x ����ֵ
 * @return double cos(x)�Ľ���ֵ
 */
double custom_cos(double x);

/**
 * @brief ��������ֵ
 * 
 * @param x ����ֵ
 * @return double tan(x)�Ľ���ֵ
 */
double custom_tan(double x);

/**
 * @brief ���㷴����ֵ
 * 
 * @param x ����ֵ����Χ[-1,1]
 * @return double asin(x)�Ļ���ֵ����Χ[-��/2, ��/2]
 */
double custom_asin(double x);

/**
 * @brief ���㷴����ֵ
 * 
 * @param x ����ֵ����Χ[-1,1]
 * @return double acos(x)�Ļ���ֵ����Χ[0, ��]
 */
double custom_acos(double x);

/**
 * @brief ���㷴����ֵ
 * 
 * @param x ����ֵ
 * @return double atan(x)�Ļ���ֵ����Χ[-��/2, ��/2]
 */
double custom_atan(double x);

/**
 * @brief ������Ȼ����
 * 
 * @param x ��������
 * @return double ln(x)�Ľ���ֵ
 */
// double ln(double x);

/**
 * @brief ����x����y������
 * 
 * @param x ������
 * @param y ����
 * @return double x����y��������������x��ͬ
 */
double custom_fmod(double x, double y);

/**
 * @brief ���㳣�ö�������10Ϊ�ף�
 * 
 * @param x ��������
 * @return double log10(x)�Ľ���ֵ
 */
// double log10(double x);

/**
 * @brief ������baseΪ�׵Ķ���
 * 
 * @param x ��������
 * @param base �����ĵ�
 * @return double log_base(x)�Ľ���ֵ
 */
// double log_base(double x, double base);

/**
 * @brief ����ָ��������e��x�η���
 * 
 * @param x ָ��ֵ
 * @return double e^x�Ľ���ֵ
 */
// double exp(double x);

/**
 * @brief ����[0,1)��Χ�ڵ������
 * 
 * @return double ���������
 */
// double random_double();

/**
 * @brief ����[a,b]��Χ�ڵ��������
 * 
 * @param a ��Сֵ
 * @param b ���ֵ
 * @return int �������
 */
// int random_int(int a, int b);

/**
 * @brief ����׳�
 * 
 * @param n �Ǹ�����
 * @return long long n�Ľ׳�
 */
// long long factorial(int n);

/**
 * @brief ����쳲��������еĵ�n��
 * 
 * @param n ����
 * @return long long ��n���ֵ
 */
// long long fibonacci(int n);

/**
 * @brief ���������C(n,k)
 * 
 * @param n ����
 * @param k ѡ����
 * @return long long ��������
 */
// long long combination(int n, int k);

/**
 * @brief ����������P(n,k)
 * 
 * @param n ����
 * @param k ѡ����
 * @return long long ���������
 */
// long long permutation(int n, int k);

/**
 * @brief ��������֮��ľ���
 * 
 * @param x1 ��һ�����x����
 * @param y1 ��һ�����y����
 * @param x2 �ڶ������x����
 * @param y2 �ڶ������y����
 * @return double ����֮���ŷ����þ���
 */
// double distance(double x1, double y1, double x2, double y2);

/**
 * @brief ����ʽ��ֵ�����ɷ���
 * 
 * @param coefficients ����ʽϵ�����飨�ӵʹ���ߴ��
 * @param degree ����ʽ����
 * @param x �Ա���ֵ
 * @return double ����ʽ��x����ֵ
 */
// double polynomial(double coefficients[], int degree, double x);

/**
 * @brief ���Բ�ֵ
 * 
 * @param x0 ��һ�����x����
 * @param y0 ��һ�����y����
 * @param x1 �ڶ������x����
 * @param y1 �ڶ������y����
 * @param x Ҫ��ֵ��x����
 * @return double ��ֵ���
 */
// double linear_interpolation(double x0, double y0, double x1, double y1, double x);

/**
 * @brief �Ƕ�ת��������ת�Ƕ�
 * 
 * @param radians ����ֵ
 * @return double �Ƕ�ֵ
 */
// double radians_to_degrees(double radians);

/**
 * @brief �Ƕ�ת�����Ƕ�ת����
 * 
 * @param degrees �Ƕ�ֵ
 * @return double ����ֵ
 */
// double degrees_to_radians(double degrees);

#endif // MATH_H