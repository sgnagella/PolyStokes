#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "Stokes.h"
#include <iostream>

namespace py = pybind11;

PYBIND11_MODULE(PolyStokes, m) {
    m.doc() = "Polymer Stokesian Dynamics simulation module";
    py::class_<PolyStokes>(m,"PolyStokes")
        .def(py::init<double, int, double, std::string>(),
             py::arg("dt"), 
             py::arg("samplerate"),
             py::arg("tmax"),
             py::arg("output_dir"))
        .def("initial_configuration", &PolyStokes::initial_configuration, 
             py::arg("init_x0"), "Initialize the configuration of the particles")
        .def("particle_info", &PolyStokes::particle_info, 
             py::arg("Np"), 
             py::arg("Nc"), 
             py::arg("Nm"), 
             py::arg("Npoly"), 
             py::arg("Nmono_per_chain"), 
             py::arg("beta"), 
             py::arg("kbond"), 
             py::arg("r0"), 
             py::arg("Lmax"), 
             py::arg("tau"), "Set the parameters for the particles")
        .def("trap_info", &PolyStokes::trap_info,
             py::arg("ktrap"), 
             py::arg("tstart"), 
             py::arg("trun"), "Set the parameters for the traps")
        .def("run", &PolyStokes::run, "Run the simulation");
}
