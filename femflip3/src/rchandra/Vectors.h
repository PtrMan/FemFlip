#ifndef VECTORS_H
#define VECTORS_H
// File Name: Vectors.h
// Last Modified: 7/8/2000
// Author: Raghavendra Chandrashekara
// Email: rc99@doc.ic.ac.uk, rchandrashekara@hotmail.com
//
// Description: This file contains some useful structures.

typedef double POINT3D[3];
typedef double VECTOR3D[3];

struct POINT3DXYZ {
	double x, y, z;
	friend POINT3DXYZ operator+(const POINT3DXYZ& pt3dPoint1, const POINT3DXYZ& pt3dPoint2);
	friend POINT3DXYZ operator-(const POINT3DXYZ& pt3dPoint1, const POINT3DXYZ& pt3dPoint2);
	friend POINT3DXYZ operator*(const POINT3DXYZ& pt3dPoint, float fScale);
	friend POINT3DXYZ operator*(float fScale, const POINT3DXYZ& pt3dPoint);
	friend POINT3DXYZ operator/(const POINT3DXYZ& pt3dPoint, float fScale);
	friend POINT3DXYZ& operator*=(POINT3DXYZ& pt3dPoint, float fScale);
	friend POINT3DXYZ& operator/=(POINT3DXYZ& pt3dPoint, float fScale);
	friend POINT3DXYZ& operator+=(POINT3DXYZ& pt3dPoint1, const POINT3DXYZ& pt3dPoint2);
	friend POINT3DXYZ& operator-=(POINT3DXYZ& pt3dPoint1, const POINT3DXYZ& pt3dPoint2);
};

typedef POINT3DXYZ VECTOR3DXYZ;
#endif // VECTORS_H
