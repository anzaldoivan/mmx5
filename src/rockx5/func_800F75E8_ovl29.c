#include "types.h"

extern s32 func_800317B8(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern u8* func_8002D1A4();
extern s32 D_8009A420;

void func_800F75E8_ovl29(u8* obj) {
    u8* child;
    s32 t;
    s16 y;

    func_800317B8(obj);
    func_8002D9EC(obj, 0x30, 0x30);
    if (D_8009A420 & 1) {
        func_80017248(obj);
        t = *(u16*)(obj + 0x88) - 1;
        *(u16*)(obj + 0x88) = t;
        if ((t << 16) == 0 && (obj[0x70] & 3) == 0) {
            child = func_8002D1A4();
            if (child != 0) {
                child[0] = 0x41;
                child[1] = 0x29;
                child[2] = 3;
                *(u8**)(child + 0x7C) = obj;
                y = *(s16*)(obj + 0xA);
                *(s16*)(child + 0xA) = obj[0x15] ? y + 0x18 : y - 0x18;
                *(s16*)(child + 0xE) = *(s16*)(obj + 0xE);
                *(s16*)(child + 0x88) = 3;
            }
        }
        if (obj[0x47] == 0x8A) {
            *(s32*)(obj + 0x50) = 0;
        }
    }
    if (*(s8*)(obj + 0x46) == 0) {
        obj[5] = 0;
        obj[6] = 0;
        obj[4]++;
    }
}
