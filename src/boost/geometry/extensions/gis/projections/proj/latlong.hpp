#ifndef BOOST_GEOMETRY_PROJECTIONS_LATLONG_HPP
#define BOOST_GEOMETRY_PROJECTIONS_LATLONG_HPP

// Boost.Geometry - extensions-gis-projections (based on PROJ4)
// This file is automatically generated. DO NOT EDIT.

// Copyright (c) 2008-2011 Barend Gehrels, Amsterdam, the Netherlands.

// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// This file is converted from PROJ4, http://trac.osgeo.org/proj
// PROJ4 is originally written by Gerald Evenden (then of the USGS)
// PROJ4 is maintained by Frank Warmerdam
// PROJ4 is converted to Boost.Geometry by Barend Gehrels (Geodan, Amsterdam)

// Original copyright notice:

// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#include <boost/math/special_functions/hypot.hpp>

#include <boost/geometry/extensions/gis/projections/impl/base_static.hpp>
#include <boost/geometry/extensions/gis/projections/impl/base_dynamic.hpp>
#include <boost/geometry/extensions/gis/projections/impl/projects.hpp>
#include <boost/geometry/extensions/gis/projections/impl/factory_entry.hpp>

#include <boost/geometry/extensions/gis/projections/epsg_traits.hpp>

namespace boost { namespace geometry { namespace projection
{
    #ifndef DOXYGEN_NO_DETAIL
    namespace detail { namespace latlong{


            /* very loosely based upon DMA code by Bradford W. Drew */


            // template class, using CRTP to implement forward/inverse
            template <typename Geographic, typename Cartesian, typename Parameters>
            struct base_latlong_other : public base_t_fi<base_latlong_other<Geographic, Cartesian, Parameters>,
                     Geographic, Cartesian, Parameters>
            {

                 typedef double geographic_type;
                 typedef double cartesian_type;


                inline base_latlong_other(const Parameters& par)
                    : base_t_fi<base_latlong_other<Geographic, Cartesian, Parameters>,
                     Geographic, Cartesian, Parameters>(*this, par) {}

                inline void fwd(geographic_type& lp_lon, geographic_type& lp_lat, cartesian_type& xy_x, cartesian_type& xy_y) const
                {

                        xy_x = lp_lon / this->m_par.a;
                        xy_y = lp_lat / this->m_par.a;
                }

                inline void inv(cartesian_type& xy_x, cartesian_type& xy_y, geographic_type& lp_lon, geographic_type& lp_lat) const
                {

                        lp_lat = xy_y * this->m_par.a;
                        lp_lon = xy_x * this->m_par.a;
                }
            };

            // Lat/long (Geodetic)
            template <typename Parameters>
            void setup_lonlat(Parameters& par)
            {
                    par.is_latlong = 1;
                    par.x0 = 0.0;
                    par.y0 = 0.0;
                // par.inv = inverse;
                // par.fwd = forward;
            }

            // Lat/long (Geodetic alias)
            template <typename Parameters>
            void setup_latlon(Parameters& par)
            {
                    par.is_latlong = 1;
                    par.x0 = 0.0;
                    par.y0 = 0.0;
                // par.inv = inverse;
                // par.fwd = forward;
            }

            // Lat/long (Geodetic alias)
            template <typename Parameters>
            void setup_latlong(Parameters& par)
            {
                    par.is_latlong = 1;
                    par.x0 = 0.0;
                    par.y0 = 0.0;
                // par.inv = inverse;
                // par.fwd = forward;
            }

            // Lat/long (Geodetic alias)
            template <typename Parameters>
            void setup_longlat(Parameters& par)
            {
                    par.is_latlong = 1;
                    par.x0 = 0.0;
                    par.y0 = 0.0;
                // par.inv = inverse;
                // par.fwd = forward;
            }

        }} // namespace detail::latlong
    #endif // doxygen

    /*!
        \brief Lat/long (Geodetic) projection
        \ingroup projections
        \tparam Geographic latlong point type
        \tparam Cartesian xy point type
        \tparam Parameters parameter type
        \par Projection characteristics
        \par Example
        \image html ex_lonlat.gif
    */
    template <typename Geographic, typename Cartesian, typename Parameters = parameters>
    struct lonlat_other : public detail::latlong::base_latlong_other<Geographic, Cartesian, Parameters>
    {
        inline lonlat_other(const Parameters& par) : detail::latlong::base_latlong_other<Geographic, Cartesian, Parameters>(par)
        {
            detail::latlong::setup_lonlat(this->m_par);
        }
    };

    /*!
        \brief Lat/long (Geodetic alias) projection
        \ingroup projections
        \tparam Geographic latlong point type
        \tparam Cartesian xy point type
        \tparam Parameters parameter type
        \par Projection characteristics
        \par Example
        \image html ex_latlon.gif
    */
    template <typename Geographic, typename Cartesian, typename Parameters = parameters>
    struct latlon_other : public detail::latlong::base_latlong_other<Geographic, Cartesian, Parameters>
    {
        inline latlon_other(const Parameters& par) : detail::latlong::base_latlong_other<Geographic, Cartesian, Parameters>(par)
        {
            detail::latlong::setup_latlon(this->m_par);
        }
    };

    /*!
        \brief Lat/long (Geodetic alias) projection
        \ingroup projections
        \tparam Geographic latlong point type
        \tparam Cartesian xy point type
        \tparam Parameters parameter type
        \par Projection characteristics
        \par Example
        \image html ex_latlong.gif
    */
    template <typename Geographic, typename Cartesian, typename Parameters = parameters>
    struct latlong_other : public detail::latlong::base_latlong_other<Geographic, Cartesian, Parameters>
    {
        inline latlong_other(const Parameters& par) : detail::latlong::base_latlong_other<Geographic, Cartesian, Parameters>(par)
        {
            detail::latlong::setup_latlong(this->m_par);
        }
    };

    /*!
        \brief Lat/long (Geodetic alias) projection
        \ingroup projections
        \tparam Geographic latlong point type
        \tparam Cartesian xy point type
        \tparam Parameters parameter type
        \par Projection characteristics
        \par Example
        \image html ex_longlat.gif
    */
    template <typename Geographic, typename Cartesian, typename Parameters = parameters>
    struct longlat_other : public detail::latlong::base_latlong_other<Geographic, Cartesian, Parameters>
    {
        inline longlat_other(const Parameters& par) : detail::latlong::base_latlong_other<Geographic, Cartesian, Parameters>(par)
        {
            detail::latlong::setup_longlat(this->m_par);
        }
    };

    #ifndef DOXYGEN_NO_DETAIL
    namespace detail
    {

        // Factory entry(s)
        template <typename Geographic, typename Cartesian, typename Parameters>
        class lonlat_entry : public detail::factory_entry<Geographic, Cartesian, Parameters>
        {
            public :
                virtual projection<Geographic, Cartesian>* create_new(const Parameters& par) const
                {
                    return new base_v_fi<lonlat_other<Geographic, Cartesian, Parameters>, Geographic, Cartesian, Parameters>(par);
                }
        };

        template <typename Geographic, typename Cartesian, typename Parameters>
        class latlon_entry : public detail::factory_entry<Geographic, Cartesian, Parameters>
        {
            public :
                virtual projection<Geographic, Cartesian>* create_new(const Parameters& par) const
                {
                    return new base_v_fi<latlon_other<Geographic, Cartesian, Parameters>, Geographic, Cartesian, Parameters>(par);
                }
        };

        template <typename Geographic, typename Cartesian, typename Parameters>
        class latlong_entry : public detail::factory_entry<Geographic, Cartesian, Parameters>
        {
            public :
                virtual projection<Geographic, Cartesian>* create_new(const Parameters& par) const
                {
                    return new base_v_fi<latlong_other<Geographic, Cartesian, Parameters>, Geographic, Cartesian, Parameters>(par);
                }
        };

        template <typename Geographic, typename Cartesian, typename Parameters>
        class longlat_entry : public detail::factory_entry<Geographic, Cartesian, Parameters>
        {
            public :
                virtual projection<Geographic, Cartesian>* create_new(const Parameters& par) const
                {
                    return new base_v_fi<longlat_other<Geographic, Cartesian, Parameters>, Geographic, Cartesian, Parameters>(par);
                }
        };

        template <typename Geographic, typename Cartesian, typename Parameters>
        inline void latlong_init(detail::base_factory<Geographic, Cartesian, Parameters>& factory)
        {
            factory.add_to_factory("lonlat", new lonlat_entry<Geographic, Cartesian, Parameters>);
            factory.add_to_factory("latlon", new latlon_entry<Geographic, Cartesian, Parameters>);
            factory.add_to_factory("latlong", new latlong_entry<Geographic, Cartesian, Parameters>);
            factory.add_to_factory("longlat", new longlat_entry<Geographic, Cartesian, Parameters>);
        }

    } // namespace detail
    // Create EPSG specializations
    // (Proof of Concept, only for some)

    template<typename LatLongRadian, typename Cartesian, typename Parameters>
    struct epsg_traits<4326, LatLongRadian, Cartesian, Parameters>
    {
        typedef longlat_other<LatLongRadian, Cartesian, Parameters> type;
        static inline std::string par()
        {
            return "+proj=longlat +ellps=WGS84 +datum=WGS84";
        }
    };


    #endif // doxygen

}}} // namespace boost::geometry::projection

#endif // BOOST_GEOMETRY_PROJECTIONS_LATLONG_HPP
