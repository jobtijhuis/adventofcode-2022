from conan import ConanFile
from conan.tools.cmake import CMakeDeps, CMakeToolchain, CMake
from conan.tools.build import check_min_cppstd

class AdventofcodeDay01(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    name = "adventofcode-day01"
    generators = "CMakeDeps", "CMakeToolchain", "VirtualBuildEnv"
    package_type = "application"

    def requirements(self):
        self.requires("cppfront/main", build=True, headers=True)

    def validate_build(self):
        check_min_cppstd(self, "20")
