#include "types.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s32 func_8002F8FC(u8* a0);
extern void (*D_800FE774_ovl28[])(void*);
extern void (*D_800FE780_ovl28[])(void*);
extern void (*D_800FE78C_ovl28[])(void*);
extern void (*D_800FE798_ovl28[])(void*);
extern void (*D_800FE7A4_ovl28[])(void*);
extern void (*D_800FE7B0_ovl28[])(void*);
extern void (*D_800FE7BC_ovl28[])(void*);
extern void (*D_800FE7C8_ovl28[])(void*);
extern void (*D_800FE7D4_ovl28[])(void*);
extern void (*D_800FE7E0_ovl28[])(void*);
extern void (*D_800FE7EC_ovl28[])(void*);

void func_800F7BE4_ovl28(u8* self) {
    func_8002F8FC(self);
    M2C_FIELD(self, s8*, 3) = 0;
    switch (M2C_FIELD(self, s8*, 2)) {
    case 0:
        D_800FE774_ovl28[M2C_FIELD(self, s8*, 4)](self);
        break;
    case 1:
        D_800FE780_ovl28[M2C_FIELD(self, s8*, 4)](self);
        break;
    case 2:
        D_800FE78C_ovl28[M2C_FIELD(self, s8*, 4)](self);
        break;
    case 3:
        D_800FE798_ovl28[M2C_FIELD(self, s8*, 4)](self);
        break;
    case 4:
        D_800FE7A4_ovl28[M2C_FIELD(self, s8*, 4)](self);
        break;
    case 5:
        D_800FE7B0_ovl28[M2C_FIELD(self, s8*, 4)](self);
        break;
    case 6:
        D_800FE7BC_ovl28[M2C_FIELD(self, s8*, 4)](self);
        break;
    case 7:
        D_800FE7C8_ovl28[M2C_FIELD(self, s8*, 4)](self);
        break;
    case 8:
        D_800FE7D4_ovl28[M2C_FIELD(self, s8*, 4)](self);
        break;
    case 9:
    case 10:
        D_800FE7E0_ovl28[M2C_FIELD(self, s8*, 4)](self);
        break;
    case 11:
        D_800FE7EC_ovl28[M2C_FIELD(self, s8*, 4)](self);
        break;
    }
}
