/* Adapted from mmx6 @c1c892d src/shared/rock_00/func_801EE5D4.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/weapons/weapon_00_lemon.c:lemon_deflected, AGPL-3.0; proven shared with X6 by exact signature 9c5292152b2a (see THIRD_PARTY.md). */
#include "types.h"
#define ANIMATED_OBJECT(object) ((X4_Obj*)(object))
#define BASE_OBJECT(object) ((X4_Obj*)(object))
#define MOVING_OBJECT(object) ((X4_Obj*)(object))
#define M2C_UNK s32
void func_80046030(void* arg0);
M2C_UNK func_8002D9EC(void*, M2C_UNK, M2C_UNK);
void func_80017248(X4_Obj*);
void func_8002DF54(X4_Obj*);
s32 func_8002D938(X4_Obj*, s32, s32);

void func_80045FCC(X4_Obj* arg0) {
    if (func_8002D938(BASE_OBJECT(arg0), 0xC, 8) == 0) {
        func_80017248(ANIMATED_OBJECT(arg0));
        func_8002DF54(MOVING_OBJECT(arg0));
        func_8002D9EC(BASE_OBJECT(arg0), 0xC, 8);
        return;
    }
    func_80046030(arg0);
}
