#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"
#include "mmx5/system.h"

extern void (*D_80101BB0_ovl04[])(u8*);

void func_800F51F4_ovl04(u8* obj) {
    D_80101BB0_ovl04[(s8)obj[5]](obj);
    if (((s8*)obj)[3] != 0) {
        func_8002D9EC(obj, 0x40, 0x40);
    }
}

void func_800F5254_ovl04(Obj5254* obj) {
    obj->unk20 = 0xFFFE0000;
    obj->unk7C = 0xD0;
    set_animation(obj, 3);
    obj->unk6++;
}

extern s16 D_8009A0AE;

void func_800F5298_ovl04(u8* obj) {
    move_object(obj);
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        *(s16*)(obj + 0xE) = D_8009A0AE;
        *(u8*)(obj + 0x15) = 0x40;
        *(u8*)(obj + 0x6) += 1;
        *(s32*)(obj + 0x20) = 0x20000;
        *(s16*)(obj + 0x7C) = 0x50;
    }
}

void func_800F530C_ovl04(u8* obj) {
    move_object(obj);
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        obj[6]++;
    }
}

void func_800F5364_ovl04(u8* obj) {
    set_animation(obj, 4);
    *(s16*)(obj + 0x7C) = (random_byte() & 3) * 10 + 0x20;
    obj[6]++;
}

#define g_Player_as_Obj5864 (*(Obj5864*)&g_Player)

void func_800F53B8_ovl04(Obj5864* obj) {
    animate_object(obj);
    if (obj->unkE > g_Player_as_Obj5864.unkE) {
        if (obj->unkE - g_Player_as_Obj5864.unkE >= 9) {
            obj->unkE -= 2;
            goto end; // !FAKE: skips the second compare, as the target branches to the tail
        }
    }
    if (obj->unkE < g_Player_as_Obj5864.unkE) {
        if (g_Player_as_Obj5864.unkE - obj->unkE >= 9) {
            obj->unkE += 2;
        }
    }
end:
    if (--obj->unk7C == 0) {
        obj->unk6++;
    }
}

void func_800F546C_ovl04(u8* arg0) {
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        arg0[6] = 3;
    }
}
