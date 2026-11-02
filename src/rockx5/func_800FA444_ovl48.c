#include "types.h"

extern void func_8001E668(void);
extern void func_8002C50C(void);
extern void func_800FA004_ovl48(u8* obj);
extern u8 D_8009A1F8[];
extern s8 D_8009A424;
extern u8 D_800D1F3C;

void func_800FA444_ovl48(u8* obj) {
    s32 i;
    s32 a;
    s32 b;
    s32 c;

    if (D_800D1F3C == 0 && D_8009A424 == 0) {
        func_8001E668();
        D_8009A1F8[3] = 0;
        D_8009A1F8[0x57] = 0;
        D_8009A1F8[0xAB] = 0;
        func_8002C50C();
        for (i = 0; i < 16; i++) {
            obj[0x26 + i] = 0;
        }
        func_800FA004_ovl48(obj);
        if (obj[0xCB] & 0x80) {
            a = 9;
            b = 0xB;
            c = 0xFF;
        } else {
            a = 0xA;
            b = 0xC;
            c = 0xFF;
        }
        obj[0x194] = a;
        ((volatile u8*)obj)[0x195] =
            b; // !FAKE: volatile chain keeps the 0x1D store after 0x196
        ((volatile u8*)obj)[0x196] =
            c; // !FAKE: volatile chain keeps the 0x1D store after 0x196
        ((volatile u8*)obj)[0x1D] =
            a; // !FAKE: volatile chain keeps the 0x1D store after 0x196
        obj[0] = 0x13;
        obj[1] = 0;
        obj[2] = 0;
        obj[3] = 0;
    }
}
