#include "types.h"

extern void func_8003B33C(u8*, s32);
extern u8* func_8002D0E4(void);
extern u8* func_8002D078();
extern void func_8002DED4(u8* obj);
extern void func_8003D344(void* arg0);
extern s8 D_80074824[];
extern u8 D_80074828[];

static inline s32 func_800392E4_scan(u8* obj) {
    s32 i;
    s8* t;
    u8* q;

    for (i = 1, t = D_80074824, q = obj + 0x4C; i < 3; i++) {
        if (*(s8*)q != 0) {
            (*q)--;
            if (*(s8*)q == 0) {
                if (obj[0x4B] <= *t) {
                    *(s32*)(obj + 0x24) = 0;
                    return 1;
                }
            }
        }
        t++;
        q++;
    }
    return 0;
}

s32 func_800392E4(u8* obj) {
    s32 hit;
    u8* p;
    u8 c;

    hit = 0;
    if (obj[0x89] & 4) {
        hit = 1;
        *(s32*)(obj + 0x24) = 0;
    }
    if (*(s32*)(obj + 0x24) <= 0) {
        hit = 1;
    }
    if (*(s8*)(obj + 2) != 0) {
        if (func_800392E4_scan(obj)) {
            hit = 1;
        }
    }
    if (hit) {
        func_8003B33C(obj, D_80074828[*(s8*)(obj + 2)]);
        if (*(s8*)(obj + 2) != 0) {
            p = func_8002D0E4();
            if (p != 0) {
                p[0] = 1;
                p[1] = 0x27;
                p[2] = 0;
                p[0x14] = obj[0x14];
            }
        }
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s8*)(obj + 0x67) = -1;
        obj[6] = 3;
        return 1;
    }
    if (obj[2] != 0) {
        obj[0x4E]++;
        c = obj[0x4E];
        if ((c & 3) == 0) {
            p = func_8002D078();
            if (p != 0) {
                p[0] = 1;
                p[1] = 0x3F;
                p[0x14] = obj[0x14];
                p[0x15] = obj[0x15];
            }
        }
    }
    func_8002DED4(obj);
    func_8003D344(obj);
    return 0;
}
