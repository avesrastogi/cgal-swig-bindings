// ------------------------------------------------------------------------------
// Copyright (c) 2011 GeometryFactory (FRANCE)
// SPDX-License-Identifier: GPL-3.0-or-later OR LicenseRef-Commercial
// ------------------------------------------------------------------------------ 


#ifndef SWIG_CGAL_KERNEL_WEIGHTED_POINT_2_H
#define SWIG_CGAL_KERNEL_WEIGHTED_POINT_2_H

#include <sstream>
#include <SWIG_CGAL/Kernel/typedefs.h>
#include <SWIG_CGAL/Kernel/Point_2.h>

#include <CGAL/Weighted_point_2.h>

class SWIG_CGAL_KERNEL_DECL Weighted_point_2{
public:
  typedef CGAL::Weighted_point_2<EPIC_Kernel> cpp_base;
private:
  cpp_base data;
public:
  #ifndef SWIG
  const cpp_base& get_data() const {return data;}
        cpp_base& get_data()       {return data;}
  Weighted_point_2(const cpp_base& base):data(base){}
  #endif

//Creation
  Weighted_point_2():data(){}
  Weighted_point_2(double x,double y):data(x,y){}
  Weighted_point_2(const Point_2& p,double w):data(p.get_data(),w){}
//Operations
  double weight() const {return data.weight();}
  double x() const {return data.x();}
  double y() const {return data.y();}
  Point_2 point() const {return Point_2(data.point());}
//Operators
  DEFINE_EQUALITY_OPERATORS(Weighted_point_2)
//I/O
  std::string toString(){
    std::stringstream sstr;
    sstr << data;
    return sstr.str();
  }
//Deep copy
  typedef Weighted_point_2 Self;
  Self deepcopy() const {return Self(data);}
  void deepcopy(const Self& other){data=other.get_data();}
};

#endif //SWIG_CGAL_KERNEL_WEIGHTED_POINT_2_H
