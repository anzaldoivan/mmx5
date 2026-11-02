#include "types.h"

extern s32 func_8003952C(u8* arg0);
extern s32 func_80041C80(u8* p);
extern s32 func_80044228(u8* p);
extern s32 func_80041B84(u8* p);
extern s32 func_80044328(u8*);
extern void func_8003B33C(u8*, s32);
extern void func_80016490(s32, s32, void*);
extern s32 func_8002DF78(void);
extern void func_8003CF74(u8*, s32);
extern void func_80042090(u8*);
extern s32 func_80039C80(u8* arg0);
extern s32 func_80039588(u8* arg0);
extern s32 func_800395E8(u8* arg0);
extern void func_8003A7E4(u8* arg0);
extern void func_8003B1A8(u8* a0);
extern void func_8003A418(u8* a0);
extern void func_8003A670(u8* arg0);
extern s8 D_800D1C0F;

static inline s32 func_800434A4_probe(u8* p) {
    if (*(s8*)(p + 2) != 0 && *(s8*)(p + 0xD3) == 0) {
        p[0x156] = 1;
        if (func_80041C80(p) != 0) {
            return 1;
        }
        if (func_80044228(p) != 0) {
            return 1;
        }
        if (func_80041B84(p) != 0) {
            return 1;
        }
        p[0x156] = 0;
    }
    return 0;
}

static inline s32 func_800434A4_reset(u8* p) {
    if (func_80044328(p) == 0) {
        return 0;
    }
    func_8003B33C(p, 0x58);
    func_80016490(1, 7, p);
    if (func_8002DF78() & 4) {
        func_8003CF74(p, 3);
    }
    p[0x84] = 0;
    p[0x86] = 0;
    p[5] = 0x30;
    p[6] = 0;
    func_80042090(p);
    return 1;
}

static inline s32 func_800434A4_check(u8* p) {
    if (func_80039C80(p) != 0) {
        return 1;
    }
    if (func_80039588(p) != 0) {
        return 1;
    }
    if (func_800395E8(p) != 0) {
        func_8003A7E4(p);
        return 1;
    }
    return 0;
}

void func_800434A4(u8* p) {
    if (*(s8*)(p + 0xD3) == 0) {
        p[0x8E] = 0;
        if (func_8003952C(p) != 0) {
            return;
        }
        if (p[0x45] & 0x40) {
            if (func_800434A4_probe(p) != 0) {
                return;
            }
            if (func_800434A4_reset(p) != 0) {
                return;
            }
            if (func_800434A4_check(p) != 0) {
                return;
            }
        }
        p[0x8E] = 1;
    }
    if (*(s8*)(p + 0x46) == 0) {
        p[0x8E] = 0;
        if (D_800D1C0F != 0) {
            func_8003B1A8(p);
            return;
        }
        if (*(s8*)(p + 0xD0) != 0) {
            func_8003A418(p);
            return;
        }
        func_8003A670(p);
    }
}
