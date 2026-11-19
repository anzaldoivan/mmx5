#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800F6D64_ovl28(u8* obj) {
    u8* p;

    if (is_off_screen(obj, 0xF0, 0x60) == 0) {
        animate_object(obj);
        func_800317B8(obj);
        move_object(obj);
        func_8002D9EC(obj, 0xC0, 0x40);
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
