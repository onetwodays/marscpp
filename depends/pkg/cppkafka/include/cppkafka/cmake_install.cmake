# Install script for directory: /home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xHeadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cppkafka" TYPE FILE FILES
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/buffer.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/clonable_ptr.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/configuration.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/configuration_base.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/configuration_option.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/consumer.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/cppkafka.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/error.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/exceptions.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/group_information.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/kafka_handle_base.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/logging.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/macros.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/message.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/message_builder.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/message_internal.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/metadata.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/producer.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/queue.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/topic.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/topic_configuration.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/topic_partition.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/topic_partition_list.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xHeadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cppkafka/utils" TYPE FILE FILES
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/utils/backoff_committer.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/utils/backoff_performer.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/utils/buffered_producer.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/utils/compacted_topic_processor.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/utils/consumer_dispatcher.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/utils/poll_interface.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/utils/poll_strategy_base.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/utils/roundrobin_poll_strategy.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xHeadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cppkafka/detail" TYPE FILE FILES
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/detail/callback_invoker.h"
    "/home/iliu/backend-hopex/cpphope/depends/pkg/cppkafka/include/cppkafka/detail/endianness.h"
    )
endif()

