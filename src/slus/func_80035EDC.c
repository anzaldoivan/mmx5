#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern void func_8003D344(void* arg0);
extern u8 D_8009A1F8[];

void func_80035EDC(u8* obj) {
    u8* p;
    u16 v;

    animate_object(obj);
    if (((s8*)obj)[6] == 0) {
        if (((s8*)obj)[0x46] == 0) {
            p = D_8009A1F8;
            v = *(u16*)(p + 0xE);
            *(s16*)(p + 0x28) = v;
            *(s16*)(p + 0x2A) = v;
            *(s16*)(p + 0x20) = v;
            *(s16*)(p + 0x22) = v;
            func_8003B33C(obj, 4);
            obj[6]++;
        }
    } else if (is_off_screen(obj, 0x20, 0x40) == 0) {
        move_object(obj);
        func_8003D344(obj);
    } else {
        obj[3] = 0;
        obj[4] = 3;
        obj[5] = 0;
        obj[6] = 0;
    }
}
