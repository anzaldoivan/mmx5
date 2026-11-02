#include "types.h"
#include "addr.h"

extern u8 D_8009A0A0[];
extern void* D_800FD544_ovl01[];
extern void func_80017248(u8* obj);
extern s32 func_8003240C(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F7EB0_ovl01(u8* obj) {
    u8* g;

    if ((((s8*)obj)[2] & 0xF0) && (*(u8**)(D_1F80004C.bytes + 0x80))[7] >= 2) {
        obj[4] = 2;
        func_8004FD24(obj);
        return;
    }
    g = D_8009A0A0;
    if (g[0xF7] == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        func_80017248(obj);
        ((void (*)(u8*))D_800FD544_ovl01[((s8*)obj)[5]])(obj);
    }
    if (((s8*)obj)[5] != 3 && g[0xF8] == 0) {
        func_8003240C(obj);
    }
    func_80031DD0(obj);
    if (func_8002D938(obj, 0x50, 0x40) == 0) {
        func_8002D9EC(obj, 0x30, 0x30);
        return;
    }
    if (!(((s8*)obj)[2] & 0xF0)) {
        obj[4] = 3;
    }
}
