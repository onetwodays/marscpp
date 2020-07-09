#!/usr/bin/env bash
# 库目录由${CURRENT_PATH}/lib 改为/usr/local/lib
CURRENT_PATH=`pwd`

cd  ${CURRENT_PATH} && source ./3.build_hiredis.sh
cd  ${CURRENT_PATH} && source ./6.build_cppkafka.sh
cd  ${CURRENT_PATH} && source ./11.build_fmt.sh
#cd  ${CURRENT_PATH} && source ./20.build_spdlog.sh
#cd  ${CURRENT_PATH} && source ./5.build_mongocxx.sh
#cd  ${CURRENT_PATH} && source ./0.build_leveldb.sh
#cd  ${CURRENT_PATH} && source ./1.build_rocksdb.sh







    







