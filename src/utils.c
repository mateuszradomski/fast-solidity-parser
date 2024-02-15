extern unsigned char __heap_base;
unsigned int bump_pointer = (unsigned int)(&__heap_base);

void*
malloc(unsigned long n) {
  unsigned int r = bump_pointer;
  bump_pointer += n;
  return (void *)r;
}

static void free(void* p) {}

static void
memcpy(void *dst, void *src, int n) {
    char *d = dst;
    char *s = src;
    for (int i = 0; i < n; i++) {
        d[i] = s[i];
    }
}
