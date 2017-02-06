/*
 *	macros.h
 *	
 *	Created by Ryoichi Ando on 11/3/11
 *	Email: and@verygood.aid.design.kyushu-u.ac.jp
 *
 */

#ifndef _MACROS_H
#define _MACROS_H

#define DIM			2				// Simulation dimension
#define NUM_VERT	3				// Number of vertices in a element
typedef float		FLOAT32;		// 32 bit floating point
typedef double		FLOAT64;		// 64 bit floating point
typedef long double	FLOAT80;		// 80 bit floating point
typedef unsigned int uint;			// Generic unsigned integer
typedef unsigned char uint8;		// 8 bit unsigned char
typedef unsigned long long uint64;	// 64 bit integer

// Fluid and solid number
enum { FLUID, SOLID };

// Easy PI
#define PI	3.14159265

// Integer min() and max() operators
#define imin( i, j ) ( (i) < (j) ? (i) : (j) )
#define imax( i, j ) ( (i) < (j) ? (j) : (i) )
#define iabs(i) ( i < 0 ? -(i) : (i) )

#if defined(WIN32)
#define fmin( i, j ) ( (i) < (j) ? (i) : (j) )
#define fmax( i, j ) ( (i) < (j) ? (j) : (i) )
#endif

// Useful macros for nested loops
#define FOR_EACH(W,H)			for( int ci=0; ci<(W)*(H); ci++ ) { { { int i=ci%(W); int j=ci/(W);
#define FOR_EACH_SIZE(S)		for( int ci=0; ci<(S.w)*(S.h); ci++ ) { { { int i=ci%(S.w); int j=ci/(S.w);
#define FOR_NEIGHBORS(i,j,iw,jw,w,h) for( int ni=(int)(i)-(int)(iw); ni<=(int)(i)+(int)(iw); ni++ ) { \
									 for( int nj=(int)(j)-(int)(jw); nj<=(int)(j)+(int)(jw); nj++ ) { \
									 if( ni<0 || ni>=w || nj<0 || nj>=h ) continue; {
#define FOR_EACH_PARTICLE(particles) for( int pcount=0; pcount<particles.size(); pcount++ ) \
									{ { { particle2 &p = *particles[pcount];
#define FOR_EACH_NEIGHBOR_PARTICLE(particles) for( int npcount=0; npcount<particles.size(); npcount++ ) \
									{ {  particle2 &np = *particles[npcount]; if(np.rm) continue; {
#define END_FOR } } }

// Try turn on OpenMP if available
#if defined(_OPENMP)
#define USE_OPENMP		1
#endif

// Set GCC version if we are on the GCC compiler
#if __GNUG__
#define GCC_VERSION (__GNUC__ * 10000 \
+ __GNUC_MINOR__ * 100 \
+ __GNUC_PATCHLEVEL__)
#endif

// Check that we might be on the Apple implementation with a buggy OpenMP...
#if defined(__APPLE__) && GCC_VERSION < 40400 && USE_OPENMP
// In such case we force disable OpenMP !
#undef USE_OPENMP
#define USE_OPENMP	0
#warning "OpenMP is only allowed with GCC v.4.4 or higher due to the buggy Apple implementation"
#endif

#if USE_OPENMP
#include <omp.h>
#define PARALLEL_FOR		_Pragma("omp parallel for" )
#define PARALLEL_SECTION	_Pragma("omp section" )
#define PARALLEL_BEGIN		_Pragma("omp parallel" ) {
#define PARALLEL_END		}
#define PARALLEL_FOR_P		_Pragma("omp for" )
#else
#define PARALLEL_FOR
#define PARALLEL_SECTION
#define PARALLEL_BEGIN
#define PARALLEL_END
#define PARALLEL_FOR_P
#endif

#endif