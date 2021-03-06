# FreeRDP: A Remote Desktop Protocol Client
# FreeRDP cmake build script
#
# Copyright 2011 O.S. Systems Software Ltda.
# Copyright 2011 Otavio Salvador <otavio@ossystems.com.br>
# Copyright 2011 Marc-Andre Moreau <marcandre.moreau@gmail.com>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

set(TSMF_FFMPEG_SRCS
	tsmf_ffmpeg.c
)

include_directories(..)
include_directories(${FFMPEG_INCLUDE_DIRS})

add_library(tsmf_ffmpeg ${TSMF_FFMPEG_SRCS})
set_target_properties(tsmf_ffmpeg PROPERTIES PREFIX "")

if(CMAKE_COMPILER_IS_GNUCC)
	CHECK_C_COMPILER_FLAG(-Wno-deprecated-declarations Wno-deprecated-declarations)
	if(Wno-deprecated-declarations)
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-deprecated-declarations")
	endif()
endif()

target_link_libraries(tsmf_ffmpeg freerdp-utils)
target_link_libraries(tsmf_ffmpeg ${FFMPEG_LIBRARIES})

install(TARGETS tsmf_ffmpeg DESTINATION ${FREERDP_PLUGIN_PATH})

