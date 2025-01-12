# 定义编译器
CC=gcc

# 定义编译选项
CFLAGS=-Wall

# 定义最终目标名称
TARGET=myCpp

# 定义要编译的源文件
SOURCES=main.c config.c extern_global.c

# 定义对象文件
OBJECTS=$(SOURCES:.c=.o)

# 默认目标
all: $(TARGET)

# 生成最终目标
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

# 从.c生成.o的规则
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理编译生成的文件
clean:
	rm -f $(TARGET) $(OBJECTS)
