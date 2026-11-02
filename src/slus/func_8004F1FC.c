#include "types.h"
#include "addr.h"

extern s32 func_80045E2C(void);
extern void func_8004F874(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80016490(s32, s32, void*);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_8007B2E8[];
extern u8 D_8007B5DC[][3];
extern u8 D_8009A0A0[];

void func_8004F1FC(u8* obj) {
    s32 i;
    s8 st;
    u8* g;
    u8* h;
    u8* v;
    u8 b;

    st = ((s8*)obj)[2];
    obj[3] = 1;
    if (st == 9) {
        i = 0;
    } else if (st == 18) {
        i = 1;
    } else if (st == 20) {
        i = 2;
    } else if (st == 0) {
        i = 3;
    } else if (st == 19 || st == 46) {
        i = 2;
    }
    v = D_1F80001C.bytes + D_1F80001C.s32s[D_8007B5DC[i][0]];
    *(u8**)(obj + 0x30) = D_8007B2E8;
    *(s16*)(obj + 0x40) = 0;
    *(s16*)(obj + 0x42) = 0x7802;
    *(u8**)(obj + 0x3C) = v;
    if (i == 3) {
        *(s16*)(obj + 0x42) = func_80045E2C();
        g = D_8009A0A0;
        if (*(s32*)(g + 0xFC) & 0x800) {
            *(s16*)(obj + 0x42) = 0x7844;
        }
    }
    h = D_8009A0A0;
    obj[0x16] = 0;
    b = h[0x15];
    obj[0x5C] = 0;
    obj[0x15] = b;
    func_8004F874(obj);
    *(s16*)(obj + 0x8) = 0;
    *(s16*)(obj + 0xC) = 0;
    func_800171E8(obj, D_8007B5DC[i][1]);
    func_80016490(1, D_8007B5DC[i][2], obj);
    obj[4]++;
    func_8002D9EC(obj, 0x40, 0x20);
}
