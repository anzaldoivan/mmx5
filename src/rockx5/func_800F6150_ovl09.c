#include "types.h"

extern void func_800171E8(Ent6234*, s32);
extern void func_80017248(Ent6234*);
extern void func_8002DED4(Ent6234*);
extern u8 D_800FAD58_ovl09[][6];

void func_800F6150_ovl09(Ent6234* e) {
    if (--e->unk7C == 0) {
        u8 t;
        func_800171E8(e, 0);
        t = D_800FAD58_ovl09[e->unk96][e->unk97++];
        e->unk6 = 0;
        e->unk5 = t;
    }
    func_80017248(e);
    func_8002DED4(e);
}
