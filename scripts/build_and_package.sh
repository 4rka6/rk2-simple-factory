#!/bin/bash
set -e

PROJECT_NAME="simple-factory"
VERSION="1.0.0"
BUILD_DIR="build"
PACKAGE_DIR="${PROJECT_NAME}_${VERSION}"

echo "=== Building project ==="
mkdir -p ${BUILD_DIR}
cd ${BUILD_DIR}
cmake .. -DBUILD_TESTS=ON
make -j$(nproc)

echo "=== Running tests ==="
ctest --output-on-failure

echo "=== Creating deb package ==="
mkdir -p ${PACKAGE_DIR}/usr/local/lib
mkdir -p ${PACKAGE_DIR}/DEBIAN

cp libfactory.a ${PACKAGE_DIR}/usr/local/lib/
cp ../src/*.h ${PACKAGE_DIR}/usr/local/include/ 2>/dev/null || true

cat > ${PACKAGE_DIR}/DEBIAN/control << CONTROLEOF
Package: ${PROJECT_NAME}
Version: ${VERSION}
Section: devel
Priority: optional
Architecture: amd64
Maintainer: 4rka6 <gurkovskija@gmail.com>
Description: Simple Factory pattern implementation in C++
CONTROLEOF

dpkg-deb --build ${PACKAGE_DIR}
mv ${PACKAGE_DIR}.deb ../${PROJECT_NAME}_${VERSION}.deb

echo "=== Package created: ${PROJECT_NAME}_${VERSION}.deb ==="
