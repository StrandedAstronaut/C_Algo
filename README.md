# C语言算法库

一个高效、可靠的C语言算法集合，包含常用的排序、搜索、数学计算、向量运算等算法实现。

## 特性

- 模块化设计，易于扩展和使用
- 每个算法都有详细注释和API文档
- 优化的性能和内存使用
- 跨平台兼容（Windows、Linux、macOS）
- 完整的测试用例和性能评估

## 包含的算法与功能

### 排序算法
- 快速排序（quick_sort）
- 冒泡排序（bubble_sort）
- [更多算法将持续添加...]

### 搜索算法
- 二分查找（binary_search）

### 过滤器
- 均值滤波器（mean_filter）

### 数学函数库

#### 基础数学函数
- 绝对值计算（整数和浮点数）
- 最大/最小值计算（整数和浮点数）
- 幂运算（整数次幂）
- 平方根和立方根计算
- 四舍五入、向上取整、向下取整
- 素数判断
- 最大公约数(GCD)和最小公倍数(LCM)计算
- 浮点数取模运算（fmod）

#### 三角函数
- 正弦函数（sin）
- 余弦函数（cos）
- 正切函数（tan）
- 反正弦函数（asin）
- 反余弦函数（acos）
- 反正切函数（atan）

#### 对数与指数函数
- 以2为底的对数（log2）
- 常用对数（以10为底，log10）
- 以任意为底的对数（log_base）
- 自然指数函数（exp）

#### 向量运算函数
- **2D向量运算**
  - 点积计算（vector2d_dot）
  - 向量长度计算（vector2d_length）
  - 向量归一化（vector2d_normalize）
  - 向量加减法（vector2d_add, vector2d_subtract）
  - 向量标量乘法（vector2d_scale）
  - 向量夹角计算（vector2d_angle）
  - 向量投影（vector2d_project）

- **3D向量运算**
  - 点积计算（vector3d_dot）
  - 叉积计算（vector3d_cross）
  - 向量长度计算（vector3d_length）
  - 向量归一化（vector3d_normalize）
  - 向量加减法（vector3d_add, vector3d_subtract）
  - 向量标量乘法（vector3d_scale）
  - 向量夹角计算（vector3d_angle）
  - 向量投影（vector3d_project）

## 项目结构

```
c-algorithm-library/
├── include/          # 头文件目录
│   ├── math/         # 数学库头文件
│   ├── sort/         # 排序算法头文件
│   ├── search/       # 搜索算法头文件
│   └── filter/       # 过滤器头文件
├── src/              # 源代码目录
│   ├── math/         # 数学库实现
│   ├── sort/         # 排序算法实现
│   ├── search/       # 搜索算法实现
│   └── filter/       # 过滤器实现
├── examples/         # 示例代码
├── test/             # 测试用例
├── Makefile          # 编译配置
└── README.md         # 项目说明文档
```

## 使用方法

### 编译库

```bash
make
```

Windows环境下也可以使用批处理文件：

```bash
build_math.bat
```

### 运行测试

```bash
make tests
./build/test_math
```

Windows环境下：

```bash
compile_math_test.bat
```

### 运行示例

```bash
make examples
./build/examples/math_example
```

### 在你的项目中使用

1. 包含相应的头文件
   ```c
   #include "math/math.h"
   #include "sort/quick_sort.h"
   // 其他需要的头文件
   ```

2. 链接编译好的库文件

## 性能说明

- 数学函数已针对性能进行了优化，但与系统标准库相比可能仍有差距
- 排序算法在大数据量下表现良好
- 向量运算函数提供了基础的线性代数操作支持

## 如何贡献

1. Fork 本仓库
2. 创建你的特性分支 (`git checkout -b feature/amazing-feature`)
3. 提交你的修改 (`git commit -m 'Add some amazing feature'`)
4. 推送到分支 (`git push origin feature/amazing-feature`)
5. 打开一个Pull Request

## 许可证

本项目采用MIT许可证 - 详见LICENSE文件
    