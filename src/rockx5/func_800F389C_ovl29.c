#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern s16 D_8009A0AA;
extern u8 D_800F9894_ovl29[];
extern u8 D_800F98A0_ovl29[];
extern s16 D_800FA648_ovl29;
extern s16 D_800FA64C_ovl29;

void func_800F389C_ovl29(u8* obj) {
    s16 x;
    s16 d;
    s32 v;

    if (*(s8*)(obj + 0x45) != 0) {
        *(u8**)(obj + 0x50) = D_800F98A0_ovl29;
    } else {
        *(u8**)(obj + 0x50) = D_800F9894_ovl29;
    }
    if (obj[0x70] & 8) {
        obj[6]++;
        func_800171E8(obj, 6);
        *(u8**)(obj + 0x50) = D_800F9894_ovl29;
        obj[0x60] = 4;
        obj[0x67] = 0;
        func_80016490(2, 0xAF, obj);
    }
    if (*(s8*)(obj + 0x45) == 2) {
        d = D_8009A0AA;
        x = *(s16*)(obj + 0xA);
        if (x < d) {
            if (x < D_800FA648_ovl29 - 0x50) {
                obj[0x15] = 0x40;
            } else {
                obj[0x15] = 0;
            }
        } else if (x < D_800FA64C_ovl29 + 0x50) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        v = 0xFFF80000;
        if (obj[0x15] != 0) {
            v = 0x80000;
        }
        *(s32*)(obj + 0x20) = v;
    }
    if (*(s8*)(obj + 0x45) == 1) {
        func_8002DED4(obj);
    }
    func_80017248(obj);
}
