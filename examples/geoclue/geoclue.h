/*
 * Copyright © 2013 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License version 3,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Thomas Voß <thomas.voss@canonical.com>
 */

#ifndef ORG_FREEDESKTOP_GEOCLUE_H_
#define ORG_FREEDESKTOP_GEOCLUE_H_

#include "org/freedesktop/dbus/service.h"
#include "org/freedesktop/dbus/types/object_path.h"
#include "org/freedesktop/dbus/types/struct.h"

#include <chrono>
#include <string>

namespace org
{
namespace freedesktop
{
struct Geoclue
{
    struct Master
    {
        struct Create
        {
            inline static std::string name()
            {
                return "Create";
            } typedef Master Interface;
            inline static const std::chrono::milliseconds default_timeout() { return std::chrono::seconds{1}; }
        };
    };

    struct MasterClient
    {
        struct SetRequirements
        {
            inline static std::string name()
            {
                return "SetRequirements";
            } typedef MasterClient Interface;
            inline static const std::chrono::milliseconds default_timeout() { return std::chrono::seconds{1}; }
        };
        struct GetAddressProvider
        {
            inline static std::string name()
            {
                return "GetAddressProvider";
            } typedef MasterClient Interface;
            inline static const std::chrono::milliseconds default_timeout() { return std::chrono::seconds{1}; }
        };
        struct GetPositionProvider
        {
            inline static std::string name()
            {
                return "GetPositionProvider";
            } typedef MasterClient Interface;
            inline static const std::chrono::milliseconds default_timeout() { return std::chrono::seconds{1}; }
        };
    };

    struct Address
    {
        struct GetAddress
        {
            inline static std::string name()
            {
                return "GetAddress";
            } typedef Address Interface;
            inline static const std::chrono::milliseconds default_timeout() { return std::chrono::seconds{1}; }
        };
    };

    struct Position
    {
        struct GetPosition
        {
            inline static std::string name()
            {
                return "GetPosition";
            } typedef Position Interface;
            inline static const std::chrono::milliseconds default_timeout() { return std::chrono::seconds{1}; }
        };
        struct Signals
        {
            struct PositionChanged
            {
                inline static std::string name()
                {
                    return "PositionChanged";
                };
                typedef Position Interface;
                typedef std::tuple<int32_t, int32_t, double, double, double, dbus::types::Struct<std::tuple<int32_t, double, double>>> ArgumentType;
            };
        };
    };
};
}
}

namespace org
{
namespace freedesktop
{
namespace dbus
{
namespace traits
{
template<>
struct Service<org::freedesktop::Geoclue>
{
    inline static const std::string& interface_name()
    {
        static const std::string s
        {"org.freedesktop.Geoclue"
        };
        return s;
    }
};

template<>
struct Service<org::freedesktop::Geoclue::Master>
{
    inline static const std::string& interface_name()
    {
        static const std::string s
        {"org.freedesktop.Geoclue.Master"
        };
        return s;
    }
};

template<>
struct Service<org::freedesktop::Geoclue::MasterClient>
{
    inline static const std::string& interface_name()
    {
        static const std::string s
        {"org.freedesktop.Geoclue.MasterClient"
        };
        return s;
    }
};

template<>
struct Service<org::freedesktop::Geoclue::Address>
{
    inline static const std::string& interface_name()
    {
        static const std::string s
        {"org.freedesktop.Geoclue.Address"
        };
        return s;
    }
};

template<>
struct Service<org::freedesktop::Geoclue::Position>
{
    inline static const std::string& interface_name()
    {
        static const std::string s
        {"org.freedesktop.Geoclue.Position"
        };
        return s;
    }
};
}
}
}
}

#endif // ORG_FREEDESKTOP_GEOCLUE_H_
