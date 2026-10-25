#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern void func_80016490(s32, s32, void*);
extern void func_80028B18(s32, s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002A5C4(s32, s32, s32);
extern u8 D_800F9F04_ovl26[];
extern u8 D_8009A244;

void func_800F53E8_ovl26(u8* obj) {
    u8* p;

    func_80017248(obj);
    func_8002DF54(obj);
    if (obj[0x70] & 3) {
        func_80016490(2, 0x63, obj);
        p = D_800F9F04_ovl26;
        func_80028B18(0, 0x8B0, 0x11D0, p);
        func_80028B18(0, 0xA60, 0x11D0, p + 8);
        D_8009A244 = 1;
        func_800171E8(obj, 0x12);
        func_8002A5C4(0x32, 8, 1);
        *(s16*)(obj + 0x7C) = 0x5A;
        obj[6]++;
    }
}
