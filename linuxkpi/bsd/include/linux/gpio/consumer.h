/*-
 * SPDX-License-Identifier: BSD-2-Clause
 * Copyright (c) 2024 Aymeric Wibo <obiwac@freebsd.com>
 */

#ifndef	_LINUXKPI_LINUX_GPIO_CONSUMER_H
#define	_LINUXKPI_LINUX_GPIO_CONSUMER_H

#include <linux/device.h>

struct gpio_desc {
};

static inline int
gpiod_get_value_cansleep(struct gpio_desc const *desc)
{

	pr_debug("%s: TODO\n", __func__);
	return (0);
}

#define	GPIOD_IN	0

static inline struct gpio_desc *
devm_gpiod_get_optional(struct device *dev, char const *id, uint32_t flags)
{

	pr_debug("%s: TODO\n", __func__);
	return (NULL);
}

#endif	/* _LINUXKPI_LINUX_GPIO_CONSUMER_H */
