#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern void func_800F6A8C_ovl28(u8* obj);

void func_800F6644_ovl28(u8* obj) {
    D_1F80004C.bytes[0x8C] = 0;
    func_800F6A8C_ovl28(obj);
    animate_object(obj);
    set_animation(obj, 1);
    obj[6]++;
}

void func_800F6694_ovl28(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 7) == 2) {
        set_animation(obj, 10);
        *(s16*)(obj + 0x7C) = 0;
        *(s16*)(obj + 0x7E) = 5;
        obj[6]++;
    }
}

#define G D_1F80004C.bytes

void func_800F66E8_ovl28(u8* obj) {
    animate_object(obj);
    if (G[0x8C] == 2) {
        obj[6]++;
    }
}
#undef G

extern u8 D_800FE198_ovl28[][3];

#define G D_1F80004C.bytes
void func_800F6738_ovl28(u8* obj) {
    animate_object(obj);
    obj[5] = D_800FE198_ovl28[0][++G[0x8A] + G[0x89] * 3];
    obj[6] = 0;
    obj[7] = 0;
}
