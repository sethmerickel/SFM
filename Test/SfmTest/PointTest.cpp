#include <gmock\gmock.h>
#include <Point.hpp>

TEST(PointTests, test_operators)
{   
   const Sfm::Point3D<double> p1(-1.0);
   const Sfm::Point3D<double> p2(0.0);

   auto p3 = p1 + p2;
   auto exp = p1;
   EXPECT_EQ(p1, p3);

   p3 = p2 + p1;
   EXPECT_EQ(exp, p3);

   p3 = p2 - p1;
   exp = Sfm::Point3D<double>(1.0);
   EXPECT_EQ(exp, p3);

   p3 = 5.0 * p1;
   exp = Sfm::Point3D<double>(-5.0);
   EXPECT_EQ(exp, p3);
}
