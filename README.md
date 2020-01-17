# OpenWrt package feed for general purpose allocators and utils

This packages contains libraries that can replace the malloc implementation of the used c-library.

# Usage inside the OpenWrt buildroot or SDK

Add the following line to `feeds.conf` which is at the root of OpenWrt source tree.

	src-git allocators git://github.com/THRO-INFM18/openwrt-allocator-packages.git

Update the feeds.

	./scripts/feeds update allocators

Activate packages in feeds

	./scripts/feeds install -a -p allocators

Select what you want to include in the final image in `make menuconfig`.
