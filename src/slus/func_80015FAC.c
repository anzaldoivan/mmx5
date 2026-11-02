#include "types.h"

extern void func_8005A2D8(void);
extern void SsSetTableSize(void* table, s32 l, s32 t);
extern void SsSetTickMode(s32 mode);
extern void SsUtSetReverbType(s32 type);
extern s32 SpuClearReverbWorkArea(s32 mode);
extern void func_8005E428(void);
extern void SsUtSetReverbDepth(s32 l, s32 r);

extern u8 D_800E6B78;
extern s8 D_80093E60[];
extern s8 D_80093E6C[];
extern u8 D_800E8040[];
extern s8 D_800E8028[];
extern void* D_800E9618[];
extern u8 D_800E6B88[];

extern void _SsNoteOn();
extern void _SsSetProgramChange();
extern void dmy_SsNoteOn();
extern void func_8005CA58();
extern void _SsSetControlChange();
extern void func_8005CA98();
extern void _SsContMainVol();
extern void func_8005CB18();
extern void func_8005CB58();
extern void func_8005CB98();
extern void func_8005CC18();
extern void func_8005CC58();
extern void _SsContRpn1();
extern void func_8005CC98();
extern void func_8005CBD8();
extern void func_8005CCD8();
extern void func_8005CAD8();
extern void dmy_SsSetNrpnVabAttr0();
extern void func_8005CD58();
extern void func_8005CD98();
extern void func_8005CDD8();
extern void func_8005CE18();
extern void func_8005CE58();
extern void func_8005CE98();
extern void func_8005CED8();
extern void func_8005CF18();
extern void func_8005CF58();
extern void func_8005CF98();
extern void func_8005CFD8();
extern void func_8005D018();
extern void func_8005D058();
extern void func_8005D098();
extern void func_8005D0D8();
extern void func_8005D118();
extern void func_8005D158();
extern void func_8005D198();
extern void func_8005D1D8();

void func_80015FAC(void) {
    u8 i;
    void** p;

    D_800E6B78 = 0;
    for (i = 0; i < 6; i++) {
        D_80093E60[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        D_80093E6C[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        D_800E8040[i] = 0xFF;
    }
    for (i = 0; i < 24; i++) {
        D_800E8028[i] = -1;
    }
    p = D_800E9618;
    p[0] = _SsNoteOn;
    p[1] = _SsSetProgramChange;
    p[3] = dmy_SsNoteOn;
    p[2] = func_8005CA58;
    p[4] = _SsSetControlChange;
    p[5] = func_8005CA98;
    p[7] = _SsContMainVol;
    p[8] = func_8005CB18;
    p[9] = func_8005CB58;
    p[10] = func_8005CB98;
    p[11] = func_8005CC18;
    p[12] = func_8005CC58;
    p[13] = _SsContRpn1;
    p[14] = func_8005CC98;
    p[15] = func_8005CBD8;
    p[16] = func_8005CCD8;
    p[6] = func_8005CAD8;
    p[17] = dmy_SsSetNrpnVabAttr0;
    p[18] = func_8005CD58;
    p[19] = func_8005CD98;
    p[20] = func_8005CDD8;
    p[21] = func_8005CE18;
    p[22] = func_8005CE58;
    p[23] = func_8005CE98;
    p[24] = func_8005CED8;
    p[25] = func_8005CF18;
    p[26] = func_8005CF58;
    p[27] = func_8005CF98;
    p[28] = func_8005CFD8;
    p[29] = func_8005D018;
    p[30] = func_8005D058;
    p[31] = func_8005D098;
    p[32] = func_8005D0D8;
    p[33] = func_8005D118;
    p[34] = func_8005D158;
    p[35] = func_8005D198;
    p[36] = func_8005D1D8;
    func_8005A2D8();
    SsSetTableSize(D_800E6B88, 3, 10);
    SsSetTickMode(1);
    SsUtSetReverbType(2);
    while (SpuClearReverbWorkArea(2) == -1) {
    }
    func_8005E428();
    SsUtSetReverbDepth(8, 8);
}
