#include "types.h"

extern s32 func_8003E6FC(void*, s8);
extern u8* func_8003D3A8(s32, s32, s32, u8*);
extern void func_80017248(u8* obj);
extern void func_800443A8(u8*, s8);
extern s32 func_80042494(u8*);
extern s32 func_8003952C(u8* arg0);
extern s32 func_80039588(u8* arg0);
extern s32 func_80041C80(u8* p);
extern s32 func_80044228(u8* p);
extern s32 func_80041B84(u8* p);
extern s32 func_80044328(u8*);
extern void func_8003B33C(u8*, s32);
extern void func_80016490(s32, s32, void*);
extern s32 func_8002DF78(void);
extern void func_8003CF74(u8*, s32);
extern s32 func_8004445C(u8* arg0);
extern void func_800444B4(u8* a0);

void func_80042090(u8* p);

static inline s32 func_80042090_probe(u8* p) {
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

static inline s32 func_80042090_reset(u8* p) {
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

void func_80042090(u8* p) {
    u8* q;
    s32 r;

    if (*(s8*)(p + 2) != 0 && *(s8*)(p + 0xD3) == 0 && *(s8*)(p + 0x93) == 3 &&
        (*(u16*)(p + 0x80) & 0x20) && *(s8*)(p + 0xA6) == 0) {
        r = func_8003E6FC(p, 3);
        if (!(*(s16*)(p + 0xAE) < r)) {
            q = func_8003D3A8(1, 0x2B, 0, p);
            if (q != 0) {
                *(s16*)(p + 0xAE) -= func_8003E6FC(p, 3);
                q[0x99] = 0;
            }
        }
    }
    if (*(s8*)(p + 6) == 0) {
        p[6]++;
    } else {
        func_80017248(p);
        func_800443A8(p, 0x18);
        if (func_80042494(p) != 0) {
            return;
        }
    }
    if (*(s8*)(p + 0xD3) == 0) {
        p[0x8E] = 0;
        if (!(p[0x45] & 1)) {
            if (func_8003952C(p) != 0) {
                return;
            }
            if (*(s8*)(p + 0xCB) < 2) {
                if (func_80039588(p) != 0) {
                    return;
                }
                if (p[0x45] & 0x40) {
                    if (func_80042090_probe(p) != 0) {
                        return;
                    }
                    if (func_80042090_reset(p) != 0) {
                        return;
                    }
                    if (func_8004445C(p) != 0) {
                        return;
                    }
                }
            }
        }
        p[0x8E] = 1;
    }
    func_800444B4(p);
}
