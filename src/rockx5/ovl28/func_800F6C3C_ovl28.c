#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800F6C3C_ovl28(u8* obj) {
    u8* p;

    if ((u16)(*(u16*)(obj + 0xA) - 0x18E1) < 0x18F) {
        func_800317B8(obj);
        animate_object(obj);
        move_object(obj);
        func_8002D9EC(obj, 0x20, 0x14);
    } else {
        if ((obj[2] >> 4) == 1) {
            p = *(u8**)(obj + 0x7C);
            p[0x8C]++;
        }
        obj[4]++;
    }
    if (*(signed char*)(*(u8**)(obj + 0x7C) + 4) == 2) {
        obj[4] = 2;
    }
}
