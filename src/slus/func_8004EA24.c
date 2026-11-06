#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D89C(u8* obj);
extern u8 D_8009A420[];
extern u16 D_800C9320;
extern s8 D_800D1F28;

void func_8004EA24(u8* obj) {
    u16 pad;
    u8 v;

    if (obj[0x55] == 0) {
        if (((s8*)obj)[2] == -1 || ((pad = D_800C9320) & 0x10) ||
            ((pad & 0x800) && D_800D1F28 == 10)) {
            ((s8*)obj)[2] = -1;
        }
        if (((s8*)obj)[2] == -1 || ((pad = D_800C9320) & 0x10) ||
            ((pad & 0x800) && D_800D1F28 == 8)) {
            ((s8*)obj)[2] = -1;
        }
    }
    if (((s8*)obj)[2] != -1) {
        if (obj[0x54] != D_8009A420[7]) {
            v = D_8009A420[7];
            *(s16*)(obj + 0xE) = (*(u8**)(obj + 0x50))[v * 3 + 2];
            obj[0x54] = D_8009A420[7];
        }
    }
    func_80017248(obj);
    func_8002D89C(obj);
}
