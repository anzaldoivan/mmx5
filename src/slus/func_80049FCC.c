#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern int func_80045D44();
extern s32 func_80016490(s32, s32, void*);
extern u8 D_8009A0A0[];
extern u8 D_8007B488[];
extern s32 D_80077144[];

void func_80049FCC(u8* obj) {
    u8* p = D_8009A0A0;
    u8* t;
    s32 off;

    obj[3] = 1;
    *(u8**)(obj + 0x38) = D_1F800014 + *(s32*)(D_1F800014 + 0x2C);
    t = D_1F80001C.bytes;
    off = *(s32*)(t + 0x60);
    *(u8**)(obj + 0x30) = D_8007B488;
    *(s16*)(obj + 0x40) = 0x540;
    *(s16*)(obj + 0x42) = 0x7801;
    obj[0x16] = 2;
    *(u8**)(obj + 0x3C) = t + off;
    obj[0x15] = p[0x15];
    func_800171E8(obj, 0);
    *(s32**)(obj + 0x50) = &D_80077144[((s8*)obj)[0x45]];
    func_80045D44(obj, p, ((s8*)obj)[1]);
    if (obj[0x15] != 0) {
        *(u16*)(obj + 0xA) += 0x84;
    } else {
        *(u16*)(obj + 0xA) -= 0x84;
    }
    func_80016490(1, 0x18, obj);
    *(s16*)(obj + 0x8C) = 0;
    obj[4]++;
}
