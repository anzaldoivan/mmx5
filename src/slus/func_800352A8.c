#include "types.h"

extern void func_800389E8(u8* obj);
extern void func_800396E8(u8* obj);
extern void func_80039864(u8* obj);
extern void func_800399D4(u8* obj);
extern void func_80039A7C(u8* obj);
extern void func_80039BF0(u8* obj);
extern void func_8003A1FC(u8* obj);
extern void func_8003C3A8(u8* obj);
extern void func_8003C4C0(u8* obj);
extern void func_8003C5D8(u8* obj);
extern void func_8003E85C(u8* obj);
extern void func_8003ED94(u8* obj);
extern void* D_800745F0[];
extern u8 D_800D1C00[];

void func_800352A8(u8* obj) {
    u8* d;
    u8* e;
    s32 v;

    d = D_800D1C00;
    v = obj[0xD0];
    v |= d[0xF];
    v |= obj[0xD4];
    obj[0x8F] = 0;
    obj[0x90] = 0;
    obj[0xCF] = 0;
    obj[0x156] = 0;
    obj[0xD3] = v;
    obj[0x89] = obj[0x70] | obj[0x71];
    if (((s8*)d)[0x10] == 0) {
        if (obj[0xF8] != 0) {
            obj[0xF8]--;
        }
        func_800389E8(obj);
        if (((s8*)obj)[0x5C] == 0) {
            return;
        }
        func_80039BF0(obj);
        func_8003A1FC(obj);
        if (((s8*)obj)[0x154] != 0) {
            obj[0x154] = obj[0x154] - 1;
            if (((s8*)obj)[0x154] == 0) {
                obj[0x14B] = 0;
                func_8003C5D8(obj);
            }
        }
        if (obj[0x92] != 0) {
            obj[0x92]--;
        }
        if (obj[0x91] != 0) {
            obj[0x91]--;
            if (obj[0x91] == 0) {
                obj[0x90] = 1;
                obj[0x8E] = 0;
            }
        }
        if (((s8*)obj)[0xEA] > 0) {
            obj[0xEA] = obj[0xEA] - 1;
            if (((s8*)obj)[0xEA] == 0) {
                ((s8*)obj)[0xEA] = -1;
            }
        }
        func_800399D4(obj);
        func_80039A7C(obj);
        func_80039864(obj);
        func_800396E8(obj);
        func_8003ED94(obj);
        ((void (*)(u8*))D_800745F0[((s8*)obj)[5]])(obj);
        obj[0x71] = 0;
        obj[0x4A] = 0;
    }
    e = D_800D1C00;
    if (((s8*)e)[0x10] != 2) {
        func_8003E85C(obj);
        func_8003C4C0(obj);
        func_8003C3A8(obj);
    }
}
