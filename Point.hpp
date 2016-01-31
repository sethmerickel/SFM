#pragma once

#include <type_traits>

// 2D Point Class

namespace Sfm
{
   template <typename CoordT> class Point2D;
   template <typename CoordT> class Point3D;

   namespace Detail
   {
      template <typename CoordT1, typename CoordT2>
      using PointType2D = Point2D<std::common_type_t<CoordT1, CoordT2>>;

      template <typename CoordT1, typename CoordT2>
      using PointType3D = Point3D<std::common_type_t<CoordT1, CoordT2>>;
   }

   template <typename CoordT>
   class Point2D
   {
   public:
      Point2D() : m_x(0), m_y(0) {}
      
      Point2D(const CoordT& x, const CoordT& y) : m_x(x), m_y(y) {}
      
      explicit Point2D(const CoordT& val) : m_x(val), m_y(val) {}

      template <typename CoordTT>
      Point2D(const Point2D<CoordTT>& pt)
         : m_x(pt.m_x), m_y(pt.m_y)
      {}

      bool operator==(const Point2D<CoordT>& rhs) const
      {
         return m_x == rhs.m_x && m_y == rhs.m_y;
      }

      bool operator!=(const Point2D<CoordT>& rhs) const
      {
         return !(*this == rhs);
      }

   public:
      CoordT m_x;
      CoordT m_y;
   };

   template <typename CoordT1, typename CoordT2>
   Detail::PointType2D<CoordT1, CoordT2>
      operator+(const Point2D<CoordT1>& lhs, const Point2D<CoordT2>& p2)
   {
      using point_type = Detail::PointType2D<CoordT1, CoordT2>;
      return point_type(lhs.m_x + rhs.m_x, lhs.m_y + rhs.m_y);
   }

   template <typename CoordT1, typename CoordT2>
   Detail::PointType2D<CoordT1, CoordT2>
      operator-(const Point2D<CoordT1>& lhs, const Point2D<CoordT2>& rhs)
   {
      using point_type = Detail::PointType2D<CoordT1, CoordT2>;
      return point_type(lhs.m_x - rhs.m_x, lhs.m_y - rhs.m_y);
   }

   template <typename CoordT>
   Point2D<CoordT> operator+(const Point2D<CoordT>& lhs, const CoordT& val)
   {
      return Point2D<CoordT>(lhs.m_x + val, lhs.m_y + val);
   }

   template <typename CoordT>
   Point2D<CoordT> operator-(const Point2D<CoordT>& lhs, const CoordT& val)
   {
      return Point2D<CoordT>(lhs.m_x - val, lhs.m_y - val);
   }

   template <typename CoordT>
   Point2D<CoordT> operator*(const Point2D<CoordT>& lhs, const CoordT& val)
   {
      return Point2D<CoordT>(lhs.m_x * val, lhs.m_y * val);
   }

   template <typename CoordT>
   Point2D<CoordT> operator*(const CoordT& val, const Point2D<CoordT>& lhs)
   {
      return Point2D<CoordT>(lhs.m_x * val, lhs.m_y * val);
   }

   template <typename CoordT>
   Point2D<CoordT> operator/(const Point2D<CoordT>& lhs, const CoordT& val)
   {
      return Point2D<CoordT>(lhs.m_x / val, lhs.m_y / val);
   }

   template <typename CoordT>
   Point2D<CoordT> operator/(const CoordT& val, const Point2D<CoordT>& rhs)
   {
      return rhs / val;
   }


   // 3D Point Class

   template <typename CoordT>
   class Point3D
   {
   public:
      Point3D() : m_x(0), m_y(0), m_z(0) {}

      Point3D(const CoordT& x, const CoordT& y, const CoordT& z)
         : m_x(x), m_y(y), m_z(z) {}

      explicit Point3D(const CoordT& val) : m_x(val), m_y(val), m_z(val) {}

      template <typename CoordTT>
      Point3D(const Point3D<CoordTT>& pt)
         : m_x(pt.m_x), m_y(pt.m_y), m_z(pt.m_z)
      {}

      bool operator==(const Point3D<CoordT>& rhs) const
      {
         return m_x == rhs.m_x &&
            m_y == rhs.m_y &&
            m_z == rhs.m_z;
      }

      bool operator!=(const Point3D<CoordT>& rhs) const
      {
         return !(*this == rhs);
      }

   public:
      CoordT m_x;
      CoordT m_y;
      CoordT m_z;
   };

   template <typename CoordT1, typename CoordT2>
   Detail::PointType3D<CoordT1, CoordT2>
      operator+(const Point3D<CoordT1>& lhs, const Point3D<CoordT2>& rhs)
   {
      using point_type = Detail::PointType3D<CoordT1, CoordT2>;
      return point_type(
         lhs.m_x + rhs.m_x, lhs.m_y + rhs.m_y, lhs.m_z + rhs.m_z);
   }

   template <typename CoordT1, typename CoordT2>
   Detail::PointType3D<CoordT1, CoordT2>
      operator-(const Point3D<CoordT1>& lhs, const Point3D<CoordT2>& rhs)
   {
      using point_type = Detail::PointType3D<CoordT1, CoordT2>;
      return point_type(
         lhs.m_x - rhs.m_x, lhs.m_y - rhs.m_y, lhs.m_z - rhs.m_z);
   }

   template <typename CoordT>
   Point3D<CoordT> operator+(const Point3D<CoordT>& lhs, const CoordT& val)
   {
      return Point3D<CoordT>(lhs.m_x + val, lhs.m_y + val);
   }

   template <typename CoordT>
   Point3D<CoordT> operator-(const Point3D<CoordT>& lhs, const CoordT& val)
   {
      return Point3D<CoordT>(lhs.m_x - val, lhs.m_y - val);
   }

   template <typename CoordT>
   Point3D<CoordT> operator*(const Point3D<CoordT>& lhs, const CoordT& val)
   {
      return Point3D<CoordT>(lhs.m_x * val, lhs.m_y * val, lhs.m_z * val);
   }

   template <typename CoordT>
   Point3D<CoordT> operator*(const CoordT& val, const Point3D<CoordT>& rhs)
   {
      return rhs * val;
   }

   template <typename CoordT>
   Point3D<CoordT> operator/(const Point3D<CoordT>& lhs, const CoordT& val)
   {
      return Point3D<CoordT>(lhs.m_x / val, lhs.m_y / val, lhs.m_x / val);
   }

   template <typename CoordT>
   Point3D<CoordT> operator/(const CoordT& val, const Point3D<CoordT>& rhs)
   {
      return rhs / val;
   }

}