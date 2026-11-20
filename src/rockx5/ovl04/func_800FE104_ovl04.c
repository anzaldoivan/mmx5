#include "types.h"
#include "mmx5/globals.h"

extern u8 D_800D1C2A;
extern void (*D_80102BA0_ovl04[])(u8*);

void func_800FE104_ovl04(u8* obj) {
    u8* child;

    child = *(u8**)(obj + 0x80);
    func_800317B8(obj);
    animate_object(obj);
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
