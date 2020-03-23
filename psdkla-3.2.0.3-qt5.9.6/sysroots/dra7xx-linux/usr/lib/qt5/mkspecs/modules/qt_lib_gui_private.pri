QT.gui_private.VERSION = 5.9.6
QT.gui_private.name = QtGui
QT.gui_private.module =
QT.gui_private.libs = $$QT_MODULE_LIB_BASE
QT.gui_private.includes = $$QT_MODULE_INCLUDE_BASE/QtGui/5.9.6 $$QT_MODULE_INCLUDE_BASE/QtGui/5.9.6/QtGui
QT.gui_private.frameworks =
QT.gui_private.depends = core_private gui
QT.gui_private.uses =
QT.gui_private.module_config = v2 internal_module
QT.gui_private.enabled_features = egl eglfs evdev freetype system-freetype fontconfig gif jpeg libinput libinput-axis-api linuxfb multiprocess png system-jpeg system-png vnc
QT.gui_private.disabled_features = xcb accessibility-atspi-bridge angle_d3d11_qdtd direct2d directfb egl_x11 eglfs_brcm eglfs_egldevice eglfs_gbm eglfs_mali eglfs_openwfd eglfs_rcar eglfs_viv eglfs_viv_wl harfbuzz ico integrityfb integrityhid kms mirclient mtdev system-harfbuzz system-xcb tslib xkbcommon-evdev xlib
QMAKE_LIBS_OPENGL_ES2 = -lGLESv2 -lsrv_um
QMAKE_INCDIR_OPENGL_ES2 = 
QMAKE_LIBS_EGL = -lEGL -lIMGegl -ldrm_omap -lsrv_um
QMAKE_INCDIR_EGL = 
QMAKE_LIBS_FREETYPE = -lfreetype
QMAKE_INCDIR_FREETYPE = ${STAGING_DIR_HOST}/usr/include/freetype2
QMAKE_LIBS_FONTCONFIG = -lfontconfig -lfreetype
QMAKE_INCDIR_FONTCONFIG = ${STAGING_DIR_HOST}/usr/include/freetype2
QMAKE_LIBS_LIBINPUT = -linput
QMAKE_LIBS_LIBJPEG = -ljpeg
QMAKE_LIBS_LIBPNG = -lpng16
QMAKE_INCDIR_LIBPNG = ${STAGING_DIR_HOST}/usr/include/libpng16