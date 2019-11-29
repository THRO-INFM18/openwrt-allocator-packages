#
# Copyright (C) 2019 Johann Neuhauser <johann@it-neuhauser.de>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=tinymembench
PKG_VERSION:=0.4.9
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/ssvb/tinymembench.git
PKG_SOURCE_VERSION:=a2cf6d7e382e3aea1eb39173174d9fa28cad15f3
PKG_MIRROR_HASH:=ed3cf063aac1a1dca52f273261e60d1047ef2bdbcb27889f33e542724f40af79

PKG_MAINTAINER:=Johann Neuhauser <johann@it-neuhauser.de>
PKG_LICENSE:=Unknown
PKG_LICENSE_FILES:=LICENSE

CMAKE_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/tinymembench
  SECTION:=utils
  CATEGORY:=Utilities
  DEPENDS:=@(aarch64||arm||i386||i686||mips||mipsel||x86_64)
  TITLE:=Simple benchmark for memory throughput and latency
endef

define Package/tinymembench/description
  This is a simple memory benchmark program, which tries to measure the peak
  bandwidth of sequential memory accesses and the latency of random memory
  accesses. Bandwidth is measured by running different assembly code for
  the aligned memory blocks and attempting different prefetch strategies.

  The benchmark results for some hardware can be found in the wiki page:
  https://github.com/ssvb/tinymembench/wiki
endef

CMAKE_OPTIONS+=\
	-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON

define Package/tinymembench/install
	$(INSTALL_DIR) $(1)/usr/local/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/local/bin/tinymembench $(1)/usr/local/bin/
endef

$(eval $(call BuildPackage,tinymembench))
