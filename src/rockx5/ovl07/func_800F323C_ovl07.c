#include "types.h"
#include "mmx5/title.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

extern int func_8002D7A0();
extern s32 func_8002E804(u8*, u8*);
extern u8 D_800D1C00[];
extern u8 D_800D1DC0[];

void func_800F323C_ovl07(u8* arg0) {
    u8* p;

    p = g_Player;
    if (((s8*)p)[0xD5] != 0) {
        p = D_800D1DC0;
        if (((s8*)p)[5] == 0) {
            p += 0xB0;
        }
    }
    if (func_8002E804(arg0, p) != 0) {
        play_sound(5, 0x23, 0);
        D_800D1C00[0x26]++;
        arg0[4]++;
    }
    animate_object(arg0);
    if (is_off_screen(arg0, 0x40, 0x40) == 0) {
        func_8002D9EC(arg0, 0x20, 0x20);
        return;
    }
    func_8002D7A0(arg0);
}
