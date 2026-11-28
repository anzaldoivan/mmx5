#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern void func_800132F8(s32);
extern s32 func_80017D88(void);
extern s8 D_8009A424;

void func_8001E2E4(u8* obj) {
    if (D_8009A424 == 0) {
        if (g_pad1_buttons[2] & 0x1000) {
            play_sound(0, 0xC, 0);
            if (((s8*)obj)[2] == 0) {
                obj[2] = 3;
            } else {
                obj[2] = obj[2] - 1;
            }
        }
        if (g_pad1_buttons[2] & 0x4000) {
            play_sound(0, 0xC, 0);
            if (((s8*)obj)[2] == 3) {
                obj[2] = 0;
            } else {
                obj[2] = obj[2] + 1;
            }
        }
        if (g_pad1_buttons[2] & 0x840) {
            play_sound(0, 0x22, 0);
            func_800132F8(8);
            func_80017D88();
            obj[1]++;
        }
        if (g_pad1_buttons[2] == 0) {
            *(u16*)(obj + 4) += 1;
            if (*(s16*)(obj + 4) > 0x4650) {
                func_80017D88();
                func_800132F8(8);
                *(u16*)(obj + 4) = 0;
                obj[1] += 2;
            }
        } else {
            *(u16*)(obj + 4) = 0;
        }
    }
}

extern s8 D_8009A424;
extern void func_8002CF20(void);
extern void create_task(s32, void (*)(void));
extern void func_80012EAC(void);
extern void func_80020904(void);

void func_8001E440(u8* a0) {
    u8 v;

    if (D_8009A424 == 0) {
        switch (((s8*)a0)[2]) {
        case 0:
            func_8002CF20();
            g_playthrough_state.u[0] = 0;
            g_playthrough_state.u[1] = 0;
            g_playthrough_state.u[2] = 0;
            g_playthrough_state.u[3] = 0;
            create_task(1, func_80020904);
            func_80012EAC();
            break;
        case 1:
            v = 7;
            goto store; // !FAKE: goto kept for the matching branch layout
        case 2:
            v = 8;
        store: // !FAKE: label kept for the matching branch layout
            a0[0] = v;
            a0[1] = 0;
            a0[2] = 0;
            a0[3] = 0;
            break;
        default:
            func_8002CF20();
            g_playthrough_state.u[0] = 0;
            g_playthrough_state.u[1] = 0;
            g_playthrough_state.u[2] = 0;
            g_playthrough_state.u[3] = 0;
            g_playthrough_state.u[0x79] = 10;
            create_task(1, func_80020904);
            func_80012EAC();
            break;
        }
    }
}
