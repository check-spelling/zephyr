/*
 * Copyright (c) 2016 Freescale Semiconductor, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <init.h>
#include <drivers/pinmux.h>
#include <drivers/gpio.h>
#include <fsl_port.h>

static int hexiwear_k64_pinmux_init(const struct device *dev)
{
	ARG_UNUSED(dev);

#if DT_NODE_HAS_STATUS(DT_NODELABEL(portb), okay)
	__unused const struct device *portb =
		DEVICE_DT_GET(DT_NODELABEL(portb));
	__ASSERT_NO_MSG(device_is_ready(portb));
#endif
#if DT_NODE_HAS_STATUS(DT_NODELABEL(portc), okay)
	__unused const struct device *portc =
		DEVICE_DT_GET(DT_NODELABEL(portc));
	__ASSERT_NO_MSG(device_is_ready(portc));
#endif
#if DT_NODE_HAS_STATUS(DT_NODELABEL(portd), okay)
	__unused const struct device *portd =
		DEVICE_DT_GET(DT_NODELABEL(portd));
	__ASSERT_NO_MSG(device_is_ready(portd));
#endif
#if DT_NODE_HAS_STATUS(DT_NODELABEL(porte), okay)
	__unused const struct device *porte =
		DEVICE_DT_GET(DT_NODELABEL(porte));
	__ASSERT_NO_MSG(device_is_ready(porte));
#endif

#if DT_NODE_HAS_STATUS(DT_NODELABEL(i2c0), okay) && CONFIG_I2C
	const struct device *gpiob =
	       device_get_binding(DT_LABEL(DT_NODELABEL(gpiob)));

	gpio_pin_configure(gpiob, 12, GPIO_OUTPUT_LOW);
#endif

#if defined(CONFIG_MAX30101) && DT_NODE_HAS_STATUS(DT_NODELABEL(gpioa), okay)
	const struct device *gpioa =
	       device_get_binding(DT_LABEL(DT_NODELABEL(gpioa)));

	gpio_pin_configure(gpioa, 29, GPIO_OUTPUT_HIGH);
#endif

#ifdef CONFIG_BATTERY_SENSE
	const struct device *gpioc =
	       device_get_binding(DT_LABEL(DT_NODELABEL(gpioc)));

	gpio_pin_configure(gpioc, 14, GPIO_OUTPUT_LOW);
#endif

	return 0;
}

SYS_INIT(hexiwear_k64_pinmux_init, PRE_KERNEL_1, CONFIG_PINMUX_INIT_PRIORITY);
