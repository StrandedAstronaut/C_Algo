# C�����㷨��

һ����Ч���ɿ���C�����㷨���ϣ��������õ�������������ѧ���㡢����������㷨ʵ�֡�

## ����

- ģ�黯��ƣ�������չ��ʹ��
- ÿ���㷨������ϸע�ͺ�API�ĵ�
- �Ż������ܺ��ڴ�ʹ��
- ��ƽ̨���ݣ�Windows��Linux��macOS��
- �����Ĳ�����������������

## �������㷨�빦��

### �����㷨
- ��������quick_sort��
- ð������bubble_sort��
- [�����㷨���������...]

### �����㷨
- ���ֲ��ң�binary_search��

### ������
- ��ֵ�˲�����mean_filter��

### ��ѧ������

#### ������ѧ����
- ����ֵ���㣨�����͸�������
- ���/��Сֵ���㣨�����͸�������
- �����㣨�������ݣ�
- ƽ����������������
- �������롢����ȡ��������ȡ��
- �����ж�
- ���Լ��(GCD)����С������(LCM)����
- ������ȡģ���㣨fmod��

#### ���Ǻ���
- ���Һ�����sin��
- ���Һ�����cos��
- ���к�����tan��
- �����Һ�����asin��
- �����Һ�����acos��
- �����к�����atan��

#### ������ָ������
- ��2Ϊ�׵Ķ�����log2��
- ���ö�������10Ϊ�ף�log10��
- ������Ϊ�׵Ķ�����log_base��
- ��Ȼָ��������exp��

#### �������㺯��
- **2D��������**
  - ������㣨vector2d_dot��
  - �������ȼ��㣨vector2d_length��
  - ������һ����vector2d_normalize��
  - �����Ӽ�����vector2d_add, vector2d_subtract��
  - ���������˷���vector2d_scale��
  - �����нǼ��㣨vector2d_angle��
  - ����ͶӰ��vector2d_project��

- **3D��������**
  - ������㣨vector3d_dot��
  - ������㣨vector3d_cross��
  - �������ȼ��㣨vector3d_length��
  - ������һ����vector3d_normalize��
  - �����Ӽ�����vector3d_add, vector3d_subtract��
  - ���������˷���vector3d_scale��
  - �����нǼ��㣨vector3d_angle��
  - ����ͶӰ��vector3d_project��

## ��Ŀ�ṹ

```
c-algorithm-library/
������ include/          # ͷ�ļ�Ŀ¼
��   ������ math/         # ��ѧ��ͷ�ļ�
��   ������ sort/         # �����㷨ͷ�ļ�
��   ������ search/       # �����㷨ͷ�ļ�
��   ������ filter/       # ������ͷ�ļ�
������ src/              # Դ����Ŀ¼
��   ������ math/         # ��ѧ��ʵ��
��   ������ sort/         # �����㷨ʵ��
��   ������ search/       # �����㷨ʵ��
��   ������ filter/       # ������ʵ��
������ examples/         # ʾ������
������ test/             # ��������
������ Makefile          # ��������
������ README.md         # ��Ŀ˵���ĵ�
```

## ʹ�÷���

### �����

```bash
make
```

Windows������Ҳ����ʹ���������ļ���

```bash
build_math.bat
```

### ���в���

```bash
make tests
./build/test_math
```

Windows�����£�

```bash
compile_math_test.bat
```

### ����ʾ��

```bash
make examples
./build/examples/math_example
```

### �������Ŀ��ʹ��

1. ������Ӧ��ͷ�ļ�
   ```c
   #include "math/math.h"
   #include "sort/quick_sort.h"
   // ������Ҫ��ͷ�ļ�
   ```

2. ���ӱ���õĿ��ļ�

## ����˵��

- ��ѧ������������ܽ������Ż�������ϵͳ��׼����ȿ������в��
- �����㷨�ڴ��������±�������
- �������㺯���ṩ�˻��������Դ�������֧��

## ��ι���

1. Fork ���ֿ�
2. ����������Է�֧ (`git checkout -b feature/amazing-feature`)
3. �ύ����޸� (`git commit -m 'Add some amazing feature'`)
4. ���͵���֧ (`git push origin feature/amazing-feature`)
5. ��һ��Pull Request

## ���֤

����Ŀ����MIT���֤ - ���LICENSE�ļ�
    