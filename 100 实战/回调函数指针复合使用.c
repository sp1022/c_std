#include<stdio.h>
#include<stdlib.h>


typedef void *(*memory_callback_t)(size_t);
static void **memory_blocks=NULL;
static int memory_block_count = 0;


/*分配内存*/
void *cust_alloc(size_t size)
{
    void *ptr=malloc(size);
    printf("Allocated %lu bytes of memory at address %p\n", size, ptr);
    return ptr;
}

void *cust_free(size_t size)
{
    printf("Simulated freeing %lu bytes of memory\n", size);
    return NULL;  
}

//初始化内存池
void init_memory_pool(int count)
{
    memory_block_count=count;
    memory_blocks =(void **)malloc(sizeof(void *)* memory_block_count);
    for(int i=0;i<memory_block_count;i++)
    {
        memory_blocks[i]=NULL;
    }
    printf("Initialized memory pool for %d blocks\n", memory_block_count);
}

void manage_memory(memory_callback_t alloc_func, memory_callback_t free_func) {
    // 通过多维指针分配和释放内存
    for (int i = 0; i < memory_block_count; i++) {
        if (memory_blocks[i] == NULL) {
            memory_blocks[i] = alloc_func(64);  // 分配64字节的内存块
        }
    }
    // 模拟释放内存
    for (int i = 0; i < memory_block_count; i++) {
        if (memory_blocks[i] != NULL) {
            free_func(64);
            free(memory_blocks[i]);
            memory_blocks[i] = NULL;
        }
    }
}

// 清理内存池
void cleanup_memory_pool() {
    if (memory_blocks) {
        free(memory_blocks);
        memory_blocks = NULL;
    }
    printf("Memory pool cleaned up\n");
}

// main函数，模拟PostgreSQL内核风格的运行
int main() {
    // 初始化5个内存块的内存池
    init_memory_pool(5);

    // 使用回调函数管理内存分配和释放
    manage_memory(cust_alloc, cust_free);

    // 清理内存池
    cleanup_memory_pool();

    return 0;
}