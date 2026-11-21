#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/ovl07.h"

void func_800FC718_ovl07(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == -1) {
        switch (D_1F80004C.bytes[0x90]) {
        case 0:
            set_animation(obj, 0x15);
            break;
        case 1:
            set_animation(obj, 0x15);
            break;
        case 2:
            set_animation(obj, 0x13);
            break;
        }
        obj[6]++;
    } else {
        animate_object(obj);
    }
}

void func_800FC7D4_ovl07(u8* arg0) {
    if (((signed char*)arg0)[0x45] == 1) {
        func_800FB030_ovl07(arg0);
    } else {
        animate_object(arg0);
    }
}
