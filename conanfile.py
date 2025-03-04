from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout


class CHIP8(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        pass

    def build_requirements(self):
        pass

    def layout(self):
        cmake_layout(self)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
