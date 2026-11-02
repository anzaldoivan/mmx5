#include "types.h"
#include "addr.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8003D430(s32, s32, s32, void*);
extern s32 func_80045D44();
extern u8 D_80077138[];
extern u8 D_8007713C[];
extern u8 D_80077140[];
extern u8 D_8007B44C[];
extern u8 D_8009A0A0[];

void func_800498F4(u8* obj) {
    u8* p;
    u8* q;
    u8* src;
    u8* base;
    s32 mode;

    obj[3] = 1;
    mode = ((s8*)obj)[2];
    p = D_1F800014;
    *(u8**)(obj + 0x38) = p + *(s32*)(p + 0x1C);
    q = D_1F80001C.bytes;
    *(u8**)(obj + 0x3C) = q + *(s32*)(q + 0x3C);
    *(u8**)(obj + 0x30) = D_8007B44C;
    *(s16*)(obj + 0x40) = 0x520;
    *(s16*)(obj + 0x42) = 0x7801;
    base = D_8009A0A0;
    if (mode == 0) {
        obj[0x16] = 2;
        obj[0x15] = base[0x15];
        *(u8**)(obj + 0x50) = D_80077138;
        *(u8**)(obj + 0x68) = D_80077140;
        func_80045D44(obj, base, ((s8*)obj)[1]);
        if (base[0x15] != 0) {
            *(s32*)(obj + 0x20) = 0x20000;
            obj[6] = 1;
        } else {
            *(s32*)(obj + 0x20) = 0xFFFE0000;
            obj[6] = 2;
        }
        *(s32*)(obj + 0x24) = 0;
        *(s16*)(obj + 0x8E) = 0xC;
        func_800171E8(obj, 0);
        func_80016490(1, 0xE, obj);
        func_8003D430(1, ((s8*)obj)[1], 1, obj);
    } else if (mode == 1) {
        src = *(u8**)(obj + 0x7C);
        obj[0x16] = mode;
        *(u16*)(obj + 0xA) = *(u16*)(src + 0xA);
        *(u16*)(obj + 0xE) = *(u16*)(src + 0xE);
        obj[0x15] = src[0x15];
        obj[5] = mode;
        obj[6] = src[6];
        func_800171E8(obj, 4);
    } else if (mode == 2) {
        src = *(u8**)(obj + 0x7C);
        obj[0x16] = mode;
        *(u16*)(obj + 0xA) = *(u16*)(src + 0xA);
        *(u16*)(obj + 0xE) = *(u16*)(src + 0xE);
        obj[0x15] = 0;
        obj[5] = mode;
        *(u8**)(obj + 0x50) = D_8007713C;
        func_800171E8(obj, 3);
    }
    *(s16*)(obj + 0x8C) = 0;
    obj[4]++;
}
