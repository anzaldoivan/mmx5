#include "types.h"

// from rockx5 800F8EF4: timer at 0x7C, table row 0x8D, column 0x8E
typedef struct Ent8EF4 {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x7C - 0x07];
    /* 0x7C */ s16 unk7C;
    /* 0x7E */ u8 pad7E[0x8D - 0x7E];
    /* 0x8D */ u8 unk8D;
    /* 0x8E */ u8 unk8E;
} Ent8EF4;

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
