#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <decomp_geometry/geometric_utils.h>
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
      .def("d", &Ellipsoid2D::d);
  py::class_<Polyhedron2D>(m, "Polyhedron2D")
      .def(py::init<>())
      .def(py::init<const vec_E<Hyperplane<2>>&>())
      .def("add", &Polyhedron2D::add)
      .def("inside", &Polyhedron2D::inside)
      .def("points_inside", &Polyhedron2D::points_inside)
      .def("cal_normals", &Polyhedron2D::cal_normals)
      .def("hyperplanes", &Polyhedron2D::hyperplanes);
}