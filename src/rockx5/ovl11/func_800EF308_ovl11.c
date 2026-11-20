#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8* alloc_class3_slot(void);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern u8* find_free_visual_obj(void);
extern void start_pad_vibration(s32);
extern u8 D_800F95F0_ovl11[];

void func_800EF308_ovl11(u8* obj) {
    u8* q;
    u8* p;

    q = alloc_class3_slot();
    if (q != 0) {
        q[0] = 1;
        q[1] = 5;
    }
    func_8004FD24(obj);
    func_8004D4F4(2, D_800F95F0_ovl11, obj);
    set_animation(obj, 3);
    obj[4] = 2;
    *(s16*)(obj + 0x82) = 1;
    p = find_free_visual_obj();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 8;
        p[2] = 0;
        p[0x15] = obj[0x15];
        *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
        *(u16*)(p + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
        *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
        *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
        p[0x14] = obj[0x14];
        *(s32*)(p + 0x8) = *(s32*)(obj + 0x8);
        *(s32*)(p + 0xC) = *(s32*)(obj + 0xC);
    }
    start_pad_vibration(9);
}
