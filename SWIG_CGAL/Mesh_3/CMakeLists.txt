SET (LIBSTOLINKWITH CGAL_Kernel_cpp)
if (TBB_FOUND)
  set(LIBSTOLINKWITH ${LIBSTOLINKWITH} TBB::tbb TBB::tbbmalloc Threads::Threads)
endif()


# cpp common library
ADD_SWIG_CGAL_LIBRARY ( CGAL_Mesh_3_cpp Object.cpp ${LIBSTOLINKWITH} )

# Modules
ADD_SWIG_CGAL_JAVA_MODULE   ( Mesh_3 CGAL_Mesh_3_cpp ${LIBSTOLINKWITH} )
ADD_SWIG_CGAL_PYTHON_MODULE ( Mesh_3 CGAL_Mesh_3_cpp ${LIBSTOLINKWITH} )
ADD_SWIG_CGAL_RUBY_MODULE   ( Mesh_3 CGAL_Mesh_3_cpp ${LIBSTOLINKWITH} )
