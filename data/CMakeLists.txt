# Copyright © 2013 Canonical Ltd.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 3 as
# published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# Authored by: Thomas Voss <thomas.voss@canonical.com>

configure_file(
  dbus-cpp.pc.in dbus-cpp.pc @ONLY
)

install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/dbus-cpp.pc
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)

message(STATUS "Installing session and system bus config files to ${CMAKE_INSTALL_DATAROOTDIR}/dbus-cpp")

install(
  FILES ${CMAKE_CURRENT_SOURCE_DIR}/session.conf ${CMAKE_CURRENT_SOURCE_DIR}/system.conf
  DESTINATION
  "${CMAKE_INSTALL_DATAROOTDIR}/dbus-cpp/"
)

