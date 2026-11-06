#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_8002DF78(void);
extern s16 D_8009A0AA;
extern signed char D_800D1CA2;
extern u8 D_800FA2E0_ovl29[][6];

void func_800F367C_ovl29(u8* obj) {
    u32 r;
    u8 b;

    if (D_8009A0AA > *(s16*)(obj + 0xA)) {
        obj[0x15] = 0x40;
    } else {
        obj[0x15] = 0;
    }
    r = func_8002DF78() & 0xF;
    obj[0x8E] = 0;
    if (D_800D1CA2 / 2 < *(s8*)(obj + 0x5C)) {
        if (r < 7) {
            obj[0x8D] = 0;
        } else {
            obj[0x8D] = 1;
        }
    } else if (r < 3) {
        obj[0x8D] = 2;
    } else if (r < 6) {
        obj[0x8D] = 3;
    } else if (r < 8) {
        obj[0x8D] = 4;
    } else {
        obj[0x8D] = 5;
    }
    b = D_800FA2E0_ovl29[obj[0x8D]][obj[0x8E]];
    obj[6] = 0;
    obj[0x8E]++;
    obj[5] = b;
    func_80017248(obj);
    func_8002D9EC(obj, 0x40, 0x40);
}
