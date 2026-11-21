#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/ovl06.h"

extern u8 D_80074EE0[];
extern u8 D_80075FC0[];

void func_800FA400_ovl06(u8* obj) {
    move_object(obj);
    *(u8**)(obj + 0x58) = D_80074EE0;
    func_8002FB58(obj);
    animate_object(obj);
    if (!(obj[0x70] & 3)) {
        if (obj[0x15] == 0) {
            if (*(s16*)(obj + 0xA) >= *(s16*)(D_1F80004C.bytes + 0x8C) - 0xA0) {
                return;
            }
        } else {
            if (*(s16*)(D_1F80004C.bytes + 0x8C) + 0xA0 >= *(s16*)(obj + 0xA)) {
                return;
            }
        }
    }
    set_animation(obj, 0x1E);
    *(u8**)(obj + 0x58) = D_80075FC0;
    obj[0x62] = 0;
    obj[6]++;
}

void func_800FA4D8_ovl06(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        obj[0x60] = 5;
        animate_object(obj);
        func_800F9180_ovl06(obj);
    }
}
