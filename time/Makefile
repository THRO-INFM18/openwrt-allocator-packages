#
# Copyright (C) 2019 Johann Neuhauser <johann@it-neuhauser.de>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=time
PKG_VERSION:=1.9
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://ftp.gnu.org/gnu/$(PKG_NAME)
PKG_HASH:=fbacf0c81e62429df3e33bda4cee38756604f18e01d977338e23306a3e3b521e

PKG_MAINTAINER:=Johann Neuhauser <johann@it-neuhauser.de>
PKG_LICENSE:=GPL-3.0-only
PKG_LICENSE_FILES:=COPYING

PKG_INSTALL:=1
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk

define Package/time
  SECTION:=utils
  CATEGORY:=Utilities
  URL:=http://www.gnu.org/software/time/
  TITLE:=GNU time program for measuring CPU resource usage
endef

define Package/time/description
  The 'time' command runs another program,
  then displays information about the resources used by that program,
  collected by the system while the program was running.

  You can select which information is reported and the format in which it is shown,
  or have 'time' save the information in a file instead of display it on the screen.

  The resources that 'time' can report on fall into the general categories of 
  time, memory, I/O, and IPC calls.

  The GNU version can format the output in arbitrary ways by using a
  printf-style format string to include various resource measurements. 
endef

define Package/time/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/time $(1)/usr/bin/
endef

$(eval $(call BuildPackage,time))