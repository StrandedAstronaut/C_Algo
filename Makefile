# ����������
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -O2
LDFLAGS = -lm

# Ŀ¼����
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = test
EXAMPLES_DIR = examples
BUILD_DIR = build

# Դ�ļ���Ŀ���ļ�
SRC_FILES = $(wildcard $(SRC_DIR)/*/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

# �����ļ�
TEST_FILES = $(wildcard $(TEST_DIR)/*.c)
TEST_EXES = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/%, $(TEST_FILES))

# ʾ���ļ�
EXAMPLE_FILES = $(wildcard $(EXAMPLES_DIR)/*.c)
EXAMPLE_EXES = $(patsubst $(EXAMPLES_DIR)/%.c, $(BUILD_DIR)/examples/%, $(EXAMPLE_FILES))

# ���ļ�
LIBRARY = $(BUILD_DIR)/libalgorithm.a

# Ĭ��Ŀ��
all: $(LIBRARY) tests examples

# ����Ŀ¼
$(shell mkdir -p $(BUILD_DIR)/sort $(BUILD_DIR)/search $(BUILD_DIR)/graph $(BUILD_DIR)/utils $(BUILD_DIR)/examples $(BUILD_DIR)/data_structures)

# �����
$(LIBRARY): $(OBJ_FILES)
	ar rcs $@ $^

# ����Դ�ļ�
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# �������
$(BUILD_DIR)/%: $(TEST_DIR)/%.c $(LIBRARY)
	$(CC) $(CFLAGS) $< $(LIBRARY) -o $@ $(LDFLAGS)

# ����ʾ��
$(BUILD_DIR)/examples/%: $(EXAMPLES_DIR)/%.c $(LIBRARY)
	$(CC) $(CFLAGS) $< $(LIBRARY) -o $@ $(LDFLAGS)

# ����Ŀ��
tests: $(TEST_EXES)

# ʾ��Ŀ��
examples: $(EXAMPLE_EXES)

# ����
clean:
	rm -rf $(BUILD_DIR)

# αĿ��
.PHONY: all clean tests examples
    