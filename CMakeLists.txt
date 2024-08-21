# CMakeList.txt: projeto de CMake para Ray_Tracing_Fast_CMake, incluir origem e definir
# lógica específica a um projeto aqui.
#
cmake_minimum_required (VERSION 3.8)

# Habilite a Recarga Dinâmica para compiladores MSVC, se houver suporte.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Ray_Tracing_Fast_CMake")

# Adicione a origem ao executável deste projeto.
add_executable (Ray_Tracing_Fast_CMake "Ray_Tracing_Fast_CMake.cpp" "Ray_Tracing_Fast_CMake.h" "vec3.h" "color.h" "ray.h" "back up main 1.cpp" "hittable.h" "sphere.h" "hittable_list.h" "rtweekend.h" "interval.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Ray_Tracing_Fast_CMake PROPERTY CXX_STANDARD 20)
endif()

# TODO: Adicione testes e instale destinos, se necessário.
