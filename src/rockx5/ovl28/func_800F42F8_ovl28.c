#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "addr.h"
#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern u8 D_800FE310_ovl28[];

void func_800F42F8_ovl28(u8* obj) {
    u8* p;

    if (is_off_screen(obj, 0x20, 0x14) == 0) {
        animate_object(obj);
        func_800317B8(obj);
        if (D_8009A420_as_s32 & 1) {
            func_8002C338(
                0x13E,
                (void*)((s32)D_1F800024 + (D_800FE310_ovl28[obj[0x8F]] << 5)),
                1);
            func_8002C338(
                0x13F,
                (void*)((s32)D_1F800024 + (D_800FE310_ovl28[obj[0x8F]] << 5)),
                1);
            if (++obj[0x8F] == 6) {
                obj[0x8F] = 0;
            }
        }
        move_object(obj);
        func_8002D9EC(obj, 0x20, 0x14);
        return;
    }
    if ((obj[2] >> 4) == 1) {
        p = *(u8**)(obj + 0x7C);
        p[0x8C]++;
    }
    obj[4]++;
}
