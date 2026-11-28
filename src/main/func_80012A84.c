#include "types.h"
#include "mmx5/globals.h"
#define D_800C931C_as_u16 (*(u16*)&g_pad1_buttons)

extern void SetDispMask(s32);
extern s32 end_task_slot(s32);
extern void func_80016384(void);
extern void func_8001E6AC(void);
extern void func_8002CF20(void);
extern s32 D_8006FB14;
extern s32 D_8006FC24;
extern s32 D_80091D54;
extern u16 D_8009A41A;
extern s8 D_8009A424;

void func_80012A84(void) {
    s32 t;

    if (D_80091D54 != 0 && D_8009A424 == 0) {
        if ((D_800C931C_as_u16 & 0x900) == 0x900) {
            t = D_8009A41A - 1;
            D_8009A41A = t;
            if ((t << 16) == 0) {
                D_8006FB14 = 0;
                D_8006FC24 = 0;
                D_8006FC28.s = 0;
                D_80091D54 = 0;
                D_800E9300.s = 0;
                SetDispMask(0);
                end_task_slot(0);
                end_task_slot(1);
                end_task_slot(2);
                end_task_slot(3);
                D_8009A41A = 60;
                func_8001E668();
                func_80016384();
                func_8002CF20();
                func_8001E6AC();
            }
        } else {
            D_8009A41A = 60;
        }
    }
}
