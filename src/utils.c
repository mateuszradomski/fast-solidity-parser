#ifdef WASM
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef char s8;
typedef short s16;
typedef int s32;

typedef u32 bool;
typedef u32 size_t;
#endif

#ifdef LINUX
#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;

typedef u32 bool;
#endif

const u32 Kilobyte = 1024;
const u32 Megabyte = Kilobyte * 1024;
const u32 Gigabyte = Megabyte * 1024;

#define true 1
#define false 0

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ARRAY_LENGTH(a) (sizeof((a))/sizeof((a)[0]))

#define STMNT(s) do{ s }while(0)

#define SLL_STACK_PUSH_(H,N) N->next=H,H=N
#define SLL_STACK_POP_(H) H=H=H->next
#define SLL_QUEUE_PUSH_MULTIPLE_(F,L,FF,LL) if(LL){if(F){L->next=FF;}else{F=FF;}L=LL;L->next=0;}
#define SLL_QUEUE_PUSH_(F,L,N) SLL_QUEUE_PUSH_MULTIPLE_(F,L,N,N)
#define SLL_QUEUE_POP_(F,L) if (F==L) { F=L=0; } else { F=F->next; }

#define SLL_STACK_PUSH(H,N) (SLL_STACK_PUSH_((H),(N)))
#define SLL_STACK_POP(H) (SLL_STACK_POP_((H)))
#define SLL_QUEUE_PUSH_MULTIPLE(F,L,FF,LL) STMNT( SLL_QUEUE_PUSH_MULTIPLE_((F),(L),(FF),(LL)) )
#define SLL_QUEUE_PUSH(F,L,N) STMNT( SLL_QUEUE_PUSH_((F),(L),(N)) )
#define SLL_QUEUE_POP(F,L) STMNT( SLL_QUEUE_POP_((F),(L)) )

#define WASM_PAGE_SIZE 65536

#define assert(expression) __assert((void*)(expression))

#ifdef LINUX
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void javascriptPrintStringPtr(void *s) {}
void javascriptPrintNumber(u32 n) {}
void traceBegin(u32 n) {}
void traceEnd() {}
#endif

#ifdef WASM
extern unsigned char __heap_base;
unsigned int bumpPointer = (unsigned int)(&__heap_base);

extern void javascriptPrintStringPtr(void *s);
extern void javascriptPrintNumber(u32 n);
extern void traceBegin(u32 n);
extern void traceEnd();

static void __assert(void *boolean) {
    if (!boolean) {
        __builtin_unreachable();
    }
}

void*
malloc(unsigned long n) {
    __builtin_wasm_memory_grow(0, n / WASM_PAGE_SIZE + 1);
    unsigned int r = bumpPointer;
    bumpPointer += n;
    return (void *)r;
}

static void free(void* p) {}

void *
memcpy(void *dst, const void *src, unsigned long n) {
    char *d = dst;
    const char *s = src;
    for (int i = 0; i < n; i++) {
        d[i] = s[i];
    }
    return dst;
}

static void
memset(void *dst, u8 value, int n) {
    u8 *d = (u8 *)dst;
    for (int i = 0; i < n; i++) {
        d[i] = value;
    }
}
#endif

typedef struct MemoryCursor {
    u8* basePointer;
    u8* cursorPointer;
    size_t size;
} MemoryCursor;

typedef struct MemoryCursorNode {
    struct MemoryCursorNode *next;
    MemoryCursor cursor;
} MemoryCursorNode;

typedef struct Arena {
    MemoryCursorNode *cursorNode;
    size_t chunkSize;
    size_t alignment;
} Arena;

static MemoryCursorNode *
arenaNewNode(Arena *arena, size_t size) {
    MemoryCursorNode *result = 0x0;
    size = MAX(arena->chunkSize, size);
    
    void *memory = (u8 *)malloc(size + sizeof(MemoryCursorNode));
    assert(memory);
    
    result = (MemoryCursorNode *)memory;
    
    result->cursor.basePointer = (u8 *)memory + sizeof(MemoryCursorNode);
    result->cursor.cursorPointer = result->cursor.basePointer;
    result->cursor.size = size;
    SLL_STACK_PUSH(arena->cursorNode, result);
    
    return result;
}

static void
cursorDestroy(MemoryCursor *cursor) {
    if(cursor && cursor->basePointer) {
        void *pointer = (u8 *)cursor->basePointer - sizeof(MemoryCursorNode);
        free(pointer);
    }
}

static size_t
cursorFreeBytes(MemoryCursor *cursor) {
    size_t result = cursor->size - (size_t)(cursor->cursorPointer - cursor->basePointer);

    return result;
}

static size_t
cursorTakenBytes(MemoryCursor *cursor) {
    size_t result = (size_t)(cursor->cursorPointer - cursor->basePointer);

    return result;
}

static void
arenaDestroy(Arena *arena) {
    if(arena) {
        MemoryCursorNode *toDestroy = 0x0;
        for(MemoryCursorNode *cursorNode = arena->cursorNode;
            cursorNode != 0x0;
            cursorNode = cursorNode->next) {
            if(toDestroy) {
                cursorDestroy(&toDestroy->cursor);
            }
            
            toDestroy = cursorNode;
        }
        
        if(toDestroy) {
            cursorDestroy(&toDestroy->cursor);
        }
        
        arena->cursorNode = 0x0;
    }
}

static Arena
arenaCreate(size_t size, size_t chunkSize, size_t alignment) {
    Arena result = {};

    result.chunkSize = chunkSize;
    result.alignment = alignment;

    if(size > 0) {
    	arenaNewNode(&result, size);
    }

    return result;
}

static void
cursorClear(MemoryCursor *cursor, u8 clearTo) {
    memset(cursor->basePointer, clearTo, cursor->size);
    cursor->cursorPointer = cursor->basePointer;
}

static Arena
arenaCreateZeros(size_t size, size_t chunkSize, size_t alignment) {
    Arena result = {};
    
    result = arenaCreate(size, chunkSize, alignment);
    cursorClear(&result.cursorNode->cursor, 0);
    
    return result;
}

static void *
arenaPush(Arena *arena, size_t size) {
    void *result = 0x0;
    
    assert(arena);
    
    if(size) {
        MemoryCursorNode *cursorNode = arena->cursorNode;
        if(!cursorNode) {
            cursorNode = arenaNewNode(arena, size);
        }
        
        MemoryCursor *cursor = &cursorNode->cursor;
        size_t bytesLeft = cursorFreeBytes(cursor);
        // Calculates how many bytes we need to add to be aligned on the 16 bytes.
        size_t paddingNeeded = (0x10 - ((size_t)cursor->cursorPointer & 0xf)) & 0xf;
        
        if(size + paddingNeeded > bytesLeft) {
            cursorNode = arenaNewNode(arena, size + paddingNeeded);
            cursor = &cursorNode->cursor;
        }
        
        cursor->cursorPointer += paddingNeeded;
        result = cursor->cursorPointer;
        cursor->cursorPointer += size;
    }
    
    return result;
}

static void
arenaPop(Arena *arena, size_t size) {
    assert(arena);

    if(size) {
        MemoryCursorNode *cursorNode = arena->cursorNode;
        if(!cursorNode) {
            return;
        }

        while(size > 0) {
            MemoryCursor *cursor = &cursorNode->cursor;

            size -= cursorTakenBytes(cursor);
            cursor->cursorPointer = cursor->basePointer;
            cursorNode = cursorNode->next;
        }
    }
}

static void *
arenaPushZero(Arena *arena, size_t size) {
    void *memory = arenaPush(arena, size);
    memset(memory, 0, size);
    return memory;
}

#define arrayPush(a,T,c) ((T *)arenaPush((a), sizeof(T)*(c)))
#define arrayPushZero(a,T,c) ((T *)arenaPushZero((a), sizeof(T)*(c)))
#define structPush(a, T) ((T *)arenaPush((a), sizeof(T)))
#define bytesPush(a, c) (arenaPush((a), (c)))

typedef struct String
{
    u8 *data;
    size_t size;     
} String;

#define LIT_TO_STR(x) ((String){ .data = (u8 *)x, .size = sizeof(x) - 1 })

#define javascriptPrintString(s) _javascriptPrintString((s), sizeof(s) - 1)

void _javascriptPrintString(char *s, u32 size) {
    String str = { .data = (u8 *)s, .size = size };
    javascriptPrintStringPtr(&str);
}

static bool
isWhitespace(char c) {
    return c == 0x20 || (c >= 0x09 && c <= 0x0d);
}

static char
toUpper(char c) {
    return c & ~(1 << 5);
}

static bool
isAlphabet(char c) {
    c = toUpper(c);
    return (c >= 'A' && c <= 'Z');
}

static bool
isDigit(char c) {
    return (c >= '0' && c <= '9');
}

static bool
isHexDigit(char c) {
    char upper = toUpper(c);
    return (c >= '0' && c <= '9') | (upper >= 'A' && upper <= 'F');
}

static bool
isBinDigit(char c) {
    return (c >= '0' && c <= '1');
}


typedef struct SplitIterator
{
    char delim;
    u32 strLength;
    char *string;
    char *head;
} SplitIterator;

static String
stringPush(Arena *arena, size_t size) {
    String string = {};
    string.data = arrayPush(arena, u8, size);
    string.size = size;
    return string;
}

static s32
stringCompare(String a, String b){
    s32 result = 0;
    if(a.size != b.size) {
        return a.size < b.size ? -1 : 1;
    }

    for (size_t i = 0; i < a.size || i < b.size; i += 1){
        u8 ca = (i < a.size)?a.data[i]:0;
        u8 cb = (i < b.size)?b.data[i]:0;
        s32 dif = ((ca) - (cb));
        if (dif != 0){
            result = (dif > 0)?1:-1;
            break;
        }
    }
    return(result);
}

static SplitIterator
stringSplit(String string, char delim) {
    SplitIterator it = { };
    
    it.string = (char *)string.data;
    it.strLength = string.size;
    it.head = (char *)string.data;
    it.delim = delim;
    
    return it;
}

static bool
stringMatch(String a, String b) {
    if(a.size == b.size) {
        for(u32 k = 0; k < a.size; k++) {
            if(a.data[k] != b.data[k]) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

static bool
stringStartsWith(String string, String prefix) {
    if(string.size < prefix.size) {
        return false;
    } else {
        string.size = prefix.size;
        return stringMatch(string, prefix);
    }
}

static bool
stringIsInteger(String string) {
    for(u32 i = 0; i < string.size; i++) {
        if(!isDigit(string.data[i])) {
            return false;
        }
    }

    return true;
}

static u32
stringToInteger(String string) {
    u32 result = 0;

    assert(string.data[0] != '-');

    for(u32 i = 0; i < string.size; i++) {
        if(!isDigit(string.data[i])) {
            return result;
        }

        u32 digit = string.data[i] - '0';
        result = result * 10 + digit;
    }

    return result;
}

static String
stringNextInSplit(SplitIterator *it) {
    String result = { };
    
    size_t readLength = (size_t)(it->head - it->string);
    
    if(readLength < it->strLength) {
        char *head = it->head;
        result.data = (u8 *)head;
        size_t toRead = it->strLength - readLength;
        for(size_t i = 0; (i < toRead) && (head[0] != it->delim); i++) {
            head++;
            result.size += 1;
        }
        
        if(head[0] == it->delim) {
            head++;
        }
        it->head = head;
    } else {
        result.data = 0x0;
    }
    
    return result;
}

static String
stringConsumeIteratorIntoString(SplitIterator it)
{
    String result = { 0 };

    size_t readLength = (size_t)(it.head - it.string);
    size_t toRead = it.strLength - readLength;

    result.data = (u8 *)it.head;
    result.size = toRead;
    
    return result;
}

static String
subStringUntilDelimiter(String string, u32 startOffset, u32 endOffset, char delimiter)
{
    String result = { 0 };
    result.data = string.data + startOffset;
    result.size = endOffset - startOffset;

    while(((result.size-1) + startOffset) < string.size && result.data[result.size-1] != '\n') {
        result.size += 1;
    }

    return result;
}

typedef struct ByteConsumer {
    u8 *data;
    u8 *head;
    u32 length;
} ByteConsumer;

static u32
consumerGood(ByteConsumer *c) {
    return (c->head - c->data) < c->length;
}

static u32
consumerGoodN(ByteConsumer *c, u32 size) {
    return ((c->head - c->data) + size - 1) < c->length;
}

static u8
consumeByte(ByteConsumer *c) {
    assert(consumerGood(c));
    return *(c->head++);
}

static u8
peekByte(ByteConsumer *c) {
    assert(consumerGood(c));
    return *(c->head);
}

static String
peekString(ByteConsumer *c, u32 size) {
    return (String){
        .data = c->head,
        .size = size,
    };
}

typedef struct StringNode {
    String string;
    struct StringNode *next;
} StringNode;

typedef struct StringList {
    StringNode *head;
    StringNode *last;
} StringList;

static String
neutralizeUnicode(const char *string, int len, Arena *arena) {
    static u8 followingByteCount[] = {
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 2, 2, 3, 0xff,
    };

    String result = {
        .data = arrayPush(arena, u8, len),
        .size = 0,
    };

    for(int i = 0; i < len; i++) {
        if(string[i] & 0x80) {
            u8 c = string[i];
            u8 first5Bits = (c >> 3) & 0x1f;
            u8 bytesToFollow = followingByteCount[first5Bits];
            u32 codePoint = c & (0x7f >> (bytesToFollow + 1));

            assert(i + bytesToFollow < len);
            for(int j = 0; j < bytesToFollow; j++) {
                u8 b = string[++i];
                assert((b & 0xc0) == 0x80);
                codePoint = (codePoint << 6) | (b & 0x3f);
            }

            if(codePoint > 0xffff) {
                result.data[result.size++] = 'u';
            }
            result.data[result.size++] = 'u';
        } else {
            result.data[result.size++] = string[i];
        }
    }

    return result;
}
