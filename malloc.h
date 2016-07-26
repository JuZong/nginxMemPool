class LargeMalloc
{
    public:
        LargeMalloc *next;
        void *alloc;
};
class ControlMsg
{
    public:
        char *last;
        char *end;
        NginxMalloc *next;
        char failed;
};
class Pool
{
    public:
        ControlMsg msg;
        int left_size;
        Pool *current;
        LargeMalloc *large;
};
class NginxMalloc
{
    private:
        Pool *_pool;
    public:
        NginxMalloc(size_t data_size=1024);
        void *allocate(size_t n);
        void *large_malloc(size_t n);
};