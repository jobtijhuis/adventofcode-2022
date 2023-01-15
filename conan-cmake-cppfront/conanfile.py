from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout
from conan.tools.files import get, copy

import os

required_conan_version = ">=2.0.0-beta7"

class CppfrontRecipe(ConanFile):
    name = "cppfront"

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"

    exports_sources = "CMakeLists.txt"

    def source(self):
        get(self, "https://github.com/hsutter/cppfront/archive/refs/heads/main.zip",
                  strip_root=True)

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        copy(self, "LICENSE", src=self.source_folder, dst=os.path.join(self.package_folder, "licenses"))
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libdirs = []
