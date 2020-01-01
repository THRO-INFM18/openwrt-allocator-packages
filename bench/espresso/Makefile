#
# Copyright (C) 2019 Johann Neuhauser <johann@it-neuhauser.de>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

# notes: warning: type defaults to 'int' in declaration of 'XXXX' [-Wimplicit-int]

include $(TOPDIR)/rules.mk

PKG_NAME:=espresso
PKG_VERSION:=0.1
PKG_RELEASE:=1

PKG_MAINTAINER:=Johann Neuhauser <johann@it-neuhauser.de>
PKG_LICENSE:=Unknown
PKG_LICENSE_FILES:=README.md

CMAKE_INSTALL:=1
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/espresso
  SECTION:=utils
  CATEGORY:=Utilities
  DEPENDS:=
  TITLE:=espresso
endef

define Package/espresso/description
  No one knows something about it, but it´s used for benchmarking malloc implementations.
endef

CMAKE_OPTIONS+=\
	-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON

define Package/espresso/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/espresso $(1)/usr/bin/
	$(INSTALL_DIR) $(1)/usr/share/espresso
	$(INSTALL_DATA) ./src/largest.espresso $(1)/usr/share/espresso/largest.espresso
endef

$(eval $(call BuildPackage,espresso))
