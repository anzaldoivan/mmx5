#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"

extern void (*D_80102BA0_ovl04[])(u8*);

void func_800FE068_ovl04(u8* obj) {
    u8* child;

    child = *(u8**)(obj + 0x80);
    *(u16*)(obj + 0x42) &= 0x7FFF;
    if (obj[0x45] & 1) {
        obj[3] = 1;
    } else {
        obj[3] = 0;
    }
    if (((s8*)child)[5] >= 4) {
        obj[5]++;
        set_animation(obj, 0xB);
    }
    D_80102BA0_ovl04[((s8*)obj)[6]](obj);
}

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

#include "shared/func_800FE228_ovl04.c"

void func_800FE230_ovl04(u8* arg0) {
    arg0[5] = arg0[0x8E];
}
