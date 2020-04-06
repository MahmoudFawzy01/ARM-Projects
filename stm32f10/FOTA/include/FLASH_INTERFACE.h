#ifndef FLASH_INTERFACE_H_
#define FLASH_INTERFACE_H_

typedef enum
{
	locked,
	unlocked,
	noterased,
	erased,
	notwrite
}FlashStatus;


void FLASH_voidInt(void);
u8 FLASH_u8GetStatues(void);
FlashStatus FLASH_EnumWrite(u8 Copy_u8TypeOfData,u32 Copy_u32Data,u32 Copy_u32Address);
FlashStatus FLASH_EnumWriteString(u8 Copy_u8TypeOfData,u32 *Local_p32Buffer,u32 Copy_u32Address,u16 Copy_u16Size);
u16 FLASH_u16ReadHalfWord(u32 Copy_u32Address);
void FLASH_voidRead(u8 Copy_u8TypeOfData,u64 *Copy_u64ReadData,u32 Copy_u32Address);
//void FLASH_voidReadString(u8 Copy_u8TypeOfData,u64 *Copy_pu64Buffer,u32 Copy_u32Address,u16 Copy_u16Size);
FlashStatus FLASH_EnumErasePage(u32 Copy_u32Address);
FlashStatus FLASH_EnumEraseAllPage(void);
FlashStatus FLASH_EnumUnlock(void);
FlashStatus FLASH_EnumLock(void);
void FLASH_EnumWriteHalfWord(u16 Copy_u16HalfWord,u32 Copy_u32Address);


#define HALF_WORD						2
#define ONE_WORD						4
#define TWO_WORD						8


#define FLASH_PAGE_0_ADDRESS            0
#define FLASH_PAGE_1_ADDRESS            1
#define FLASH_PAGE_2_ADDRESS            2
#define FLASH_PAGE_3_ADDRESS            3
#define FLASH_PAGE_4_ADDRESS            4
#define FLASH_PAGE_5_ADDRESS            5
#define FLASH_PAGE_6_ADDRESS            6
#define FLASH_PAGE_7_ADDRESS            7
#define FLASH_PAGE_8_ADDRESS            8
#define FLASH_PAGE_9_ADDRESS            9
#define FLASH_PAGE_10_ADDRESS           10
#define FLASH_PAGE_11_ADDRESS           11
#define FLASH_PAGE_12_ADDRESS           12
#define FLASH_PAGE_13_ADDRESS           13
#define FLASH_PAGE_14_ADDRESS           14
#define FLASH_PAGE_15_ADDRESS           15
#define FLASH_PAGE_16_ADDRESS           16
#define FLASH_PAGE_17_ADDRESS           17
#define FLASH_PAGE_18_ADDRESS           18
#define FLASH_PAGE_19_ADDRESS           19
#define FLASH_PAGE_20_ADDRESS           20
#define FLASH_PAGE_21_ADDRESS           21
#define FLASH_PAGE_22_ADDRESS           22
#define FLASH_PAGE_23_ADDRESS           23
#define FLASH_PAGE_24_ADDRESS           24
#define FLASH_PAGE_25_ADDRESS           25
#define FLASH_PAGE_26_ADDRESS           26
#define FLASH_PAGE_27_ADDRESS           27
#define FLASH_PAGE_28_ADDRESS           28
#define FLASH_PAGE_29_ADDRESS           29
#define FLASH_PAGE_30_ADDRESS           30
#define FLASH_PAGE_31_ADDRESS           31
#define FLASH_PAGE_32_ADDRESS           32
#define FLASH_PAGE_33_ADDRESS           33
#define FLASH_PAGE_34_ADDRESS           34
#define FLASH_PAGE_35_ADDRESS           35
#define FLASH_PAGE_36_ADDRESS           36
#define FLASH_PAGE_37_ADDRESS           37
#define FLASH_PAGE_38_ADDRESS           38
#define FLASH_PAGE_39_ADDRESS           39
#define FLASH_PAGE_40_ADDRESS           40
#define FLASH_PAGE_41_ADDRESS           41
#define FLASH_PAGE_42_ADDRESS           42
#define FLASH_PAGE_43_ADDRESS           43
#define FLASH_PAGE_44_ADDRESS           44
#define FLASH_PAGE_45_ADDRESS           45
#define FLASH_PAGE_46_ADDRESS           46
#define FLASH_PAGE_47_ADDRESS           47
#define FLASH_PAGE_48_ADDRESS           48
#define FLASH_PAGE_49_ADDRESS           49
#define FLASH_PAGE_50_ADDRESS           50
#define FLASH_PAGE_51_ADDRESS           51
#define FLASH_PAGE_52_ADDRESS           52
#define FLASH_PAGE_53_ADDRESS           53
#define FLASH_PAGE_54_ADDRESS           54
#define FLASH_PAGE_55_ADDRESS           55
#define FLASH_PAGE_56_ADDRESS           56
#define FLASH_PAGE_57_ADDRESS           57
#define FLASH_PAGE_58_ADDRESS           58
#define FLASH_PAGE_59_ADDRESS           59
#define FLASH_PAGE_60_ADDRESS           60
#define FLASH_PAGE_61_ADDRESS           61
#define FLASH_PAGE_62_ADDRESS           62
#define FLASH_PAGE_63_ADDRESS           63
#define FLASH_PAGE_64_ADDRESS           64
#define FLASH_PAGE_65_ADDRESS           65
#define FLASH_PAGE_66_ADDRESS           66
#define FLASH_PAGE_67_ADDRESS           67
#define FLASH_PAGE_68_ADDRESS           68
#define FLASH_PAGE_69_ADDRESS           69
#define FLASH_PAGE_70_ADDRESS           70
#define FLASH_PAGE_71_ADDRESS           71
#define FLASH_PAGE_72_ADDRESS           72
#define FLASH_PAGE_73_ADDRESS           73
#define FLASH_PAGE_74_ADDRESS           74
#define FLASH_PAGE_75_ADDRESS           75
#define FLASH_PAGE_76_ADDRESS           76
#define FLASH_PAGE_77_ADDRESS           77
#define FLASH_PAGE_78_ADDRESS           78
#define FLASH_PAGE_79_ADDRESS           79
#define FLASH_PAGE_80_ADDRESS           80
#define FLASH_PAGE_81_ADDRESS           81
#define FLASH_PAGE_82_ADDRESS           82
#define FLASH_PAGE_83_ADDRESS           83
#define FLASH_PAGE_84_ADDRESS           84
#define FLASH_PAGE_85_ADDRESS           85
#define FLASH_PAGE_86_ADDRESS           86
#define FLASH_PAGE_87_ADDRESS           87
#define FLASH_PAGE_88_ADDRESS           88
#define FLASH_PAGE_89_ADDRESS           89
#define FLASH_PAGE_90_ADDRESS           90
#define FLASH_PAGE_91_ADDRESS           91
#define FLASH_PAGE_92_ADDRESS           92
#define FLASH_PAGE_93_ADDRESS           93
#define FLASH_PAGE_94_ADDRESS           94
#define FLASH_PAGE_95_ADDRESS           95
#define FLASH_PAGE_96_ADDRESS           96
#define FLASH_PAGE_97_ADDRESS           97
#define FLASH_PAGE_98_ADDRESS           98
#define FLASH_PAGE_99_ADDRESS           99
#define FLASH_PAGE_100_ADDRESS          100
#define FLASH_PAGE_101_ADDRESS          101
#define FLASH_PAGE_102_ADDRESS          102
#define FLASH_PAGE_103_ADDRESS          103
#define FLASH_PAGE_104_ADDRESS          104
#define FLASH_PAGE_105_ADDRESS          105
#define FLASH_PAGE_106_ADDRESS          106
#define FLASH_PAGE_107_ADDRESS          107
#define FLASH_PAGE_108_ADDRESS          108
#define FLASH_PAGE_109_ADDRESS          109
#define FLASH_PAGE_110_ADDRESS          110
#define FLASH_PAGE_111_ADDRESS          111
#define FLASH_PAGE_112_ADDRESS          112
#define FLASH_PAGE_113_ADDRESS          113
#define FLASH_PAGE_114_ADDRESS          114
#define FLASH_PAGE_115_ADDRESS          115
#define FLASH_PAGE_116_ADDRESS          116
#define FLASH_PAGE_117_ADDRESS          117
#define FLASH_PAGE_118_ADDRESS          118
#define FLASH_PAGE_119_ADDRESS          119
#define FLASH_PAGE_120_ADDRESS          120
#define FLASH_PAGE_121_ADDRESS          121
#define FLASH_PAGE_122_ADDRESS          122
#define FLASH_PAGE_123_ADDRESS          123
#define FLASH_PAGE_124_ADDRESS          124
#define FLASH_PAGE_125_ADDRESS          125
#define FLASH_PAGE_126_ADDRESS          126
#define FLASH_PAGE_127_ADDRESS          127






#endif
