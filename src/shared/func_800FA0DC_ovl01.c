/* Shared body (DK-5), from the banked draft of func_800FA0DC_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002DED4(u8* obj);
extern void func_80017248(u8* obj);
extern void func_8001296C(s32);
extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8002A600(s32, s32, s32);
extern u8 D_800FD578_ovl01[];
extern u8 D_800FD57C_ovl01[];
extern u8 D_800FD5A8_ovl01[];
extern u8 D_800FD5AC_ovl01[];

void DEDUP_NAME(u8* obj) {
    func_8002DED4(obj);
    func_80017248(obj);
    if ((obj[0x70] & 8) && *(s32*)(obj + 0x24) < 0) {
        func_8001296C(5);
        func_80016490(2, 7, obj);
        func_800171E8(obj, 0xF);
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(s16*)(obj + 0x7C) = 0x28;
        func_8002A600(0x1E, 4, 2);
        obj[6] = 2;
    }
    if (obj[0x47] == 9) {
        *(u8**)(obj + 0x54) = D_800FD5AC_ovl01;
        *(u8**)(obj + 0x50) = D_800FD5A8_ovl01;
    } else {
        *(u8**)(obj + 0x54) = D_800FD578_ovl01;
        *(u8**)(obj + 0x50) = D_800FD57C_ovl01;
    }
}
