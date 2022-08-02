#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <decomp_geometry/geometric_utils.h>
#include <decomp_util/ellipsoid_decomp.h>
#include <decomp_util/line_segment.h>

namespace py = pybind11;

PYBIND11_MODULE(decomp_util, m) {
  py::class_<LineSegment2D>(m, "LineSegment2D")
      .def(py::init<>())
      .def(py::init<const Vecf<2> &, const Vecf<2> &>())
      .def("dilate", &LineSegment2D::dilate)
      .def("get_line_segment", &LineSegment2D::get_line_segment)
      .def("set_local_bbox", &LineSegment2D::set_local_bbox)
      .def("get_ellipsoid", &LineSegment2D::get_ellipsoid)
      .def("get_polyhedron", &LineSegment2D::get_polyhedron)
      .def("set_obs", &LineSegment2D::set_obs);
  py::class_<Ellipsoid2D>(m, "Ellipsoid2D")
      .def(py::init<>())
      .def(py::init<const Matf<2, 2> &, const Vecf<2> &>())
      .def("dist", &Ellipsoid2D::dist)
      .def("inside", &Ellipsoid2D::inside)
      .def("points_inside", &Ellipsoid2D::points_inside)
      .def("closest_point", &Ellipsoid2D::closest_point)
      .def("closest_hyperplane", &Ellipsoid2D::closest_hyperplane)
      .def("print", &Ellipsoid2D::print)
      .def("C", &Ellipsoid2D::C)
      .def("d", &Ellipsoid2D::d)
      .def("sample", &Ellipsoid2D::sample<2>);
  py::class_<Polyhedron2D>(m, "Polyhedron2D")
      .def(py::init<>())
      .def(py::init<const vec_E<Hyperplane<2>> &>())
      .def("add", &Polyhedron2D::add)
      .def("inside", &Polyhedron2D::inside)
      .def("points_inside", &Polyhedron2D::points_inside)
      .def("cal_normals", &Polyhedron2D::cal_normals)
      .def("hyperplanes", &Polyhedron2D::hyperplanes);
  py::class_<EllipsoidDecomp2D>(m, "EllipsoidDecomp2D")
      .def(py::init<>())
      .def(py::init<const Vecf<2> &, const Vecf<2> &>())
      .def("set_obs", &EllipsoidDecomp2D::set_obs)
      .def("get_polyhedrons", &EllipsoidDecomp2D::get_polyhedrons)
      .def("get_ellipsoids", &EllipsoidDecomp2D::get_ellipsoids)
      .def("set_local_bbox", &EllipsoidDecomp2D::set_local_bbox)
      .def("dilate", &EllipsoidDecomp2D::dilate);
  m.def("cal_vertices", py::overload_cast<const Polyhedron2D&>(&cal_vertices));
}