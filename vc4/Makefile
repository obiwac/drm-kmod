# $FreeBSD$

SRCDIR=	${.CURDIR:H}/drivers/gpu/drm/vc4

.PATH:	${SRCDIR}

.include "../kconfig.mk"
.include "../linuxkpi_version.mk"

KMOD=	vc4
SRCS=	vc4_bo.c \
	vc4_crtc.c \
	vc4_drv.c \
	vc4_dpi.c \
	vc4_dsi.c \
	vc4_fence.c \
	vc4_kms.c \
	vc4_gem.c \
	vc4_hdmi.c \
	vc4_hdmi_phy.c \
	vc4_vec.c \
	vc4_hvs.c \
	vc4_irq.c \
	vc4_perfmon.c \
	vc4_plane.c \
	vc4_render_cl.c \
	vc4_trace_points.c \
	vc4_txp.c \
	vc4_v3d.c \
	vc4_validate.c \
	vc4_validate_shaders.c

CLEANFILES+= ${KMOD}.ko.full ${KMOD}.ko.debug

# TODO Which of these are actually needed?

CFLAGS+= -I${.CURDIR:H}/linuxkpi/gplv2/include
CFLAGS+= -I${.CURDIR:H}/linuxkpi/bsd/include
CFLAGS+= -I${SYSDIR}/compat/linuxkpi/common/include
CFLAGS+= -I${SYSDIR}/compat/linuxkpi/dummy/include
CFLAGS+= -I${.CURDIR:H}/linuxkpi/dummy/include

CFLAGS+= -I${.CURDIR:H}/include
CFLAGS+= -I${.CURDIR:H}/include/drm
CFLAGS+= -I${.CURDIR:H}/include/uapi
CFLAGS+= -I${SRCDIR:H:H}

CFLAGS+= '-DKBUILD_MODNAME="${KMOD}"'
CFLAGS+= '-DLINUXKPI_PARAM_PREFIX=vc4_' -DDRM_SYSCTL_PARAM_PREFIX=_${KMOD}
CFLAGS+= ${KCONFIG:C/(.*)/-DCONFIG_\1/}

SRCS+=	device_if.h vnode_if.h bus_if.h pci_if.h pci_iov_if.h device_if.h iicbus_if.h opt_drm.h \
	opt_vm.h opt_syscons.h

.include <bsd.kmod.mk>

CWARNFLAGS+=			-Wno-pointer-arith ${CWARNFLAGS.${.IMPSRC:T}}

# TODO Which of these are actually needed?

CFLAGS.gcc+= -Wno-redundant-decls -Wno-unused-but-set-variable \
	-Wno-maybe-uninitialized

CFLAGS+=	-Wno-cast-qual -Wno-incompatible-pointer-types-discards-qualifiers -Wno-format-extra-args
