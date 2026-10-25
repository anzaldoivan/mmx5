#include "types.h"

extern u8 D_800FB448_ovl00[][6];
extern void func_80017248(Ent8EF4*);
extern void func_8002DED4(Ent8EF4*);
extern void func_8002D9EC(Ent8EF4* obj, s32 a, s32 b);

void func_800F8EF4_ovl00(Ent8EF4* obj) {
    if (--obj->unk7C == -1) {
        obj->unk5 = D_800FB448_ovl00[obj->unk8D][obj->unk8E++];
        obj->unk6 = 0;
    }
    func_80017248(obj);
    func_8002DED4(obj);
    func_8002D9EC(obj, 0xFF, 0xFF);
}
