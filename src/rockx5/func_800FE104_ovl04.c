#include "types.h"

extern s32 func_800317B8(u8* a0);
extern void func_80017248(u8* obj);
extern void func_8004FD90(u8*, s32, s32, s32);
extern s32 func_8004FD24(u8* a0);
extern u8 D_800D1C2A;
extern void (*D_80102BA0_ovl04[])(u8*);

void func_800FE104_ovl04(u8* obj) {
    u8* child;

    child = *(u8**)(obj + 0x80);
    func_800317B8(obj);
    func_80017248(obj);
    obj[3] = 1;
    if (*(u16*)(child + 0x42) & 0x8000) {
        *(u16*)(obj + 0x42) |= 0x8000;
    } else {
        *(u16*)(obj + 0x42) &= 0x7FFF;
    }
    if (D_800D1C2A & 4) {
        *(u16*)(obj + 0x42) &= 0x7FFF;
        obj[5]++;
        func_8004FD90(obj, 1, 0x1F, 0x1F);
        func_8004FD90(obj, 1, 0x1F, 0x1F);
        func_8004FD90(obj, 1, 0x1F, 0x1F);
        func_8004FD90(obj, 1, 0x1F, 0x1F);
        func_8004FD24(obj);
        return;
    }
    D_80102BA0_ovl04[((s8*)obj)[6]](obj);
}
