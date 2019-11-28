cmake_minimum_required(VERSION 3.0)
project(cfrac CXX C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(cfrac_sources
    atop.c
    cfrac.c
    errorp.c
    getopt.c
    itop.c
    ltop.c
    pabs.c
    padd.c
    pcfrac.c
    pcmp.c
    pconst.c
    pdivmod.c
#    pfactor.c
    pfloat.c
    pgcd.c
    phalf.c
    picmp.c
    pidiv.c
    pimod.c
    pio.c
    pmul.c
    pneg.c
    podd.c
    pops.c
    ppowmod.c
    primes.c
    psqrt.c
    psub.c
    ptoa.c
    ptob.c
    ptou.c
    utop.c
)

add_executable(cfrac ${cfrac_sources})
target_compile_options(cfrac PRIVATE $<$<C_COMPILER_ID:GNU>:-std=gnu89>)
target_compile_definitions(cfrac PRIVATE NOMEMOPT=1)
target_link_libraries(cfrac m)

INSTALL(TARGETS cfrac RUNTIME DESTINATION /usr/local/bin/)
