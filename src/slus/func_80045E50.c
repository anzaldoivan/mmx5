/* Adapted from mmx6 @c1c892d src/shared/rock_00/func_801EE458.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/weapons/weapon_00_lemon.c:lemon_main, AGPL-3.0; proven shared with X6 by exact signature e25d4c5c1482 (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define ANIMATED_OBJECT(object) ((X4_Obj*)(object))
#define BASE_OBJECT(object) ((X4_Obj*)(object))
void func_80045ED4(X4_Obj*);
void func_80045F30(X4_Obj*);
void func_80046030(void* arg0);
#define M2C_UNK s32
M2C_UNK func_8002D9EC(void*, M2C_UNK, M2C_UNK);
void func_80017248(X4_Obj*);
s32 func_8002D938(X4_Obj*, s32, s32);

void func_80045E50(X4_Obj* arg0) {
    if (func_8002D938(BASE_OBJECT(arg0), 0xC, 8) == 0) {
        func_80017248(ANIMATED_OBJECT(arg0));
        if (M2C_FIELD(arg0, s8*, 0x98) == 0) {
            func_80045ED4(ANIMATED_OBJECT(arg0));
            func_8002D9EC(BASE_OBJECT(arg0), 0xC, 8);
            return;
        }
        func_80045F30(arg0);
        return;
    }
    func_80046030(arg0);
}
