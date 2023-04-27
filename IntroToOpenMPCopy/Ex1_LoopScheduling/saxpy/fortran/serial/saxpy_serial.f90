!!!!
!! File: saxpy_serial.f90
!! Description: SAXPY simple implementation.
!! Author: Bruno R. de Abreu  |  babreu at illinois dot edu
!! National Center for Supercomputing Applications (NCSA)
!!  
!! Creation Date: Wednesday, 19th January 2022, 2:54:45 pm
!! Last Modified: Wednesday, 19th January 2022, 2:54:47 pm
!!  
!! Copyright (c) 2022, Bruno R. de Abreu, National Center for Supercomputing Applications.
!! All rights reserved.
!! License: This program and the accompanying materials are made available to any individual
!!          under the citation condition that follows: On the event that the software is
!!          used to generate data that is used implicitly or explicitly for research
!!          purposes, proper acknowledgment must be provided in the citations section of
!!          publications. This includes both the author's name and the National Center
!!          for Supercomputing Applications. If you are uncertain about how to do
!!          so, please check this page: https://github.com/babreu-ncsa/cite-me.
!!          This software cannot be used for commercial purposes in any way whatsoever.
!!          Omitting this license when redistributing the code is strongly disencouraged.
!!          The software is provided without warranty of any kind. In no event shall the
!!          author or copyright holders be liable for any kind of claim in connection to
!!          the software and its usage.
!!!!

program saxpy_serial
    use, intrinsic :: iso_fortran_env
    implicit none
    integer, parameter :: sp = REAL32   ! single precision
    integer, parameter :: dp = REAL64   ! double precision
    integer, parameter :: ORD = 2**27   ! arrays size
    real(sp), dimension(:), allocatable :: x, y     ! arrays
    real(sp) :: a   ! scalar constant    
    integer :: i    ! integer helper

    ! allocate memory space
    allocate(x(ORD))
    allocate(y(ORD))
    
    ! initialize random number generator, set values of x, y, a
    call random_seed()
    call random_number(x)   ! x is noise
    y = 1.0_sp              ! y is just ones
    a = 2.0_sp              ! a is the scalar y -> a*x + y

    ! perform SAXPY
    do i = 1, ORD
        y(i) = a*x(i) + y(i)
    enddo

    ! clean up
    deallocate(x,y)

end program saxpy_serial

