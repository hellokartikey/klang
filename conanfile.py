from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout


class CHIP8(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("ctre/3.9.0")
        self.requires("magic_enum/0.9.7")

    def build_requirements(self):
        pass

    def layout(self):
        cmake_layout(self)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
