#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern void func_80027288(void);
extern void func_80017D88(void);
extern void silence_sound(s32, s32);
extern void func_8002D004(void);
extern void end_task_slot(s32);
extern void func_800132F8(s32);
extern void task_yield(s32);
extern u8 D_800D1F28[];
extern void* D_80070EFC[];

void func_8001E534(void) {
    u8* s;
    u8* p;
    s32 mask;

    s = D_800D1F28;
    s[0xD] = 1;
    D_8009A420[6] = 0;
    D_8009A420[8] = 1;
    func_80027288();
    func_80017D88();
    silence_sound(0xFF, 0);
    func_8002C50C();
    func_8002D004();
    for (;;) {
        p = D_800D1F28;
        ((void (*)(u8*))D_80070EFC[(s8)D_800D1F28[0]])(p);
        if (((s8*)p)[0xD] == 0) {
            if ((s8)D_800D1F28[0] != 1) {
                mask = 0x8F0;
            } else {
                mask = 0x800;
            }
            if (g_pad1_buttons[2] & mask) {
                play_sound(0, 0x22, 0);
                p[0xD] = 1;
                p[0xE] = D_800D1F28[0];
                end_task_slot(1);
                if ((s8)D_8009A420[4] == 0) {
                    func_800132F8(8);
                }
                D_800D1F28[0] = 5;
                p[1] = 0;
                p[2] = 0;
                p[3] = 0;
            }
        }
        task_yield(1);
    }
}
