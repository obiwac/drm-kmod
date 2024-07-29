/*-
 * SPDX-License-Identifier: BSD-2-Clause
 * Copyright (c) 2024 Aymeric Wibo <obiwac@freebsd.com>
 */

#ifndef	_LINUXKPI_SOUND_HDMI_CODEC_H
#define	_LINUXKPI_SOUND_HDMI_CODEC_H

#include <linux/types.h>
#include <linux/hdmi.h>
#include <sound/asoundef.h>
#include <sound/pcm.h>

#define	HDMI_CODEC_DRV_NAME	"hdmi-audio-codec"

struct hdmi_codec_daifmt {
};

#define	AES_IEC958_STATUS_SIZE	24

struct hdmi_codec_params {
	uint32_t			sample_rate;
	size_t				channels;
	struct snd_aes_iec958		iec;
	struct hdmi_audio_infoframe	cea;
};

/*
static const struct hdmi_codec_ops vc4_hdmi_codec_ops = {
	.get_eld = vc4_hdmi_audio_get_eld,
	.prepare = vc4_hdmi_audio_prepare,
	.audio_shutdown = vc4_hdmi_audio_shutdown,
	.audio_startup = vc4_hdmi_audio_startup,
};

static struct hdmi_codec_pdata vc4_hdmi_codec_pdata = {
	.ops = &vc4_hdmi_codec_ops,
	.max_i2s_channels = 8,
	.i2s = 1,
};
*/

struct hdmi_codec_ops {
	int	(*get_eld)(struct device *, void *, uint8_t *, size_t);
	int	(*prepare)(struct device *, void *, struct hdmi_codec_daifmt *, struct hdmi_codec_params *);
	void	(*audio_shutdown)(struct device *, void *);
	int	(*audio_startup)(struct device *, void *);
};

struct hdmi_codec_pdata {
	const struct hdmi_codec_ops *ops;
	uint32_t max_i2s_channels;
	uint32_t i2s;
};

#endif	/* _LINUXKPI_SOUND_HDMI_CODEC_H */
