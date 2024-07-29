/*-
 * SPDX-License-Identifier: BSD-2-Clause
 * Copyright (c) 2024 Aymeric Wibo <obiwac@freebsd.com>
 */

#ifndef	_LINUXKPI_LINUX_RATIONAL_H
#define	_LINUXKPI_LINUX_RATIONAL_H

#include <linux/kernel.h>

static inline void
rational_best_approximation(
	uint32_t given_numerator, uint32_t given_denominator,
	uint32_t max_numerator, uint32_t max_denominator,
	unsigned long *best_numerator, unsigned long *best_denominator
)
{

	pr_debug("%s: TODO\n", __func__);
}

#endif	/* _LINUXKPI_LINUX_RATIONAL_H */
