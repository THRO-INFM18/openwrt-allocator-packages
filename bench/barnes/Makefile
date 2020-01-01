#
# Copyright (C) 2019 Johann Neuhauser <johann@it-neuhauser.de>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

# notes: produces a lot of warnings

include $(TOPDIR)/rules.mk

PKG_NAME:=barnes
PKG_VERSION:=0.1
PKG_RELEASE:=1

PKG_MAINTAINER:=Johann Neuhauser <johann@it-neuhauser.de>
PKG_LICENSE:=
PKG_LICENSE_FILES:=

CMAKE_INSTALL:=1
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/barnes
  SECTION:=utils
  CATEGORY:=Utilities
  DEPENDS:=
  TITLE:=barnes
endef

define Package/barnes/description
  No one knows something about it, but it´s used for benchmarking malloc implementations.
endef

CMAKE_OPTIONS+=\
	-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON

define Package/barnes/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/barnes $(1)/usr/bin/
	$(INSTALL_DIR) $(1)/usr/share/barnes
	$(INSTALL_DATA) ./src/input $(1)/usr/share/barnes/input
endef

$(eval $(call BuildPackage,barnes))
