#include "types.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "addr.h"
#define D_800D1C28_as_u8 (*(u8*)&D_800D1C28)

extern u8* find_free_visual_obj(void);
extern u32* D_8007B2E8[];
extern s8 D_8009A0A2;

void func_800FF630_ovl07(u8* obj) {
    u8* e;
    u8* p;
    s32 off;

    move_object(obj);
    ((s32(*)())animate_object)(obj);
    if (*(s16*)(obj + 0xA) >= 0x1F20) {
        *(s16*)(obj + 0xA) = 0x1F20;
        e = find_free_visual_obj();
        if (e != 0) {
            e[0] = 0x21;
            e[1] = 3;
            if (D_8009A0A2 == 0) {
                e[2] = 3;
            } else {
                e[2] = 0xC;
            }
            e[0x14] = obj[0x14];
            p = D_1F80001C.bytes;
            off = *(s32*)(p + 4);
            *(u32***)(e + 0x30) = D_8007B2E8;
            *(s16*)(e + 0x40) = 0;
            *(u16*)(e + 0x42) = 0x7802;
            e[0x16] = 0;
            *(u8**)(e + 0x3C) = p + off;
            *(s16*)(e + 0xA) = *(s16*)(obj + 0xA);
            *(s16*)(e + 0xE) = *(s16*)(obj + 0xE);
            e[0x15] = 0;
        }
        play_sound(5, 0x25, obj);
        D_800D1C28_as_u8 = 1;
        obj[4]++;
        return;
    }
    func_8002D89C(obj);
}
