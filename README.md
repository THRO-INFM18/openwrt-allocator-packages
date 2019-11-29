# OpenWrt package feed for general purpose allocators and utils

This packages contains libraries that can replace the malloc implementation of the used c-library.

# Usage inside the QpenWrt buildroot or SDK

Add the following line to `feeds.conf` which is at the root of OpenWrt source tree.

	src-git openwrt-allocator-packages git://github.com/jneuhauser/openwrt-allocator-packages.git

Update the feeds.

	./scripts/feeds update openwrt-allocator-packages

Activate packages in feeds

	./scripts/feeds install -a -p openwrt-allocator-packages

Select what you want to include in the final image in `make menuconfig`.
