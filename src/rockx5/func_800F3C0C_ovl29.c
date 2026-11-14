#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern u8* func_8002D27C(void);
extern void func_8002DED4(u8* obj);
extern s16 D_800FA648_ovl29;
extern s16 D_800FA64C_ovl29;

void func_800F3C0C_ovl29(u8* obj) {
    u8* p;
    s32 v;
    s32 d;
    s32 x;
    s32 y;

    if (obj[0x8B] != 0) {
        if (obj[0x8C] != 0) {
            s32 n;

            y = *(s16*)(obj + 0xA) + 0x30;
            x = D_800FA648_ovl29;
            n = obj[0x8B];
            d = x - y;
            if (d < 0) {
                d = y - x;
            }
            v = (d << 16) / n;
        } else {
            s32 n;

            y = *(s16*)(obj + 0xA) - 0x30;
            x = D_800FA64C_ovl29;
            n = obj[0x8B];
            d = y - x;
            if (d < 0) {
                d = x - y;
            }
            v = (d << 16) / n;
        }
        if (obj[0x8C] == 0) {
            v = -v;
        }
        *(s32*)(obj + 0x20) = v;
        obj[0x8B]--;
    }
    func_8002DED4(obj);
    if ((obj[0x70] & 8) && *(s32*)(obj + 0x24) < 0) {
        if (obj[0x8C] != 0) {
            y = (u16)D_800FA648_ovl29 - 0x30;
        } else {
            y = (u16)D_800FA64C_ovl29 + 0x30;
        }
        *(s16*)(obj + 0xA) = y;
        func_800171E8(obj, 6);
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x26;
            p[2] = 2;
            *(u8**)(p + 0x50) = obj;
        }
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x26;
            p[2] = 3;
            *(u8**)(p + 0x50) = obj;
        }
        obj[0x67] = 0;
        func_80016490(2, 0xAF, obj);
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        obj[6]++;
    }
}
