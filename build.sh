source /opt/intel/inteloneapi/setvars.sh > setvars.sh
[ -d build ] || mkdir build
cd build
[ -d CMakeCache.txt ] && rm CMakeCache.txt
cmake .. -DPROGRAM=$1
cmake --build .
