#include "types.h"

extern void func_800EFCE4_ovl07(u8* obj, s32 arg1);
extern void func_800F0924_ovl07(u8* obj);
extern void func_800F0864_ovl07(u8* obj);
extern void func_800F0670_ovl07(u8* obj);
extern void func_80017248(u8* obj);
extern void func_800F0008_ovl07(u8* obj);

void func_800F0464_ovl07(u8* obj) {
    if (!(obj[0x70] & 8)) {
        obj[5] = 4;
        obj[6] = 0;
    } else {
        func_800EFCE4_ovl07(obj, obj[0x82]);
        func_800F0924_ovl07(obj);
        if (obj[0x7D] == 0) {
            func_800F0864_ovl07(obj);
        }
        func_800F0670_ovl07(obj);
        func_80017248(obj);
        func_800F0008_ovl07(obj);
    }
}
