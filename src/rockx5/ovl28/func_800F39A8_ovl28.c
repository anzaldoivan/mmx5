#include "types.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

extern Tbl39A8 D_800EEB14_ovl28;

extern void func_800F6A8C_ovl28(u8* obj);
extern s32 func_8002B5B4(s32);

void func_800F39A8_ovl28(u8* obj) {
    Tbl39A8 tbl;
    u8* e;
    s32 i;
    s32 r;
    s32 x;
    s32 y;

    tbl = D_800EEB14_ovl28;
    animate_object(obj);
    func_800F6A8C_ovl28(obj);
    if (*(s16*)(obj + 0x7C) != 0) {
        (*(s16*)(obj + 0x7C))--;
        return;
    }
    for (i = 0; i < *(s16*)(obj + 0x7E) + 1; i++) {
        e = func_8002D1A4();
        if (e != 0) {
            if (*(s16*)(obj + 0x7E) == 2 && i == 2) {
                e[2] = 0x10;
                obj[6]++;
            } else {
                if (*(s16*)(obj + 0x7E) == 0 && i == 0) {
                    r = (u8)(((u32(*)())random_byte)() % 3);
                    switch (r) {
                    case 1:
                        play_sound(2, 0x7F, obj);
                        break;
                    case 2:
                        play_sound(2, 0x80, obj);
                        break;
                    }
                }
                e[2] = 0;
                *(s16*)(obj + 0x7C) = 50;
            }
            e[0] = 0x61;
            e[1] = 0x23;
            e[2] |= tbl.b[*(s16*)(obj + 0x7E)][i];
            x = func_8002B5B4(0x40);
            y = func_8002B5B4(0x40);
            *(s16*)(e + 0x42) =
                ((x * 4 + 0x19) % 16) | (((y + 6) / 4 + 0x1E0) << 6);
            *(u16*)(e + 0x40) = *(u16*)(obj + 0x40);
            *(s32*)(e + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(e + 0x3C) = *(s32*)(obj + 0x3C);
            *(u8**)(e + 0x7C) = obj;
        }
    }
    (*(s16*)(obj + 0x7E))++;
}
