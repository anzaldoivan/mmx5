#include "types.h"
#include "addr.h"

extern u8 D_80078C80[];
extern u8 D_8007A0E4[];
extern void func_80017214(u8* a0, s32 a1, s32 a2);

void func_8003B4CC(u8* p, s32 idx, s32 a2) {
    u8 t;

    if (*(signed char*)(p + 2) == 0) {
        if (D_80078C80[idx] == 0) {
            *(u8**)(p + 0x38) = D_1F800014 + *(s32*)D_1F800014;
            *(u8**)(p + 0x3C) = D_1F80001C.bytes + *(s32*)D_1F80001C.bytes;
            p[0x155] = 5;
        } else {
            *(u8**)(p + 0x38) = D_1F800014 + *(s32*)(D_1F800014 + 0x28);
            *(u8**)(p + 0x3C) =
                D_1F80001C.bytes + *(s32*)(D_1F80001C.bytes + 0x48);
            p[0x155] = 0x13;
        }
    } else {
        t = D_8007A0E4[idx];
        if (t == 0) {
            *(u8**)(p + 0x38) = D_1F800014 + *(s32*)D_1F800014;
            *(u8**)(p + 0x3C) = D_1F80001C.bytes + *(s32*)D_1F80001C.bytes;
        } else if (t == 1) {
            *(u8**)(p + 0x38) = D_1F800014 + *(s32*)(D_1F800014 + 4);
            *(u8**)(p + 0x3C) =
                D_1F80001C.bytes + *(s32*)(D_1F80001C.bytes + 0x14);
        } else if (t == 2) {
            *(u8**)(p + 0x38) = D_1F800014 + *(s32*)(D_1F800014 + 8);
            *(u8**)(p + 0x3C) =
                D_1F80001C.bytes + *(s32*)(D_1F80001C.bytes + 0x1C);
        }
    }
    func_80017214(p, idx, a2);
}
