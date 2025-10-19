# 编译器设置
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -O2
LDFLAGS = -lm

# 目录设置
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = test
EXAMPLES_DIR = examples
BUILD_DIR = build

# 源文件和目标文件
SRC_FILES = $(wildcard $(SRC_DIR)/*/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

# 测试文件
TEST_FILES = $(wildcard $(TEST_DIR)/*.c)
TEST_EXES = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/%, $(TEST_FILES))

# 示例文件
EXAMPLE_FILES = $(wildcard $(EXAMPLES_DIR)/*.c)
EXAMPLE_EXES = $(patsubst $(EXAMPLES_DIR)/%.c, $(BUILD_DIR)/examples/%, $(EXAMPLE_FILES))

# 库文件
LIBRARY = $(BUILD_DIR)/libalgorithm.a

# 默认目标
all: $(LIBRARY) tests examples

# 创建目录
$(shell mkdir -p $(BUILD_DIR)/sort $(BUILD_DIR)/search $(BUILD_DIR)/graph $(BUILD_DIR)/utils $(BUILD_DIR)/examples $(BUILD_DIR)/data_structures)

# 编译库
$(LIBRARY): $(OBJ_FILES)
	ar rcs $@ $^

# 编译源文件
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# 编译测试
$(BUILD_DIR)/%: $(TEST_DIR)/%.c $(LIBRARY)
	$(CC) $(CFLAGS) $< $(LIBRARY) -o $@ $(LDFLAGS)

# 编译示例
$(BUILD_DIR)/examples/%: $(EXAMPLES_DIR)/%.c $(LIBRARY)
	$(CC) $(CFLAGS) $< $(LIBRARY) -o $@ $(LDFLAGS)

# 测试目标
tests: $(TEST_EXES)

# 示例目标
examples: $(EXAMPLE_EXES)

# 清理
clean:
	rm -rf $(BUILD_DIR)

# 伪目标
.PHONY: all clean tests examples
    