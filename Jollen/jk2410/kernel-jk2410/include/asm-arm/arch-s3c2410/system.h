/*
 * linux/include/asm-arm/arch-s3c2400/system.h
 *
 * Copyright (C) 2001,2002 MIZI Research, Inc.
 *
 * Author: Janghoon Lyu <nandy@mizi.com>
 *   Date: $Date: 2002/05/30 08:08:08 $
 *
 * $Revision: 1.1 $
 *
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file COPYING in the main directory of this archive
 * for more details.
 */

#include <linux/config.h>
#include <asm/arch/hardware.h>

static inline void arch_idle(void)
{
	/* TODO */
	cpu_do_idle(0);
}

/*
 * NB: 
 * 동작은 안되지만, 형태는 이렇게 되야 될 것 같음.
 * vivi에서는 잘되는데 왜 여기서는 안될까???
 */
static inline void arch_reset(char mode)
{
	if (mode == 's') {
		/* Jump into ROM at address 0 */
		cpu_reset(0);
	} else {
		WTCNT = 0x100;
		WTDAT = 0x100;
		WTCON = 0x8021;
	}
}
