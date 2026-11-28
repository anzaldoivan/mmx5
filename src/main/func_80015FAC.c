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
extern void dmy_SsGetMetaEvent();
extern void dmy_SsSetPitchBend();
extern void _SsSetControlChange();
extern void dmy_SsContBankChange();
extern void _SsContMainVol();
extern void dmy_SsContPanpot();
extern void dmy_SsContExpression();
extern void dmy_SsContDamper();
extern void dmy_SsContNrpn1();
extern void dmy_SsContNrpn2();
extern void _SsContRpn1();
extern void dmy_SsContRpn2();
extern void dmy_SsContExternal();
extern void dmy_SsContResetAll();
extern void dmy_SsContDataEntry();
extern void dmy_SsSetNrpnVabAttr0();
extern void dmy_SsSetNrpnVabAttr1();
extern void dmy_SsSetNrpnVabAttr2();
extern void dmy_SsSetNrpnVabAttr3();
extern void dmy_SsSetNrpnVabAttr4();
extern void dmy_SsSetNrpnVabAttr5();
extern void dmy_SsSetNrpnVabAttr6();
extern void dmy_SsSetNrpnVabAttr7();
extern void dmy_SsSetNrpnVabAttr8();
extern void dmy_SsSetNrpnVabAttr9();
extern void dmy_SsSetNrpnVabAttr10();
extern void dmy_SsSetNrpnVabAttr11();
extern void dmy_SsSetNrpnVabAttr12();
extern void dmy_SsSetNrpnVabAttr13();
extern void dmy_SsSetNrpnVabAttr14();
extern void dmy_SsSetNrpnVabAttr15();
extern void dmy_SsSetNrpnVabAttr16();
extern void dmy_SsSetNrpnVabAttr17();
extern void dmy_SsSetNrpnVabAttr18();
extern void dmy_SsSetNrpnVabAttr19();

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
    p[3] = dmy_SsGetMetaEvent;
    p[2] = dmy_SsSetPitchBend;
    p[4] = _SsSetControlChange;
    p[5] = dmy_SsContBankChange;
    p[7] = _SsContMainVol;
    p[8] = dmy_SsContPanpot;
    p[9] = dmy_SsContExpression;
    p[10] = dmy_SsContDamper;
    p[11] = dmy_SsContNrpn1;
    p[12] = dmy_SsContNrpn2;
    p[13] = _SsContRpn1;
    p[14] = dmy_SsContRpn2;
    p[15] = dmy_SsContExternal;
    p[16] = dmy_SsContResetAll;
    p[6] = dmy_SsContDataEntry;
    p[17] = dmy_SsSetNrpnVabAttr0;
    p[18] = dmy_SsSetNrpnVabAttr1;
    p[19] = dmy_SsSetNrpnVabAttr2;
    p[20] = dmy_SsSetNrpnVabAttr3;
    p[21] = dmy_SsSetNrpnVabAttr4;
    p[22] = dmy_SsSetNrpnVabAttr5;
    p[23] = dmy_SsSetNrpnVabAttr6;
    p[24] = dmy_SsSetNrpnVabAttr7;
    p[25] = dmy_SsSetNrpnVabAttr8;
    p[26] = dmy_SsSetNrpnVabAttr9;
    p[27] = dmy_SsSetNrpnVabAttr10;
    p[28] = dmy_SsSetNrpnVabAttr11;
    p[29] = dmy_SsSetNrpnVabAttr12;
    p[30] = dmy_SsSetNrpnVabAttr13;
    p[31] = dmy_SsSetNrpnVabAttr14;
    p[32] = dmy_SsSetNrpnVabAttr15;
    p[33] = dmy_SsSetNrpnVabAttr16;
    p[34] = dmy_SsSetNrpnVabAttr17;
    p[35] = dmy_SsSetNrpnVabAttr18;
    p[36] = dmy_SsSetNrpnVabAttr19;
    func_8005A2D8();
    SsSetTableSize(D_800E6B88, 3, 10);
    SsSetTickMode(1);
    SsUtSetReverbType(2);
    while (SpuClearReverbWorkArea(2) == -1) {
    }
    func_8005E428();
    SsUtSetReverbDepth(8, 8);
}
