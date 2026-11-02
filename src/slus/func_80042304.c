#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_8003952C(u8* arg0);
extern void func_8003B4CC(u8* obj, s32 arg1, s32 arg2);
extern void func_8003CD08(u8* obj);
extern void func_8003CD60(u8* obj);
extern u8* func_8003D3A8(s32, s32, s32, u8*);
extern s32 func_8003E6FC(void*, s8);
extern void func_800443A8(u8*, s8);

void func_80042304(u8* obj) {
    u8* p;
    s32 t;

    func_8003CD08(obj);
    t = *(s8*)(obj + 0x2);
    if (t != 0 && *(s8*)(obj + 0xD3) == 0 && (t = *(s8*)(obj + 0x93)) == 3 &&
        (*(u16*)(obj + 0x80) & 0x20) && *(s8*)(obj + 0xA6) == 0 &&
        func_8003E6FC(obj, 3) <= *(s16*)(obj + 0xAE)) {
        p = func_8003D3A8(1, 0x2B, 0, obj);
        if (p != 0) {
            *(u16*)(obj + 0xAE) -= func_8003E6FC(obj, 3);
            p[0x99] = 0;
        }
    }
    if (*(s8*)(obj + 0x6) == 0) {
        obj[0x6]++;
    } else {
        func_80017248(obj);
        func_800443A8(obj, 0x25);
    }
    if (*(u16*)(obj + 0x80) & 2) {
        obj[0x15] = 0;
    }
    if (*(u16*)(obj + 0x80) & 1) {
        obj[0x15] = 0x40;
    }
    if (*(s8*)(obj + 0xD3) == 0) {
        obj[0x8E] = 0;
        if (func_8003952C(obj) == 0) {
            obj[0x8E] = 1;
            goto block_18; // !FAKE: goto kept for the matching branch layout
        }
    } else {
    block_18:
        if (*(s8*)(obj + 0x46) == 0) {
            obj[0x8E] = 0;
            func_8003B4CC(obj, 0x51, 2);
            obj[0x5] = 0x1A;
            obj[0x6] = 1;
        }
        func_8003CD60(obj);
    }
}
