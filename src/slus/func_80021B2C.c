#include "types.h"

extern void SetDispMask(s32);
extern void func_80012EAC(void);
extern void func_800132F8(s8 arg);
extern void func_80016384(void);
extern s32 func_80016490(s32, s32, void*);
extern void func_8001E668(void);
extern void func_8001E6AC(void);
extern void func_800211C4(void*, s32);
extern s32 func_8002BBF8(void);
extern void func_8002CF20(void);
extern u8* func_8002D2DC(void);
extern u8 D_8007113C[];
extern u8 D_80071148[];
extern u8 D_80071154[];
extern u8 D_8009A420[];
extern u16 D_800C9320;

void func_80021B2C(u8* arg0) {
    u8* base;
    u8* tbl;
    u8* tbl2;
    u8* p;
    s8 v;

    base = D_8009A420;
    if (*(s8*)(base + 4) != 0) {
        return;
    }
    if (*(s32*)(arg0 + 0x34) == 0) {
        func_800211C4(base + 7, 1);
        if (!(D_800C9320 & 0x40)) {
            return;
        }
        func_80016490(0, 0x22, 0);
        if (base[7] == 0) {
            func_800132F8(8);
            v = 2;
            goto store; // !FAKE: goto kept for the matching branch layout
        }
        *(s32*)(arg0 + 0x34) = 1;
        func_8002BBF8();
        base[7] = 1;
        tbl = D_80071148;
        if (*tbl != 0xFF) {
            do {
                p = func_8002D2DC();
                if (p != 0) {
                    p[0] = 1;
                    p[1] = 1;
                    p[2] = tbl[0];
                    *(s16*)(p + 0xE) = tbl[1] + 8;
                    p[7] = tbl[2];
                }
                tbl += 3;
            } while (*tbl != 0xFF);
        }
        p = func_8002D2DC();
        if (p != 0) {
            p[0] = 1;
            *(s8*)(p + 2) = -1;
            p[1] = 0;
            *(u8**)(p + 0x50) = D_80071154;
            *(s16*)(p + 0xA) = 0x78;
        }
    } else {
        func_800211C4(base + 7, 1);
        if (!(D_800C9320 & 0x40)) {
            return;
        }
        func_80016490(0, 0x22, 0);
        *(s32*)(arg0 + 0x34) = 0;
        if (base[7] == 0) {
            arg0[7] = 0;
            SetDispMask(0);
            func_8001E668();
            func_80016384();
            func_8002CF20();
            func_8001E6AC();
            func_80012EAC();
            return;
        }
        func_8002BBF8();
        base[7] = 0;
        tbl2 = D_8007113C;
        if (*tbl2 != 0xFF) {
            do {
                p = func_8002D2DC();
                if (p != 0) {
                    p[0] = 1;
                    p[1] = 1;
                    p[2] = tbl2[0];
                    *(s16*)(p + 0xE) = tbl2[1] + 8;
                    p[7] = tbl2[2];
                }
                tbl2 += 3;
            } while (*tbl2 != 0xFF);
        }
        p = func_8002D2DC();
        if (p != 0) {
            p[0] = 1;
            *(s8*)(p + 2) = -1;
            p[1] = 0;
            *(u8**)(p + 0x50) = D_80071154;
            *(s16*)(p + 0xA) = 0x78;
        }
        v = 1;
    store:
        arg0[7] = v;
    }
}
