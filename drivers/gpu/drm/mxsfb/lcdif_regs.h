/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright (C) 2022 Marek Vasut <marex@denx.de>
 *
 * i.MX8MP/i.MXRT LCDIF LCD controller driver.
 */

#ifndef __LCDIF_REGS_H__
#define __LCDIF_REGS_H__

#define REG_SET	4
#define REG_CLR	8

/* V8 register set */
#define LCDC_V8_CTRL			0x00
#define LCDC_V8_DISP_PARA		0x10
#define LCDC_V8_DISP_SIZE		0x14
#define LCDC_V8_HSYN_PARA		0x18
#define LCDC_V8_VSYN_PARA		0x1c
#define LCDC_V8_VSYN_HSYN_WIDTH		0x20
#define LCDC_V8_INT_STATUS_D0		0x24
#define LCDC_V8_INT_ENABLE_D0		0x28
#define LCDC_V8_INT_STATUS_D1		0x30
#define LCDC_V8_INT_ENABLE_D1		0x34
#define LCDC_V8_CTRLDESCL0_1		0x200
#define LCDC_V8_CTRLDESCL0_3		0x208
#define LCDC_V8_CTRLDESCL_LOW0_4	0x20c
#define LCDC_V8_CTRLDESCL_HIGH0_4	0x210
#define LCDC_V8_CTRLDESCL0_5		0x214
#define LCDC_V8_CSC0_CTRL		0x21c
#define LCDC_V8_CSC0_COEF0		0x220
#define LCDC_V8_CSC0_COEF1		0x224
#define LCDC_V8_CSC0_COEF2		0x228
#define LCDC_V8_CSC0_COEF3		0x22c
#define LCDC_V8_CSC0_COEF4		0x230
#define LCDC_V8_CSC0_COEF5		0x234
#define LCDC_V8_PANIC0_THRES		0x238

#define CTRL_SFTRST			BIT(31)
#define CTRL_CLKGATE			BIT(30)
#define CTRL_BYPASS_COUNT		BIT(19)
#define CTRL_VSYNC_MODE			BIT(18)
#define CTRL_DOTCLK_MODE		BIT(17)
#define CTRL_DATA_SELECT		BIT(16)
#define CTRL_BUS_WIDTH_16		(0 << 10)
#define CTRL_BUS_WIDTH_8		(1 << 10)
#define CTRL_BUS_WIDTH_18		(2 << 10)
#define CTRL_BUS_WIDTH_24		(3 << 10)
#define CTRL_BUS_WIDTH_MASK		(0x3 << 10)
#define CTRL_WORD_LENGTH_16		(0 << 8)
#define CTRL_WORD_LENGTH_8		(1 << 8)
#define CTRL_WORD_LENGTH_18		(2 << 8)
#define CTRL_WORD_LENGTH_24		(3 << 8)
#define CTRL_MASTER			BIT(5)
#define CTRL_DF16			BIT(3)
#define CTRL_DF18			BIT(2)
#define CTRL_DF24			BIT(1)
#define CTRL_RUN			BIT(0)

#define CTRL1_RECOVER_ON_UNDERFLOW	BIT(24)
#define CTRL1_FIFO_CLEAR		BIT(21)
#define CTRL1_SET_BYTE_PACKAGING(x)	(((x) & 0xf) << 16)
#define CTRL1_GET_BYTE_PACKAGING(x)	(((x) >> 16) & 0xf)
#define CTRL1_CUR_FRAME_DONE_IRQ_EN	BIT(13)
#define CTRL1_CUR_FRAME_DONE_IRQ	BIT(9)

#define CTRL2_SET_OUTSTANDING_REQS_1	0
#define CTRL2_SET_OUTSTANDING_REQS_2	(0x1 << 21)
#define CTRL2_SET_OUTSTANDING_REQS_4	(0x2 << 21)
#define CTRL2_SET_OUTSTANDING_REQS_8	(0x3 << 21)
#define CTRL2_SET_OUTSTANDING_REQS_16	(0x4 << 21)
#define CTRL2_SET_OUTSTANDING_REQS_MASK	(0x7 << 21)

#define TRANSFER_COUNT_SET_VCOUNT(x)	(((x) & 0xffff) << 16)
#define TRANSFER_COUNT_GET_VCOUNT(x)	(((x) >> 16) & 0xffff)
#define TRANSFER_COUNT_SET_HCOUNT(x)	((x) & 0xffff)
#define TRANSFER_COUNT_GET_HCOUNT(x)	((x) & 0xffff)

#define VDCTRL0_ENABLE_PRESENT		BIT(28)
#define VDCTRL0_VSYNC_ACT_HIGH		BIT(27)
#define VDCTRL0_HSYNC_ACT_HIGH		BIT(26)
#define VDCTRL0_DOTCLK_ACT_FALLING	BIT(25)
#define VDCTRL0_ENABLE_ACT_HIGH		BIT(24)
#define VDCTRL0_VSYNC_PERIOD_UNIT	BIT(21)
#define VDCTRL0_VSYNC_PULSE_WIDTH_UNIT	BIT(20)
#define VDCTRL0_HALF_LINE		BIT(19)
#define VDCTRL0_HALF_LINE_MODE		BIT(18)
#define VDCTRL0_SET_VSYNC_PULSE_WIDTH(x) ((x) & 0x3ffff)
#define VDCTRL0_GET_VSYNC_PULSE_WIDTH(x) ((x) & 0x3ffff)

#define VDCTRL2_SET_HSYNC_PERIOD(x)	((x) & 0x3ffff)
#define VDCTRL2_GET_HSYNC_PERIOD(x)	((x) & 0x3ffff)

#define VDCTRL3_MUX_SYNC_SIGNALS	BIT(29)
#define VDCTRL3_VSYNC_ONLY		BIT(28)
#define SET_HOR_WAIT_CNT(x)		(((x) & 0xfff) << 16)
#define GET_HOR_WAIT_CNT(x)		(((x) >> 16) & 0xfff)
#define SET_VERT_WAIT_CNT(x)		((x) & 0xffff)
#define GET_VERT_WAIT_CNT(x)		((x) & 0xffff)

#define VDCTRL4_SET_DOTCLK_DLY(x)	(((x) & 0x7) << 29) /* v4 only */
#define VDCTRL4_GET_DOTCLK_DLY(x)	(((x) >> 29) & 0x7) /* v4 only */
#define VDCTRL4_SYNC_SIGNALS_ON		BIT(18)
#define SET_DOTCLK_H_VALID_DATA_CNT(x)	((x) & 0x3ffff)

#define DEBUG0_HSYNC			BIT(26)
#define DEBUG0_VSYNC			BIT(25)

#define AS_CTRL_PS_DISABLE		BIT(23)
#define AS_CTRL_ALPHA_INVERT		BIT(20)
#define AS_CTRL_ALPHA(a)		(((a) & 0xff) << 8)
#define AS_CTRL_FORMAT_RGB565		(0xe << 4)
#define AS_CTRL_FORMAT_RGB444		(0xd << 4)
#define AS_CTRL_FORMAT_RGB555		(0xc << 4)
#define AS_CTRL_FORMAT_ARGB4444		(0x9 << 4)
#define AS_CTRL_FORMAT_ARGB1555		(0x8 << 4)
#define AS_CTRL_FORMAT_RGB888		(0x4 << 4)
#define AS_CTRL_FORMAT_ARGB8888		(0x0 << 4)
#define AS_CTRL_ENABLE_COLORKEY		BIT(3)
#define AS_CTRL_ALPHA_CTRL_ROP		(3 << 1)
#define AS_CTRL_ALPHA_CTRL_MULTIPLY	(2 << 1)
#define AS_CTRL_ALPHA_CTRL_OVERRIDE	(1 << 1)
#define AS_CTRL_ALPHA_CTRL_EMBEDDED	(0 << 1)
#define AS_CTRL_AS_ENABLE		BIT(0)

/* V8 register set */
#define CTRL_SW_RESET			BIT(31)
#define CTRL_FETCH_START_OPTION_FPV	0
#define CTRL_FETCH_START_OPTION_PWV	BIT(8)
#define CTRL_FETCH_START_OPTION_BPV	BIT(9)
#define CTRL_FETCH_START_OPTION_RESV	GENMASK(9, 8)
#define CTRL_FETCH_START_OPTION_MASK	GENMASK(9, 8)
#define CTRL_NEG			BIT(4)
#define CTRL_INV_PXCK			BIT(3)
#define CTRL_INV_DE			BIT(2)
#define CTRL_INV_VS			BIT(1)
#define CTRL_INV_HS			BIT(0)

#define DISP_PARA_DISP_ON		BIT(31)
#define DISP_PARA_SWAP_EN		BIT(30)
#define DISP_PARA_LINE_PATTERN_UYVY_H	(0xd << 26)
#define DISP_PARA_LINE_PATTERN_RGB565	(0x7 << 26)
#define DISP_PARA_LINE_PATTERN_RGB888	(0x0 << 26)
#define DISP_PARA_LINE_PATTERN_MASK	GENMASK(29, 26)
#define DISP_PARA_DISP_MODE_MASK	GENMASK(25, 24)
#define DISP_PARA_BGND_R_MASK		GENMASK(23, 16)
#define DISP_PARA_BGND_G_MASK		GENMASK(15, 8)
#define DISP_PARA_BGND_B_MASK		GENMASK(7, 0)

#define DISP_SIZE_DELTA_Y(n)		(((n) & 0xffff) << 16)
#define DISP_SIZE_DELTA_Y_MASK		GENMASK(31, 16)
#define DISP_SIZE_DELTA_X(n)		((n) & 0xffff)
#define DISP_SIZE_DELTA_X_MASK		GENMASK(15, 0)

#define HSYN_PARA_BP_H(n)		(((n) & 0xffff) << 16)
#define HSYN_PARA_BP_H_MASK		GENMASK(31, 16)
#define HSYN_PARA_FP_H(n)		((n) & 0xffff)
#define HSYN_PARA_FP_H_MASK		GENMASK(15, 0)

#define VSYN_PARA_BP_V(n)		(((n) & 0xffff) << 16)
#define VSYN_PARA_BP_V_MASK		GENMASK(31, 16)
#define VSYN_PARA_FP_V(n)		((n) & 0xffff)
#define VSYN_PARA_FP_V_MASK		GENMASK(15, 0)

#define VSYN_HSYN_WIDTH_PW_V(n)		(((n) & 0xffff) << 16)
#define VSYN_HSYN_WIDTH_PW_V_MASK	GENMASK(31, 16)
#define VSYN_HSYN_WIDTH_PW_H(n)		((n) & 0xffff)
#define VSYN_HSYN_WIDTH_PW_H_MASK	GENMASK(15, 0)

#define INT_STATUS_D0_FIFO_EMPTY	BIT(24)
#define INT_STATUS_D0_DMA_DONE		BIT(16)
#define INT_STATUS_D0_DMA_ERR		BIT(8)
#define INT_STATUS_D0_VS_BLANK		BIT(2)
#define INT_STATUS_D0_UNDERRUN		BIT(1)
#define INT_STATUS_D0_VSYNC		BIT(0)

#define INT_ENABLE_D0_FIFO_EMPTY_EN	BIT(24)
#define INT_ENABLE_D0_DMA_DONE_EN	BIT(16)
#define INT_ENABLE_D0_DMA_ERR_EN	BIT(8)
#define INT_ENABLE_D0_VS_BLANK_EN	BIT(2)
#define INT_ENABLE_D0_UNDERRUN_EN	BIT(1)
#define INT_ENABLE_D0_VSYNC_EN		BIT(0)

#define INT_STATUS_D1_PLANE_PANIC	BIT(0)

#define INT_ENABLE_D1_PLANE_PANIC_EN	BIT(0)

#define CTRLDESCL0_1_HEIGHT(n)		(((n) & 0xffff) << 16)
#define CTRLDESCL0_1_HEIGHT_MASK	GENMASK(31, 16)
#define CTRLDESCL0_1_WIDTH(n)		((n) & 0xffff)
#define CTRLDESCL0_1_WIDTH_MASK		GENMASK(15, 0)

#define CTRLDESCL0_3_P_SIZE(n)		(((n) << 20) & CTRLDESCL0_3_P_SIZE_MASK)
#define CTRLDESCL0_3_P_SIZE_MASK	GENMASK(22, 20)
#define CTRLDESCL0_3_T_SIZE(n)		(((n) << 16) & CTRLDESCL0_3_T_SIZE_MASK)
#define CTRLDESCL0_3_T_SIZE_MASK	GENMASK(17, 16)
#define CTRLDESCL0_3_PITCH(n)		((n) & 0xffff)
#define CTRLDESCL0_3_PITCH_MASK		GENMASK(15, 0)

#define CTRLDESCL_HIGH0_4_ADDR_HIGH(n)	((n) & 0xf)
#define CTRLDESCL_HIGH0_4_ADDR_HIGH_MASK	GENMASK(3, 0)

#define CTRLDESCL0_5_EN			BIT(31)
#define CTRLDESCL0_5_SHADOW_LOAD_EN	BIT(30)
#define CTRLDESCL0_5_BPP_16_RGB565	(0x4 << 24)
#define CTRLDESCL0_5_BPP_16_ARGB1555	(0x5 << 24)
#define CTRLDESCL0_5_BPP_16_ARGB4444	(0x6 << 24)
#define CTRLDESCL0_5_BPP_YCbCr422	(0x7 << 24)
#define CTRLDESCL0_5_BPP_24_RGB888	(0x8 << 24)
#define CTRLDESCL0_5_BPP_32_ARGB8888	(0x9 << 24)
#define CTRLDESCL0_5_BPP_32_ABGR8888	(0xa << 24)
#define CTRLDESCL0_5_BPP_MASK		GENMASK(27, 24)
#define CTRLDESCL0_5_YUV_FORMAT_Y2VY1U	(0x0 << 14)
#define CTRLDESCL0_5_YUV_FORMAT_Y2UY1V	(0x1 << 14)
#define CTRLDESCL0_5_YUV_FORMAT_VY2UY1	(0x2 << 14)
#define CTRLDESCL0_5_YUV_FORMAT_UY2VY1	(0x3 << 14)
#define CTRLDESCL0_5_YUV_FORMAT_MASK	GENMASK(15, 14)

#define CSC0_CTRL_CSC_MODE_YUV2RGB	(0x0 << 1)
#define CSC0_CTRL_CSC_MODE_YCbCr2RGB	(0x1 << 1)
#define CSC0_CTRL_CSC_MODE_RGB2YUV	(0x2 << 1)
#define CSC0_CTRL_CSC_MODE_RGB2YCbCr	(0x3 << 1)
#define CSC0_CTRL_CSC_MODE_MASK		GENMASK(2, 1)
#define CSC0_CTRL_BYPASS		BIT(0)

#define CSC0_COEF0_A2(n)		(((n) << 16) & CSC0_COEF0_A2_MASK)
#define CSC0_COEF0_A2_MASK		GENMASK(26, 16)
#define CSC0_COEF0_A1(n)		((n) & CSC0_COEF0_A1_MASK)
#define CSC0_COEF0_A1_MASK		GENMASK(10, 0)

#define CSC0_COEF1_B1(n)		(((n) << 16) & CSC0_COEF1_B1_MASK)
#define CSC0_COEF1_B1_MASK		GENMASK(26, 16)
#define CSC0_COEF1_A3(n)		((n) & CSC0_COEF1_A3_MASK)
#define CSC0_COEF1_A3_MASK		GENMASK(10, 0)

#define CSC0_COEF2_B3(n)		(((n) << 16) & CSC0_COEF2_B3_MASK)
#define CSC0_COEF2_B3_MASK		GENMASK(26, 16)
#define CSC0_COEF2_B2(n)		((n) & CSC0_COEF2_B2_MASK)
#define CSC0_COEF2_B2_MASK		GENMASK(10, 0)

#define CSC0_COEF3_C2(n)		(((n) << 16) & CSC0_COEF3_C2_MASK)
#define CSC0_COEF3_C2_MASK		GENMASK(26, 16)
#define CSC0_COEF3_C1(n)		((n) & CSC0_COEF3_C1_MASK)
#define CSC0_COEF3_C1_MASK		GENMASK(10, 0)

#define CSC0_COEF4_D1(n)		(((n) << 16) & CSC0_COEF4_D1_MASK)
#define CSC0_COEF4_D1_MASK		GENMASK(24, 16)
#define CSC0_COEF4_C3(n)		((n) & CSC0_COEF4_C3_MASK)
#define CSC0_COEF4_C3_MASK		GENMASK(10, 0)

#define CSC0_COEF5_D3(n)		(((n) << 16) & CSC0_COEF5_D3_MASK)
#define CSC0_COEF5_D3_MASK		GENMASK(24, 16)
#define CSC0_COEF5_D2(n)		((n) & CSC0_COEF5_D2_MASK)
#define CSC0_COEF5_D2_MASK		GENMASK(8, 0)

#define PANIC0_THRES_LOW_MASK		GENMASK(24, 16)
#define PANIC0_THRES_HIGH_MASK		GENMASK(8, 0)
#define PANIC0_THRES_MAX		511

#define LCDIF_MIN_XRES			120
#define LCDIF_MIN_YRES			120
#define LCDIF_MAX_XRES			0xffff
#define LCDIF_MAX_YRES			0xffff

#endif /* __LCDIF_REGS_H__ */
